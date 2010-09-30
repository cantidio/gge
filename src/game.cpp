#include "../include/game.hpp"
int fps = 0;
int fps_antigo = 0;
int timer = 0;

void frame_rate()
{
	fps_antigo	= fps;
	fps			= 0;
}

void game_time()
{
	++timer;
}
END_OF_FUNCTION(game_time);
//-------------------------------------------------------------------------------TIMER UP------------------------------------
Game::Game()
{
	init();
}
Game::~Game()
{
	Input::halt();
}
bool Game::init
(
	const std::string&	pWindowTitle,
	const int&			pWidth,
	const int&			pHeight,
	const bool&			pFullScreen
)
{
	allegro_init();
	LOCK_VARIABLE(timer);
	LOCK_FUNCTION(game_time);
	install_int( frame_rate, 1000 );
	install_int_ex(game_time, BPS_TO_TIMER(mFPS));
	Gorgon::Log::init("gge_log.txt");
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
}

void Game::registerLuaFunctions()
{
	ObjectLua::registerFunctions(mScript);
	TileLua::registerFunctions(mScript);
	InputLua::registerFunctions(mScript);
}

void Game::run()
{
	try
	{
		while(!key[KEY_ESC])
		{
			while(timer >= 0 && !key[KEY_ESC])
			{
				Gorgon::Video::get().clear(0xAA0BDD);

				//executa funćão logic do mal aqui
			
				//TextWindow::get().show();
				Gorgon::Video::get().drawText(10,10,0,-1,"FPS: %d",fps_antigo);
				Gorgon::Video::get().show();
				--timer;
				++fps;
			}
		}
	}
	catch(Gorgon::Exception e)
	{
		std::cout << e.getMessage() << std::endl;
	}
}

