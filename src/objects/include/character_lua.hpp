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
#ifndef _CHARACTER_LUA_
#define	_CHARACTER_LUA_
#include "character.hpp"
#include "../../../../gorgon++/src/script/include/gorgon_lua.hpp"
/**
 * Bindings para os métodos de classe serem usados nos scritps em lua
 */
namespace CharacterLua
{
	/**
	 * Função que retorna o life do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_getLife(lua_State* state);
	/**
	 * Função que seta o life do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_setLife(lua_State* state);
	/**
	 * Função que subtrai um valor do life do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_subLife(lua_State* state);
	/**
	 * Função que adiciona um valor ao life do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_addLife(lua_State* state);
	/**
	 * Função que retorna verdadeiro se o personagem está vivo
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_isAlive(lua_State* state);
	/**
	 * Função que ativa o objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_ativate(lua_State* state);
	/**
	 * Função que desativa o objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	13/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_inativate(lua_State* state);
	/**
	 * Função que retorna verdadeiro se o personagem está ativo
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_isAtive(lua_State* state);
	/**
	 * Função que retorna verdadeiro se o personagem está imortal
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_isImortal(lua_State* state);
	/**
	 * Função que machuca o personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_hurt(lua_State* state);
	/**
	 * Função que chama um helper
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	14/03/2009
	 * @param	lua_State* state, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_callHelper(lua_State* state);
	/**
	 * Método que registra as funçãode cenário para serem acessadas por um script
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	31/03/2009
	 * @final	31/03/2009
	 * @param	Gorgon::Lua* script, ponteiro para a classe lua que receberá as funções
	 */
	void registerFunctions(Gorgon::Lua* script);
}
#endif
