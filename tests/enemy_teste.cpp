#include "../src/objects/include/object.hpp"

int main(int argc, char* argv[])
{
	try
	{
		allegro_init();
		install_keyboard();
		Gorgon::Video::init("Teste inimigo com script");
		vector<Object*> objects;
		if(argc>1)
		{
			for(int i=1; i<argc; ++i)
			{
				string a;
				a=argv[i];
				objects.push_back(new Object(a,0,30*i));
			}
		}
		else
		{
			objects.push_back(new Object("resources/character/enemy/caterpie.lua",0,30));
			objects.push_back(new Object("resources/character/enemy/klona.lua",300,60));
			objects.push_back(new Object("resources/character/enemy/klona2.lua",300,90));
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
