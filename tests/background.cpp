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
		Gorgon::Video::init("Teste Player");
		Input::init();
		std::vector<Player*> objects;
		objects.push_back(new Player("data/character/player/lemin.lua",Gorgon::Point(0,100)));
		objects[objects.size()-1]->ativate();
		
		Background* bg=new Background("teste.lua");//createYamattoBackground();

		while(!key[KEY_ESC])
		{
			Gorgon::Video::get()->clear(0xAA0BDD);
			bg->logic();

			for(int i=0; i<objects.size(); objects[i]->logic(),++i);
			bg->draw(*Gorgon::Video::get());
			for(int i=0; i<objects.size(); objects[i]->draw(),++i);
			
			Gorgon::Video::get()->show();
			rest(16);
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


