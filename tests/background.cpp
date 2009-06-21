#include "../src/background/include/background.hpp"
#include "../../gorgon++/src/core/include/gorgon_log.hpp"
#include "../src/objects/include/player.hpp"

#include "background.hpp"

int main(int argc, char* argv[])
{
	try
	{
		allegro_init();
		Gorgon::Log::init("log.txt");
		Gorgon::Video::init("Teste Player",320,240,true);
		Input::init();
		std::vector<Player*> objects;
		//objects.push_back(new Player("data/character/player/mature.lua",Gorgon::Point(150,250)));

		objects.push_back(new Player("data/character/enemy/frozen_shade/frozen_shade.lua",Gorgon::Point(150,250)));
		objects[objects.size()-1]->ativate();
		
		Background* bg = new Background("teste.lua");

		while(!key[KEY_ESC])
		{
			Gorgon::Video::get().clear(0xAA0BDD);
			bg->logic();

			for(int i = 0; i < objects.size(); ++i)
			{
				objects[i]->logic();
			}
			bg->draw(Gorgon::Video::get());

			for(int i = 0; i < objects.size(); ++i)
			{
				objects[i]->draw();
			}
			
			Gorgon::Video::get().show();
			rest(1);
		}
		for(int i=0; i<objects.size(); ++i)
			delete objects[i];
	}
	catch(Gorgon::Exception e)
	{
		std::cout << e.getMessage() << std::endl;
	}
	Input::halt();
	return 0;
}


