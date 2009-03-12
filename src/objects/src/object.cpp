#include "../include/object.hpp"

Object::Object
(
	const string& scriptName,
	const int& x,
	const int& y
)
{
	script				= new Gorgon::Lua("resources/object/object.lua");
	script->loadScript(scriptName);
	name				= script->getStringVar("name");
	spritePackName		= script->getStringVar("sprite");
	animationPackName	= script->getStringVar("animation");
	colisionPackName	= script->getStringVar("colision");
	paletteName			= script->getStringVar("palette");

	posX				= x;
	posY				= y;
	xPulse				= script->getNumericVar("xPulse");
	yPulse				= script->getNumericVar("yPulse");
	xPulseMax			= script->getNumericVar("xPulseMax");
	stateOn;

	spritePack			= ResourceManager::SpriteManager::load(spritePackName);
	animationPack		= ResourceManager::AnimationManager::load(animationPackName);

	animationHandler	= new Gorgon::AnimationHandler(*spritePack,*animationPack);
	
	registerFunctions();
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

void Object::setXPosition(const int& x)
{
	posX=x;
}

void Object::setYPosition(const int& y)
{
	posY=y;
}

void Object::setPosition(const int& x,const int& y)
{
	posX=x;
	posY=y;
}

void Object::addXPosition(const int& x)
{
	posX+=x;
}

void Object::addYPosition(const int& y)
{
	posY+=y;
}

void Object::addPosition(const int& x,const int& y)
{
	posX+=x;
	posY+=y;
}

int Object::getXPosition() const
{
	return posX;
}

int Object::getYPosition() const
{
	return posY;
}

void Object::draw() const
{
	animationHandler->draw
	(
		*Gorgon::Video::get(),
		posX,
		posY,
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

void Object::logic()
{
	script->function("logic",Gorgon::mountParam(""),0);
	animationHandler->playByStep();
}

void Object::registerFunctions()
{
	vector<Gorgon::LuaParam> obj=Gorgon::mountParam("i",this);
	script->function("getObject",obj,0);
	script->registerFunction("lua_changeAnimation",lua_changeAnimation);
	script->registerFunction("lua_animationIsPlaying",lua_animationIsPlaying);
	script->registerFunction("lua_getXPosition",lua_getXPosition);
	script->registerFunction("lua_getYPosition",lua_getYPosition);
	script->registerFunction("lua_setXPosition",lua_setXPosition);
	script->registerFunction("lua_setYPosition",lua_setYPosition);
	script->registerFunction("lua_setPosition",lua_setPosition);
	script->registerFunction("lua_addXPosition",lua_addXPosition);
	script->registerFunction("lua_addYPosition",lua_addYPosition);
	script->registerFunction("lua_addPosition",lua_addPosition);
	script->registerFunction("lua_setMirroring",lua_setMirroring);
	script->registerFunction("lua_getMirroring",lua_getMirroring);
}

int lua_changeAnimation(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	a->changeAnimation((int)lua_tointeger(state,2));
	return 0;
}
int lua_animationIsPlaying(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	lua_pushboolean(state,a->animationIsPlaying());;
	return 1;
}
int lua_getXPosition(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	lua_pushnumber(state,a->getXPosition());
	return 1;
}

int lua_getYPosition(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	lua_pushnumber(state,a->getYPosition());
	return 1;
}

int lua_setXPosition(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	a->setXPosition((int)lua_tointeger(state,2));
	return 0;
}
int lua_setYPosition(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	a->setYPosition((int)lua_tointeger(state,2));
	return 0;
}
int lua_setPosition(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	a->setPosition
	(
		(int)lua_tointeger(state,2),
		(int)lua_tointeger(state,3)
	);
	return 0;
}
int lua_addXPosition(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	a->addXPosition((int)lua_tointeger(state,2));
	return 0;
}
int lua_addYPosition(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	a->addYPosition((int)lua_tointeger(state,2));
	return 0;
}
int lua_addPosition(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	a->addPosition
	(
		(int)lua_tointeger(state,2),
		(int)lua_tointeger(state,3)
	);
	return 0;
}

int lua_setMirroring(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	switch((int)lua_tointeger(state,2))
	{
		case 0:		a->setMirroring(Gorgon::Mirroring::Normal);	break;
		case 1:		a->setMirroring(Gorgon::Mirroring::HFlip);	break;
		case 2:		a->setMirroring(Gorgon::Mirroring::VFlip);	break;
		default:	a->setMirroring(Gorgon::Mirroring::VHFlip);	break;
	}
	return 0;
}

int lua_getMirroring(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Object* a=(Object*)pointer;
	switch(a->getMirroring().getType())
	{
		case Gorgon::Mirroring::Normal: lua_pushnumber(state,0);	break;
		case Gorgon::Mirroring::HFlip:	lua_pushnumber(state,1);	break;
		case Gorgon::Mirroring::VFlip:	lua_pushnumber(state,2);	break;
		default:						lua_pushnumber(state,3);	break;
	}
	return 1;
}
