	#include "../include/background_lua.hpp"

namespace BackgroundLua
{
	inline Background* getBackgroundPointer(lua_State* pState)
	{
		return (Background*)lua_tointeger(pState,1);
	}

	int getXPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		lua_pushnumber(pState,background->getXPos());
		return 1;
	}

	int getYPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		lua_pushnumber(pState,background->getYPos());
		return 1;
	}

	int setXPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->setXPos((int)lua_tonumber(pState,2));
		return 0;
	}

	int setYPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->setYPos((int)lua_tonumber(pState,2));
		return 0;
	}

	int addXPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->setXPos(background->getXPos()+lua_tonumber(pState,2));
		return 0;
	}

	int addYPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->setYPos(background->getYPos()+lua_tonumber(pState,2));
		return 0;
	}

	int subXPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->setXPos(background->getXPos()-lua_tonumber(pState,2));
		return 0;
	}

	int subYPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->setYPos(background->getYPos()-lua_tonumber(pState,2));
		return 0;
	}

	int scrollLock(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->scroolLock();
		return 0;
	}

	int scrollUnlock(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->scroolUnlock();
		return 0;
	}

	void registerFunctions(Gorgon::Lua* pScript)
	{
		pScript->registerFunction("lua_getXPosition",getXPosition);
		pScript->registerFunction("lua_getYPosition",getYPosition);
		pScript->registerFunction("lua_setXPosition",setXPosition);
		pScript->registerFunction("lua_setYPosition",setYPosition);
		pScript->registerFunction("lua_addXPosition",addXPosition);
		pScript->registerFunction("lua_addYPosition",addYPosition);
		pScript->registerFunction("lua_subXPosition",subXPosition);
		pScript->registerFunction("lua_subYPosition",subYPosition);
		pScript->registerFunction("lua_scrollLock",scrollLock);
		pScript->registerFunction("lua_scrollUnlock",scrollUnlock);
	}
}


