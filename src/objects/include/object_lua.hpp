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
#ifndef _OBJECT_LUA_
#define	_OBJECT_LUA_
#include "object.hpp"
#include <gorgon++/gorgon.hpp>

/**
 * Bindings para os métodos de classe serem usados nos scritps em lua
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @version	26/06/2009
 * @ingroup	Objects
 */
namespace ObjectLua
{
	/**
	 * Funćão que retorna se o objeto está ativo
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/01/2010
	 * @version	26/01/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_isActive(lua_State* pState);
	/**
	 * Funćão que ativa o objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/01/2010
	 * @version	26/01/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_activate(lua_State* pState);
	/**
	 * Funćão que inativa o objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/01/2010
	 * @version	26/01/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_inativate(lua_State* pState);
	/**
	 * Função que retorna o índice real da animação dados o seu grupo e índice
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	18/06/2009
	 * @version	18/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_getAnimationRealIndex(lua_State* pState);
	/**
	 * Função que muda a animação de um objeto através de um índice direto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @version	12/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_changeAnimationByIndex(lua_State* pState);
	/**
	 * Função que muda a animação de um objeto por seu grupo e índice
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	09/06/2009
	 * @version	09/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_changeAnimation(lua_State* pState);
	/**
	 * Função que retorna verdadeiro se a animação está tocando
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @version	12/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_animationIsPlaying(lua_State* pState);
	/**
	 * Função que retorna o número da animação que está tocando
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	14/03/2009
	 * @version	14/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_getAnimationOn(lua_State* pState);
	/**
	 * Função que retorna o número do frame atual da animação que está tocando
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	14/03/2009
	 * @version	14/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_getFrameOn(lua_State* pState);
	/**
	 * Função que retorna a posição do objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @version	31/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_getPosition(lua_State* pState);
	/**
	 * Função que seta a posição x y do objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @version	31/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_setPosition(lua_State* pState);
	/**
	 * Função que adiciona um valor a posição xy do objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @version	31/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_addPosition(lua_State* pState);
	/**
	 * Função que adiciona um valor a posição xy do objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	31/03/2009
	 * @version	31/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_subPosition(lua_State* pState);
	/**
	 * Função que seta o espelhamento do objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @version	12/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_setMirroring(lua_State* pState);
	/**
	 * Função que retorna o espelhamento do objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @version	12/03/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_getMirroring(lua_State* pState);
	/**
	 * Função que retorna o ponteiro do layer do objeto
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	20/01/2009
	 * @version	02/01/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int lua_getLayer(lua_State* pState);
	/**
	 * Função para setar o método de afterImage para Normal
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/06/2009
	 * @version	26/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 */
	int setAfterImageMethodNormal(lua_State* pState);
	/**
	 * Função para setar o método de afterImage para add
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/06/2009
	 * @version	26/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 */
	int setAfterImageMethodAdd(lua_State* pState);
	/**
	 * Função para setar o método de afterImage para Trans
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/06/2009
	 * @version	26/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 */
	int setAfterImageMethodTrans(lua_State* pState);
	/**
	 * Função para setar o modo do sistema de afterImages
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/06/2009
	 * @version	26/06/2009
	 * @param	lua_State* pState, estado do interpretador lua atual
	 */
	int setAfterImageMode(lua_State* pState);
	/**
	 * Método que registra as funçãode cenário para serem acessadas por um script
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	31/03/2009
	 * @version	31/03/2009
	 * @param	Gorgon::Lua* script, ponteiro para a classe lua que receberá as funções
	 */
	void registerFunctions(Gorgon::Lua* script);
}
#endif
