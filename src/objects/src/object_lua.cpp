#include "../include/object_lua.hpp"
#define ObjectObj() int pointer=lua_tointeger(state,1); Object* object=(Object*)pointer;

namespace ObjectLua
{
	int lua_changeAnimation(lua_State* state)
	{
		ObjectObj();
		object->changeAnimation((int)lua_tointeger(state,2));
		return 0;
	}

	int lua_animationIsPlaying(lua_State* state)
	{
		ObjectObj();
		lua_pushboolean(state,object->animationIsPlaying());
		return 1;
	}

	int lua_getAnimationOn(lua_State* state)
	{
		ObjectObj();
		lua_pushnumber(state,object->getAnimationOn());
		return 1;
	}

	int lua_getFrameOn(lua_State* state)
	{
		ObjectObj();
		lua_pushnumber(state,object->getFrameOn());
		return 1;
	}

	int lua_getXPosition(lua_State* state)
	{
		ObjectObj();
		lua_pushnumber(state,object->getXPosition());
		return 1;
	}

	int lua_getYPosition(lua_State* state)
	{
		ObjectObj();
		lua_pushnumber(state,object->getYPosition());
		return 1;
	}


	int lua_setXPosition(lua_State* state)
	{
		ObjectObj();
		object->setXPosition(lua_tonumber(state,2));
		return 0;
	}

	int lua_setYPosition(lua_State* state)
	{
		ObjectObj();
		object->setYPosition(lua_tonumber(state,2));
		return 0;
	}

	int lua_setPosition(lua_State* state)
	{
		ObjectObj();
		object->setPosition
		(
			Gorgon::Point
			(
				lua_tonumber(state,2),
				lua_tonumber(state,3)
			)
		);
		return 0;
	}

	int lua_addXPosition(lua_State* state)
	{
		ObjectObj();
		object->addXPosition(lua_tonumber(state,2));
		return 0;
	}

	int lua_addYPosition(lua_State* state)
	{
		ObjectObj();
		object->addYPosition(lua_tonumber(state,2));
		return 0;
	}

	int lua_addPosition(lua_State* state)
	{
		ObjectObj();
		object->addPosition
		(
			lua_tonumber(state,2),
			lua_tonumber(state,3)
		);
		return 0;
	}

	int lua_subXPosition(lua_State* state)
	{
		ObjectObj();
		object->subXPosition(lua_tonumber(state,2));
		return 0;
	}

	int lua_subYPosition(lua_State* state)
	{
		ObjectObj();
		object->subYPosition(lua_tonumber(state,2));
		return 0;
	}

	int lua_subPosition(lua_State* state)
	{
		ObjectObj();
		object->subPosition
		(
			lua_tonumber(state,2),
			lua_tonumber(state,3)
		);
		return 0;
	}

	int lua_setMirroring(lua_State* state)
	{
		ObjectObj();
		switch((int)lua_tointeger(state,2))
		{
			case 0:		object->setMirroring(Gorgon::Mirroring::Normal);	break;
			case 1:		object->setMirroring(Gorgon::Mirroring::HFlip);		break;
			case 2:		object->setMirroring(Gorgon::Mirroring::VFlip);		break;
			default:	object->setMirroring(Gorgon::Mirroring::VHFlip);	break;
		}
		return 0;
	}

	int lua_getMirroring(lua_State* state)
	{
		ObjectObj();
		switch(object->getMirroring().getType())
		{
			case Gorgon::Mirroring::Normal: lua_pushnumber(state,0);	break;
			case Gorgon::Mirroring::HFlip:	lua_pushnumber(state,1);	break;
			case Gorgon::Mirroring::VFlip:	lua_pushnumber(state,2);	break;
			default:						lua_pushnumber(state,3);	break;
		}
		return 1;
	}

	void registerFunctions(Gorgon::Lua* script)
	{
		script->registerFunction("lua_changeAnimation",lua_changeAnimation);
		script->registerFunction("lua_animationIsPlaying",lua_animationIsPlaying);
		script->registerFunction("lua_getAnimationOn",lua_getAnimationOn);
		script->registerFunction("lua_getFrameOn",lua_getFrameOn);
		script->registerFunction("lua_getXPosition",lua_getXPosition);
		script->registerFunction("lua_getYPosition",lua_getYPosition);
		script->registerFunction("lua_setXPosition",lua_setXPosition);
		script->registerFunction("lua_setYPosition",lua_setYPosition);
		script->registerFunction("lua_setPosition",lua_setPosition);
		script->registerFunction("lua_addXPosition",lua_addXPosition);
		script->registerFunction("lua_addYPosition",lua_addYPosition);
		script->registerFunction("lua_addPosition",lua_addPosition);
		script->registerFunction("lua_subXPosition",lua_subXPosition);
		script->registerFunction("lua_subYPosition",lua_subYPosition);
		script->registerFunction("lua_subPosition",lua_subPosition);
		script->registerFunction("lua_setMirroring",lua_setMirroring);
		script->registerFunction("lua_getMirroring",lua_getMirroring);
	}
}
