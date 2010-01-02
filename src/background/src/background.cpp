#include "../include/background.hpp"
#include "../include/background_lua.hpp"
#include "../include/layer_lua.hpp"

Background::Background
(
	const int&				pWidth,
	const int&				pHeight,
	const Gorgon::Point&	pPosition
)
{
	mScript		= new Gorgon::Lua("data/background/class_background.lua");
	mWidth		= pWidth;
	mHeight		= pHeight;
	mPosition	= pPosition;
	mScript->function("script_background_setPointer",Gorgon::LuaParam("n",this));
	BackgroundLua::registerFunctions(mScript);
	LayerLua::registerFunctions(mScript);
}

Background::Background(const std::string& pFileName)
{
	mScript = new Gorgon::Lua("data/background/class_background.lua");
	load(pFileName);
}

Background::~Background()
{
	for(int i=0; i<mLayers.size(); ++i)
	{
		delete mLayers[i];
	}
	mLayers.clear();
}

void Background::addLayer(Layer* pLayer)
{
	mLayers.push_back(pLayer);
}

void Background::logic()
{
	mScript->function("script_background_logic");
	for(int i=0; i<mLayers.size(); ++i)
	{
		mLayers[i]->logic();
	}
}

void Background::draw(Gorgon::Sprite& pSprite)
{
	for(int i=0; i<mLayers.size(); ++i)
	{
		mLayers[i]->draw(pSprite,mPosition);
	}
}

void Background::save(const std::string& pFileName) const
{
	std::fstream file(pFileName.c_str(),std::ios::out);
	
	if(file.is_open())
	{
		file << "--Background Script File just modify if you know what you are doing" << std::endl;
		file << "--Background gravity"	<< std::endl;
		file << "gravity		= "		<< mGravity << std::endl;
		file << "--Friction when not coliding" << std::endl;
		file << "voidFriction	= "		<< mVoidFriction << std::endl;
		file << "--width of the background" << std::endl;
		file << "width			= "		<< mWidth << std::endl;
		file << "--height of the background" << std::endl;
		file << "height			= "		<< mHeight << std::endl;
		file << "--init x position"		<< std::endl;
		file << "posX			= "		<< mPosition.getX() << std::endl;
		file << "--init y position"		<< std::endl;
		file << "posY			= "		<< mPosition.getY() << std::endl;
		file << "--vector with the layers of the background" << std::endl;
		file << "layers	= {";

		if(mLayers.size()>0)
		{
			file << std::endl;
			for(int i=0; i<mLayers.size(); ++i)
			{
				std::stringstream layerName;
				layerName << pFileName.substr(0,pFileName.find(".")) << "_layer" << i << pFileName.substr(pFileName.find("."),pFileName.length()-1);
				
				file << "\t\"" << layerName.str() << "\"," << std::endl;
				mLayers[i]->save(layerName.str());
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
	mGravity		= mScript->function("script_background_getGravity"		,Gorgon::LuaParam(),1)->getNumericValue();
	mVoidFriction	= mScript->function("script_background_getVoidFriction"	,Gorgon::LuaParam(),1)->getNumericValue();
	mWidth			= mScript->function("script_background_getWidth"		,Gorgon::LuaParam(),1)->getNumericValue();
	mHeight			= mScript->function("script_background_getHeight"		,Gorgon::LuaParam(),1)->getNumericValue();
	mPosition.setX	( mScript->function("script_background_getPosX"			,Gorgon::LuaParam(),1)->getNumericValue());
	mPosition.setY	( mScript->function("script_background_getPosY"			,Gorgon::LuaParam(),1)->getNumericValue());
}

void Background::loadLayers()
{
	const int layerNumber =(int)mScript->function("script_background_getLayerNumber",Gorgon::LuaParam(),1)->getNumericValue();
	for(int i = 1; i <= layerNumber; ++i)
	{
		mLayers.push_back
		(
			new Layer
			(
				mScript->function("script_background_getLayer",Gorgon::LuaParam("n",i),1)->getStringValue(),
				this
			)
		);
	}
}

void Background::setUp()
{
	loadGlobalVars();
	mScript->function("script_background_setPointer",Gorgon::LuaParam("n",this));
	BackgroundLua::registerFunctions(mScript);
	LayerLua::registerFunctions(mScript);
	loadLayers();
}

void Background::load(const std::string& pFileName)
{
	mScript->loadScript(pFileName);
	setUp();
}

void Background::scroolLock()
{
	mLockScrool = true;
}

void Background::scroolUnlock()
{
	mLockScrool = false;
}

int Background::getWidth() const
{
	return mWidth;
}

int Background::getHeight() const
{
	return mHeight;
}

void Background::setPosition(const Gorgon::Point& pPosition)
{
	if(!mLockScrool)
	{
		mPosition = pPosition;
	}
}

Gorgon::Point Background::getPosition() const
{
	return mPosition;
}

void Background::addPosition(const Gorgon::Point& pPosition)
{
	setPosition(mPosition + pPosition);
}

void Background::subPosition(const Gorgon::Point& pPosition)
{
	setPosition(mPosition - pPosition);
}

int Background::getLayerNumber() const
{
	return mLayers.size();
}

const Layer& Background::operator [](const int& pPos) const
{
	if(pPos >= 0 && pPos < mLayers.size())
	{
		return *mLayers[pPos];
	}
}

Layer& Background::operator [](const int& pPos)
{
	if(pPos >= 0 && pPos < mLayers.size())
	{
		return *mLayers[pPos];
	}
}