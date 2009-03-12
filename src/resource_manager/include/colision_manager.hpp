a#ifndef _ANIMATION_MANAGER_
#define _ANIMATION_MANAGER_
//#include "../../../../gorgon++/src/graphic/include/gorgon_animationpack.hpp"

namespace ResourceManager
{
	/**
	 * Estrutura que guarda uma entrada na tabela de recursos de colisão
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	11/03/2009
	 * @final	11/03/2009
	 */
	typedef struct
	{
		Gorgon::ColisionPack*	colisionPack;
		string					fileName;
		int						use;
	}ColisionId;

	/**
	 * Classe que gerencia os animationPacks usados
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	11/03/2009
	 * @final	11/03/2009
	 */
	class ColisionManager
	{
		private:
			/**
			 * Tabela com os recursos de animação
			 */
			static vector<ColisionId> table;
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
			static Gorgon::ColisionPack* load(const string& name);
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

