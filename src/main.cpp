#include "../include/game.hpp"
#include "../include/console_window.hpp"
#include <omp.h>
#include <gorgon++/addon/image_loader/magick++/gorgon_image_loader.hpp>

int main(int argc, char** argv)
{
	Gorgon::Core::Log::init("gge_log.txt");
	Gorgon::ImageLoader::setLoader(new Gorgon::ImageLoaderMagick());	
	Game::instantiate(argc,argv);
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

