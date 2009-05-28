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
#ifndef _GSBGE_PLAYER_
#define	_GSBGE_PLAYER_
#include "character.hpp"
#include "../../input/include/input_lua.hpp"

/**
 * Classe que representa um jogador controlado por scripts
 *
 * @author	Cantidio Oliveira Fontes
 * @since	14/03/2009
 * @final	16/03/2009
 */
class Player : public Character
{
	protected:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @final	14/03/2009
		 */
		Player();
		/**
		 * Método para carregar as variáveis globais de um jogador declaradas no script
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @final	14/03/2009
		 */
		void loadGlobalVars();
		/**
		 * Método para registrar as funções a serem usadas nos scripts em lua
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @final	16/03/2009
		 */
		void registerFunctions();
		/**
		 * Método para preparar o jogador com as informações já recolhidas
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @final	14/03/2009
		 */
		void setUp();
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @final	31/03/2009
		 * @param	const std::string& fileName, localização do arquivo de script do jogador
		 * @param	const Gorgon::Point& position, posição xy a criar o personagem
		 */
		Player(const std::string& fileName,const Gorgon::Point& position=Gorgon::Point(0,0));
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @final	14/03/2009
		 */
		virtual ~Player();
};
#endif
