#include "objects/include/object.hpp"

int main()
{
	try
	{
		allegro_init();
		install_keyboard();
		Gorgon::Video::init("Teste inimigo com script");
		Object caterpie("resources/enemy/caterpie.lua",0,50);
		Object klona("resources/enemy/klona.lua",300,100);
		Object klona2("resources/enemy/klona.lua",300,200);
		Object klona3("resources/enemy/klona2.lua",300,210);
		Object klona4("resources/enemy/klona2.lua",0,220);
		Object klona5("resources/enemy/klona2.lua",300,230);

		while(!key[KEY_ESC])
		{
			Gorgon::Video::get()->clear();
			caterpie.logic();
			klona.logic();
			klona2.logic();
			klona3.logic();
			klona4.logic();
			klona5.logic();
			caterpie.draw();
			klona.draw();
			klona2.draw();
			klona3.draw();
			klona4.draw();
			klona5.draw();
			Gorgon::Video::get()->show();
			rest(40);
		}
	}
	catch(Gorgon::Exception e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}
