/*
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
#ifndef _GSBGE_SPRITE_MANAGER_
#define _GSBGE_SPRITE_MANAGER_
#include <gorgon++/gorgon.hpp>

namespace ResourceManager
{
	/**
	 * Estrutura que guarda uma entrada na tabela de recursos de sprites
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	11/03/2009
	 * @version	11/03/2009
	 * @ingroup	ResourceManager
	 */
	typedef struct
	{
		Gorgon::SpritePack* spritePack;
		std::string			fileName;
		int					use;
	}SpriteId;
	
	/**
	 * Classe que gerência os spritePacks usados
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	11/03/2009
	 * @version	29/09/2010
	 * @ingroup	ResourceManager
	 */
	class SpriteManager
	{
		private:
			/**
			 * Tabela com os recursos de sprites
			 */
			static std::vector<SpriteId> mTable;
		public:
			/**
			 * Para para carregar um spritePack, se o mesmo já tiver sido carregado retorna o ponteiro para o mesmo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	29/09/2010
			 * @param	const std::string& pSpritePackName, nome do spritePack
			 * @return	Gorgon::SpritePack&
			 */
			static Gorgon::SpritePack& load(const std::string& pSpritePackName);
			/**
			 * Método para retirar da memória o spritePack carregado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	28/05/2009
			 * @param	const std::string& pSpritePackName, nome do spritePack a ser removido
			 * @details
			 *			Esse método antes de remover o SpritePack completamente,
			 * verifica se algum outro objeto está usando o recurso do mesmo, ninguém
			 * mais estiver o usando então livra a memória do mesmo.
			 */
			static void unload(const std::string& pSpritePackName);
			/**
			 * Método para forçar a limpeza de toda tabela
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	28/05/2009
			 */
			static void clear();
	};
}
#endif

