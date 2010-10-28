#include "../include/game.hpp"
#include "../include/console_window.hpp"


//-------------------------------------------------------------------------------TIMER--------------------------------------
int fps			= 0;
int fps_antigo	= 0;
int timer		= 0;
void frame_rate()	{ fps_antigo = fps; fps = 0; }
void game_time()	{ ++timer; }
END_OF_FUNCTION(game_time);
//-------------------------------------------------------------------------------TIMER UP------------------------------------

void trySaveScreenShot(const int& pShotNumber)
{
	std::stringstream out;
	out << "shots/shot" << pShotNumber << ".bmp";
	Gorgon::Core::File file(out.str(),std::ios::in | std::ios::binary);
	
	if(file.is_open())
	{
		file.close();
		trySaveScreenShot(pShotNumber + 1);
	}
	else
	{
		Gorgon::ImageFormatBmp imageFormat;
		file.close();
		imageFormat.save(static_cast<Gorgon::Image&>(Gorgon::Video::get()),out.str());
		Gorgon::Core::Log::get().RegisterFormated("C++ -> ScreenShot saved: %s",out.str().c_str());
	}
}

void screenShot()
{
	if(key[KEY_F12])
	{
		Gorgon::Core::Log::get().RegisterFormated("C++ -> Trying to take a Screenshot...");
		trySaveScreenShot(0);
		key[KEY_F12] = 0;
	}
}

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
    install_mouse();
    install_timer();
	Input::get();//just to init the input
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

	ObjectLua::registerClass(mScript);
	TileLua::registerClass(mScript);
	InputLua::registerFunctions(mScript);
	GameLua::registerFunctions(mScript);
	
	mScript.loadScript("data/include.lua");
	mScript.loadScript("data/class.lua");
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
	int state = 0;
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Game::run()");
	try
	{
		mScript.loadScript("game.lua");//carrega o game
		mRunning = true;
		
		while(!key[KEY_ESC])
		{
			while(timer >= 0 && !key[KEY_ESC])
			{
				screenShot();
				Gorgon::Video::get().clear(0xAA0BDD);
				if(state==0)
				{
					//executa funcao logic do mal aqui
					mScript.function("GGE_game_runStep");
					Gorgon::Video::get().drawText(10,10,0xFF0000,-1,"FPS: %d",fps_antigo);
					
					if(key[KEY_F2])
					{
						state = 1;
						key[KEY_F2] = 0;
						clear_keybuf();
						ConsoleWindow::get().run();
					}
				}
				else
				{
					ConsoleWindow::get().draw();
					ConsoleWindow::get().logic();
					if(key[KEY_F2])
					{
						ConsoleWindow::get().stop();
						state = 0;
						key[KEY_F2] = 0;
					}
					if(key[KEY_F5])//mandou executar
					{
						key[KEY_F5] = 0;
						mScript.executeString
						(
							ConsoleWindow::get().getText()
						);
					}
				}
		
				//TextWindow::get().show();
				
				Gorgon::Video::get().show();
				--timer;
				++fps;
			}
		}
		mRunning = false;
	}
	catch(Gorgon::Core::Exception e)
	{
		std::cout << e.getMessage() << std::endl;
	}
}

bool Game::isRunning() const
{
	return mRunning;
}
void Game::console(const std::string& pString)
{
	std::cout << pString << std::endl;
	mScript.executeString(pString);
}

