#include "../include/background_lua.hpp"

namespace BackgroundLua
{
	inline Background* getBackgroundPointer(lua_State* pState)
	{
		return (Background*)lua_tointeger(pState,1);
	}

	int getWidth(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		lua_pushnumber(pState,background->getWidth());
		return 1;
	}

	int getHeight(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		lua_pushnumber(pState,background->getHeight());
		return 1;
	}
	
	int getPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		lua_pushnumber(pState,background->getPosition().getX());
		lua_pushnumber(pState,background->getPosition().getY());
		return 2;
	}

	int setPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->setPosition(Gorgon::Point(lua_tonumber(pState,2),lua_tonumber(pState,3)));
		return 0;
	}

	int addPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->addPosition(Gorgon::Point(lua_tonumber(pState,2), lua_tonumber(pState,3)));
		return 0;
	}

	int subPosition(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		background->subPosition(Gorgon::Point(lua_tonumber(pState,2), lua_tonumber(pState,3)));
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
	int getLayerNumber(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		lua_pushnumber(pState,background->getLayerNumber());
		return 1;
	}
	
	int getLayer(lua_State* pState)
	{
		Background* background = getBackgroundPointer(pState);
		lua_pushnumber(pState,(int)&(*background)[(int)lua_tonumber(pState,2)]);
		return 1;
	}

	void registerFunctions(Gorgon::Lua* pScript)
	{
		pScript->registerFunction("lua_background_getWidth",getWidth);
		pScript->registerFunction("lua_background_getHeight",getHeight);
		pScript->registerFunction("lua_background_getPosition",getPosition);
		pScript->registerFunction("lua_background_setPosition",setPosition);
		pScript->registerFunction("lua_background_addPosition",addPosition);
		pScript->registerFunction("lua_background_subPosition",subPosition);
		pScript->registerFunction("lua_background_scrollLock",scrollLock);
		pScript->registerFunction("lua_background_scrollUnlock",scrollUnlock);
		pScript->registerFunction("lua_background_getLayerNumber",getLayerNumber);
		pScript->registerFunction("lua_background_getLayer",getLayer);
	}
}


