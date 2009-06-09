#include "../include/object.hpp"
#include "../include/object_lua.hpp"

Object::Object()
{
	mScript = new Gorgon::Lua("data/object/object.lua");
}

void Object::loadGlobalVars()
{
	mName				= mScript->getStringVar("name");
	mSpritePackName		= mScript->getStringVar("sprite");
	mAnimationPackName	= mScript->getStringVar("animation");
	mColisionPackName	= mScript->getStringVar("colision");
	mPaletteName		= mScript->getStringVar("palette");
	mXPulse				= mScript->getNumericVar("xPulse");
	mYPulse				= mScript->getNumericVar("yPulse");
	mXPulseMax			= mScript->getNumericVar("xPulseMax");
	mGravityAffected	= mScript->getBooleanVar("gravityAffected");
}

void Object::setUp()
{
	loadGlobalVars();
	mScript->function("getObject",Gorgon::LuaParam("n",this));
	ObjectLua::registerFunctions(mScript);
	mSpritePack			= ResourceManager::SpriteManager::load(mSpritePackName);
	mAnimationPack		= ResourceManager::AnimationManager::load(mAnimationPackName);
	mAnimationHandler	= new Gorgon::AnimationHandler(*mSpritePack,*mAnimationPack);
}

Object::Object(const std::string& pScriptName,const Gorgon::Point& pPosition)
{
	setPosition(pPosition);
	mScript	= new Gorgon::Lua("data/object/object.lua");
	mScript->loadScript(pScriptName);
	setUp();
}

Object::~Object()
{
	ResourceManager::SpriteManager::unload(mSpritePackName);
	ResourceManager::AnimationManager::unload(mAnimationPackName);
	delete mAnimationHandler;
}

void Object::setMirroring(const Gorgon::Mirroring& pMirroring)
{
	mDirection=pMirroring;
}

Gorgon::Mirroring Object::getMirroring() const
{
	return mDirection;
}

void Object::setXPosition(const double& pPosX)
{
	mPosition.setX(pPosX);
}

void Object::setYPosition(const double& pPosY)
{
	mPosition.setY(pPosY);
}

void Object::setPosition(const Gorgon::Point& pPosition)
{
	mPosition=pPosition;
}

void Object::addXPosition(const double& pPosX)
{
	mPosition.addX(pPosX);
}

void Object::addYPosition(const double& pPosY)
{
	mPosition.addY(pPosY);
}

	void Object::addPosition(const double& pPosX,const double& pPosY)
{
	mPosition.addX(pPosX);
	mPosition.addY(pPosY);
}

void Object::subXPosition(const double& pPosX)
{
	mPosition.subX(pPosX);
}

void Object::subYPosition(const double& pPosY)
{
	mPosition.subY(pPosY);
}

void Object::subPosition(const double& pPosX,const double& pPosY)
{
	mPosition.subX(pPosX);
	mPosition.subY(pPosY);
}

double Object::getXPosition() const
{
	return mPosition.getX();
}

double Object::getYPosition() const
{
	return mPosition.getY();
}

void Object::draw() const
{
	mAnimationHandler->draw
	(
		*Gorgon::Video::get(),
		(int)mPosition.getX(),
		(int)mPosition.getY(),
		mDirection
	);
}

void Object::changeAnimation(const int& pAnimation)
{
	mAnimationHandler->changeAnimation(pAnimation,true);
}

void Object::changeAnimation(const int& pGroup, const int& pIndex)
{
	mAnimationHandler->changeAnimation(pGroup,pIndex,true);
}

bool Object::animationIsPlaying() const
{
	return mAnimationHandler->isPlaying();
}

int Object::getAnimationOn() const
{
	return mAnimationHandler->getAnimationOn();
}

int Object::getFrameOn() const
{
	return mAnimationHandler->getFrameOn();
}

void Object::logic()
{
	mScript->function("logic");
	mAnimationHandler->playByStep();
}
