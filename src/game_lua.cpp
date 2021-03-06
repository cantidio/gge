#include "../include/game_lua.hpp"
#include "../include/game.hpp"
#include <gorgon++/graphic/display.hpp>

namespace GameLua
{
	int returnArray(lua_State* L, std::vector<std::string> pStrings)
	{
		lua_createtable(L, pStrings.size(), 0);
		int newTable = lua_gettop(L);
		for(int i = 0 ; i < pStrings.size(); ++i)
		{
			lua_pushstring(L, pStrings[i].c_str());
			lua_rawseti(L, newTable, i + 1);
		}
		return 1;
	}

	int GGE_game_getArgs(lua_State* pState)
	{
		return returnArray(pState,Game::get().getArgs());
	}

	int GGE_game_init(lua_State* pState)
	{
		bool noError = Game::get().init
		(
			lua_tostring(pState,1),
			(int)lua_tointeger(pState,2),
			(int)lua_tointeger(pState,3),
			(int)lua_toboolean(pState,4)
		);
		lua_pushboolean(pState,noError);
		return 1;
	}

	int GGE_game_halt(lua_State* pState)
	{
		Game::halt();
		return 0;
	}

	int GGE_game_log(lua_State* pState)
	{
		Gorgon::Core::Log::get().writeFormatted
		(
			"LUA -> %s\n",lua_tostring(pState,1)
		);
		return 0;
	}

	int GGE_game_setGameName(lua_State* pState)
	{
		lua_tostring(pState,1);
		lua_pushboolean(pState,true);
		return 1;
	}

	int GGE_game_setGameVersion(lua_State* pState)
	{
		//Game::get().setGameVersion()
		lua_tostring(pState,1);
		lua_pushboolean(pState,true);
		return 1;
	}

	int GGE_game_setFPS(lua_State* pState)
	{
		Game::get().setFPS( (int)lua_tointeger(pState, 1) );
		lua_pushboolean(pState,true);
		return 1;
	}

	int GGE_game_getWidth(lua_State* pState)
	{
		lua_pushnumber( pState, Game::get().getWidth() );
		return 1;
	}

	int GGE_game_getHeight(lua_State* pState)
	{
		lua_pushnumber( pState, Game::get().getHeight() );
		return 1;
	}

	void registerFunctions(Gorgon::Script::Lua& pScript)
	{
		pScript.registerFunction("GGE_game_getArgs"			, GGE_game_getArgs			);
		pScript.registerFunction("GGE_game_init"			, GGE_game_init				);
		pScript.registerFunction("GGE_game_halt"			, GGE_game_halt				);
		pScript.registerFunction("GGE_game_log"				, GGE_game_log				);
		pScript.registerFunction("GGE_game_setFPS"			, GGE_game_setFPS			);
		pScript.registerFunction("GGE_game_setGameName"		, GGE_game_setGameName		);
		pScript.registerFunction("GGE_game_setGameVersion"	, GGE_game_setGameVersion	);
		pScript.registerFunction("GGE_game_getWidth"		, GGE_game_getWidth			);
		pScript.registerFunction("GGE_game_getHeight"		, GGE_game_getHeight		);
	}
}
