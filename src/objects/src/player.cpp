#include "../include/player.hpp"

Player::Player()
{
	mScript->loadScript("data/character/player/player.lua");
}

void Player::loadGlobalVars()
{
}

void Player::registerFunctions()
{
	InputLua::registerFunctions(mScript);
}

void Player::setUp()
{
	Character::setUp();
	loadGlobalVars();
	registerFunctions();
}

Player::Player
(
	const std::string& pFileName,
	const Gorgon::Point& pPosition
)
{
	mScript->loadScript("data/character/player/player.lua");
	mScript->loadScript(pFileName);
	setPosition(pPosition);
	setUp();
}

Player::~Player()
{

}