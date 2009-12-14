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
#ifndef _LAYER_LUA_
#define	_LAYER_LUA_
#include "background.hpp"
#include <gorgon++/gorgon.hpp>

/**
 * NameSpace que engloba os wrappers de algumas funções em lua relacionadas ao Layers
 *
 * @author	Cantidio Oliveira Fontes
 * @since	13/12/2009
 * @version	15/12/2009
 * @ingroup	Background
 */
namespace LayerLua
{
        /**
	 * Função que pega o numero de tiles no layer
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/12/2009
	 * @version	13/12/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int getTileNumber(lua_State* pState);
	/**
	 * Função que retorna uma instancia do tile
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/12/2009
	 * @version	14/12/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int getTilePointer(lua_State* pState);
	/**
	 * Função que retorna o ponteiro do Background do Layer
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	15/12/2009
	 * @version	15/12/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int getBackgroundPointer(lua_State* pState);
	/**
	 * Método que registra as funçoes do layer para serem acessadas por um script
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/12/2009
	 * @version	13/12/2009
	 * @param	Gorgon::Lua* pScript, ponteiro para a classe lua que receberá as funções
	 */
	void registerFunctions(Gorgon::Lua* pScript);
}
#endif
