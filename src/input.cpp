#include "../include/input.hpp"

Input* Input::mSingleton= NULL;

Input::Input()
{
	Gorgon::Core::Log::get().writeFormatted("C++ -> Input::Input()\n");
	mKeyboard = new Gorgon::Input::Keyboard();
	loadConfiguration();
}

Input::~Input()
{
	Gorgon::Core::Log::get().writeFormatted("C++ -> Input::~Input()\n");
	delete mKeyboard;
}

void Input::halt()
{
	if( mSingleton != NULL )
	{
		delete mSingleton;
		mSingleton = NULL;
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
	Gorgon::Core::Log::get().writeFormatted("C++ -> Input::createDefaultConfiguration()\n");
	mKey_start		= Gorgon::Input::Key::ENTER;
	mKey_up			= Gorgon::Input::Key::UP;
	mKey_down		= Gorgon::Input::Key::DOWN;
	mKey_left		= Gorgon::Input::Key::LEFT;
	mKey_right		= Gorgon::Input::Key::RIGHT;
	mKey_button1	= Gorgon::Input::Key::Q;
	mKey_button2	= Gorgon::Input::Key::W;
	mKey_button3	= Gorgon::Input::Key::E;
	mKey_button4	= Gorgon::Input::Key::R;
	mKey_button5	= Gorgon::Input::Key::A;
	mKey_button6	= Gorgon::Input::Key::S;
	mKey_button7	= Gorgon::Input::Key::D;
	mKey_button8	= Gorgon::Input::Key::F;
}

void Input::loadConfiguration()
{
	Gorgon::Core::Log::get().writeFormatted("C++ -> Input::loadConfiguration()\n");
	std::fstream* file;
	file = new std::fstream("data/input.cfg",std::ios::in|std::ios::binary);

	if(!file->is_open())
	{
		Gorgon::Core::Log::get().writeFormatted("C++ -> Input::loadConfiguration(): data/input.cfg ... Error\n");
		createDefaultConfiguration();
		saveConfiguration();
	}
	else
	{
		file->read( (char*)&mKey_start		, sizeof(int) );
		file->read( (char*)&mKey_up			, sizeof(int) );
		file->read( (char*)&mKey_down		, sizeof(int) );
		file->read( (char*)&mKey_left		, sizeof(int) );
		file->read( (char*)&mKey_right		, sizeof(int) );
		file->read( (char*)&mKey_button1	, sizeof(int) );
		file->read( (char*)&mKey_button2	, sizeof(int) );
		file->read( (char*)&mKey_button3	, sizeof(int) );
		file->read( (char*)&mKey_button4	, sizeof(int) );
		file->read( (char*)&mKey_button5	, sizeof(int) );
		file->read( (char*)&mKey_button6	, sizeof(int) );
		file->read( (char*)&mKey_button7	, sizeof(int) );
		file->read( (char*)&mKey_button8	, sizeof(int) );
		Gorgon::Core::Log::get().writeFormatted("C++ -> Input::loadConfiguration(): data/input.cfg ... Done\n");
	}
	file->close();
	delete file;
}

void Input::saveConfiguration() const
{
	Gorgon::Core::Log::get().writeFormatted("C++ -> Input::saveConfiguration()\n");
	std::fstream* file;
	file = new std::fstream("data/input.cfg",std::ios::out|std::ios::binary);

	if(!file->is_open())
	{
		Gorgon::Core::Log::get().writeFormatted("C++ -> Input::saveConfiguration(): data/input.cfg ... Error\n");
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
		Gorgon::Core::Log::get().writeFormatted("C++ -> Input::saveConfiguration(): data/input.cfg ... Done\n");
	}
	file->close();
	delete file;
}

bool Input::buttonStart()	{ return mKeyboard->getKey( mKey_start	).isPressed();	}
bool Input::buttonUp()		{ return mKeyboard->getKey( mKey_up		).isPressed(); 	}
bool Input::buttonDown()	{ return mKeyboard->getKey( mKey_down	).isPressed();	}
bool Input::buttonLeft()	{ return mKeyboard->getKey( mKey_left	).isPressed();	}
bool Input::buttonRight()	{ return mKeyboard->getKey( mKey_right	).isPressed();	}
bool Input::button1()		{ return mKeyboard->getKey( mKey_button1 ).isPressed();	}
bool Input::button2()		{ return mKeyboard->getKey( mKey_button2 ).isPressed();	}
bool Input::button3()		{ return mKeyboard->getKey( mKey_button3 ).isPressed();	}
bool Input::button4()		{ return mKeyboard->getKey( mKey_button4 ).isPressed();	}
bool Input::button5()		{ return mKeyboard->getKey( mKey_button5 ).isPressed();	}
bool Input::button6()		{ return mKeyboard->getKey( mKey_button6 ).isPressed();	}
bool Input::button7()		{ return mKeyboard->getKey( mKey_button7 ).isPressed();	}
bool Input::button8()		{ return mKeyboard->getKey( mKey_button8 ).isPressed();	}
void Input::cleanKeyBuffer()
{
	//mKeyboard->clearBuffer();
	/**@todo implementar o método acima*/
}

void Input::update() { mKeyboard->update() ; }
