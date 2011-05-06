#include "../include/animation_manager.hpp"

namespace ResourceManager
{
	std::vector<AnimationId> AnimationManager::mTable;
	
	Gorgon::Graphic::AnimationPack& AnimationManager::load(const std::string& pAnimationPackName)
	{
		int i;
//		Gorgon::Core::Log::get().RegisterFormated("C++ -> AnimationManager::load()");
		Gorgon::Core::Log::get().writeFormatted("C++ -> AnimationManager::load(\"%s\"): ",pAnimationPackName.c_str());
		for(i = 0; i < mTable.size(); ++i)
		{
			if(mTable[i].fileName == pAnimationPackName)
			{
				//Gorgon::Core::Log::get().writeFormatted("AnimationPack found: in position: %d.\n", i);
				Gorgon::Core::Log::get().write(std::string("AnimationPack found in table."),true,false);
				++mTable[i].use;
				return *mTable[i].animationPack;
			}
		}
		//Gorgon::Core::Log::get().writeFormatted("AnimationPack not found in table, inserted in position: %d.\n", i);
		Gorgon::Core::Log::get().write(std::string("AnimationPack not found in table, inserted in new position."),true,false);
		//Gorgon::Core::Log::get().writeFormatted("C++ -> AnimationManager::load(): AnimationPack: \"%s\" not found in AnimationManager Table\n",pAnimationPackName.c_str());
		//Gorgon::Core::Log::get().writeFormatted("C++ -> AnimationManager::load(): AnimationPack: \"%s\" add in AnimationManager Table\n",pAnimationPackName.c_str());
		AnimationId animationId;
		animationId.use				= 1;
		animationId.fileName		= pAnimationPackName;
		animationId.animationPack	= new Gorgon::Graphic::AnimationPack(pAnimationPackName);
		mTable.push_back(animationId);
		return *animationId.animationPack;
	}

	void AnimationManager::unload(const std::string& pAnimationPackName)
	{
		Gorgon::Core::Log::get().writeFormatted("C++ -> AnimationManager::unload()\n");
		for(int i = 0; i < mTable.size(); ++i)
		{
			if(mTable[i].fileName == pAnimationPackName)
			{
				Gorgon::Core::Log::get().writeFormatted("C++ -> AnimationManager::unload(): Reference of AnimationPack: \"%s\" removed of AnimationManager Table\n",pAnimationPackName.c_str());
				--mTable[i].use;
				if(mTable[i].use<=0)
				{
					Gorgon::Core::Log::get().writeFormatted("C++ -> AnimationManager::unload(): AnimationPack: \"%s\" removed of AnimationManager Table\n",pAnimationPackName.c_str());
					delete mTable[i].animationPack;
					mTable.erase(mTable.begin()+i);
				}
				break;
			}
		}
	}

	void AnimationManager::clear()
	{
		Gorgon::Core::Log::get().writeFormatted("C++ -> AnimationManager::clear()\n");
		for(int i = 0; i < mTable.size(); ++i)
		{
			Gorgon::Core::Log::get().writeFormatted("C++ -> AnimationManager::clear(): deleting AnimationPack: \"%s\", allocated in position: %d...\n",mTable[i].fileName.c_str(),i);
			delete mTable[i].animationPack;
		}
		mTable.clear();
	}
}

