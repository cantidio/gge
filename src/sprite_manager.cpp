#include "../include/sprite_manager.hpp"

namespace ResourceManager
{
	std::vector<SpriteId> SpriteManager::mTable;

	Gorgon::Graphic::SpritePack& SpriteManager::load(const std::string& pSpritePackName)
	{
		Gorgon::Core::Log::get().writeFormatted("C++ -> SpriteManager::load(\"%s\"): ",pSpritePackName.c_str());
		for(int i = 0; i < mTable.size(); ++i)
		{
			if(mTable[i].fileName == pSpritePackName)
			{
//				Gorgon::Core::Log::get().writeFormatted("C++ -> SpriteManager::load(): SpritePack: \"%s\" found in position: %d",pSpritePackName.c_str(),i);
				Gorgon::Core::Log::get().write(std::string("SpritePack found in table."),true,false);
				++mTable[i].use;
				return *mTable[i].spritePack;
			}
		}
		Gorgon::Core::Log::get().write(std::string("SpritePack not found in table, inserted in new position."),true,false);
		//Gorgon::Core::Log::get().writeFormatted("C++ -> SpriteManager::load(): SpritePack: \"%s\" not found in SpriteManager Table\n",pSpritePackName.c_str());
		//Gorgon::Core::Log::get().writeFormatted("C++ -> SpriteManager::load(): SpritePack: \"%s\" add in SpriteManager Table\n",pSpritePackName.c_str());
		SpriteId spriteId;
		spriteId.use		= 1;
		spriteId.fileName	= pSpritePackName;
		spriteId.spritePack	= new Gorgon::Graphic::SpritePack(pSpritePackName);
		mTable.push_back(spriteId);
		return *spriteId.spritePack;
	}

	void SpriteManager::unload(const std::string& pSpritePackName)
	{
		Gorgon::Core::Log::get().writeFormatted("C++ -> SpriteManager::unload()\n");
		for(int i = 0; i < mTable.size(); ++i)
		{
			if(mTable[i].fileName == pSpritePackName)
			{
				Gorgon::Core::Log::get().writeFormatted("C++ -> SpriteManager::unload(): Reference of SpritePack: \"%s\" removed of SpriteManager Table\n",pSpritePackName.c_str());
				--mTable[i].use;
				if(mTable[i].use <= 0)
				{
					Gorgon::Core::Log::get().writeFormatted("C++ -> SpriteManager::unload(): SpritePack: \"%s\" removed of SpriteManager Table\n",pSpritePackName.c_str());
					delete mTable[i].spritePack;
					mTable.erase(mTable.begin()+i);
				}
				break;
			}
		}
	}

	void SpriteManager::clear()
	{
		Gorgon::Core::Log::get().writeFormatted("C++ -> SpriteManager::clear()\n");
		for(int i = 0; i < mTable.size(); ++i)
		{
			Gorgon::Core::Log::get().writeFormatted("C++ -> SpriteManager::clear(): deleting SpritePack: \"%s\", allocated in position: %d...\n",mTable[i].fileName.c_str(),i);
			delete mTable[i].spritePack;
		}
		mTable.clear();
	}
}
