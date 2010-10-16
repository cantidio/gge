#include "../include/game.hpp"

int main()
{
	Gorgon::Core::Log::init("gge_log.txt");
	Game::get().run();
	Game::halt();
	return 0;
}END_OF_MAIN()

