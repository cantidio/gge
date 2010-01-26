#include "../include/character.hpp"
#include "../include/character_lua.hpp"

Character::Character
(
	const Gorgon::Point&	pPosition,
	Layer*					pLayer,
	const bool&				pActive
) : Object(pPosition,pLayer,pActive)
{
	mScript->loadScript("data/character/class_character.lua");
}

void Character::loadGlobalVars()
{
	mLife			= (int)mScript->function("script_character_getLife"			,Gorgon::LuaParam(),1)->getNumericValue();
	mImortalTime	= (int)mScript->function("script_character_getImortalTime"	,Gorgon::LuaParam(),1)->getNumericValue();
}

Character::Character
(
	const std::string&		pFileName,
	const Gorgon::Point&	pPosition,
	Layer*					pLayer,
	const bool&				pActive
) : Object(pPosition,pLayer,pActive)
{
	mScript->loadScript("data/character/class_character.lua");
	mScript->loadScript(pFileName);
	setUp();
}

void Character::setUp()
{
	Object::setUp();
	loadGlobalVars();
	CharacterLua::registerFunctions(mScript);
	mCurrentLife	= mLife;
	mImortal		= 0;
	prepareHelpers();
}

Character::~Character()
{
	for(int i = 0; i < mHelpers.size(); ++i)
	{
		for(int j = 0; j < mHelpers[i].size(); ++j)
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
	mCurrentLife = pLife;
}

void Character::subLife(const int& pLife)
{
	mCurrentLife -= pLife;
}

void Character::addLife(const int& pLife)
{
	mCurrentLife += pLife;
}

bool Character::isAlive() const
{
	return (mCurrentLife>0) ? true : false;
}

bool Character::isImortal() const
{
	return mImortal > 0 ? true : false;
}

void Character::hurt(const int& pDamage)
{
	subLife(pDamage);
	mImortal = mImortalTime;
}

void Character::prepareHelpers()
{
	const int &num = (int)mScript->function("script_character_getHelpersNumber",Gorgon::LuaParam(),1)->getNumericValue();
	for(int i = 0; i < num; ++i)
	{
		const int numInstances			= mScript->function("script_character_getHelperMaxInstances",Gorgon::LuaParam("i",i+1),1)->getNumericValue();
		std::string helperScriptFile	= mScript->function("script_character_getHelperScriptFile",Gorgon::LuaParam("i",i+1),1)->getStringValue();
		std::vector<Character*> helper;
		
		for(int j = 0; j < numInstances; ++j)
		{
			helper.push_back
			(
				new Character
				(
					helperScriptFile,
					Gorgon::Point(),
					getLayer(),
					false
				)
			);
			helper[j]->mScript->function("script_character_setParentPointer",Gorgon::LuaParam("n",this));
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
		if(!mHelpers[pHelper][i]->isActive())
		{
			mHelpers[pHelper][i]->setPosition(pPosition);
			mHelpers[pHelper][i]->activate();
			mHelpers[pHelper][i]->setMirroring(pMirroring);
			return mHelpers[pHelper][i];
		}
	}
	return NULL;
}

void Character::draw() const
{
	if((mImortal > 0 && (mImortal % 2 == 0)) || mImortal==0)
	{
		Object::draw();
	}
	for(int i = 0; i < mHelpers.size(); ++i)
	{
		for(int j = 0; j < mHelpers[i].size(); ++j)
		{
			mHelpers[i][j]->draw();
		}
	}
}

void Character::logic()
{
	Object::logic();
	if(mImortal > 0)
	{
		--mImortal;
	}
	for(int i = 0; i < mHelpers.size(); ++i)
	{
		for(int j = 0; j < mHelpers[i].size(); ++j)
		{
			mHelpers[i][j]->logic();
		}
	}
}
