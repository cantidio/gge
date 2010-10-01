#include "../include/object_lua.hpp"

namespace ObjectLua
{
	inline Object* getObjectPointer(lua_State* pState)
	{
		return (Object*)lua_tointeger(pState,1);
	}

	int GGE_object_new(lua_State* pState)
	{
		Object* object = new Object
		(
			lua_tostring(pState,1),
			lua_tostring(pState,2)
		);
		lua_pushnumber(pState,(int)object);
		return 1;
	}
	
	int GGE_object_delete(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		delete object;
	}

	int GGE_object_animationGetRealIndex(lua_State* pState)
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

	int GGE_object_animationChangeByIndex(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->changeAnimation((int)lua_tointeger(pState,2));
		return 0;
	}

	int GGE_object_animationChange(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->changeAnimation
		(
			(int)lua_tointeger(pState,2),
			(int)lua_tointeger(pState,3)
		);
		return 0;
	}

	int GGE_object_animationIsPlaying(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushboolean(pState,object->animationIsPlaying());
		return 1;
	}

	int GGE_object_animationOnGet(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber(pState,object->getAnimationOnGroup());
		lua_pushnumber(pState,object->getAnimationOnIndex());
		lua_pushnumber(pState,object->getAnimationOn());
		return 3;
	}

	int GGE_object_animationGetFrameOn(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber(pState,object->getFrameOn());
		return 1;
	}

	int GGE_object_animationSetFrameOn(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->setFrameOn( lua_tointeger(pState,2) );
		return 0;
	}
	
	int GGE_object_animationRunStep(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		object->animationRunStep();
		return 0;
	}

/*	int lua_getLayer(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber(pState,(int)object->getLayer());
		return 1;
	}
*/
	int GGE_object_draw(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		const Gorgon::Point position
		(
			lua_tointeger(pState,2),
			lua_tointeger(pState,3)
		);
		Gorgon::Mirroring mirror;

		switch((int)lua_tointeger(pState,4))
		{
			case 0:		mirror = Gorgon::Mirroring::Normal;	break;
			case 1:		mirror = Gorgon::Mirroring::HFlip;	break;
			case 2:		mirror = Gorgon::Mirroring::VFlip;	break;
			default:	mirror = Gorgon::Mirroring::VHFlip;	break;
		}
		
		object->draw( position, mirror );
		return 1;
	}

/*	int lua_setAfterImageMethodNormal(lua_State* pState)
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
*/
	void registerFunctions(Gorgon::Lua* pScript)
	{
		pScript->registerFunction("GGE_object_new"						,GGE_object_new						);
		pScript->registerFunction("GGE_object_delete"					,GGE_object_delete					);
		pScript->registerFunction("GGE_object_draw"						,GGE_object_draw					);
		pScript->registerFunction("GGE_object_animationChangeByIndex"	,GGE_object_animationChangeByIndex	);
		pScript->registerFunction("GGE_object_animationGetRealIndex"	,GGE_object_animationGetRealIndex	);
		pScript->registerFunction("GGE_object_animationChange"			,GGE_object_animationChange			);
		pScript->registerFunction("GGE_object_animationOnGet"			,GGE_object_animationOnGet			);
		pScript->registerFunction("GGE_object_animationIsPlaying"		,GGE_object_animationIsPlaying		);
		pScript->registerFunction("GGE_object_animationGetFrameOn"		,GGE_object_animationGetFrameOn		);
		pScript->registerFunction("GGE_object_animationSetFrameOn"		,GGE_object_animationSetFrameOn		);
		pScript->registerFunction("GGE_object_animationRunStep"			,GGE_object_animationRunStep		);
		
		/*
		pScript->registerFunction("lua_object_setAfterImageMode",lua_setAfterImageMode);
		pScript->registerFunction("lua_object_setAfterImageMethodNormal",lua_setAfterImageMethodNormal);
		pScript->registerFunction("lua_object_setAfterImageMethodAdd",lua_setAfterImageMethodAdd);
		pScript->registerFunction("lua_object_setAfterImageMethodTrans",lua_setAfterImageMethodTrans);
		*/
	}
}
