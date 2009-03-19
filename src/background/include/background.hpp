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
#ifndef _GSBGE_BACKGROUND_
#define _GSBGE_BACKGROUND_
#include "layer.hpp"

/**
 * Classe que representa um cenário
 *
 * @author	Cantidio Oliveira Fontes
 * @since	18/03/2009
 * @final	19/03/2009
 */
class Background
{
	private:
		/**
		 * Vetor com os layers do background
		 */
		std::vector<Layer> layers;
		/**
		 * Posição x do background
		 */
		int posX;
		/**
		 * Posição y do background
		 */
		int posY;
		/**
		 * Largura do background
		 */
		int width;
		/**
		 * Altura do cenário
		 */
		int height;
		/**
		 * Variável que trava o scrooling do cenário
		 */
		bool lockScrool;
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 * @param	const int& width	, largura do cenário
		 * @param	const int& height	, altura do cenário
		 * @param	const int& posX		, posição x que o cenário se encontra
		 * @param	const int& posY		, posição y que o cenário se encontra
		 */
		Background
		(
			const int& width,
			const int& height,
			const int& posX=0,
			const int& posY=0
		);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 */
		~Background();
		/**
		 * Método para se adicionar um layer ao background
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 * @param	Layer& layer, layer a ser adicionado
		 */
		void addLayer(Layer& layer);
		/**
		 * Método que executa a lógica envolvida no background
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 */
		void logic();
		/**
		 * Método para se desenhar o cenário e todos objetos que o compõem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @final	18/03/2009
		 * @param	Gorgon::Sprite& sprite, sprite que o cenário será desenhado
		 */
		void draw(Gorgon::Sprite& sprite);
		/**
		 * Método para salvar o background e seus componentes
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/03/2009
		 * @final	19/03/2009
		 * @param	const std::string& fileName, nome do arquivo a salvar
		 */
		void save(const std::string& fileName) const;
};
#endif
