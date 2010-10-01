#include "../include/animation_manager.hpp"

namespace ResourceManager
{
	using namespace Gorgon;
	std::vector<AnimationId> AnimationManager::mTable;
	
	AnimationPack& AnimationManager::load(const std::string& pAnimationPackName)
	{
		Gorgon::Log::get()->RegisterFormated("C++ -> AnimationManager::load()");
		for(int i = 0; i < mTable.size(); ++i)
		{
			if(mTable[i].fileName == pAnimationPackName)
			{
				Gorgon::Log::get()->RegisterFormated("C++ -> AnimationManager::load(): AnimationPack: \"%s\" found in position: %d",pAnimationPackName.c_str(), i);
				++mTable[i].use;
				return *mTable[i].animationPack;
			}
		}
		Gorgon::Log::get()->RegisterFormated("C++ -> AnimationManager::load(): AnimationPack: \"%s\" not found in AnimationManager Table",pAnimationPackName.c_str());
		Gorgon::Log::get()->RegisterFormated("C++ -> AnimationManager::load(): AnimationPack: \"%s\" add in AnimationManager Table",pAnimationPackName.c_str());
		AnimationId animationId;
		animationId.use				= 1;
		animationId.fileName		= pAnimationPackName;
		animationId.animationPack	= new AnimationPack(pAnimationPackName);
		mTable.push_back(animationId);
		return *animationId.animationPack;
	}

	void AnimationManager::unload(const std::string& pAnimationPackName)
	{
		Gorgon::Log::get()->RegisterFormated("C++ -> AnimationManager::unload()");
		for(int i = 0; i < mTable.size(); ++i)
		{
			if(mTable[i].fileName == pAnimationPackName)
			{
				Gorgon::Log::get()->RegisterFormated("C++ -> AnimationManager::unload(): Reference of AnimationPack: \"%s\" removed of AnimationManager Table",pAnimationPackName.c_str());
				--mTable[i].use;
				if(mTable[i].use<=0)
				{
					Gorgon::Log::get()->RegisterFormated("C++ -> AnimationManager::unload(): AnimationPack: \"%s\" removed of AnimationManager Table",pAnimationPackName.c_str());
					delete mTable[i].animationPack;
					mTable.erase(mTable.begin()+i);
				}
				break;
			}
		}
	}

	void AnimationManager::clear()
	{
		Gorgon::Log::get()->RegisterFormated("C++ -> AnimationManager::clear()");
		for(int i = 0; i < mTable.size(); ++i)
		{
			Gorgon::Log::get()->RegisterFormated("C++ -> AnimationManager::clear(): deleting AnimationPack: \"%s\", allocated in position: %d...",mTable[i].fileName.c_str(),i);
			delete mTable[i].animationPack;
		}
		mTable.clear();
	}
}

