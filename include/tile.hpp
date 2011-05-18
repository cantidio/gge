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
#ifndef _GGE_TILE_
#define	_GGE_TILE_
#include <gorgon++/gorgon.hpp>
#include "resource_manager.hpp"
/**
 * Classe que representa um tilede um cenário
 *
 * @author	Cantidio Oliveira Fontes
 * @since	17/03/2009
 * @version	29/09/2010
 * @ingroup	Background
 */
class Tile
{
	protected:
		/**
		 * Handler de animação do objeto
		 */
		Gorgon::Graphic::AnimationHandler* mAnimationHandler;
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	29/09/2010
		 * @param	Gorgon::SpritePack*		pSpritePack			, ponteiro para o pacote de sprites
		 * @param	Gorgon::AnimationPack*	pAnimationPack		, ponteiro para o pacote de animações
		 * @param	const int&              pAnimationNumber	, número da animação do tile
		 */
		Tile
		(
			Gorgon::Graphic::SpritePack&	pSpritePack,
			Gorgon::Graphic::AnimationPack&	pAnimationPack,
			const int&						pAnimationNumber
		);
		/**
		 * Método Construtor de Cópia
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	29/09/2010
		 * @param	const Tile& pTile, tile original
		 */
		Tile(const Tile& pTile);
		/**
		 * Método destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 */
		virtual ~Tile();
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
		* Método para mudar a animacao do tile
		*
		* @author  Cantidio Oliveira Fontes
		* @since   13/12/2009
		* @version 13/12/2009
		* @param   const int& pAnimation, o numero da nova animacão
		*/
		void setAnimation(const int& pAnimation);
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
		 * @version	29/09/2010
		 * @param	const Gorgon::Core::Point& pPosition, posição
		 */
		void draw(const Gorgon::Core::Point& pPosition = Gorgon::Core::Point(0,0));
};
#endif

