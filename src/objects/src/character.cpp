#include "../include/character.hpp"
#include "../include/character_lua.hpp"

Character::Character()
{
	mScript->loadScript("data/character/character.lua");
}

void Character::loadGlobalVars()
{
	mLife			= (int)mScript->getNumericVar("life");
	mImortalTime	= (int)mScript->getNumericVar("imortalTime");
}

void Character::setUp()
{
	Object::setUp();
	loadGlobalVars();
	CharacterLua::registerFunctions(mScript);
	mCurrentLife	= mLife;
	mImortal		= 0;
	mAtive			= false;
	prepareHelpers();
}

Character::Character(const std::string& pFileName,const Gorgon::Point& pPosition)
{
	mScript->loadScript("data/character/character.lua");
	mScript->loadScript(pFileName);
	setPosition(pPosition);
	setUp();
}

Character::~Character()
{
	for(int i=0; i<mHelpers.size(); ++i)
	{
		for(int j=0; j<mHelpers[i].size(); ++j)
		{
			delete mHelpers[i][j];
		}
	}
}

int Character::getLife() const
{
	return mCurrentLife;
}

void Character::setLife(const int& pLife)
{
	mCurrentLife=pLife;
}

void Character::subLife(const int& pLife)
{
	mCurrentLife-=pLife;
}

void Character::addLife(const int& pLife)
{
	mCurrentLife+=pLife;
}

bool Character::isAlive() const
{
	return (mCurrentLife>0) ? true : false;
}

void Character::ativate()
{
	mAtive=true;
}
void Character::inativate()
{
	mAtive=false;
}

bool Character::isAtive() const
{
	return mAtive;
}

bool Character::isImortal() const
{
	return mImortal>0 ? true : false;
}

void Character::hurt(const int& pDamage)
{
	subLife(pDamage);
	mImortal=mImortalTime;
}

void Character::prepareHelpers()
{
	const int &num=(int)mScript->function("getHelpersNumber",Gorgon::LuaParam(),1)->getNumericValue();
	for(int i=0; i<num; ++i)
	{
		const int numInstances			= mScript->function("getHelperMaxInstances",Gorgon::LuaParam("i",i+1),1)->getNumericValue();
		std::string helperScriptFile	= mScript->function("getHelperScriptFile",Gorgon::LuaParam("i",i+1),1)->getStringValue();
		std::vector<Character*> helper;
		
		for(int j = 0; j<numInstances; ++j)
		{
			helper.push_back(new Character(helperScriptFile));
			helper[j]->mScript->function("setCallerPointer",Gorgon::LuaParam("n",this));
		}
		mHelpers.push_back(helper);
	}
}

Character* Character::callHelper
(
	const Gorgon::Point&		pPosition,
	const Gorgon::Mirroring&	pMirroring,
	const int&					pHelper
)
{
	for(int i = 0; i < mHelpers[pHelper].size(); ++i)
	{
		if(!mHelpers[pHelper][i]->isAtive())
		{
			mHelpers[pHelper][i]->setPosition(pPosition);
			mHelpers[pHelper][i]->ativate();
			mHelpers[pHelper][i]->setMirroring(pMirroring);
			return mHelpers[pHelper][i];
		}
	}
	return NULL;
}

void Character::draw() const
{
	if(mAtive)
	{
		if((mImortal > 0 && (mImortal % 2 == 0)) || mImortal==0)
		{
			Object::draw();
		}
		for(int i = 0; i < mHelpers.size(); ++i)
		{
			for(int j=0; j < mHelpers[i].size(); ++j)
			{
				if(mHelpers[i][j]->isAtive())
				{
					mHelpers[i][j]->draw();
				}
			}
		}
	}
}

void Character::logic()
{
	Object::logic();
	if(mImortal>0)
	{
		--mImortal;
	}
	for(int i = 0; i < mHelpers.size(); ++i)
	{
		for(int j = 0; j < mHelpers[i].size(); ++j)
		{
			if(mHelpers[i][j]->isAtive())
			{
				mHelpers[i][j]->logic();
			}
		}
	}
}
