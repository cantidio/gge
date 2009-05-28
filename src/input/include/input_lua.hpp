/*
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
#ifndef _GSBGE_INPUT_LUA_
#define	_GSBGE_INPUT_LUA_
#include "input.hpp"
#include "../../../../gorgon++/src/script/include/gorgon_lua.hpp"

/**
 * @defgroup	Input
 *
 * @author		Cantidio Oliveira Fontes
 * @since		16/03/2009
 * @version		28/05/2009
 * @details
 *				O módulo Input engloba todas as funcionalidades relacionadas
 *				à parte de entrada de dados por parte do usuário
 */

/**
 * NameSpace que engloba os wrappers de algumas funções em lua relacionadas ao input
 *
 * @author	Cantidio Oliveira Fontes
 * @since	16/03/2009
 * @version	28/05/2009
 * @ingroup	Input
 */
namespace InputLua
{
	/**
	 * Função que retorna verdadeiro se o botão start estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_buttonStart(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão direcional para cima estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_buttonUp(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão direcional para baixo estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_buttonDown(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão direcional esquerdo estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_buttonLeft(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão direcional direito estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_buttonRight(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão1 estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_button1(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão2 estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_button2(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão3 estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_button3(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão4 estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_button4(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão5 estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_button5(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão6 estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_button6(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão7 estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_button7(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se o botão8 estiver apertado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	int lua_button8(lua_State* pState);
	/**
	 * Função que cadastra todas as funções em lua de input no estado indicado
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/03/2009
	 * @final	16/03/2009
	 * @param	lua_State* pState, estado lua que a função será cadastrada
	 * @return	int
	 */
	void registerFunctions(Gorgon::Lua* pScript);
}
#endif
