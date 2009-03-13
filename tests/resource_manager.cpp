#include "/home/cantidio/Development/gorgon++/src/graphic/include/gorgon_video.hpp"
#include "include/sprite_manager.hpp"

using namespace ResourceManager;
using namespace Gorgon;
const string base="/home/cantidio/Development/gorgon++";
int main()
{
	allegro_init();
	install_keyboard();
	try
	{
		Video::init("Teste da classe ImagePcx");
		ResourceManager::SpriteManager::load(base+"/examples/resources/klona.gspk");
		ResourceManager::SpriteManager::load(base+"/examples/resources/klona.gspk");
		ResourceManager::SpriteManager::load(base+"/src/graphic/tools/spritePackEditor/bin/baby.gspk");
		ResourceManager::SpriteManager::load(base+"/src/graphic/tools/spritePackEditor/bin/baby.gspk");
		ResourceManager::SpriteManager::load(base+"/src/graphic/tools/spritePackEditor/bin/baby.gspk");
		ResourceManager::SpriteManager::load(base+"/src/graphic/tools/spritePackEditor/bin/baby.gspk");
		ResourceManager::SpriteManager::load(base+"/src/graphic/tools/spritePackEditor/bin/spider.gspk");

		while(!key[KEY_ESC])
		{



		}
	}
	catch(Gorgon::Exception e)
	{
		cout << e.getMessage() << endl;
	}
	ResourceManager::SpriteManager::clear();
	return 0;
}
