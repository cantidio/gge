#include "../include/layer.hpp"
#include "../include/layer_lua.hpp"

Layer::Layer(const double& pXScrollSpeed,const double& pYScrollSpeed)
{
	mBackground		= NULL;
	mScript			= new Gorgon::Lua("data/background/class_layer.lua");
	mXScrollSpeed	= pXScrollSpeed;
	mYScrollSpeed	= pYScrollSpeed;
	mSpritePack     = new Gorgon::SpritePack();
	mAnimationPack  = new Gorgon::AnimationPack();
	mScript->function("setPointer",Gorgon::LuaParam("n",this));
	LayerLua::registerFunctions(mScript);
}

Layer::Layer(const Layer& pOrig)
{
	mXScrollSpeed	= pOrig.mXScrollSpeed;
	mYScrollSpeed	= pOrig.mYScrollSpeed;
	mBackground		= pOrig.mBackground;
	/**
	 * @todo colocar o resto aki, ta faltando mto coisa, como copiar o script, clonar um estado lua...
	 */
}

Layer::Layer(const std::string& pScriptName,Background* pBackground)
{
	mBackground = pBackground;
	load(pScriptName);
}

Layer::~Layer()
{
	mTiles.clear();
	mObjects.clear();
	ResourceManager::SpriteManager::unload(mSpritePackName);
	ResourceManager::AnimationManager::unload(mAnimationPackName);
}

void Layer::describe() const
{
	std::cout << "Layer describer" << std::endl;
	std::cout << "ScrollingXSpeed:" << mXScrollSpeed << std::endl;
	std::cout << "ScrollingYSpeed:" << mYScrollSpeed << std::endl;
	std::cout << "Tiles:" << std::endl;

	for(int i = 0; i < mTiles.size(); ++i)
	{
		std::cout << "Tile: " << i << std::endl;
		mTiles[i]->describe();
	}
}

Background* Layer::getBackground()
{
	return mBackground;
}

Gorgon::SpritePack* Layer::getSpritePack()
{
    return mSpritePack;
}

Gorgon::AnimationPack* Layer::getAnimationPack()
{
    return mAnimationPack;
}

int Layer::getTileNumber() const
{
	return mTiles.size();
}

Gorgon::Point Layer::getRealPosition(const Gorgon::Point& pPosition) const
{
	return pPosition*Gorgon::Point(mXScrollSpeed,mYScrollSpeed);
}

void Layer::addTile(Tile* pTile)
{
	mTiles.push_back(pTile);
}

void Layer::addObject(Object* pObject)
{
	mObjects.push_back(pObject);
}

void Layer::logic()
{
	mScript->function("script_logic");
	int i;
	for(i=0; i<mTiles.size(); ++i)
	{
		mTiles[i]->logic();
	}
	for(i=0; i<mObjects.size(); ++i)
	{
		mObjects[i]->logic();
	}
}

void Layer::draw
(
	Gorgon::Sprite& pSprite,
	const Gorgon::Point& pPosition
)
{
	int i;
	for(i = 0; i < mTiles.size(); ++i)
	{
		mTiles[i]->draw
		(
			pSprite,
			getRealPosition(pPosition)
		);
	}
}

void Layer::save(const std::string& pFileName) const
{
	std::fstream file(pFileName.c_str(),std::ios::out);
	std::string baseName = pFileName;
	baseName.erase(baseName.find_first_of('.'));
	std::string className = baseName;
	className.erase(0,className.find_last_of('/') + 1);
	className.erase(0,className.find_last_of('\\') + 1);
	
	if(file.is_open())
	{
//		file << "--Layer Script File just modify if you know what you are doing" << std::endl;
		file << "function " << className << "()" << std::endl;
		file << "\tlocal this\t= Layer()" << std::endl;
//		file << "\t--location of the layer spritePack" << std::endl;
		file << "\tthis.sprite\t\t\t\t= " << "\"" << baseName << ".gspk" << "\"" << std::endl;
//		file << "\t--location of the layer animationPack" << std::endl;
		file << "\tthis.animation\t\t\t= " << "\"" << baseName << ".gapk" << "\"" << std::endl;
//		file << "\t--x scrolling velocity" << std::endl;
		file << "\tthis.xScrollingSpeed\t= " << mXScrollSpeed << std::endl;
//		file << "\t--y scrolling velocity" << std::endl;
		file << "\tthis.yScrollingSpeed\t= " << mYScrollSpeed << std::endl;
//		file << "v--vector with the tiles of the layer" << std::endl;
		file << "\tthis.tiles\t\t\t\t= {";

		if(mTiles.size() > 0)
		{
			file << std::endl;
			for(int i = 0; i < mTiles.size(); ++i)
			{
				file << "\t\t{" << std::endl;
				file << "\t\t\tanimation\t= "	<< mTiles[i]->getAnimation() << "," << std::endl;
				file << "\t\t\tposition\t= ";
				file << "{ x = "				<< mTiles[i]->getPosition().getX();
				file << ", y = "				<< mTiles[i]->getPosition().getY() << " }" << std::endl;
				file << "\t\t},"				<< std::endl;
			}
		}
		file << "\t}" << std::endl;
		file << "\tthis.logic = function ()" << std::endl;
		file << "\t\t--Put your Layer Logic Here" << std::endl;
		file << "\tend" << std::endl;
		file << "\treturn this" << std::endl;
		file << "end" << std::endl;
		file << "this = " << className << "()";
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
	}
	else
	{
		std::cout << "Erro ao salvar cenário!\n";
	}
	file.close();
}

void Layer::load(const std::string& pFileName)
{
	mScript	= new Gorgon::Lua("data/background/class_layer.lua");
	mScript->loadScript(pFileName);
	loadGlobalVars();
	setUp();
}

void Layer::loadGlobalVars()
{
	mSpritePackName		= mScript->function("script_getSpritePack",Gorgon::LuaParam(),1)->getStringValue();
	mAnimationPackName	= mScript->function("script_getAnimationPack",Gorgon::LuaParam(),1)->getStringValue();
	mXScrollSpeed		= mScript->function("script_getXScroolingSpeed",Gorgon::LuaParam(),1)->getNumericValue();
	mYScrollSpeed		= mScript->function("script_getYScroolingSpeed",Gorgon::LuaParam(),1)->getNumericValue();
}

void Layer::loadTiles()
{
	const int tileNumber	=(int)mScript->function("script_getTileNumber",Gorgon::LuaParam(),1)->getNumericValue();
	for(int i = 1; i <= tileNumber; ++i)
	{
		mTiles.push_back
		(
			new Tile
			(
				*mSpritePack,
				*mAnimationPack,
				(int)mScript->function("script_getTileAnimation",Gorgon::LuaParam("n",i),1)->getNumericValue(),
				Gorgon::Point
				(
					(int)mScript->function("script_getTileXPosition",Gorgon::LuaParam("nn",i),1)->getNumericValue(),
					(int)mScript->function("script_getTileYPosition",Gorgon::LuaParam("nn",i),1)->getNumericValue()
				),
				this
			)
		);
		/*
		const int tileInstances =(int)mScript->function("script_getTileInstances",Gorgon::LuaParam("n",i),1)->getNumericValue();

		for(int j = 1; j <= tileInstances; ++j)
		{
			mTiles.push_back
			(
				new Tile
				(
					*mSpritePack,
					*mAnimationPack,
					(int)mScript->function("script_getTileAnimation",Gorgon::LuaParam("n",i),1)->getNumericValue(),
					Gorgon::Point
					(
						(int)mScript->function("script_getTileXPosition",Gorgon::LuaParam("nn",i,j),1)->getNumericValue(),
						(int)mScript->function("script_getTileYPosition",Gorgon::LuaParam("nn",i,j),1)->getNumericValue()
					),
					this
				)
			);
		}*/
	}
}

void Layer::loadObjects()
{
	/*const int objectNumber	=(int)mScript->function("this.script_getObjectNumber",Gorgon::LuaParam(),1)->getNumericValue();
	for(int i=1; i<=objectNumber; ++i)
	{
		const int objectInstances=(int)mScript->function("this.script_getObjectInstances",Gorgon::LuaParam("n",i),1)->getNumericValue();
		for(int j=1; j<=objectInstances; ++j)
		{
			mObjects.push_back
			(
				new Object
				(
					mScript->function("this.script_getObjectScript",Gorgon::LuaParam("n",i),1)->getStringValue(),
					Gorgon::Point
					(
						mScript->function("this.script_getObjectXPosition",Gorgon::LuaParam("nn",i,j),1)->getNumericValue(),
						mScript->function("this.script_getObjectYPosition",Gorgon::LuaParam("nn",i,j),1)->getNumericValue()
					)
				)
			);
		}
	}*/
}

void Layer::setUp()
{
	loadGlobalVars();
	mScript->function("setPointer",Gorgon::LuaParam("n",this));
	LayerLua::registerFunctions(mScript);
	//registerFunctions();
	mSpritePack		= ResourceManager::SpriteManager::load(mSpritePackName);
	mAnimationPack	= ResourceManager::AnimationManager::load(mAnimationPackName);
	loadTiles();
	loadObjects();
}

Tile& Layer::operator [](const int& pPos)
{
	if(pPos < mTiles.size())
	{
		return *mTiles[pPos];
	}
}

const Tile& Layer::operator [](const int& pPos) const
{
	if(pPos < mTiles.size())
	{
		return *mTiles[pPos];
	}
}