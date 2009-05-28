#include "../include/sprite_manager.hpp"

namespace ResourceManager
{
	std::vector<SpriteId> SpriteManager::table;

	Gorgon::SpritePack* SpriteManager::load(const std::string& name)
	{
		Gorgon::LogRegister("Cheking the existence of the SpritePack: \"%s\" ...",name.c_str());
		for(int i=0; i<table.size(); ++i)
		{
			if(table[i].fileName==name)
			{
				Gorgon::LogRegister("SpritePack found in position: %d",i);
				++table[i].use;
				return table[i].spritePack;
			}
		}
		Gorgon::LogRegister("SpritePack not found in SpriteManager Table...",name.c_str());
		Gorgon::LogRegister("Putting new SpritePack in SpriteManager Table...",name.c_str());
		SpriteId a;
		a.use		= 1;
		a.fileName	= name;
		a.spritePack= new Gorgon::SpritePack(name);
		table.push_back(a);
		return a.spritePack;
	}

	void SpriteManager::unload(const std::string& name)
	{
		for(int i=0; i<table.size(); ++i)
		{
			if(table[i].fileName==name)
			{
				--table[i].use;
				if(table[i].use<=0)
				{
					Gorgon::LogRegister("Taking \"%s\" out of SpriteManager Table...",name.c_str());
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
			Gorgon::LogRegister("Deleting sprite in table position: %d...",i);
			delete table[i].spritePack;
		}
		table.clear();
	}
}
