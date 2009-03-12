#include "../include/animation_manager.hpp"

namespace ResourceManager
{
	using namespace Gorgon;
	vector<AnimationId> AnimationManager::table;	
	
	AnimationPack* AnimationManager::load(const string& name)
	{
		for(int i=0; i<table.size(); ++i)
		{
			if(table[i].fileName==name)
			{
				++table[i].use;
				return table[i].animationPack;
			}
		}
		AnimationId a;
		a.use		= 1;
		a.fileName	= name;
		a.animationPack= new AnimationPack(name);
		table.push_back(a);
		return a.animationPack;
	}

	void AnimationManager::unload(const string& name)
	{
		for(int i=0; i<table.size(); ++i)
		{
			if(table[i].fileName==name)
			{
				--table[i].use;
				if(table[i].use<=0)
				{
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
			delete table[i].animationPack;
		}
		table.clear();
	}
}

