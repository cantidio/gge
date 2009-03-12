/**
 *
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
#ifndef _OBJECT_
#define	_OBJECT_
#include "../../../../gorgon++/src/graphic/include/gorgon_video.hpp"
#include "../../../../gorgon++/src/graphic/include/gorgon_animation_handler.hpp"
#include "../../../../gorgon++/src/script/include/gorgon_lua.hpp"
#include "../../resource_manager/include/sprite_manager.hpp"
#include "../../resource_manager/include/animation_manager.hpp"

/**
 * Classe que representa um objeto interativo
 *
 * @author	Cantidio Oliveira Fontes
 * @since	11/03/2009
 * @final	12/03/2009
 */
class Object
{
	private:
		/**
		 * Nome do arquivo de sprites do objeto
		 */
		string spritePackName;
		/**
		 * Nome do arquivo de animações do objeto
		 */
		string animationPackName;
		/**
		 * Nome do arquivo de colisões do objeo
		 */
		string colisionPackName;
		/**
		 * Nome do arquivo da paleta de cores do objeto
		 */
		string paletteName;
		/**
		 * Ponteiro para o spritePack do objeto
		 */
		Gorgon::SpritePack* spritePack;
		/**
		 * Ponteiro para o animationPack do objeto
		 */
		Gorgon::AnimationPack* animationPack;
		/**
		 * Ponteiro para a paleta de cores do objeto
		 */
		Gorgon::Palette* palette;
		/**
		 * Script que comanda as ações do objeto
		 */
		Gorgon::Lua* script;
		/**
		 * Handler de animação do objeto
		 */
		Gorgon::AnimationHandler* animationHandler;
		/**
		 * Direção do objeto
		 */
		Gorgon::Mirroring direction;
		/**
		 * Nome do objeto
		 */
		string name;
		/**
		 * Posição do objeto no eixo x
		 */
		int posX;
		/**
		 * Posição do objeto no eixo y
		 */
		int posY;
		/**
		 * Peso do objeto
		 */
		int weight;
		/**
		 * Impulso horizontal que o objeto dispõem
		 */
		int xPulse;
		/**
		 * Impulso vertical que o objeto dispõem
		 */
		int yPulse;
		/**
		 * Impulso máximo no eixo x
		 */
		int xPulseMax;
		/**
		 * Estado atual do objeto
		 */
		int stateOn;

	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @final	11/03/2009
		 * @param	const string& scriptName, nome do script do objeto
		 * @param	const int& x, posição x do objeto
		 * @param	const int& y, posição y do objeto
		 */
		Object
		(
			const string& scriptName,
			const int& x = 0,
			const int& y = 0
		);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @final	11/03/2009
		 */
		virtual ~Object();
		/**
		 * Método para desenhar o objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @final	11/03/2009
		 */
		void draw() const;
		/**
		 * Método que realiza as operações lógicas do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @final	11/03/2009
		 */
		void logic();
		/**
		 * Método para setar o espelhamento do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @param	const Gorgon::Mirroring& mirroring, espelhamento
		 */
		void setMirroring(const Gorgon::Mirroring& mirroring);
		/**
		 * Método para retornar o espelhamento do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @return	Gorgon::Mirroring
		 */
		Gorgon::Mirroring getMirroring() const;
		/**
		 * Método para setar a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @param	const int& x, nova posição no eixo x
		 */
		void setXPosition(const int& x);
		/**
		 * Método para setar a posição y do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @param	const int& y, nova posição no eixo y
		 */
		void setYPosition(const int& y);
		/**
		 * Método para setar a posição xy do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @param	const int& x, nova posição no eixo x
		 * @param	const int& y, nova posição no eixo y
		 */
		void setPosition(const int& x,const int& y);
		/**
		 * Método para adicionar um valor a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @param	const int& x, valor a ser adicionado a posição no eixo x
		 */
		void addXPosition(const int& x);
		/**
		 * Método para adicionar um valor a posição y do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @param	const int& y, valor a ser adicionado a posição no eixo y
		 */
		void addYPosition(const int& y);
		/**
		 * Método para adicionar um valor a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @param	const int& x, valor a ser adicionado a posição no eixo x
		 * @param	conat int& y, valor a ser adicionado a posição no eixo y
		 */
		void addPosition(const int& x,const int& y);
		/**
		 * Método para retornar a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @return	int
		 */
		int getXPosition() const;
		/**
		 * Método para retornar a posição y do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @return	int
		 */
		int getYPosition() const;
		/**
		 * Método para mudar a animação atuante do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @param	const int& animation, nova animação
		 */
		void changeAnimation(const int& animation);
		/**
		 * Método para saber se a animação do objeto está tocando
		 *
		 * @author	Cantídio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 * @return	bool
		 */
		bool animationIsPlaying() const;
		/**
		 * Método para registrar as funções a serem usadas nos scripts em lua
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 */
		void registerFunctions();
};
/**
 * Bindings para os métodos de classe serem usados nos scritps em lua
 */
/**
 * Função que muda a animação de um objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_changeAnimation(lua_State* state);
/**
 * Função que retorna verdadeiro se a animação está tocando
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_animationIsPlaying(lua_State* state);
/**
 * Função que retorna a posição x do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_getXPosition(lua_State* state);
/**
 * Função que retorna a posição y do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_getYPosition(lua_State* state);
/**
 * Função que seta a posição x do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_setXPosition(lua_State* state);
/**
 * Função que seta a posição y do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_setYPosition(lua_State* state);
/**
 * Função que seta a posição x y do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_setPosition(lua_State* state);
/**
 * Função que adiciona um valor a posição x do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_addXPosition(lua_State* state);
/**
 * Função que adiciona um valor a posição y do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_addYPosition(lua_State* state);
/**
 * Função que adiciona um valor a posição xy do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_addPosition(lua_State* state);
/**
 * Função que seta o espelhamento do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_setMirroring(lua_State* state);
/**
 * Função que retorna o espelhamento do objeto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_getMirroring(lua_State* state);

#endif
