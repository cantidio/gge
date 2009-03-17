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
#ifndef _GSBGE_OBJECT_
#define	_GSBGE_OBJECT_
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
 * @final	14/03/2009
 */
class Object
{
	protected:
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
		double posX;
		/**
		 * Posição do objeto no eixo y
		 */
		double posY;
		/**
		 * Peso do objeto
		 */
		double weight;
		/**
		 * Impulso horizontal que o objeto dispõem
		 */
		double xPulse;
		/**
		 * Impulso vertical que o objeto dispõem
		 */
		double yPulse;
		/**
		 * Impulso máximo no eixo x
		 */
		double xPulseMax;
		/**
		 * Estado atual do objeto
		 */
		int stateOn;
		/**
		 * Método Construtor vazio
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 */
		Object();
		/**
		 * Método para carregar as variáveis globais de um objeto declaradas no script
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 */
		void loadGlobalVars();
		/**
		 * Método para registrar as funções a serem usadas nos scripts em lua
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 */
		void registerFunctions();
		/**
		 * Método para preparar o objeto com as informações já recolhidas
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	12/03/2009
		 */
		void setUp();
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @final	14/03/2009
		 * @param	const string& scriptName, nome do script do objeto
		 * @param	const double& x, posição x do objeto
		 * @param	const double& y, posição y do objeto
		 */
		Object
		(
			const string& scriptName,
			const double& x = 0,
			const double& y = 0
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
		 * @final	14/03/2009
		 * @param	const double& x, nova posição no eixo x
		 */
		void setXPosition(const double& x);
		/**
		 * Método para setar a posição y do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	14/03/2009
		 * @param	const double& y, nova posição no eixo y
		 */
		void setYPosition(const double& y);
		/**
		 * Método para setar a posição xy do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	14/03/2009
		 * @param	const double& x, nova posição no eixo x
		 * @param	const double& y, nova posição no eixo y
		 */
		void setPosition(const double& x,const double& y);
		/**
		 * Método para adicionar um valor a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	14/03/2009
		 * @param	const double& x, valor a ser adicionado a posição no eixo x
		 */
		void addXPosition(const double& x);
		/**
		 * Método para adicionar um valor a posição y do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	14/03/2009
		 * @param	const double& y, valor a ser adicionado a posição no eixo y
		 */
		void addYPosition(const double& y);
		/**
		 * Método para adicionar um valor a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	14/03/2009
		 * @param	const double& x, valor a ser adicionado a posição no eixo x
		 * @param	conat double& y, valor a ser adicionado a posição no eixo y
		 */
		void addPosition(const double& x,const double& y);
		/**
		 * Método para retornar a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	14/03/2009
		 * @return	double
		 */
		double getXPosition() const;
		/**
		 * Método para retornar a posição y do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @final	14/03/2009
		 * @return	double
		 */
		double getYPosition() const;
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
		 * Método que retorna a animação que está tocando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @final	14/03/2009
		 * @return	int
		 */
		int getAnimationOn() const;
		/**
		 * Método que retorna o frame atual da animação que está tocando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @final	14/03/2009
		 * @return	int
		 */
		int getFrameOn() const;
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
 * Função que retorna o número da animação que está tocando
 *
 * @author	Cantidio Oliveira Fontes
 * @since	14/03/2009
 * @final	14/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_getAnimationOn(lua_State* state);
/**
 * Função que retorna o número do frame atual da animação que está tocando
 *
 * @author	Cantidio Oliveira Fontes
 * @since	14/03/2009
 * @final	14/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_getFrameOn(lua_State* state);
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
