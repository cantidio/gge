#include "../include/game.hpp"

int main()
{
	Gorgon::Log::init("gge_log.txt");
	Game::get().run();
	return 0;
}END_OF_MAIN()

