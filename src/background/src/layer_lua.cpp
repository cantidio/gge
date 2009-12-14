#include "../include/layer_lua.hpp"
#include "../include/tile_lua.hpp"

namespace LayerLua
{
	inline Layer* getLayerPointer(lua_State* pState)
	{
		return (Layer*)lua_tointeger(pState,1);
	}

	int getTileNumber(lua_State* pState)
	{
		Layer* layer = getLayerPointer(pState);
		lua_pushnumber(pState,layer->getTileNumber());
		return 1;
	}

	int getTilePointer(lua_State* pState)
	{
		Layer* layer	= getLayerPointer(pState);
		lua_pushnumber
		(
			pState,
			(int)&(*layer)[(int)lua_tonumber(pState,2)]
		);
		return 1;
	}

	int getBackgroundPointer(lua_State* pState)
	{
		Layer* layer	= getLayerPointer(pState);
		lua_pushnumber(pState,(int)layer->getBackground());
		return 1;
	}

	void registerFunctions(Gorgon::Lua* pScript)
	{
		pScript->registerFunction("lua_layer_getTileNumber",getTileNumber);
		pScript->registerFunction("lua_layer_getTilePointer",getTilePointer);
		pScript->registerFunction("lua_layer_getBackgroundPointer",getBackgroundPointer);
		TileLua::registerFunctions(pScript);
	}
}



