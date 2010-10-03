#include <gorgon++/gorgon.hpp>
/**
 * Bindings para os métodos de classe serem usados nos scritps em lua
 *
 * @author	Cantidio Oliveira Fontes
 * @since	29/09/2010
 * @version	01/10/2010
 * @ingroup	Game
 */
namespace GameLua
{
	/**
	 * Função que inicia a classe game
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/09/2010
	 * @version	01/10/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int GGE_game_init(lua_State* pState);
	/**
	 * Função que termina a classe game
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/09/2010
	 * @version	01/10/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int GGE_game_halt(lua_State* pState);
	/**
	 * Função que registra um log em LUA
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/09/2010
	 * @version	01/10/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int GGE_game_log(lua_State* pState);
	/**
	 * Função para setar o nome do game
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/09/2010
	 * @version	01/10/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int GGE_game_setGameName(lua_State* pState);
	/**
	 * Função para setar a versão do game
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/09/2010
	 * @version	01/10/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int GGE_game_setGameVersion(lua_State* pState);
	/**
	 * Função para setar o FPS do game
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/09/2010
	 * @version	01/10/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	int GGE_game_setFPS(lua_State* pState);
	/**
	 * Função para registrar as funcões em LUA
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/09/2010
	 * @version	01/10/2010
	 * @param	lua_State* pState, estado do interpretador lua atual
	 * @return	int
	 */
	void registerFunctions(Gorgon::Lua* pScript);
}

