#include "../include/character_lua.hpp"
#define CharacterObj() int pointer=lua_tointeger(state,1); Character* character=(Character*)pointer;

namespace CharacterLua
{
	int lua_getLife(lua_State* state)
	{
		CharacterObj();
		lua_pushinteger(state,character->getLife());
		return 1;
	}

	int lua_setLife(lua_State* state)
	{
		CharacterObj();
		character->setLife((int)lua_tointeger(state,2));
		return 0;
	}

	int lua_subLife(lua_State* state)
	{
		CharacterObj();
		character->subLife((int)lua_tointeger(state,2));
		return 0;
	}

	int lua_addLife(lua_State* state)
	{
		CharacterObj();
		character->addLife((int)lua_tointeger(state,2));
		return 0;
	}

	int lua_isAlive(lua_State* state)
	{
		CharacterObj();
		lua_pushboolean(state,character->isAlive());
		return 1;
	}

	int lua_ativate(lua_State* state)
	{
		CharacterObj();
		character->ativate();
		return 0;
	}

	int lua_inativate(lua_State* state)
	{
		CharacterObj();
		character->inativate();
		return 0;
	}

	int lua_isAtive(lua_State* state)
	{
		CharacterObj();
		lua_pushboolean(state,character->isAtive());
		return 1;
	}

	int lua_isImortal(lua_State* state)
	{
		CharacterObj();
		lua_pushboolean(state,character->isImortal());
		return 1;
	}

	int lua_hurt(lua_State* state)
	{
		CharacterObj();
		character->hurt(lua_tointeger(state,2));
		return 0;
	}

	int lua_callHelper(lua_State* state)
	{
		CharacterObj();
		switch(lua_tointeger(state,4))
		{
			case 0:
				character->callHelper
				(
					Gorgon::Point
					(
						lua_tointeger(state,2),
						lua_tointeger(state,3)
					),
					Gorgon::Mirroring::Normal,
					lua_tointeger(state,5)
				);
				break;
			case 1:
				character->callHelper
				(
					Gorgon::Point
					(
						lua_tointeger(state,2),
						lua_tointeger(state,3)
					),
					Gorgon::Mirroring::HFlip,
					lua_tointeger(state,5)
				);
				break;
			case 2:
				character->callHelper
				(
					Gorgon::Point
					(
						lua_tointeger(state,2),
						lua_tointeger(state,3)
					),
					Gorgon::Mirroring::VFlip,
					lua_tointeger(state,5)
				);
				break;
			default:
				character->callHelper
				(
					Gorgon::Point
					(
						lua_tointeger(state,2),
						lua_tointeger(state,3)
					),
					Gorgon::Mirroring::VHFlip,
					lua_tointeger(state,5)
				);
				break;
		}
		return 0;
	}

	void registerFunctions(Gorgon::Lua* script)
	{
		script->registerFunction("lua_getLife",lua_getLife);
		script->registerFunction("lua_setLife",lua_setLife);
		script->registerFunction("lua_subLife",lua_subLife);
		script->registerFunction("lua_addLife",lua_addLife);
		script->registerFunction("lua_ativate",lua_ativate);
		script->registerFunction("lua_inativate",lua_inativate);
		script->registerFunction("lua_isAlive",lua_isAlive);
		script->registerFunction("lua_isAtive",lua_isAtive);
		script->registerFunction("lua_hurt",lua_hurt);
		script->registerFunction("lua_callHelper",lua_callHelper);
	}
}
