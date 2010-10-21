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
 *  Copyright (C) 2008-2010  Gorgon Team
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
#ifndef _GGE_TILE_LUA_
#define	_GGE_TILE_LUA_
#include <gorgon++/gorgon.hpp>
#include "tile.hpp"

/**
 * Class that makes the wrapper to use the Tile class in LUA
 *
 * @author	Cantidio Oliveira Fontes
 * @since	14/12/2009
 * @version	18/10/2010
 * @ingroup	Background
 */
class TileLua
{
	protected:
		static luaL_reg mMethods[];		/**< all class methods*/
		static luaL_reg mMetatable[];	/**< class metatable */
	public:
		/**
		 * Method that creates a new Tile in LUA
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/10/2010
		 * @version	21/10/2010
		 * @param	lua_State* pState, state of the lua interpreter
		 * @return	int
		 */
		static int constructor(lua_State* pState);
		/**
		 * Method that deletes a new Tile in LUA
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/10/2010
		 * @version	21/10/2010
		 * @param	lua_State* pState, state of the lua interpreter
		 * @return	int
		 */
		static int destructor(lua_State* pState);
		/**
		 * Função que retorna a animacão do tile
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/12/2009
		 * @version	15/12/2009
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int getAnimation(lua_State* pState);
		/**
		 * Função que seta a animacão do tile
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/12/2009
		 * @version	17/10/2010
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int setAnimation(lua_State* pState);
		/**
		 * Method that draws a Tile in LUA
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/10/2010
		 * @version	18/10/2010
		 * @param	lua_State* pState, state of the lua interpreter
		 * @return	int
		 */
		static int draw(lua_State* pState);
		/**
		 * Method that execute the tile logic function in LUA
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/10/2010
		 * @version	18/10/2010
		 * @param	lua_State* pState, state of the lua interpreter
		 * @return	int
		 */
		static int logic(lua_State* pState);
		/**
		 * Method that registers the class to be used in lua
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/12/2009
		 * @version	17/10/2010
		 * @param	Gorgon::Script::Lua& pScript, the script to register the class
		 */
		static void registerClass(Gorgon::Script::Lua& pScript);
};
#endif

