#include "../include/input_lua.hpp"

namespace InputLua
{
	int lua_buttonStart(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonStart());
		return 1;
	}

	int lua_buttonUp(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonUp());
		return 1;
	}

	int lua_buttonDown(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonDown());
		return 1;
	}

	int lua_buttonLeft(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonLeft());
		return 1;
	}

	int lua_buttonRight(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().buttonRight());
		return 1;
	}

	int lua_button1(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button1());
		return 1;
	}

	int lua_button2(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button2());
		return 1;
	}

	int lua_button3(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button3());
		return 1;
	}

	int lua_button4(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button4());
		return 1;
	}

	int lua_button5(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button5());
		return 1;
	}

	int lua_button6(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button6());
		return 1;
	}

	int lua_button7(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button7());
		return 1;
	}

	int lua_button8(lua_State* pState)
	{
		lua_pushboolean(pState,Input::get().button8());
		return 1;
	}

	void registerFunctions(Gorgon::Lua* pScript)
	{
		pScript->registerFunction("lua_input_buttonStart"	, lua_buttonStart	);
		pScript->registerFunction("lua_input_buttonUp"		, lua_buttonUp		);
		pScript->registerFunction("lua_input_buttonDown"	, lua_buttonDown	);
		pScript->registerFunction("lua_input_buttonLeft"	, lua_buttonLeft	);
		pScript->registerFunction("lua_input_buttonRight"	, lua_buttonRight	);
		pScript->registerFunction("lua_input_button1"		, lua_button1		);
		pScript->registerFunction("lua_input_button2"		, lua_button2		);
		pScript->registerFunction("lua_input_button3"		, lua_button3		);
		pScript->registerFunction("lua_input_button4"		, lua_button4		);
		pScript->registerFunction("lua_input_button5"		, lua_button5		);
		pScript->registerFunction("lua_input_button6"		, lua_button6		);
		pScript->registerFunction("lua_input_button7"		, lua_button7		);
		pScript->registerFunction("lua_input_button8"		, lua_button8		);
	}
}
