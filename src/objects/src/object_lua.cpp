#include "../include/object_lua.hpp"
#include "../../background/include/background_lua.hpp"
#include "../../background/include/layer_lua.hpp"
#include "../../background/include/tile_lua.hpp"

namespace ObjectLua
{
	inline Object* getObjectPointer(lua_State* pState)
	{
		return (Object*)lua_tointeger(pState,1);
	}

	int lua_isActive(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushboolean(pState,object->isActive());
		return 1;
	}

	int lua_activate(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->activate();
	}

	int lua_inactivate(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->inactivate();
	}

	int lua_getAnimationRealIndex(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber
		(
			pState,
			object->getAnimationRealIndex
			(
				(int)lua_tointeger(pState,2),
				(int)lua_tointeger(pState,3)
			)
		);
		return 1;
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

	int lua_getPosition(lua_State* pState)
	{
		Object*				object		= getObjectPointer(pState);
		const Gorgon::Point	position	= object->getPosition();
		lua_pushnumber(pState,position.getX());
		lua_pushnumber(pState,position.getY());
		return 2;
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

	int lua_addPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->addPosition
		(
			Gorgon::Point
			(
				lua_tonumber(pState,2),
				lua_tonumber(pState,3)
			)
		);
		return 0;
	}

	int lua_subPosition(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->subPosition
		(
			Gorgon::Point
			(
				lua_tonumber(pState,2),
				lua_tonumber(pState,3)
			)
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

	int lua_getLayer(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber(pState,(int)object->getLayer());
		return 1;
	}

	int lua_setAfterImageMethodNormal(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->setAfterImageMethodNormal();
		return 0;
	}

	int lua_setAfterImageMethodAdd(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->setAfterImageMethodAdd
		(
			Gorgon::Color
			(
				lua_tonumber(pState,2),
				lua_tonumber(pState,3),
				lua_tonumber(pState,4)
			),
			Gorgon::Color
			(
				lua_tonumber(pState,5),
				lua_tonumber(pState,6),
				lua_tonumber(pState,7)
			),
			lua_tonumber(pState,8)
		);
		return 0;
	}

	int lua_setAfterImageMethodTrans(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->setAfterImageMethodTrans(lua_tonumber(pState,2));
		return 0;
	}

	int lua_setAfterImageMode(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->setAfterImageMode
		(
			lua_toboolean(pState,2),
			lua_tonumber(pState,3),
			lua_tonumber(pState,4)
		);
		return 0;
	}

	void registerFunctions(Gorgon::Lua* pScript)
	{

		pScript->registerFunction("lua_object_isActive",lua_isActive);
		pScript->registerFunction("lua_object_activate",lua_activate);
		pScript->registerFunction("lua_object_inactivate",lua_inactivate);

		pScript->registerFunction("lua_object_getAnimationRealIndex",lua_getAnimationRealIndex);
		pScript->registerFunction("lua_object_changeAnimation",lua_changeAnimation);
		pScript->registerFunction("lua_object_changeAnimationByIndex",lua_changeAnimationByIndex);
		pScript->registerFunction("lua_object_animationIsPlaying",lua_animationIsPlaying);
		pScript->registerFunction("lua_object_getAnimationOn",lua_getAnimationOn);
		pScript->registerFunction("lua_object_getFrameOn",lua_getFrameOn);
		pScript->registerFunction("lua_object_getPosition",lua_getPosition);
		pScript->registerFunction("lua_object_setPosition",lua_setPosition);
		pScript->registerFunction("lua_object_addPosition",lua_addPosition);
		pScript->registerFunction("lua_object_subPosition",lua_subPosition);
		pScript->registerFunction("lua_object_setMirroring",lua_setMirroring);
		pScript->registerFunction("lua_object_getMirroring",lua_getMirroring);
		pScript->registerFunction("lua_object_getLayer",lua_getLayer);
		pScript->registerFunction("lua_object_setAfterImageMode",lua_setAfterImageMode);
		pScript->registerFunction("lua_object_setAfterImageMethodNormal",lua_setAfterImageMethodNormal);
		pScript->registerFunction("lua_object_setAfterImageMethodAdd",lua_setAfterImageMethodAdd);
		pScript->registerFunction("lua_object_setAfterImageMethodTrans",lua_setAfterImageMethodTrans);
		
		BackgroundLua::registerFunctions(pScript);
		LayerLua::registerFunctions(pScript);
		TileLua::registerFunctions(pScript);
	}
}
