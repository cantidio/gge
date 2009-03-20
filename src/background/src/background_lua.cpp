#include "../include/background_lua.hpp"
#define BackgroundObj() int pointer=lua_tointeger(state,1); Background* background =(Background*)pointer;

namespace BackgroundLua
{
	int getXPosition(lua_State* state)
	{
		BackgroundObj();
		lua_pushnumber(state,background->getXPos());
		return 1;
	}

	int getYPosition(lua_State* state)
	{
		BackgroundObj();
		lua_pushnumber(state,background->getYPos());
		return 1;
	}

	int setXPosition(lua_State* state)
	{
		BackgroundObj();
		background->setXPos((int)lua_tonumber(state,2));
		return 0;
	}

	int setYPosition(lua_State* state)
	{
		BackgroundObj();
		background->setYPos((int)lua_tonumber(state,2));
		return 0;
	}

	int addXPosition(lua_State* state)
	{
		BackgroundObj();
		background->setXPos(background->getXPos()+lua_tonumber(state,2));
		return 0;
	}

	int addYPosition(lua_State* state)
	{
		BackgroundObj();
		background->setYPos(background->getYPos()+lua_tonumber(state,2));
		return 0;
	}

	int subXPosition(lua_State* state)
	{
		BackgroundObj();
		background->setXPos(background->getXPos()-lua_tonumber(state,2));
		return 0;
	}

	int subYPosition(lua_State* state)
	{
		BackgroundObj();
		background->setYPos(background->getYPos()-lua_tonumber(state,2));
		return 0;
	}

	int scrollLock(lua_State* state)
	{
		BackgroundObj();
		background->scroolLock();
		return 0;
	}

	int scrollUnlock(lua_State* state)
	{
		BackgroundObj();
		background->scroolUnlock();
		return 0;
	}

	void registerFunctions(Gorgon::Lua* script)
	{
		script->registerFunction("lua_getXPosition",getXPosition);
		script->registerFunction("lua_getYPosition",getYPosition);
		script->registerFunction("lua_setXPosition",setXPosition);
		script->registerFunction("lua_setYPosition",setYPosition);
		script->registerFunction("lua_addXPosition",addXPosition);
		script->registerFunction("lua_addYPosition",addYPosition);
		script->registerFunction("lua_subXPosition",subXPosition);
		script->registerFunction("lua_subYPosition",subYPosition);
		script->registerFunction("lua_scrollLock",scrollLock);
		script->registerFunction("lua_scrollUnlock",scrollUnlock);
	}
}


