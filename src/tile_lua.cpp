#include "../include/tile_lua.hpp"
#include "../include/tile.hpp"
#define TILE_CLASS "GGE_TILE_BASIC"

luaL_reg TileLua::mMethods[] =
{
	{"new",				TileLua::constructor},
	{"getAnimation",	TileLua::getAnimation},
	{"setAnimation",	TileLua::setAnimation},
	{"draw",			TileLua::draw},
	{"logic",			TileLua::logic},
	{0,0}
};
luaL_reg TileLua::mMetatable[]=
{
	{"__gc",	TileLua::destructor},//method called when object is destroyed
	//tostring
	{0,0}
};

int TileLua::constructor(lua_State* pState)
{
	//std::cout << "Tile new" << std::endl;
	Gorgon::Script::Lua lua(pState);
	lua.createUserData
	(
		TILE_CLASS,
		new Tile
		(
			ResourceManager::SpriteManager::load	( lua_tostring(pState, 2) ),//comeća do 2 para ser usado assim: TILE:new()
			ResourceManager::AnimationManager::load	( lua_tostring(pState, 3) ),
			(int)lua_tonumber(pState, 4)
		),
		sizeof(Tile*)
	);
	return 1;
}

int TileLua::destructor(lua_State* pState)
{
	//std::cout << "Tile del\n";
	Gorgon::Script::Lua lua(pState);
	Tile* tile = (Tile*)lua.getUserData(TILE_CLASS);
	if(tile) delete tile;
	return 0;
}

int TileLua::draw(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Tile* tile = (Tile*)lua.getUserData(TILE_CLASS,1);
	tile->draw
	(
		Gorgon::Core::Point
		(
			lua_tonumber(pState, 2),
			lua_tonumber(pState, 3)
		)
	);
	return 0;
}

int TileLua::logic(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Tile* tile = (Tile*)lua.getUserData(TILE_CLASS,1);
	tile->logic();
	return 0;
}

int TileLua::getAnimation(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Tile* tile = (Tile*)lua.getUserData(TILE_CLASS,1);
	lua_pushnumber(pState,tile->getAnimation());
	return 1;
}

int TileLua::setAnimation(lua_State* pState)
{
	Gorgon::Script::Lua lua(pState);
	Tile* tile = (Tile*)lua.getUserData(TILE_CLASS,1);
	tile->setAnimation((int)lua_tonumber(pState,2));
	return 0;
}

void TileLua::registerClass(Gorgon::Script::Lua& pScript)
{
	pScript.registerUserData
	(
		TILE_CLASS,
		mMethods,
		mMetatable
	);
}

