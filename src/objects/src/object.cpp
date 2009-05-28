#include "../include/object.hpp"
#include "../include/object_lua.hpp"

Object::Object()
{
	script	= new Gorgon::Lua("data/object/object.lua");
}

void Object::loadGlobalVars()
{
	name				= script->getStringVar("name");
	spritePackName		= script->getStringVar("sprite");
	animationPackName	= script->getStringVar("animation");
	colisionPackName	= script->getStringVar("colision");
	paletteName			= script->getStringVar("palette");
	xPulse				= script->getNumericVar("xPulse");
	yPulse				= script->getNumericVar("yPulse");
	xPulseMax			= script->getNumericVar("xPulseMax");
	gravityAffected		= script->getBooleanVar("gravityAffected");
}

void Object::setUp()
{
	loadGlobalVars();
	script->function("getObject",Gorgon::LuaParam("N",this));
	ObjectLua::registerFunctions(script);
	spritePack			= ResourceManager::SpriteManager::load(spritePackName);
	animationPack		= ResourceManager::AnimationManager::load(animationPackName);
	animationHandler	= new Gorgon::AnimationHandler(*spritePack,*animationPack);
}

Object::Object(const std::string& scriptName,const Gorgon::Point& position)
{
	setPosition(position);
	script	= new Gorgon::Lua("data/object/object.lua");
	script->loadScript(scriptName);
	setUp();
}

Object::~Object()
{
	ResourceManager::SpriteManager::unload(spritePackName);
	ResourceManager::AnimationManager::unload(animationPackName);
	delete animationHandler;
}

void Object::setMirroring(const Gorgon::Mirroring& mirroring)
{
	direction=mirroring;
}

Gorgon::Mirroring Object::getMirroring() const
{
	return direction;
}

void Object::setXPosition(const double& x)
{
	position.setX(x);
}

void Object::setYPosition(const double& y)
{
	position.setY(y);
}

void Object::setPosition(const Gorgon::Point& newPosition)
{
	position=newPosition;
}

void Object::addXPosition(const double& x)
{
	position.addX(x);
}

void Object::addYPosition(const double& y)
{
	position.addY(y);
}

void Object::addPosition(const double& x,const double& y)
{
	position.addX(x);
	position.addY(y);
}

void Object::subXPosition(const double& x)
{
	position.subX(x);
}

void Object::subYPosition(const double& y)
{
	position.subY(y);
}

void Object::subPosition(const double& x,const double& y)
{
	position.subX(x);
	position.subY(y);
}

double Object::getXPosition() const
{
	return position.getX();
}

double Object::getYPosition() const
{
	return position.getY();
}

void Object::draw() const
{
	animationHandler->draw
	(
		*Gorgon::Video::get(),
		(int)position.getX(),
		(int)position.getY(),
		direction
	);
}

void Object::changeAnimation(const int& animation)
{
	animationHandler->changeAnimation(animation);
}

bool Object::animationIsPlaying() const
{
	return animationHandler->isPlaying();
}

int Object::getAnimationOn() const
{
	return animationHandler->getAnimationOn();
}

int Object::getFrameOn() const
{
	return animationHandler->getFrameOn();
}

void Object::logic()
{
	script->function("logic");
	animationHandler->playByStep();
}
