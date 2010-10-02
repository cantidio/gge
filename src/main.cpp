#include "../include/game.hpp"

int main()
{
	Gorgon::Log::init("gge_log.txt");
	Game::get().run();
	Game::halt();
	return 0;
}END_OF_MAIN()

