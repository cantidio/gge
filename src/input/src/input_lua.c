#include "../include/input_lua.hpp"

int lua_buttonStart(lua_State* state)
{
	lua_pushboolean(state,Input::get().buttonStart());
	return 1;
}

int lua_buttonUp(lua_State* state)
{
	lua_pushboolean(state,Input::get().buttonUp());
	return 1;
}

int lua_buttonDown(lua_State* state)
{
	lua_pushboolean(state,Input::get().buttonDown());
	return 1;
}

int lua_buttonLeft(lua_State* state)
{
	lua_pushboolean(state,Input::get().buttonLeft());
	return 1;
}

int lua_buttonRight(lua_State* state)
{
	lua_pushboolean(state,Input::get().buttonRight());
	return 1;
}

int lua_button1(lua_State* state)
{
	lua_pushboolean(state,Input::get().button1());
	return 1;
}

int lua_button2(lua_State* state)
{
	lua_pushboolean(state,Input::get().button2());
	return 1;
}

int lua_button3(lua_State* state)
{
	lua_pushboolean(state,Input::get().button3());
	return 1;
}

int lua_button4(lua_State* state)
{
	lua_pushboolean(state,Input::get().button4());
	return 1;
}

int lua_button5(lua_State* state)
{
	lua_pushboolean(state,Input::get().button5());
	return 1;
}

int lua_button6(lua_State* state)
{
	lua_pushboolean(state,Input::get().button6());
	return 1;
}

int lua_button7(lua_State* state)
{
	lua_pushboolean(state,Input::get().button7());
	return 1;
}

int lua_button8(lua_State* state)
{
	lua_pushboolean(state,Input::get().button8());
	return 1;
}

void lua_registerInputFunctions(Gorgon::Lua* script)
{
    script->registerFunction("buttonStart",lua_buttonStart);
    script->registerFunction("buttonUp",lua_buttonUp);
    script->registerFunction("buttonDown",lua_buttonDown);
    script->registerFunction("buttonLeft",lua_buttonLeft);
    script->registerFunction("buttonRight",lua_buttonRight);
    script->registerFunction("button1",lua_button1);
    script->registerFunction("button2",lua_button2);
    script->registerFunction("button3",lua_button3);
    script->registerFunction("button4",lua_button4);
    script->registerFunction("button5",lua_button5);
    script->registerFunction("button6",lua_button6);
    script->registerFunction("button7",lua_button7);
    script->registerFunction("button8",lua_button8);
}
