#include "../include/game.hpp"
#include "../include/console_window.hpp"
#include <omp.h>

int main()
{
//	Gorgon::Core::Log::init("gge_log.txt");
//	Game::get().init();
//	ConsoleWindow::get();
	Gorgon::Core::Log::init("gge_log.txt");
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			Game::get().run();
		}
/*		#pragma omp section
		{
			std::string a;
			do
			{
				getline(std::cin, a);
				Game::get().console(a);
			}while(Game::get().isRunning() == true);
		}*/
	}

	Game::halt();
	return 0;
}END_OF_MAIN()

