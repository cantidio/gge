#include "../include/tile_lua.hpp"
#include "../include/layer.hpp"

namespace TileLua
{
	inline Tile* getTilePointer(lua_State* pState)
	{
		return (Tile*)lua_tointeger(pState,1);
	}

	int GGE_tile_new(lua_State* pState)
	{
		Tile* tile = new Tile
		(
			ResourceManager::SpriteManager::load(lua_tostring(pState,1)),
			ResourceManager::AnimationManager::load(lua_tostring(pState,2)),
			(int)lua_tonumber(pState,3)
		);
		lua_pushnumber(pState,(int)tile);
		return 1;
	}

	int GGE_tile_delete(lua_State* pState)
	{
		Tile* tile = getTilePointer(pState);
		delete tile;
		return 0;
	}

	int GGE_tile_draw(lua_State* pState)
	{
		Tile* tile = getTilePointer(pState);
		tile->draw
		(
			Gorgon::Point
			(
				lua_tonumber(pState,2),
				lua_tonumber(pState,3)
			)
		);
		return 0;
	}

	int GGE_tile_logic(lua_State* pState)
	{
		Tile* tile = getTilePointer(pState);
		tile->logic();
		return 0;
	}

	int GGE_tile_animationGet(lua_State* pState)
	{
		Tile* tile = getTilePointer(pState);
		lua_pushnumber(pState,tile->getAnimation());
		return 1;
	}

	int GGE_tile_animationSet(lua_State* pState)
	{
		Tile* tile = getTilePointer(pState);
		tile->setAnimation((int)lua_tonumber(pState,2));
		return 0;
	}

	void registerFunctions(Gorgon::Lua* pScript)
	{
		pScript->registerFunction("GGE_tile_new"			,GGE_tile_new			);
		pScript->registerFunction("GGE_tile_delete"			,GGE_tile_delete		);
		pScript->registerFunction("GGE_tile_draw"			,GGE_tile_draw			);
		pScript->registerFunction("GGE_tile_logic"			,GGE_tile_logic			);
		pScript->registerFunction("GGE_tile_animationGet"	,GGE_tile_animationGet	);
		pScript->registerFunction("GGE_tile_animationSet"	,GGE_tile_animationSet	);
	}
}

