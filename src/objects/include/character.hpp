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
#ifndef _GSBGE_CHARACTER_
#define	_GSBGE_CHARACTER_
#include "object.hpp"

/**
 * Classe que representa um personagem controlado por scripts
 *
 * @author	Cantidio Oliveira Fontes
 * @since	12/03/2009
 * @version	31/03/2009
 * @ingroup	Objects
 */
class Character : public Object
{
	protected:
		/**
		 * Colisão Superior do personagem
		 */
		Gorgon::Rectangle mUpColision;
		/**
		 * Colisão Inferior do personagem
		 */
		Gorgon::Rectangle mDownColision;
		/**
		 * Colisão a esquerda do personagem
		 */
		Gorgon::Rectangle mLeftColision;
		/**
		 * Colisão a direita do personagem
		 */
		Gorgon::Rectangle mRightColision;
		/**
		 * Vida do personagem
		 */
		int mLife;
		/**
		 * Vida corrente do personagem
		 */
		int mCurrentLife;
		/**
		 * Se o maior que 0 o personagem está imortal
		 */
		int mImortal;
		/**
		 * O tempo que o personagem fica imortal após atingido
		 */
		int mImortalTime;
		/**
		 * Se o personagem está ativo
		 */
		bool mAtive;
		/**
		 * Vetor com os helpers do personagem
		 */
		std::vector< std::vector<Character*> > mHelpers;
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @version	14/03/2009
		 */
		Character();
		/**
		 * Método para carregar as variáveis globais de um personagem declaradas no script
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @version	14/03/2009
		 */
		void loadGlobalVars();
		/**
		 * Método para preparar o personagem com as informações já recolhidas
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @version	31/03/2009
		 */
		void setUp();
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	31/03/2009
		 * @param	const std::string& pFileName, localização do arquivo de script do personagem
		 * @param	const Gorgon::Point& pPosition, posição xy do personagem
		 */
		Character
		(
			const std::string& pFileName,
			const Gorgon::Point& pPosition=Gorgon::Point(0,0)
		);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 */
		virtual ~Character();
		/**
		 * Método para retornar o life do personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @return	int
		 */
		int getLife() const;
		/**
		 * Método para setar o life do personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @param	const int& pLife, vida do personagem
		 */
		void setLife(const int& pLife);
		/**
		 * Método que dimuniu a vida do personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @param	const int& pLife, valor a ser diminuído do life do personagem
		 */
		void subLife(const int& pLife);
		/**
		 * Método para aumentar a vida do personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @param	const int& pLife, valor a ser somado ao life do personagem
		 */
		void addLife(const int& pLife);
		/**
		 * Método que retorna verdadeiro se o personagem estiver vivo
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @return	bool
		 */
		bool isAlive() const;
		/**
		 * Método para ativar o personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 */
		void ativate();
		/**
		 * Método para desativar o personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 */
		void inativate();
		/**
		 * Método que retorna verdadeiro se o personagem estiver ativo
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @return	bool
		 */
		bool isAtive() const;
		/**
		 * Método que retorna verdadeiro se o personagem estiver imortal
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @return	bool
		 */
		bool isImortal() const;
		/**
		 * Método que machuca o personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 * @param	const int& pDamage, dano recebido
		 * @details
		 *			Diminui o dano especificado e o deixa o personagem imortal o número de tempo espeficidado
		 * na variável imortalTime
		 */
		void hurt(const int& pDamage);
		/**
		 * Método para preparar os helpers do personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	31/03/2009
		 */
		void prepareHelpers();
		/**
		 * Método para chamar um helper
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	31/03/2009
		 * @param	const Gorgon::Point& pPosition, posição x que o helper será chamado
		 * @param	const Gorgon::Mirroring& pMirroring, espelhamento que o helper será chamado
		 * @param	const int& pHelper, qual helper a chamar
		 */
		void callHelper
		(
			const Gorgon::Point&		pPosition,
			const Gorgon::Mirroring&	pMirroring,
			const int&					pHelper=0
		);
		/**
		 * Método responsável por desenhar o personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 */
		void draw() const;
		/**
		 * Método responsável pela lógica do personagem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	12/03/2009
		 */
		void logic();
};
#endif
