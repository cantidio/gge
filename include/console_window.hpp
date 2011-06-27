#ifndef _CONSOLE_WINDOW_
#define _CONSOLE_WINDOW_
#include <gorgon++/gorgon.hpp>
//#include <guichan.hpp>
//#include <guichan/allegro.hpp>

class ConsoleWindow
{
	protected:
		static ConsoleWindow* mSingleton;

		ConsoleWindow();
		~ConsoleWindow();
	public:
		static ConsoleWindow& get();
		static void halt();

		void logic();
		void draw();
		void run();
		void stop();
		std::string getText() const;
};

#endif

