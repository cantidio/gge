#include "../include/object_lua.hpp"
#define OBJECT_CLASS "GGE_OBJECT_BASIC"

luaL_reg ObjectLua::mMethods[] =
{
	{"new",						ObjectLua::constructor},
	{"draw",					ObjectLua::draw},
	{"logic",					ObjectLua::logic},
	{"getAnimationRealIndex",	ObjectLua::getAnimationRealIndex},
	{"changeAnimationByIndex",	ObjectLua::changeAnimationByIndex},
	{"changeAnimation",			ObjectLua::changeAnimation},
	{"animationIsPlaying",		ObjectLua::animationIsPlaying},
	{"getAnimationOn",			ObjectLua::getAnimationOn},
	{"animationRunStep",		ObjectLua::animationRunStep},
	{"setFrameOn",				ObjectLua::setFrameOn},
	{"getFrameOn",				ObjectLua::getFrameOn},
	{0,0}
};
luaL_reg ObjectLua::mMetatable[] =
{
	{"__gc",			ObjectLua::destructor},//method called when object is destroyed
	//tostring
	{0,0}
};

int ObjectLua::constructor(lua_State* pState)
{
//	Gorgon::Core::Log::get().RegisterFormated("C++ -> ObjectLua:new()");
	Gorgon::Script::Lua lua(pState);
	lua.createUserData
	(
		OBJECT_CLASS,
		new Object//não comeća do 1, pois espera-se que o uso seja var:new("","") e não var.new("","")
		(
			lua_tostring(pState, 2),
			lua_tostring(pState, 3)
		),
		sizeof(Object*)
	);
//	Gorgon::Core::Log::get().RegisterFormated("C++ -> ObjectLua:~new()");
	return 1;
}

int ObjectLua::destructor(lua_State* pState)
{
//	Gorgon::Core::Log::get().RegisterFormated("C++ -> ObjectLua:destructor()");
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object) delete object;
//	Gorgon::Core::Log::get().RegisterFormated("C++ -> ObjectLua:~destructor()");
	return 0;
}

int ObjectLua::draw(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
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
	}
	return 0;
}

int ObjectLua::logic(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
		object->animationRunStep();
	}
	return 0;
}

int ObjectLua::getAnimationRealIndex(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
		lua_pushnumber
		(
			pState,
			object->getAnimationRealIndex
			(
				(int)lua_tointeger(pState, 2),
				(int)lua_tointeger(pState, 3)
			)
		);
	}
	return 1;
}

int ObjectLua::changeAnimationByIndex(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
		object->changeAnimation((int)lua_tointeger(pState,2));
	}
	return 0;
}

int ObjectLua::changeAnimation(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
		object->changeAnimation
		(
			(int)lua_tointeger(pState,2),
			(int)lua_tointeger(pState,3)
		);
	}
	return 0;
}

int ObjectLua::animationIsPlaying(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
		lua_pushboolean(pState, object->animationIsPlaying());
	}
	return 1;
}

int ObjectLua::getAnimationOn(lua_State* pState)//real, group. index
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
		lua_pushnumber(pState, object->getAnimationOn());
		lua_pushnumber(pState, object->getAnimationOnGroup());
		lua_pushnumber(pState, object->getAnimationOnIndex());
	}
	return 3;
}

int ObjectLua::animationRunStep(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
		object->animationRunStep();
	}
	return 0;
}

int ObjectLua::setFrameOn(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
		object->setFrameOn( lua_tointeger(pState, 2) );
	}
	return 0;
}

int ObjectLua::getFrameOn(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Object* object = (Object*)lua.getUserData(OBJECT_CLASS);
	if(object)
	{
		lua_pushnumber(pState, object->getFrameOn());
	}
	return 1;
}

void ObjectLua::registerClass(Gorgon::Script::Lua& pScript)
{
	pScript.registerUserData
	(
		OBJECT_CLASS,
		mMethods,
		mMetatable
	);
}

/*	int lua_getLayer(lua_State* pState)
	{
		Object* object = getObjectPointer(pState);
		lua_pushnumber(pState,(int)object->getLayer());
		return 1;
	}
*/
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

