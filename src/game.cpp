#include "../include/game.hpp"
#include "../include/console_window.hpp"
#include <allegro5/allegro.h>
//#include <gorgon++/addon/image_loader/gorgon++/include/gorgon_image_loader_autodetect.hpp>


//-------------------------------------------------------------------------------TIMER--------------------------------------
int fps			= 0;
int fps_antigo	= 0;
int timer		= 0;
void frame_rate()	{ fps_antigo = fps; fps = 0; }
void game_time()	{ ++timer; }

//-------------------------------------------------------------------------------TIMER UP------------------------------------

void trySaveScreenShot(const int& pShotNumber)
{
	/*std::stringstream out;
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
		Gorgon::Core::Log::get().writeFormatted("C++ -> ScreenShot saved: %s",out.str().c_str());
	}*/
}

void screenShot()
{
	if( 0 )
	{
		Gorgon::Core::Log::get().write(std::string("C++ -> Trying to take a Screenshot..."));
		trySaveScreenShot(0);

	}
}

//-----------------------------------------------------------------------------------------------------------------
Game* Game::mSingleton = NULL;
Game::Game(int pArgc, char** pArgv)
{
	Gorgon::Core::Log::get().write(std::string("C++ -> Game::Game()"));
	if(pArgv != NULL)
	{
		for(int i = 0; i < pArgc; ++i)
		{
			if(pArgv[i] != NULL)
			{
				mArgs.push_back(pArgv[i]);
			}
		}
	}
	registerLuaFunctions();
}

std::vector<std::string> Game::getArgs() const
{
	return mArgs;
}

Game::~Game()
{
	Gorgon::Core::Log::get().write(std::string("C++ -> Game::~Game()"));
	Input::halt();
	ResourceManager::SpriteManager::clear();
	ResourceManager::AnimationManager::clear();

	delete mKeyboard;
	delete mDisplay;
}

void Game::instantiate(int pArgc, char** pArgv)
{
	if(mSingleton == NULL)
	{
		mSingleton = new Game(pArgc, pArgv);
	}
}

Game& Game::get()
{
	instantiate();
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
	Gorgon::Core::Log::get().writeFormatted
	(
		"C++ -> Game::init()\n\
			\t\t\t\tpWindowTitle: %s\n\
			\t\t\t\tpWidth:       %d\n\
			\t\t\t\tpHeight:      %d\n\
			\t\t\t\tFullscreen:   %d\n",
		pWindowTitle.c_str(),
		pWidth,pHeight,
		(int)pFullScreen
	);

    mDisplay    = new Gorgon::Graphic::Display( pWindowTitle, pWidth, pHeight, pFullScreen );
	mKeyboard   = new Gorgon::Input::Keyboard();
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
	Gorgon::Core::Log::get().write(std::string("C++ -> Game::registerLuaFunctions()"));

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
	Gorgon::Core::Log::get().write(std::string("C++ -> Game::run()"));
	try
	{
		mScript.loadScript("game.lua");//carrega o game
		mRunning = true;

		while(1)
		{
		    mKeyboard->update();
		    Input::get().update();
			if( mKeyboard->getKey( Gorgon::Input::Key::ESCAPE ).isPressed() )
			{
				break;
			}
			else if( mKeyboard->getKey( Gorgon::Input::Key::LEFT_ALT ).isPressed() && mKeyboard->getKey( Gorgon::Input::Key::ENTER ).isPressed() )
			{
				mDisplay->toogleFullScreen();
			}


            screenShot();
            mDisplay->clear( Gorgon::Graphic::Color( 0, 0, 0, 0 ) );
            if(state == 0)
            {
                //executa funcao logic do mal aqui
                mScript.function("GGE_game_runStep");
                //Gorgon::Graphic::Video::get().drawText(Gorgon::Core::Point(10,10),0xFF0000,-1,"FPS: %d",fps_antigo);

               if( 0 )//key[KEY_F2])
                {
                    state = 1;
//                    key[KEY_F2] = 0;
  //                  clear_keybuf();
                    ConsoleWindow::get().run();
                }
            }
            else
            {
             /*   ConsoleWindow::get().draw();
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
                }*/
            }

            //TextWindow::get().show();

            mDisplay->swapBuffers();

			al_rest(0.01);

            --timer;
            ++fps;

		}
		mRunning = false;
	}
	catch(Gorgon::Core::Exception& exception)
	{
		throw exception;
	}
}

bool Game::isRunning() const
{
	return mRunning;
}

int Game::getWidth() const
{
    mDisplay->getWidth();
}

int Game::getHeight() const
{
    mDisplay->getHeight();
}
