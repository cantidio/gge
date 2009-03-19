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


#ifndef _GSBGE_LAYER_
#define _GSBGE_LAYER_
#include "../../objects/include/object.hpp"
#include "tile.hpp"
#include <vector>

/**
 * Classe que representa uma camada de um cenário
 *
 * @author	Cantidio Oliveira Fontes
 * @since	17/03/2009
 * @final	18/03/2009
 */
class Layer
{
	private:
		/**
		 * Vetor com os tiles do layer
		 */
		std::vector<Tile>	tiles;
		/**
		 * Vetor com os objetos do cenário
		 */
		std::vector<Object>	objects;
		/**
		 * Velocidade de deslocamento horizontal do layer
		 */
		double xScrollSpeed;
		/**
		 * Velocidade de deslocamento vertical do layer
		 */
		double yScrollSpeed;
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	17/03/2009
		 */
		Layer(const double& xScrollSpeed=1,const double& yScrollSpeed=1);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	17/03/2009
		 */
		~Layer();
		void describe() const;
		/**
		 * Método para se adicionar um Object ao layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 * @param	Object& object, Object a ser adicionado
		 */
		void addObject(Object& object);
		/**
		 * Método para se adicionar um Tile ao Layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 * @param	Tile& tile, Tile a ser adicionado
		 */
		void addTile(Tile& tile);
		/**
		 * Método para retornar a posição x real do layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 * @param	const int& posX, posição x
		 * @return	int
		 */
		int getRealPosX(const int& posX) const;
		/**
		 * Método para retornar a posição y real do layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 * @param	const int& posY, posição y
		 * @return	int
		 */
		int getRealPosY(const int& posY) const;


		std::string getScriptName() const;
		/**
		 * Método que executa a lógica envolvida no layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	17/03/2009
		 */
		void logic();
		/**
		 * Método para se desenhar o layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 * @param	Gorgon::Sprite& sprite, sprite que o layer será desenhado
		 * @param	const int& x, posição x que o layer será desenhado
		 * @param	const int& y, posição y que o layer será desenhado
		 */
		void draw
		(
			Gorgon::Sprite& sprite,
			const int& x,
			const int& y
		);
		void save(const std::string& fileName) const;
};
#endif