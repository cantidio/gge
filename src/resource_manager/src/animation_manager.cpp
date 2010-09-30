#include "../include/animation_manager.hpp"

namespace ResourceManager
{
	using namespace Gorgon;
	std::vector<AnimationId> AnimationManager::mTable;
	
	AnimationPack& AnimationManager::load(const std::string& pAnimationPackName)
	{
		Gorgon::LogRegister("Cheking the existence of the AnimationPack: \"%s\" ...",pAnimationPackName.c_str());
		for(int i=0; i<mTable.size(); ++i)
		{
			if(mTable[i].fileName==pAnimationPackName)
			{
				Gorgon::LogRegister("AnimationPack found in position: %d",i);
				++mTable[i].use;
				return mTable[i].animationPack;
			}
		}
		Gorgon::LogRegister("AnimationPack not found in AnimationManager Table...",pAnimationPackName.c_str());
		Gorgon::LogRegister("Putting new SpritePack in AnimationManager Table...",pAnimationPackName.c_str());
		AnimationId animationId;
		animationId.use				= 1;
		animationId.fileName		= pAnimationPackName;
		animationId.animationPack	= new AnimationPack(pAnimationPackName);
		mTable.push_back(animationId);
		return *animationId.animationPack;
	}

	void AnimationManager::unload(const std::string& pAnimationPackName)
	{
		for(int i=0; i<mTable.size(); ++i)
		{
			if(mTable[i].fileName==pAnimationPackName)
			{
				--mTable[i].use;
				if(mTable[i].use<=0)
				{
					Gorgon::LogRegister("Taking \"%s\" out of AnimationManager Table...",pAnimationPackName.c_str());
					delete mTable[i].animationPack;
					mTable.erase(mTable.begin()+i);
				}
				break;
			}
		}
	}

	void AnimationManager::clear()
	{
		for(int i=0; i<mTable.size(); ++i)
		{
			Gorgon::LogRegister("Deleting animation in table position: %d: %s...",i,mTable[i].fileName.c_str());
			delete mTable[i].animationPack;
		}
		mTable.clear();
	}
}

