#ifndef _ANIMATION_MANAGER_
#define _ANIMATION_MANAGER_
#include "../../../../gorgon++/src/graphic/include/gorgon_animationpack.hpp"

namespace ResourceManager
{
	/**
	 * Estrutura que guarda uma entrada na tabela de recursos de animação
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	11/03/2009
	 * @final	11/03/2009
	 */
	typedef struct
	{
		Gorgon::AnimationPack*	animationPack;
		string					fileName;
		int						use;
	}AnimationId;

	/**
	 * Classe que gerencia os animationPacks usados
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	11/03/2009
	 * @final	11/03/2009
	 */
	class AnimationManager
	{
		private:
			/**
			 * Tabela com os recursos de animação
			 */
			static vector<AnimationId> table;
		public:
			/**
			 * Para para carregar um spritePack, se o mesmo já tiver sido carregado retorna o ponteiro para o mesmo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @final	11/03/2009
			 * @param	const string& name, nome do spritePack
			 * SpritePack* ponteiro para o spritePack carregado
			 */
			static Gorgon::AnimationPack* load(const string& name);
			/**
			 * Método para retirar da memória o spritePack carregado
			 *
			 * @author		Cantidio Oliveira Fontes
			 * @since		11/03/2009
			 * @final		11/03/2009
			 * @param		const string& name, nome do spritePack a ser removido
			 * @abstract	esse método antes de remover o sprite completamente, verifica se algum outro objeto está usando
			 * o recurso do mesmo, ninguém mais estiver o usando então livra a memória do mesmo.
			 */
			static void unload(const string& name);
			/**
			 * Método para forçar a limpeza de toda tabela
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @final	11/03/2009
			 */
			static void clear();
	};
}
#endif

