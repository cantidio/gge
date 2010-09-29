#include <sstream>
#include <gorgon++/gorgon.hpp>
#include "background/include/background.hpp"
#include "objects/include/player.hpp"
#include "core/include/text_window.hpp"
#include "background.hpp"

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


void trySaveScreenShot(const int& pShotNumber)
{
	std::stringstream out;
	out << "shots/shot" << pShotNumber << ".bmp" << std::endl;
	Gorgon::File file(out.str(),std::ios::in | std::ios::binary);
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
	}
}

void screenShot()
{
	if(key[KEY_P])
	{
		trySaveScreenShot(0);
		key[KEY_P] = 0;
	}
}

int main(int argc, char* argv[])
{
	try
	{
		allegro_init();
		LOCK_VARIABLE(timer);
		LOCK_FUNCTION(game_time);
		install_int( frame_rate, 1000 );
		install_int_ex(game_time, BPS_TO_TIMER(60));
		Gorgon::Log::init("log.txt");
		//Gorgon::Video::init("Teste Player",320,180,false);
		Gorgon::Video::init("Teste GGE",320,240,true);


		Input::init();
		std::vector<Object*> objects;

		//objects.push_back(new Player("data/character/enemy/frozen_shade/frozen_shade.lua",Gorgon::Point(150,200)));
		objects.push_back(new Player("Lemin/lemin.lua",Gorgon::Point(20,220)));
		//objects.push_back(new Player("data/character/player/mature.lua",Gorgon::Point(150,200)));

		for(int i = 0; i < objects.size(); ++i)
		{
			objects[i]->activate();
		}
		//Background* bg = new Background("data/background/breakman/breakman_background.lua");
		Background* bg = new Background("tests/background/breakman/breakman_background.lua");
		objects[0]->setLayer(&(*bg)[0]);

		while(!key[KEY_ESC])
		{
			while(timer >= 0 && !key[KEY_ESC])
			{
				screenShot();
				Gorgon::Video::get().clear(0xAA0BDD);
				bg->logic();

				for(int i = 0; i < objects.size(); ++i){	objects[i]->logic();	}
				bg->draw(Gorgon::Video::get());
				for(int i = 0; i < objects.size(); ++i){	objects[i]->draw();		}

				Gorgon::Video::get().drawText(10,10,0,-1,"FPS: %d",fps_antigo);

				
				TextWindow::get().show();
				Gorgon::Video::get().show();
				--timer;
				++fps;
			}
		}
		for(int i = 0; i < objects.size(); ++i)
		{
			delete objects[i];
		}
	}
	catch(Gorgon::Exception e)
	{
		std::cout << e.getMessage() << std::endl;
	}
	Input::halt();
	return 0;
}END_OF_MAIN()
