#include "../include/character.hpp"

Character::Character
(
	const string& fileName,
	const int& x,
	const int& y
)
{
	script->loadScript("resources/character/character.lua");
	script->loadScript(fileName);
	Object::setUp();
	life		= (int)script->getNumericVar("life");
	currentLife	= life;
	imortalTime	= (int)script->getNumericVar("imortalTime");
	imortal		= 0;
	ative		= false;
	posX		= x;
	posY		= y;
	script->registerFunction("lua_getLife",lua_getLife);
	script->registerFunction("lua_setLife",lua_setLife);
	script->registerFunction("lua_subLife",lua_subLife);
	script->registerFunction("lua_addLife",lua_addLife);
	script->registerFunction("lua_ativate",lua_ativate);
	script->registerFunction("lua_inativate",lua_inativate);
	script->registerFunction("lua_isAlive",lua_isAlive);
	script->registerFunction("lua_isAtive",lua_isAtive);
	script->registerFunction("lua_callHelper",lua_callHelper);
	prepareHelpers();
}

Character::~Character()
{
	for(int i=0; i<helpers.size(); ++i)
		delete helpers[i];
}

int Character::getLife() const
{
	return currentLife;
}

void Character::setLife(const int& life)
{
	currentLife=life;
}

void Character::subLife(const int& life)
{
	currentLife-=life;
}

void Character::addLife(const int& life)
{
	currentLife+=life;
}

bool Character::isAlive() const
{
	return (currentLife>0) ? true : false;
}

void Character::ativate()
{
	ative=true;
}
void Character::inativate()
{
	ative=false;
}

bool Character::isAtive() const
{
	return ative;
}

bool Character::isImortal() const
{
	return imortal>0 ? true : false;
}

void Character::hurt(const int& damage)
{
	subLife(damage);
	imortal=imortalTime;
}

void Character::prepareHelpers()
{
	const int numHelpers= (int)script->getNumericVar("helperMaxInstances");
	const string helperScriptFile= script->getStringVar("helperScriptFile");
	for(int i=0; i<numHelpers; ++i)
	{
		helpers.push_back(new Character(helperScriptFile));
	}
}

void Character::callHelper
(
	const int& x,
	const int& y,
	const Gorgon::Mirroring& mirroring
)
{
	for(int i=0; i<helpers.size(); ++i)
	{
		if(!helpers[i]->isAtive())
		{
			helpers[i]->setPosition(x,y);
			helpers[i]->ativate();
			helpers[i]->setMirroring(mirroring);
			break;
		}
	}
}

void Character::draw() const
{
	if(ative)
	{
		if((imortal!=0 && imortal%2) || imortal==0)
		{
			Object::draw();
		}
		for(int i=0; i<helpers.size(); ++i)
		{
			if(helpers[i]->isAtive())
			{
				helpers[i]->draw();
			}
		}
	}
}

void Character::logic()
{
	Object::logic();
	for(int i=0; i<helpers.size(); ++i)
	{
		if(helpers[i]->isAtive())
		{
			helpers[i]->logic();
		}
	}
}

int lua_getLife(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	lua_pushinteger(state,a->getLife());
	return 1;
}

int lua_setLife(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	a->setLife((int)lua_tointeger(state,2));
	return 0;
}

int lua_subLife(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	a->subLife((int)lua_tointeger(state,2));
	return 0;
}

int lua_addLife(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	a->addLife((int)lua_tointeger(state,2));
	return 0;
}

int lua_isAlive(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	lua_pushboolean(state,a->isAlive());
	return 1;
}

int lua_ativate(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	a->ativate();
	return 0;
}

int lua_inativate(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	a->inativate();
	return 0;
}

int lua_isAtive(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	lua_pushboolean(state,a->isAtive());
	return 1;
}

int lua_isImortal(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	lua_pushboolean(state,a->isImortal());
	return 1;
}

int lua_hurt(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	a->hurt(lua_tointeger(state,2));
	return 0;
}

int lua_callHelper(lua_State* state)
{
	int pointer=lua_tointeger(state,1);
	Character* a=(Character*)pointer;
	switch(lua_tointeger(state,4))
	{
		case 0:
			a->callHelper
			(
				lua_tointeger(state,2),
				lua_tointeger(state,3),
				Gorgon::Mirroring::Normal
			);
			break;
		case 1:
			a->callHelper
			(
				lua_tointeger(state,2),
				lua_tointeger(state,3),
				Gorgon::Mirroring::HFlip
			);
			break;
		case 2:
			a->callHelper
			(
				lua_tointeger(state,2),
				lua_tointeger(state,3),
				Gorgon::Mirroring::VFlip
			);
			break;
		default:
			a->callHelper
			(
				lua_tointeger(state,2),
				lua_tointeger(state,3),
				Gorgon::Mirroring::VHFlip
			);
			break;
	}
	return 0;
}
