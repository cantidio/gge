#ifndef _GGE_Game_
#define _GGE_Game_

#include <gorgon++/gorgon.hpp>
#include <string>
#include "game_lua.hpp"
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
		static Game*				mSingleton; /**<< Singleton instance of the class*/
		Gorgon::Script::Lua			mScript;    /**<< Instance of the lua interpreter*/
		Gorgon::Graphic::Display*   mDisplay;   /**<< Pointer to the display of the game*/
		Gorgon::Input::Keyboard*    mKeyboard;  /**<< Pointer to the keyboard*/

		int 						mFPS;
		bool						mRunning;
		std::vector<std::string>	mArgs;
		/**
		 * Método para registrar as funćões em Lua
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 * @return	void
		 */
		void registerLuaFunctions();
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	05/01/2011
		 */
		Game(int pArgc = 0, char** pArgv = NULL);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 */
		~Game();
	public:
		/**
		 * Método que instancia o jogo
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	05/01/2011
		 * @version	05/01/2011
		 */
		static void instantiate(int pArgc = 0, char** pArgv = NULL);
		/**
		 * Método para retornar a instancia do game
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 * @return	Game&
		 */
		static Game& get();
		/**
		 * Método para deletar a instancia do game
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 */
		static void halt();
		/**
		 * Método que retorna o vetor de argumentos
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	05/01/2011
		 * @version	05/01/2011
		 * @return	std::vector<std::string>
		 */
		std::vector<std::string> getArgs() const;
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
		/**
		 * Método que retorna se o jogo está executando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	30/09/2010
		 * @version	30/09/2010
		 */
		bool isRunning() const;
		int getWidth() const;
		int getHeight() const;
};
#endif
