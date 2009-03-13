#include "../src/objects/include/character.hpp"

int main(int argc, char* argv[])
{
	try
	{
		allegro_init();
		install_keyboard();
		Gorgon::Video::init("Teste Character");
		vector<Character*> objects;
		if(argc>1)
		{
			for(int i=1; i<argc; ++i)
			{
				string a;
				a=argv[i];
				objects.push_back(new Character(a,0,30*i));
				objects[i]->ativate();
			}
		}
		else
		{
			objects.push_back(new Character("resources/character/joao.lua",0,100));
			objects[objects.size()-1]->ativate();
		}
		while(!key[KEY_ESC])
		{
			Gorgon::Video::get()->clear(0xAA0BDD);
			
			for(int i=0; i<objects.size(); objects[i]->logic(),++i);
			
			for(int i=0; i<objects.size(); objects[i]->draw(),++i);
			
			Gorgon::Video::get()->show();
			rest(16);
		}
		for(int i=0; i<objects.size(); ++i)
			delete objects[i];
	}
	catch(Gorgon::Exception e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}

