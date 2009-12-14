#include "../include/tile_lua.hpp"
#include "../include/layer.hpp"

namespace TileLua
{
	inline Tile* getTilePointer(lua_State* pState)
	{
		return (Tile*)lua_tointeger(pState,1);
	}

	int getAnimation(lua_State* pState)
	{
		Tile* tile = getTilePointer(pState);
		lua_pushnumber(pState,tile->getAnimation());
		return 1;
	}

	int setAnimation(lua_State* pState)
	{
		Tile* tile = getTilePointer(pState);
		tile->setAnimation((int)lua_tonumber(pState,2));
		return 0;
	}

	int clone(lua_State* pState)
	{
		Tile*	tile		= getTilePointer(pState);
		Layer*	layer		= tile->getLayer();
		Tile*	tileClone	= new Tile(*tile);
		tileClone->setPosition
		(
			Gorgon::Point
			(
				lua_tonumber(pState,2),
				lua_tonumber(pState,3)
			)
		);
		layer->addTile(tileClone);
		return 0;
	}

	int getPosition(lua_State* pState)
	{
		Tile* tile	= getTilePointer(pState);
		lua_pushnumber(pState,tile->getPosition().getX());
		lua_pushnumber(pState,tile->getPosition().getY());
		return 2;
	}

	int setPosition(lua_State* pState)
	{
		Tile* tile = getTilePointer(pState);
		tile->setPosition(Gorgon::Point(lua_tonumber(pState,2),lua_tonumber(pState,3)));
		return 0;
	}

	int getLayerPointer(lua_State* pState)
	{
		Tile* tile	= getTilePointer(pState);
		lua_pushnumber(pState,(int)tile->getLayer());
		return 1;
	}

	void registerFunctions(Gorgon::Lua* pScript)
	{
		pScript->registerFunction("lua_tile_getAnimation",getAnimation);
		pScript->registerFunction("lua_tile_setAnimation",setAnimation);
		pScript->registerFunction("lua_tile_clone",clone);
		pScript->registerFunction("lua_tile_getPosition",getPosition);
		pScript->registerFunction("lua_tile_setPosition",setPosition);
		pScript->registerFunction("lua_tile_getLayerPointer",getLayerPointer);
	}
}




