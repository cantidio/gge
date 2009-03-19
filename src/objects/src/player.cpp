#include "../include/player.hpp"

Player::Player()
{
	script->loadScript("data/character/player/player.lua");
}

void Player::loadGlobalVars()
{
}

void Player::registerFunctions()
{
	lua_registerInputFunctions(script);
}

void Player::setUp()
{
	Character::setUp();
	loadGlobalVars();
	registerFunctions();
	
}

Player::Player
(
	const string& fileName,
	const int& x,
	const int& y
)
{
	script->loadScript("data/character/player/player.lua");
	script->loadScript(fileName);
	posX=x;
	posY=y;
	setUp();
}

Player::~Player()
{

}