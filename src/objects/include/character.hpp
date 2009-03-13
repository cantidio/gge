/**
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
#ifndef _CHARACTER_
#define	_CHARACTER_
#include "object.hpp"

/**
 * Classe que representa um personagem controlado por scripts
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @final	13/03/2009
 */
class Character : public Object
{
	protected:
		/**
		 * Vida do personagem
		 */
		int life;
		/**
		 * Vida corrente do personagem
		 */
		int currentLife;
		/**
		 * Se o maior que 0 o personagem está imortal
		 */
		int imortal;
		/**
		 * O tempo que o personagem fica imortal após atingido
		 */
		int imortalTime;
		/**
		 * Se o personagem está ativo
		 */
		bool ative;
		/**
		 * Vetor com os helpers do personagem
		 */
		vector<Character*> helpers;
	public:
	/**
	 * Método Construtor
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 */
	Character
	(
		const string& fileName,
		const int& x=0,
		const int& y=0
	);
	/**
	 * Método Destrutor
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 */
	virtual ~Character();
	/**
	 * Método para retornar o life do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @return	int
	 */
	int getLife() const;
	/**
	 * Método para setar o life do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	const int& life, vida do personagem
	 */
	void setLife(const int& life);
	/**
	 * Método que dimuniu a vida do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	const int& life, valor a ser diminuído do life do personagem
	 */
	void subLife(const int& life);
	/**
	 * Método para aumentar a vida do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @param	const int& life, valor a ser somado ao life do personagem
	 */
	void addLife(const int& life);
	/**
	 * Método que retorna verdadeiro se o personagem estiver vivo
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @return	bool
	 */
	bool isAlive() const;
	/**
	 * Método para ativar o personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 */
	void ativate();
	/**
	 * Método para desativar o personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 */
	void inativate();
	/**
	 * Método que retorna verdadeiro se o personagem estiver ativo
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @return	bool
	 */
	bool isAtive() const;
	/**
	 * Método que retorna verdadeiro se o personagem estiver imortal
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 * @return	bool
	 */
	bool isImortal() const;
	/**
	 * Método que machuca o personagem
	 *
	 * @author		Cantidio Oliveira Fontes
	 * @since		12/03/2009
	 * @final		12/03/2009
	 * @param		const int& damage, dano
	 * @abstract	diminui o dano especificado e o deixa o personagem imortal o número de tempo espeficidado
	 * na variável imortalTime
	 */
	void hurt(const int& damage);
	/**
	 * Método para preparar os helpers do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 */
	void prepareHelpers();
	/**
	 * Método para chamar um helper
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	13/03/2009
	 * @param	const int& x, posição x que o helper será chamado
	 * @param	const int& y, posição y que o helper será chamado
	 * @param	const Gorgon::Mirroring& mirroring, espelhamento que o helper será chamado
	 */
	void callHelper
	(
		const int& x,
		const int& y,
		const Gorgon::Mirroring& mirroring
	);
	/**
	 * Método responsável por desenhar o personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 */
	void draw() const;
	/**
	 * Método responsável pela lógica do personagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/03/2009
	 * @final	12/03/2009
	 */
	void logic();
};
/**
 * Bindings para os métodos de classe serem usados nos scritps em lua
 */
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
 * @final	12/03/2009
 * @param	lua_State* state, estado do interpretador lua atual
 * @return	int
 */
int lua_callHelper(lua_State* state);
#endif
