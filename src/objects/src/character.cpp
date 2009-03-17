#include "../include/character.hpp"

Character::Character()
{
	script->loadScript("data/character/character.lua");
}

void Character::loadGlobalVars()
{
	life		= (int)script->getNumericVar("life");
	imortalTime	= (int)script->getNumericVar("imortalTime");
}

void Character::registerFunctions()
{
	script->registerFunction("lua_getLife",lua_getLife);
	script->registerFunction("lua_setLife",lua_setLife);
	script->registerFunction("lua_subLife",lua_subLife);
	script->registerFunction("lua_addLife",lua_addLife);
	script->registerFunction("lua_ativate",lua_ativate);
	script->registerFunction("lua_inativate",lua_inativate);
	script->registerFunction("lua_isAlive",lua_isAlive);
	script->registerFunction("lua_isAtive",lua_isAtive);
	script->registerFunction("lua_hurt",lua_hurt);
	script->registerFunction("lua_callHelper",lua_callHelper);
}

void Character::setUp()
{
	Object::setUp();
	loadGlobalVars();
	registerFunctions();
	currentLife	= life;
	imortal		= 0;
	ative		= false;
	prepareHelpers();
}

Character::Character
(
	const string& fileName,
	const int& x,
	const int& y
)
{
	script->loadScript("data/character/character.lua");
	script->loadScript(fileName);
	posX		= x;
	posY		= y;
	setUp();
}

Character::~Character()
{
	for(int i=0; i<helpers.size(); ++i)
		for(int j=0; j<helpers[i].size(); ++j)
			delete helpers[i][j];
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
	const int &num=(int)script->function("getHelpersNumber",Gorgon::LuaParam(),1)->getNumericValue();
	printf("helperNum: %d\n",num);
	for(int i=0; i<num; ++i)
	{
		const int numInstances	=script->function("getHelperMaxInstances",Gorgon::LuaParam("i",i+1),1)->getNumericValue();
		string helperScriptFile	=script->function("getHelperScriptFile",Gorgon::LuaParam("i",i+1),1)->getStringValue();
		vector<Character*> helper;
		
		for(int j=0; j<numInstances; ++j)
		{
			helper.push_back(new Character(helperScriptFile));
		}
		helpers.push_back(helper);
	}
}

void Character::callHelper
(
	const int& x,
	const int& y,
	const Gorgon::Mirroring& mirroring,
	const int& helper
)
{
	for(int i=0; i<helpers[helper].size(); ++i)
	{
		if(!helpers[helper][i]->isAtive())
		{
			helpers[helper][i]->setPosition(x,y);
			helpers[helper][i]->ativate();
			helpers[helper][i]->setMirroring(mirroring);
			break;
		}	
	}
}

void Character::draw() const
{
	if(ative)
	{
		if((imortal>0 && (imortal%2==0)) || imortal==0)
		{
			Object::draw();
		}
		for(int i=0; i<helpers.size(); ++i)
		{
			for(int j=0; j<helpers[i].size(); ++j)
			{
				if(helpers[i][j]->isAtive())
				{
					helpers[i][j]->draw();
				}
			}
		}
	}
}

void Character::logic()
{
	Object::logic();
	if(imortal>0)
		--imortal;
	for(int i=0; i<helpers.size(); ++i)
	{
		for(int j=0; j<helpers[i].size(); ++j)
		{
			if(helpers[i][j]->isAtive())
			{
				helpers[i][j]->logic();
			}
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
				Gorgon::Mirroring::Normal,
				lua_tointeger(state,5)
			);
			break;
		case 1:
			a->callHelper
			(
				lua_tointeger(state,2),
				lua_tointeger(state,3),
				Gorgon::Mirroring::HFlip,
				lua_tointeger(state,5)
			);
			break;
		case 2:
			a->callHelper
			(
				lua_tointeger(state,2),
				lua_tointeger(state,3),
				Gorgon::Mirroring::VFlip,
				lua_tointeger(state,5)
			);
			break;
		default:
			a->callHelper
			(
				lua_tointeger(state,2),
				lua_tointeger(state,3),
				Gorgon::Mirroring::VHFlip,
				lua_tointeger(state,5)
			);
			break;
	}
	return 0;
}
