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
#ifndef _OBJECT_LUA_
#define	_OBJECT_LUA_
#include <gorgon++/gorgon.hpp>
#include "object.hpp"

/**
 * Bindings para os métodos de classe serem usados nos scritps em lua
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @version	20/10/2010
 * @ingroup	Objects
 */
 class ObjectLua
 {
 	protected:
		static luaL_reg mMethods[];		/**< all class methods*/
		static luaL_reg mMetatable[];	/**< class metatable */
	public:
		/**
		 * Method that creates a new Object in LUA
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/10/2010
		 * @version	20/10/2010
		 * @param	lua_State* pState, state of the lua interpreter
		 * @return	int
		 */
		static int constructor(lua_State* pState);
		/**
		 * Method that deletes a new Object in LUA
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/10/2010
		 * @version	20/10/2010
		 * @param	lua_State* pState, state of the lua interpreter
		 * @return	int
		 */
		static int destructor(lua_State* pState);
		/**
		 * Method that draws a Object in LUA
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/10/2010
		 * @version	18/10/2010
		 * @param	lua_State* pState, state of the lua interpreter
		 * @return	int
		 */
		static int draw(lua_State* pState);
		/**
		 * Method that execute the Object logic function in LUA
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/10/2010
		 * @version	18/10/2010
		 * @param	lua_State* pState, state of the lua interpreter
		 * @return	int
		 */
		static int logic(lua_State* pState);
		/**
		 * Função que retorna o índice real da animação dados o seu grupo e índice
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/06/2009
		 * @version	29/09/2010
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int getAnimationRealIndex(lua_State* pState);
		/**
		 * Função que muda a animação de um objeto através de um índice direto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int changeAnimationByIndex(lua_State* pState);
		/**
		 * Função que muda a animação de um objeto por seu grupo e índice
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	09/06/2009
		 * @version	09/06/2009
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int changeAnimation(lua_State* pState);
		/**
		 * Função que retorna verdadeiro se a animação está tocando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int animationIsPlaying(lua_State* pState);
		/**
		 * Função que retorna a posicao, o grupo e o índice da animação que está tocando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/01/2010
		 * @version	26/01/2010
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int getAnimationOn(lua_State* pState);//real, group. index
		/**
		 * Method that sets the frame on of the animation playing
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @version	14/03/2009
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int setFrameOn(lua_State* pState);
		/**
		 * Função que retorna o número do frame atual da animação que está tocando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @version	14/03/2009
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int getFrameOn(lua_State* pState);
		/**
		 * Função que roda um frame da animaćão atual do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	29/09/2010
		 * @version	29/09/2010
		 * @param	lua_State* pState, estado do interpretador lua atual
		 * @return	int
		 */
		static int animationRunStep(lua_State* pState);
		/**
		 * Method that registers the Object Class to be used in lua
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/12/2009
		 * @version	17/10/2010
		 * @param	Gorgon::Script::Lua& pScript, the script to register the class
		 */
		static void registerClass(Gorgon::Script::Lua& pScript);
 };

	
	
	/**
	 * Função para setar o método de afterImage para Normal
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/06/2009
	 * @version	26/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 */
//	int setAfterImageMethodNormal(lua_State* pState);
	/**
	 * Função para setar o método de afterImage para add
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/06/2009
	 * @version	26/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 */
//	int setAfterImageMethodAdd(lua_State* pState);
	/**
	 * Função para setar o método de afterImage para Trans
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/06/2009
	 * @version	26/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 */
//	int setAfterImageMethodTrans(lua_State* pState);
	/**
	 * Função para setar o modo do sistema de afterImages
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/06/2009
	 * @version	26/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 */
//	int setAfterImageMode(lua_State* pState);

#endif

