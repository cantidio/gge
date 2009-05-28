#include "../include/animation_manager.hpp"

namespace ResourceManager
{
	using namespace Gorgon;
	std::vector<AnimationId> AnimationManager::table;
	
	AnimationPack* AnimationManager::load(const std::string& name)
	{
		Gorgon::LogRegister("Cheking the existence of the AnimationPack: \"%s\" ...",name.c_str());
		for(int i=0; i<table.size(); ++i)
		{
			if(table[i].fileName==name)
			{
				Gorgon::LogRegister("AnimationPack found in position: %d",i);
				++table[i].use;
				return table[i].animationPack;
			}
		}
		Gorgon::LogRegister("AnimationPack not found in AnimationManager Table...",name.c_str());
		Gorgon::LogRegister("Putting new SpritePack in AnimationManager Table...",name.c_str());
		AnimationId a;
		a.use		= 1;
		a.fileName	= name;
		a.animationPack= new AnimationPack(name);
		table.push_back(a);
		return a.animationPack;
	}

	void AnimationManager::unload(const std::string& name)
	{
		for(int i=0; i<table.size(); ++i)
		{
			if(table[i].fileName==name)
			{
				--table[i].use;
				if(table[i].use<=0)
				{
					Gorgon::LogRegister("Taking \"%s\" out of AnimationManager Table...",name.c_str());
					delete table[i].animationPack;
					table.erase(table.begin()+i);
				}
				break;
			}
		}
	}

	void AnimationManager::clear()
	{
		for(int i=0; i<table.size(); ++i)
		{
			Gorgon::LogRegister("Deleting animation in table position: %d...",i);
			delete table[i].animationPack;
		}
		table.clear();
	}
}

