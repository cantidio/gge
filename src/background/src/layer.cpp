#include "../include/layer.hpp"

Layer::Layer(const double& xScrollSpeed,const double& yScrollSpeed)
{
	script				= new Gorgon::Lua("data/background/background_layer.lua");
	this->xScrollSpeed	= xScrollSpeed;
	this->yScrollSpeed	= yScrollSpeed;
}

Layer::Layer(const Layer& orig)
{
	xScrollSpeed	= orig.xScrollSpeed;
	yScrollSpeed	= orig.yScrollSpeed;

}
Layer::Layer(const std::string& scriptName)
{
	load(scriptName);
}

Layer::~Layer()
{
	tiles.clear();
	objects.clear();
	ResourceManager::SpriteManager::unload(spritePackName);
	ResourceManager::AnimationManager::unload(animationPackName);
}

void Layer::describe() const
{
	std::cout << "Layer describer" << std::endl;
	std::cout << "ScrollingXSpeed:" << xScrollSpeed << std::endl;
	std::cout << "ScrollingYSpeed:" << yScrollSpeed << std::endl;
	std::cout << "Tiles:" << std::endl;
	for(int i=0; i<tiles.size(); ++i)
	{
		std::cout << "Tile: " << i << std::endl;
		tiles[i]->describe();
	}
}

int Layer::getRealPosX(const int& posX) const
{
	return posX*xScrollSpeed;
}

int Layer::getRealPosY(const int& posY) const
{
	return posY*yScrollSpeed;
}

void Layer::addTile(Tile* tile)
{
	tiles.push_back(tile);
}

void Layer::addObject(Object* object)
{
	objects.push_back(object);
}

void Layer::logic()
{
	script->function("logic");
	int i;
	for(i=0; i<tiles.size(); ++i)
	{
		tiles[i]->logic();
	}
	for(i=0; i<objects.size(); ++i)
	{
		objects[i]->logic();
	}
}

void Layer::draw
(
	Gorgon::Sprite& sprite,
	const int& x,
	const int& y
)
{
	int i;
	for(i=0; i<tiles.size(); ++i)
	{
		tiles[i]->draw
		(
			sprite,
			getRealPosX(x),
			getRealPosY(y)
		);
	}
}

void Layer::save(const std::string& fileName) const
{
	std::fstream file(fileName.c_str(),std::ios::out);

	if(file.is_open())
	{
		file << "--Layer Script File just modify if you know what you are doing" << std::endl;
		file << "--location of the layer spritePack" << std::endl;
		file << "sprite\t\t\t\t= " << "\"" << "Blobs" << "\"" << std::endl;
		file << "--location of the layer animationPack" << std::endl;
		file << "animation\t\t\t= " << "\"" << "Blobs" << "\"" << std::endl;
		file << "--x scrolling velocity" << std::endl;
		file << "xScrollingSpeed\t\t= " << xScrollSpeed << std::endl;
		file << "--y scrolling velocity" << std::endl;
		file << "yScrollingSpeed\t\t= " << yScrollSpeed << std::endl;
		file << "--vector with the tiles of the layer" << std::endl;
		file << "tiles\t\t\t\t= {";

		if(tiles.size()>0)
		{
			file << std::endl;
			for(int i=0; i<tiles.size(); ++i)
			{
				file << "\t{" << std::endl;
				file << "\t\tanimation	= " << tiles[i]->getAnimation() << "," << std::endl;
				file << "\t\tposition	= {" << std::endl;
				for(int j=0; j<tiles[i]->getSize(); ++j)
				{
					file << "\t\t\t{ x = " << tiles[i]->getXPostion(j);
					file << ", y = " << tiles[i]->getYPostion(j) << " }," << std::endl;
				}
				file << "\t\t}" << std::endl;
				file << "\t}," << std::endl;
			}
		}
		file << "}" << std::endl << std::endl;
		/*file << "objects				= {";
		if(objects.size()>0)
		{
			file << std::endl;
			for(int i=0; i<objects.size(); ++i)
			{
				file << "\t\"" << fileName.substr(0,fileName.find(".lua")) << "_layer" << i;
				file << fileName.substr(fileName.find(".lua"),fileName.length()-1) << "\"," << std::endl;
			}
		}
		file << "}" << std::endl << std::endl;ss
*/
		file << "function logic()" << std::endl;
		file << "\t--Put your layer logic here" << std::endl;
		file << "end" << std::endl << std::endl;
	}
	else
	{
		std::cout <<"Erro ao salvar cenário!\n";
	}
	file.close();
}

void Layer::load(const std::string& fileName)
{
	script	= new Gorgon::Lua("data/background/background_layer.lua");
	script->loadScript(fileName);
	loadGlobalVars();
	setUp();
}

void Layer::loadGlobalVars()
{
	spritePackName			= script->getStringVar("sprite");
	animationPackName		= script->getStringVar("animation");
	xScrollSpeed			= script->getNumericVar("xScrollingSpeed");
	yScrollSpeed			= script->getNumericVar("yScrollingSpeed");
}

void Layer::loadTiles()
{
	const int tileNumber	=(int)script->function("getTileNumber",Gorgon::LuaParam(),1)->getNumericValue();
	for(int i=1; i<=tileNumber; ++i)
	{
		tiles.push_back
		(
			new Tile
			(
				*spritePack,
				*animationPack,
				(int)script->function("getTileAnimation",Gorgon::LuaParam("n",i),1)->getNumericValue()
			)
		);
		const int tileInstances =(int)script->function("getTileInstances",Gorgon::LuaParam("n",i),1)->getNumericValue();
		for(int j=1; j<=tileInstances; ++j)
		{
			tiles[i-1]->add
			(
				(int)script->function("getTileXPosition",Gorgon::LuaParam("nn",i,j),1)->getNumericValue(),
				(int)script->function("getTileYPosition",Gorgon::LuaParam("nn",i,j),1)->getNumericValue()
			);
		}
	}
}

void Layer::loadObjects()
{
	const int objectNumber	=(int)script->function("getObjectNumber",Gorgon::LuaParam(),1)->getNumericValue();
	for(int i=1; i<=objectNumber; ++i)
	{
		const int objectInstances=(int)script->function("getObjectInstances",Gorgon::LuaParam("n",i),1)->getNumericValue();
		for(int j=1; j<=objectInstances; ++j)
		{
			objects.push_back
			(
				new Object
				(
					script->function("getObjectScript",Gorgon::LuaParam("n",i),1)->getStringValue(),
					Gorgon::Point
					(
						script->function("getObjectXPosition",Gorgon::LuaParam("nn",i,j),1)->getNumericValue(),
						script->function("getObjectYPosition",Gorgon::LuaParam("nn",i,j),1)->getNumericValue()
					)
				)
			);
		}
	}
}

void Layer::setUp()
{
	loadGlobalVars();
	//registerFunctions();
	spritePack			= ResourceManager::SpriteManager::load(spritePackName);
	animationPack		= ResourceManager::AnimationManager::load(animationPackName);
	loadTiles();
	loadObjects();
}
