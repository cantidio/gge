#include "../include/text_window_lua.hpp"

namespace TextWindowLua
{
	int print(lua_State* pState)
	{
		TextWindow::get().add(lua_tostring(pState,1));
		return 0;
	}

	void registerFunctions(Gorgon::Script::Lua& pScript)
	{
		pScript.registerFunction("print",print);
	}
}
