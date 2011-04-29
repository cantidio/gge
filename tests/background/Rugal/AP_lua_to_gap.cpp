#include <gorgon++/gorgon.hpp>
#include <gorgon++/addons/animationpack/animationpack_lua.hpp>

int main(int argc, char** argv)
{
	if(argc == 3 )
	{
		AnimationPackLua a(argv[1]);
		AnimationPack b(a);
		b.save(argv[2]);
	}
	else
	{
		printf("usage: ./animationpack_lua_to_gorgon.e anim.lua anim.gap\n");
	}
	return 0;
}
