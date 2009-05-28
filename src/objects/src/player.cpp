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
	const std::string& fileName,
	const Gorgon::Point& position
)
{
	script->loadScript("data/character/player/player.lua");
	script->loadScript(fileName);
	setPosition(position);
	setUp();
}

Player::~Player()
{

}