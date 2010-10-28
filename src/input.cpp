#include "../include/input.hpp"

Input* Input::mSingleton= NULL;

Input::Input()
{
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Input::Input()");
	install_keyboard();
	loadConfiguration();
}

Input::~Input()
{
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Input::~Input()");
	remove_keyboard();
}

void Input::halt()
{
	if(mSingleton!=NULL)
	{
		delete mSingleton;
		mSingleton=NULL;
	}
}

Input& Input::get()
{
	if(mSingleton == NULL)
	{
		mSingleton = new Input();
	}
	return *mSingleton;
}

void Input::createDefaultConfiguration()
{
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Input::createDefaultConfiguration()");
	mKey_start		= KEY_ENTER;
	mKey_up			= KEY_UP;
	mKey_down		= KEY_DOWN;
	mKey_left		= KEY_LEFT;
	mKey_right		= KEY_RIGHT;
	mKey_button1	= KEY_Q;
	mKey_button2	= KEY_W;
	mKey_button3	= KEY_E;
	mKey_button4	= KEY_R;
	mKey_button5	= KEY_A;
	mKey_button6	= KEY_S;
	mKey_button7	= KEY_D;
	mKey_button8	= KEY_F;
}

void Input::loadConfiguration()
{
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Input::loadConfiguration()");
	std::fstream* file;
	file = new std::fstream("data/input.cfg",std::ios::in|std::ios::binary);
	
	if(!file->is_open())
	{
		Gorgon::Core::Log::get().RegisterFormated("C++ -> Input::loadConfiguration(): data/input.cfg ... Error");
		createDefaultConfiguration();
		saveConfiguration();
	}
	else
	{
		file->read((char*)&mKey_start,sizeof(int));
		file->read((char*)&mKey_up,sizeof(int));
		file->read((char*)&mKey_down,sizeof(int));
		file->read((char*)&mKey_left,sizeof(int));
		file->read((char*)&mKey_right,sizeof(int));
		file->read((char*)&mKey_button1,sizeof(int));
		file->read((char*)&mKey_button2,sizeof(int));
		file->read((char*)&mKey_button3,sizeof(int));
		file->read((char*)&mKey_button4,sizeof(int));
		file->read((char*)&mKey_button5,sizeof(int));
		file->read((char*)&mKey_button6,sizeof(int));
		file->read((char*)&mKey_button7,sizeof(int));
		file->read((char*)&mKey_button8,sizeof(int));
		Gorgon::Core::Log::get().RegisterFormated("C++ -> Input::loadConfiguration(): data/input.cfg ... Done");
	}
	file->close();
	delete file;
}

void Input::saveConfiguration() const
{
	Gorgon::Core::Log::get().RegisterFormated("C++ -> Input::saveConfiguration()");
	std::fstream* file;
	file = new std::fstream("data/input.cfg",std::ios::out|std::ios::binary);

	if(!file->is_open())
	{
		Gorgon::Core::Log::get().RegisterFormated("C++ -> Input::saveConfiguration(): data/input.cfg ... Error");
	}
	else
	{
		file->write((char*)&mKey_start,sizeof(int));
		file->write((char*)&mKey_up,sizeof(int));
		file->write((char*)&mKey_down,sizeof(int));
		file->write((char*)&mKey_left,sizeof(int));
		file->write((char*)&mKey_right,sizeof(int));
		file->write((char*)&mKey_button1,sizeof(int));
		file->write((char*)&mKey_button2,sizeof(int));
		file->write((char*)&mKey_button3,sizeof(int));
		file->write((char*)&mKey_button4,sizeof(int));
		file->write((char*)&mKey_button5,sizeof(int));
		file->write((char*)&mKey_button6,sizeof(int));
		file->write((char*)&mKey_button7,sizeof(int));
		file->write((char*)&mKey_button8,sizeof(int));
		Gorgon::Core::Log::get().RegisterFormated("C++ -> Input::saveConfiguration(): data/input.cfg ... Done");
	}
	file->close();
	delete file;
}
bool Input::buttonStart()	{ return key[mKey_start];	}
bool Input::buttonUp()		{ return key[mKey_up]; 		}
bool Input::buttonDown()	{ return key[mKey_down];	}
bool Input::buttonLeft()	{ return key[mKey_left];	}
bool Input::buttonRight()	{ return key[mKey_right];	}
bool Input::button1()		{ return key[mKey_button1];	}
bool Input::button2()		{ return key[mKey_button2];	}
bool Input::button3()		{ return key[mKey_button3];	}
bool Input::button4()		{ return key[mKey_button4];	}
bool Input::button5()		{ return key[mKey_button5];	}
bool Input::button6()		{ return key[mKey_button6];	}
bool Input::button7()		{ return key[mKey_button7];	}
bool Input::button8()		{ return key[mKey_button8];	}
void Input::cleanKeyBuffer()
{
	key[mKey_start]		= 0;
	key[mKey_up]		= 0;
	key[mKey_down]		= 0;
	key[mKey_left]		= 0;
	key[mKey_right]		= 0;
	key[mKey_button1]	= 0;
	key[mKey_button2]	= 0;
	key[mKey_button3]	= 0;
	key[mKey_button4]	= 0;
	key[mKey_button5]	= 0;
	key[mKey_button6]	= 0;
	key[mKey_button7]	= 0;
	key[mKey_button8]	= 0;
}

