#include "../include/sprite_manager.hpp"

namespace ResourceManager
{
	using namespace Gorgon;
	std::vector<SpriteId> SpriteManager::mTable;

	Gorgon::SpritePack& SpriteManager::load(const std::string& pSpritePackName)
	{
		Gorgon::Log::get().RegisterFormated("C++ -> SpriteManager::load()");
		for(int i = 0; i < mTable.size(); ++i)
		{
			if(mTable[i].fileName == pSpritePackName)
			{
				Gorgon::Log::get().RegisterFormated("C++ -> SpriteManager::load(): SpritePack: \"%s\" found in position: %d",pSpritePackName.c_str(),i);
				++mTable[i].use;
				return *mTable[i].spritePack;
			}
		}
		Gorgon::Log::get().RegisterFormated("C++ -> SpriteManager::load(): SpritePack: \"%s\" not found in SpriteManager Table",pSpritePackName.c_str());
		Gorgon::Log::get().RegisterFormated("C++ -> SpriteManager::load(): SpritePack: \"%s\" add in SpriteManager Table",pSpritePackName.c_str());
		SpriteId spriteId;
		spriteId.use		= 1;
		spriteId.fileName	= pSpritePackName;
		spriteId.spritePack	= new Gorgon::SpritePack(pSpritePackName);
		mTable.push_back(spriteId);
		return *spriteId.spritePack;
	}

	void SpriteManager::unload(const std::string& pSpritePackName)
	{
		Gorgon::Log::get().RegisterFormated("C++ -> SpriteManager::unload()");
		for(int i = 0; i < mTable.size(); ++i)
		{
			if(mTable[i].fileName == pSpritePackName)
			{
				Gorgon::Log::get().RegisterFormated("C++ -> SpriteManager::unload(): Reference of SpritePack: \"%s\" removed of SpriteManager Table",pSpritePackName.c_str());
				--mTable[i].use;
				if(mTable[i].use <= 0)
				{
					Gorgon::Log::get().RegisterFormated("C++ -> SpriteManager::unload(): SpritePack: \"%s\" removed of SpriteManager Table",pSpritePackName.c_str());
					delete mTable[i].spritePack;
					mTable.erase(mTable.begin()+i);
				}
				break;
			}
		}
	}

	void SpriteManager::clear()
	{
		Gorgon::Log::get().RegisterFormated("C++ -> SpriteManager::clear()");
		for(int i = 0; i < mTable.size(); ++i)
		{
			Gorgon::Log::get().RegisterFormated("C++ -> SpriteManager::clear(): deleting SpritePack: \"%s\", allocated in position: %d...",mTable[i].fileName.c_str(),i);
			delete mTable[i].spritePack;
		}
		mTable.clear();
	}
}
