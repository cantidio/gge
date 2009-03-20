/**
 *
 *  ____              __       __          __
 * /\  _`\           /\ \     /\ \      __/\ \__
 * \ \ \L\ \     __  \ \ \____\ \ \____/\_\ \ ,_\  ____
 *  \ \ ,  /   /'__`\ \ \ '__`\\ \ '__`\/\ \ \ \/ /\_ ,`\
 *   \ \ \\ \ /\ \L\.\_\ \ \L\ \\ \ \L\ \ \ \ \ \_\/_/  /_
 *    \ \_\ \_\ \__/.\_\\ \_,__/ \ \_,__/\ \_\ \__\ /\____\
 *     \/_/\/ /\/__/\/_/ \/___/   \/___/  \/_/\/__/ \/____/
 *
 *  Copyright (C) 2008-2009  Gorgon Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
#ifndef _BACKGROUND_LUA_
#define	_BACKGROUND_LUA_
#include "background.hpp"
#include "../../../../gorgon++/src/script/include/gorgon_lua.hpp"

namespace BackgroundLua
{
	/**
	 * Função que retorna a posição x do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int getXPosition(lua_State* state);
	/**
	 * Função que retorna a posição y do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int getYPosition(lua_State* state);
	/**
	 * Função que seta a posição x do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int setXPosition(lua_State* state);
	/**
	 * Função que seta a posição y do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int setYPosition(lua_State* state);
	/**
	 * Função que adiciona um valor a posição x do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int addXPosition(lua_State* state);
	/**
	 * Função que adiciona um valor a posição y do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int addYPosition(lua_State* state);
	/**
	 * Função que subtrai um valor a posição x do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int subXPosition(lua_State* state);
	/**
	 * Função que subtrai um valor a posição y do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int subYPosition(lua_State* state);
	/**
	 * Função que trava o scrolling do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int scrollLock(lua_State* state);
	/**
	 * Função que destrava o scrolling do cenário
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int scrollUnlock(lua_State* state);
	/**
	 * Método que registra as funçãode cenário para serem acessadas por um script
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	19/03/2009
	 * @final	19/03/2009
	 * @param	Gorgon::Lua* script, ponteiro para a classe lua que receberá as funções
	 */
	void registerFunctions(Gorgon::Lua* script);
}
#endif
