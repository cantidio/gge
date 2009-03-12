#include "../include/sprite_manager.hpp"

namespace ResourceManager
{
	vector<SpriteId> SpriteManager::table;

	Gorgon::SpritePack* SpriteManager::load(const string& name)
	{
		for(int i=0; i<table.size(); ++i)
		{
			if(table[i].fileName==name)
			{
				printf("SpritePack: \"%s\" existente na posição: %d\n",name.c_str(),i);
				++table[i].use;
				return table[i].spritePack;
			}
		}
		printf("Criando novo SpritePack: \"%s\"...\n",name.c_str());
		SpriteId a;
		a.use		= 1;
		a.fileName	= name;
		a.spritePack= new Gorgon::SpritePack(name);
		table.push_back(a);
		return a.spritePack;
	}

	void SpriteManager::unload(const string& name)
	{
		for(int i=0; i<table.size(); ++i)
		{
			if(table[i].fileName==name)
			{
				--table[i].use;
				if(table[i].use<=0)
				{
					printf("Liberando recurso: \"%s\"...\n",name.c_str());
					delete table[i].spritePack;
					table.erase(table.begin()+i);
				}
				break;
			}
		}
	}

	void SpriteManager::clear()
	{
		for(int i=0; i<table.size(); ++i)
		{
			printf("deleting: %d\n",i);
			delete table[i].spritePack;
		}
		table.clear();
	}
}

