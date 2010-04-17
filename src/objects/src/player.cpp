#include "../include/player.hpp"

Player::Player()
{
	mScript->loadScript("data/character/player/class_player.lua");
}

Player::Player
(
	const std::string&		pFileName,
	const Gorgon::Point&	pPosition,
	Layer*					pLayer,
	const bool&				pActive
) : Character(pPosition,pLayer,pActive)
{
	mScript->loadScript("data/character/player/class_player.lua");
	mScript->loadScript(pFileName);
	setPosition(pPosition);
	setUp();
}

Player::~Player(){}

void Player::loadGlobalVars() {}

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

