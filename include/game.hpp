#ifndef _GGE_Game_
#define _GGE_Game_

#include <gorgon++/gorgon.hpp>
#include <string>
#include "object_lua.hpp"
#include "tile_lua.hpp"
#include "input_lua.hpp"
#include "input.hpp"

/**
 * Classe que representa o game
 *
 * @author	Cantidio Oliveira Fontes
 * @since	30/09/2010
 * @version	30/09/2010
 */
class Game
{
	protected:
		Gorgon::Lua* mScript;
		int mFPS;

		/**
		 * Método para registrar as funćões em Lua
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 * @return	void
		 */
		void registerLuaFunctions();
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 */

		Game();
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 */
		~Game();

		/**
		 * Método que inicializa os valores
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 * @param	const std::string& pWindowTitle	, titulo da janela
		 * @param	const int&			pWidth		, largura da tela
		 * @param	const int&			pHeight		, altura da tela
		 * @param	const bool&			pFullScreen	, se é tela cheia
		 * @return	bool
		 */
		bool init
		(
			const std::string&	pWindowTitle	= "GGE" ,
			const int&			pWidth			= 320	,
			const int&			pHeight			= 240	,
			const bool&			pFullScreen		= false
		);

		/**
		 * Método para setar os FPS
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 */
		bool setFPS(const int& pFPS);

		/**
		 * Método para executar o game
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 */
		void run();
};
#endif
