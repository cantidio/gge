#include "../include/background.hpp"
#include "../include/background_lua.hpp"

Background::Background
(
	const int& width,
	const int& height,
	const double& posX,
	const double& posY
)
{
	script			= new Gorgon::Lua("data/background/background.lua");
	script->function("setBackgroundPointer",Gorgon::LuaParam("n",this));
	BackgroundLua::registerFunctions(script);
	this->width		= width;
	this->height	= height;
	this->posX		= posX;
	this->posY		= posY;
}

Background::Background(const std::string& fileName)
{
	script = new Gorgon::Lua("data/background/background.lua");
	script->function("setBackgroundPointer",Gorgon::LuaParam("n",this));
	BackgroundLua::registerFunctions(script);
	load(fileName);
}

Background::~Background()
{
	for(int i=0; i<layers.size(); ++i)
	{
		delete layers[i];
	}
	layers.clear();
}

void Background::addLayer(Layer* layer)
{
	layers.push_back(layer);
}

void Background::logic()
{
	script->function("logic");
	for(int i=0; i<layers.size(); ++i)
	{
		layers[i]->logic();
	}
}

void Background::draw(Gorgon::Sprite& sprite)
{
	for(int i=0; i<layers.size(); ++i)
	{
		layers[i]->draw(sprite,posX,posY);
	}
}

void Background::save(const std::string& fileName) const
{
	std::fstream file(fileName.c_str(),std::ios::out);
	
	if(file.is_open())
	{
		file << "--Background Script File just modify if you know what you are doing" << std::endl;
		file << "--Background gravity" << std::endl;
		file << "gravity	= " << gravity << std::endl;
		file << "--width of the background" << std::endl;
		file << "width		= " << width << std::endl;
		file << "--height of the background" << std::endl;
		file << "height		= " << height << std::endl;
		file << "--init x position" << std::endl;
		file << "posX		= " << posX << std::endl;
		file << "--init y position" << std::endl;
		file << "posY		= " << posY << std::endl;
		file << "--vector with the layers of the background" << std::endl;
		file << "layers	= {";

		if(layers.size()>0)
		{
			file << std::endl;
			for(int i=0; i<layers.size(); ++i)
			{
				std::stringstream layerName;
				layerName << fileName.substr(0,fileName.find(".")) << "_layer" << i << fileName.substr(fileName.find("."),fileName.length()-1);
				
				file << "\t\"" << layerName.str() << "\"," << std::endl;
				layers[i]->save(layerName.str());
			}
		}

		file << "}" << std::endl << std::endl;
		file << "function logic()" << std::endl;
		file << "\t--Put your background logic here" << std::endl;
		file << "end" << std::endl << std::endl;
	}
	else
	{
		std::cout <<"Erro ao salvar cenário!\n";
	}
	file.close();
}

void Background::loadGlobalVars()
{
	gravity	= script->getNumericVar("gravity");
	width	= script->getNumericVar("width");
	height	= script->getNumericVar("height");
	posX	= script->getNumericVar("posX");
	posY	= script->getNumericVar("posY");
}

void Background::loadLayers()
{
	const int layerNumber =(int)script->function("getLayerNumber",Gorgon::LuaParam(),1)->getNumericValue();
	for(int i=1; i<=layerNumber; ++i)
	{
		layers.push_back(new Layer(script->function("getLayer",Gorgon::LuaParam("n",i),1)->getStringValue()));
	}
}

void Background::setUp()
{
	loadGlobalVars();
	loadLayers();
}

void Background::load(const std::string& fileName)
{
	script->loadScript(fileName);
	setUp();
}

void Background::scroolLock()
{
	lockScrool=true;
}

void Background::scroolUnlock()
{
	lockScrool=false;
}

void Background::setXPos(const double& x)
{
	if(!lockScrool)
	{
		posX=x;
	}
}

void Background::setYPos(const double& y)
{
	if(!lockScrool)
	{
		posY=y;
	}
}

double Background::getXPos() const
{
	return posX;
}

double Background::getYPos() const
{
	return posY;
}




