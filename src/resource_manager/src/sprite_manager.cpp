#include "../include/sprite_manager.hpp"

namespace ResourceManager
{
	std::vector<SpriteId> SpriteManager::mTable;

	Gorgon::SpritePack* SpriteManager::load(const std::string& pSpritePackName)
	{
		Gorgon::LogRegister("Cheking the existence of the SpritePack: \"%s\" ...",pSpritePackName.c_str());
		for(int i=0; i<mTable.size(); ++i)
		{
			if(mTable[i].fileName==pSpritePackName)
			{
				Gorgon::LogRegister("SpritePack found in position: %d",i);
				++mTable[i].use;
				return mTable[i].spritePack;
			}
		}
		Gorgon::LogRegister("SpritePack not found in SpriteManager Table...",pSpritePackName.c_str());
		Gorgon::LogRegister("Putting new SpritePack in SpriteManager Table...",pSpritePackName.c_str());
		SpriteId spriteId;
		spriteId.use		= 1;
		spriteId.fileName	= pSpritePackName;
		spriteId.spritePack	= new Gorgon::SpritePack(pSpritePackName);
		mTable.push_back(spriteId);
		return spriteId.spritePack;
	}

	void SpriteManager::unload(const std::string& pSpritePackName)
	{
		for(int i=0; i<mTable.size(); ++i)
		{
			if(mTable[i].fileName==pSpritePackName)
			{
				--mTable[i].use;
				if(mTable[i].use<=0)
				{
					Gorgon::LogRegister("Taking \"%s\" out of SpriteManager Table...",pSpritePackName.c_str());
					delete mTable[i].spritePack;
					mTable.erase(mTable.begin()+i);
				}
				break;
			}
		}
	}

	void SpriteManager::clear()
	{
		for(int i=0; i<mTable.size(); ++i)
		{
			Gorgon::LogRegister("Deleting sprite in table position: %d: %s...",i,mTable[i].fileName.c_str());
			delete mTable[i].spritePack;
		}
		mTable.clear();
	}
}
