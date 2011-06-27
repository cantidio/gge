#include "../include/game.hpp"
#include "../include/console_window.hpp"
#include <omp.h>
#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/allegro5/graphic/system.hpp>
#include <gorgon++/addon/allegro5/input/system.hpp>

int main(int argc, char** argv)
{
	try
	{
		Gorgon::Core::Log::init("gge_log.txt");

	 	Gorgon::Graphic::Addon::System::set();
		Gorgon::Input::Addon::System::set();

		Game::instantiate(argc, argv);
//		#pragma omp parallel sections
//		{
//			#pragma omp section
//			{
				Game::get().run();
//			}
/*			#pragma omp section
			{
				std::string a;
				do
				{
					getline(std::cin, a);
					Game::get().console(a);
				}while(Game::get().isRunning() == true);
		}*/
//		}
		Game::halt();
	}
	catch(Gorgon::Core::Exception& exception)
	{
		exception.writeInLog();
		std::cout << "Exception Ocurred while running the game. See gge_log.txt for further details." << std::endl;
	}
	return 0;
}

