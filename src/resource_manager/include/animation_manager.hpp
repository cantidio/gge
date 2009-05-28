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
#ifndef _GSBGE_ANIMATION_MANAGER_
#define _GSBGE_ANIMATION_MANAGER_
#include "../../../../gorgon++/src/graphic/include/gorgon_animationpack.hpp"
#include "../../../../gorgon++/src/core/include/gorgon_log.hpp"

namespace ResourceManager
{
	/**
	 * Estrutura que guarda uma entrada na tabela de recursos de animação
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	11/03/2009
	 * @version	11/03/2009
	 * @ingroup	ResourceManager
	 */
	typedef struct
	{
		Gorgon::AnimationPack*	animationPack;
		std::string				fileName;
		int						use;
	}AnimationId;

	/**
	 * Classe que gerencia os animationPacks usados
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	11/03/2009
	 * @version	28/05/2009
	 * @ingroup	ResourceManager
	 */
	class AnimationManager
	{
		private:
			/**
			 * Tabela com os recursos de animação
			 */
			static std::vector<AnimationId> mTable;
		public:
			/**
			 * Para para carregar um spritePack, se o mesmo já tiver sido carregado retorna o ponteiro para o mesmo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	28/05/2009
			 * @param	const std::string& pAnimationPackName, nome do animationPack
			 * @return	Gorgon::AnimationPack*
			 */
			static Gorgon::AnimationPack* load(const std::string& pAnimationPackName);
			/**
			 * Método para retirar da memória o spritePack carregado
			 *
			 * @author		Cantidio Oliveira Fontes
			 * @since		11/03/2009
			 * @version		28/05/2009
			 * @param		const std::string& pAnimationPackName, nome do animationPack a ser removido
			 * @details
			 *				Esse método antes de remover o animationPack completamente,
			 * verifica se algum outro objeto está usando o recurso do mesmo, se ninguém
			 * mais estiver o usando então livra a memória do mesmo.
			 */
			static void unload(const std::string& pAnimationPackName);
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

