#include "../include/game.hpp"

//-------------------------------------------------------------------------------TIMER--------------------------------------
int fps			= 0;
int fps_antigo	= 0;
int timer		= 0;
void frame_rate()	{ fps_antigo = fps; fps = 0; }
void game_time()	{ ++timer; }
END_OF_FUNCTION(game_time);
//-------------------------------------------------------------------------------TIMER UP------------------------------------

Game* Game::mSingleton = NULL;
Game::Game()
{
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Game::Game()");
	registerLuaFunctions();
}

Game::~Game()
{
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Game::~Game()");
	Input::halt();
	ResourceManager::SpriteManager::clear();
	ResourceManager::AnimationManager::clear();
}

Game& Game::get()
{
	if(mSingleton == NULL)
	{
		mSingleton = new Game();
	}
	return *mSingleton;
}

void Game::halt()
{
	if(mSingleton != NULL)
	{
		delete mSingleton;
		mSingleton = NULL;
	}
}

bool Game::init
(
	const std::string&	pWindowTitle,
	const int&			pWidth,
	const int&			pHeight,
	const bool&			pFullScreen
)
{
	Gorgon::Core::Log::get().RegisterFormated
	(
		"C++ -> Game::init()\n\
			\t\t\t\tpWindowTitle: %s\n\
			\t\t\t\tpWidth:       %d\n\
			\t\t\t\tpHeight:      %d\n\
			\t\t\t\tFullscreen:   %d",
		pWindowTitle.c_str(),
		pWidth,pHeight,
		(int)pFullScreen
	);
	allegro_init();
	LOCK_VARIABLE(timer);
	LOCK_FUNCTION(game_time);
	install_int( frame_rate, 1000 );
	install_int_ex(game_time, BPS_TO_TIMER(mFPS));
	
	Gorgon::Video::init
	(
		pWindowTitle,
		pWidth,
		pHeight,
		pFullScreen
	);
	Input::init();
	return true;
}

bool Game::setFPS(const int& pFPS)
{
	mFPS = pFPS;
	return true;
}

void Game::registerLuaFunctions()
{
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Game::registerLuaFunctions()");

	ObjectLua::registerFunctions(mScript);
	TileLua::registerFunctions(mScript);
	InputLua::registerFunctions(mScript);
	GameLua::registerFunctions(mScript);
	
	mScript.loadScript("data/class_tile.lua");
	mScript.loadScript("data/class_layer.lua");
	mScript.loadScript("data/class_background.lua");
	mScript.loadScript("data/class_input.lua");
	mScript.loadScript("data/class_object.lua");
	mScript.loadScript("data/class_player.lua");
	mScript.loadScript("data/class_game.lua");
}

void Game::run()
{
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Game::run()");
	try
	{
		mScript.loadScript("game.lua");//carrega o game
		
		while(!key[KEY_ESC])
		{
			while(timer >= 0 && !key[KEY_ESC])
			{
				Gorgon::Video::get().clear(0xAA0BDD);

				//executa funcao logic do mal aqui
				mScript.function("GGE_game_runStep");
			
				//TextWindow::get().show();
				Gorgon::Video::get().drawText(10,10,0,-1,"FPS: %d",fps_antigo);
				Gorgon::Video::get().show();
				--timer;
				++fps;
			}
		}
	}
	catch(Gorgon::Core::Exception e)
	{
		std::cout << e.getMessage() << std::endl;
	}
}

