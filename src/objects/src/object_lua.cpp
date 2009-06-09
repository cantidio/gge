#include "../include/object_lua.hpp"

namespace ObjectLua
{
	inline Object* getObjectPointer(lua_State* pState)
	{
		return (Object*)lua_tointeger(pState,1);
	}
	
	int lua_changeAnimationByIndex(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->changeAnimation((int)lua_tointeger(pState,2));
		return 0;
	}

	int lua_changeAnimation(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->changeAnimation
		(
			(int)lua_tointeger(pState,2),
			(int)lua_tointeger(pState,3)
		);
		return 0;
	}

	int lua_animationIsPlaying(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushboolean(pState,object->animationIsPlaying());
		return 1;
	}

	int lua_getAnimationOn(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber(pState,object->getAnimationOn());
		return 1;
	}

	int lua_getFrameOn(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber(pState,object->getFrameOn());
		return 1;
	}

	int lua_getXPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber(pState,object->getXPosition());
		return 1;
	}

	int lua_getYPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber(pState,object->getYPosition());
		return 1;
	}


	int lua_setXPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->setXPosition(lua_tonumber(pState,2));
		return 0;
	}

	int lua_setYPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->setYPosition(lua_tonumber(pState,2));
		return 0;
	}

	int lua_setPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->setPosition
		(
			Gorgon::Point
			(
				lua_tonumber(pState,2),
				lua_tonumber(pState,3)
			)
		);
		return 0;
	}

	int lua_addXPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->addXPosition(lua_tonumber(pState,2));
		return 0;
	}

	int lua_addYPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->addYPosition(lua_tonumber(pState,2));
		return 0;
	}

	int lua_addPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->addPosition
		(
			lua_tonumber(pState,2),
			lua_tonumber(pState,3)
		);
		return 0;
	}

	int lua_subXPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->subXPosition(lua_tonumber(pState,2));
		return 0;
	}

	int lua_subYPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->subYPosition(lua_tonumber(pState,2));
		return 0;
	}

	int lua_subPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->subPosition
		(
			lua_tonumber(pState,2),
			lua_tonumber(pState,3)
		);
		return 0;
	}

	int lua_setMirroring(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		switch((int)lua_tointeger(pState,2))
		{
			case 0:		object->setMirroring(Gorgon::Mirroring::Normal);	break;
			case 1:		object->setMirroring(Gorgon::Mirroring::HFlip);		break;
			case 2:		object->setMirroring(Gorgon::Mirroring::VFlip);		break;
			default:	object->setMirroring(Gorgon::Mirroring::VHFlip);	break;
		}
		return 0;
	}

	int lua_getMirroring(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		switch(object->getMirroring().getType())
		{
			case Gorgon::Mirroring::Normal: lua_pushnumber(pState,0);	break;
			case Gorgon::Mirroring::HFlip:	lua_pushnumber(pState,1);	break;
			case Gorgon::Mirroring::VFlip:	lua_pushnumber(pState,2);	break;
			default:						lua_pushnumber(pState,3);	break;
		}
		return 1;
	}

	void registerFunctions(Gorgon::Lua* pScript)
	{
		pScript->registerFunction("lua_changeAnimation",lua_changeAnimation);
		pScript->registerFunction("lua_changeAnimationByIndex",lua_changeAnimationByIndex);
		pScript->registerFunction("lua_animationIsPlaying",lua_animationIsPlaying);
		pScript->registerFunction("lua_getAnimationOn",lua_getAnimationOn);
		pScript->registerFunction("lua_getFrameOn",lua_getFrameOn);
		pScript->registerFunction("lua_getXPosition",lua_getXPosition);
		pScript->registerFunction("lua_getYPosition",lua_getYPosition);
		pScript->registerFunction("lua_setXPosition",lua_setXPosition);
		pScript->registerFunction("lua_setYPosition",lua_setYPosition);
		pScript->registerFunction("lua_setPosition",lua_setPosition);
		pScript->registerFunction("lua_addXPosition",lua_addXPosition);
		pScript->registerFunction("lua_addYPosition",lua_addYPosition);
		pScript->registerFunction("lua_addPosition",lua_addPosition);
		pScript->registerFunction("lua_subXPosition",lua_subXPosition);
		pScript->registerFunction("lua_subYPosition",lua_subYPosition);
		pScript->registerFunction("lua_subPosition",lua_subPosition);
		pScript->registerFunction("lua_setMirroring",lua_setMirroring);
		pScript->registerFunction("lua_getMirroring",lua_getMirroring);
	}
}
