#include "../include/character.hpp"
#include "../include/character_lua.hpp"

Character::Character()
{
	script->loadScript("data/character/character.lua");
}

void Character::loadGlobalVars()
{
	life		= (int)script->getNumericVar("life");
	imortalTime	= (int)script->getNumericVar("imortalTime");
}

void Character::setUp()
{
	Object::setUp();
	loadGlobalVars();
	CharacterLua::registerFunctions(script);
	currentLife	= life;
	imortal		= 0;
	ative		= false;
	prepareHelpers();
}

Character::Character(const std::string& fileName,const Gorgon::Point& position)
{
	script->loadScript("data/character/character.lua");
	script->loadScript(fileName);
	setPosition(position);
	setUp();
}

Character::~Character()
{
	for(int i=0; i<helpers.size(); ++i)
	{
		for(int j=0; j<helpers[i].size(); ++j)
		{
			delete helpers[i][j];
		}
	}
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
	for(int i=0; i<num; ++i)
	{
		const int numInstances	=script->function("getHelperMaxInstances",Gorgon::LuaParam("i",i+1),1)->getNumericValue();
		std::string helperScriptFile	=script->function("getHelperScriptFile",Gorgon::LuaParam("i",i+1),1)->getStringValue();
		std::vector<Character*> helper;
		
		for(int j=0; j<numInstances; ++j)
		{
			helper.push_back(new Character(helperScriptFile));
		}
		helpers.push_back(helper);
	}
}

void Character::callHelper
(
	const Gorgon::Point& position,
	const Gorgon::Mirroring& mirroring,
	const int& helper
)
{
	for(int i=0; i<helpers[helper].size(); ++i)
	{
		if(!helpers[helper][i]->isAtive())
		{
			helpers[helper][i]->setPosition(position);
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
	{
		--imortal;
	}
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
