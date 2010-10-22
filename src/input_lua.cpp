#include "../include/input_lua.hpp"

namespace InputLua
{
	int GGE_input_buttonStart(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonStart());
		return 1;
	}

	int GGE_input_buttonUp(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonUp());
		return 1;
	}

	int GGE_input_buttonDown(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonDown());
		return 1;
	}

	int GGE_input_buttonLeft(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonLeft());
		return 1;
	}

	int GGE_input_buttonRight(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonRight());
		return 1;
	}

	int GGE_input_button1(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button1());
		return 1;
	}

	int GGE_input_button2(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button2());
		return 1;
	}

	int GGE_input_button3(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button3());
		return 1;
	}

	int GGE_input_button4(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button4());
		return 1;
	}

	int GGE_input_button5(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button5());
		return 1;
	}

	int GGE_input_button6(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button6());
		return 1;
	}

	int GGE_input_button7(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button7());
		return 1;
	}

	int GGE_input_button8(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button8());
		return 1;
	}

	void registerFunctions(Gorgon::Script::Lua& pScript)
	{
		pScript.registerFunction("GGE_input_buttonStart"	, GGE_input_buttonStart	);
		pScript.registerFunction("GGE_input_buttonUp"		, GGE_input_buttonUp	);
		pScript.registerFunction("GGE_input_buttonDown"		, GGE_input_buttonDown	);
		pScript.registerFunction("GGE_input_buttonLeft"		, GGE_input_buttonLeft	);
		pScript.registerFunction("GGE_input_buttonRight"	, GGE_input_buttonRight	);
		pScript.registerFunction("GGE_input_button1"		, GGE_input_button1		);
		pScript.registerFunction("GGE_input_button2"		, GGE_input_button2		);
		pScript.registerFunction("GGE_input_button3"		, GGE_input_button3		);
		pScript.registerFunction("GGE_input_button4"		, GGE_input_button4		);
		pScript.registerFunction("GGE_input_button5"		, GGE_input_button5		);
		pScript.registerFunction("GGE_input_button6"		, GGE_input_button6		);
		pScript.registerFunction("GGE_input_button7"		, GGE_input_button7		);
		pScript.registerFunction("GGE_input_button8"		, GGE_input_button8		);
	}
}
