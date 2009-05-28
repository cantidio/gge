#include "../include/character_lua.hpp"

namespace CharacterLua
{
	inline Character* getCharacterPointer(lua_State* pState)
	{
		return (Character*)lua_tointeger(pState,1);
	}

	int lua_getLife(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		lua_pushinteger(pState,character->getLife());
		return 1;
	}

	int lua_setLife(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		character->setLife((int)lua_tointeger(pState,2));
		return 0;
	}

	int lua_subLife(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		character->subLife((int)lua_tointeger(pState,2));
		return 0;
	}

	int lua_addLife(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		character->addLife((int)lua_tointeger(pState,2));
		return 0;
	}

	int lua_isAlive(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		lua_pushboolean(pState,character->isAlive());
		return 1;
	}

	int lua_ativate(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		character->ativate();
		return 0;
	}

	int lua_inativate(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		character->inativate();
		return 0;
	}

	int lua_isAtive(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		lua_pushboolean(pState,character->isAtive());
		return 1;
	}

	int lua_isImortal(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		lua_pushboolean(pState,character->isImortal());
		return 1;
	}

	int lua_hurt(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		character->hurt(lua_tointeger(pState,2));
		return 0;
	}

	int lua_callHelper(lua_State* pState)
	{
		Character* character = getCharacterPointer(pState);
		switch(lua_tointeger(pState,4))
		{
			case 0:
				character->callHelper
				(
					Gorgon::Point
					(
						lua_tointeger(pState,2),
						lua_tointeger(pState,3)
					),
					Gorgon::Mirroring::Normal,
					lua_tointeger(pState,5)
				);
				break;
			case 1:
				character->callHelper
				(
					Gorgon::Point
					(
						lua_tointeger(pState,2),
						lua_tointeger(pState,3)
					),
					Gorgon::Mirroring::HFlip,
					lua_tointeger(pState,5)
				);
				break;
			case 2:
				character->callHelper
				(
					Gorgon::Point
					(
						lua_tointeger(pState,2),
						lua_tointeger(pState,3)
					),
					Gorgon::Mirroring::VFlip,
					lua_tointeger(pState,5)
				);
				break;
			default:
				character->callHelper
				(
					Gorgon::Point
					(
						lua_tointeger(pState,2),
						lua_tointeger(pState,3)
					),
					Gorgon::Mirroring::VHFlip,
					lua_tointeger(pState,5)
				);
				break;
		}
		return 0;
	}

	void registerFunctions(Gorgon::Lua* pScript)
	{
		pScript->registerFunction("lua_getLife",lua_getLife);
		pScript->registerFunction("lua_setLife",lua_setLife);
		pScript->registerFunction("lua_subLife",lua_subLife);
		pScript->registerFunction("lua_addLife",lua_addLife);
		pScript->registerFunction("lua_ativate",lua_ativate);
		pScript->registerFunction("lua_inativate",lua_inativate);
		pScript->registerFunction("lua_isAlive",lua_isAlive);
		pScript->registerFunction("lua_isAtive",lua_isAtive);
		pScript->registerFunction("lua_hurt",lua_hurt);
		pScript->registerFunction("lua_callHelper",lua_callHelper);
	}
}
