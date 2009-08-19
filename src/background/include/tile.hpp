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
#ifndef _GSBGE_TILE_
#define	_GSBGE_TILE_
#include <gorgon++/include/graphic/gorgon_animation_handler.hpp>
#include <gorgon++/include/graphic/gorgon_video.hpp>
#include <vector>

/**
 * Classe que representa um tilede um cenário
 *
 * @author	Cantidio Oliveira Fontes
 * @since	17/03/2009
 * @version	28/05/2009
 * @ingroup	Background
 * @todo	Substituir o vetor de posição x e y, por um vetor de Gorgon::Point(x,y)
 */
class Tile
{
	protected:
		/**
		 * Handler de animação do objeto
		 */
		Gorgon::AnimationHandler* mAnimationHandler;
		/**
		 * Posição do objeto no eixo x
		 */
		std::vector<int> mPosX;
		/**
		 * Posição do objeto no eixo y
		 */
		std::vector<int> mPosY;
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	Gorgon::SpritePack*		pSpritePack			, ponteiro para o pacote de sprites
		 * @param	Gorgon::AnimationPack*	pAnimationPack		, ponteiro para o pacote de animações
		 * @param	const int&				pAnimationNumber	, número da animação do tile
		 */
		Tile
		(
			Gorgon::SpritePack&		pSpritePack,
			Gorgon::AnimationPack&	pAnimationPack,
			const int&				pAnimationNumber
		);
		Tile(const Tile& orig);
		/**
		 * Método destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 */
		virtual ~Tile();
		/**
		 * Método para descrever as informações do tile
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/03/2009
		 * @version	28/05/2009
		 */
		void describe() const;
		/**
		 * Método para retornar a animação do tile
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @return	int
		 */
		int getAnimation() const;
		/**
		 * Método para retornar a posição x do tile de índice indicado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @param	const int& pIndex, índice do tile
		 * @return	int
		 */
		int getXPostion(const int& pIndex) const;
		/**
		 * Método para retornar a posição y do tile de índice indicado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @param	const int& pIndex, índice do tile
		 * @return	int
		 */
		int getYPostion(const int& pIndex) const;
		/**
		 * Método para retornar o número de tiles
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @return	int
		 */
		int getSize() const;
		/**
		 * Método para se adicionar um tile na posição indicada
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	const int& pPosX, posição x do tile
		 * @param	const int& pPosY, posição y do tile
		 */
		void add(const int& pPosX, const int& pPosY);
		/**
		 * Método que executa a lógica envolvida no tile
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 */
		void logic();
		/**
		 * Método para se desenhar o tile
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	const Gorgon::Sprite&	pSprite, sprite que o tile será desenhado
		 * @param	const int&				pPosX, posição x base
		 * @param	const int&				pPosY, posição y base
		 */
		void draw
		(
			Gorgon::Sprite& pSprite,
			const int& pPosX = 0,
			const int& pPosY = 0
		);
};

#endif
