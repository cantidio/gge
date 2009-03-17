#include "../src/objects/include/player.hpp"

int main(int argc, char* argv[])
{
	try
	{
		allegro_init();
		
		Gorgon::Video::init("Teste Player");
		Input::init();
		vector<Player*> objects;
		if(argc>1)
		{
			for(int i=1; i<argc; ++i)
			{
				string a;
				a=argv[i];
				objects.push_back(new Player(a,0,30*i));
				objects[i]->ativate();
			}
		}
		else
		{
			objects.push_back(new Player("data/character/player/lemin.lua",0,100));
			objects[objects.size()-1]->ativate();
		}
		while(!key[KEY_ESC])
		{
			Gorgon::Video::get()->clear(0xAA0BDD);

			for(int i=0; i<objects.size(); objects[i]->logic(),++i);

			for(int i=0; i<objects.size(); objects[i]->draw(),++i);

			Gorgon::Video::get()->show();
		}
		for(int i=0; i<objects.size(); ++i)
			delete objects[i];
	}
	catch(Gorgon::Exception e)
	{
		cout << e.getMessage() << endl;
	}
	Input::halt();
	return 0;
}


