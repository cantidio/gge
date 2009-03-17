#include "../include/input.hpp"

Input* Input::singleton= NULL;
Input::Input()
{
	install_keyboard();
	loadConfiguration();
}

Input::~Input()
{
	remove_keyboard();
}

void Input::init()
{
	if(singleton==NULL)
	{
		singleton= new Input();
	}
}

void Input::halt()
{
	if(singleton!=NULL)
	{
		delete singleton;
		singleton=NULL;
	}
}

Input& Input::get()
{
	init();
	return *singleton;
}

void Input::createDefaultConfiguration()
{
	key_start	= KEY_ENTER;
	key_up		= KEY_UP;
	key_down	= KEY_DOWN;
	key_left	= KEY_LEFT;
	key_right	= KEY_RIGHT;
	key_button1	= KEY_Q;
	key_button2	= KEY_W;
	key_button3	= KEY_E;
	key_button4	= KEY_R;
	key_button5	= KEY_A;
	key_button6	= KEY_S;
	key_button7	= KEY_D;
	key_button8	= KEY_F;
}

void Input::loadConfiguration()
{
	std::fstream *file;
	file = new std::fstream("data/input.cfg",std::ios::in|std::ios::binary);
	std::cout << "Loading input configuration... ";
	if(!file->is_open())
	{
		std::cout << "Error..." << std::endl;
		std::cout << "Creating new default input configuration..." << std::endl;
		createDefaultConfiguration();
		saveConfiguration();
	}
	else
	{
		file->read((char*)&key_start,sizeof(int));
		file->read((char*)&key_up,sizeof(int));
		file->read((char*)&key_down,sizeof(int));
		file->read((char*)&key_left,sizeof(int));
		file->read((char*)&key_right,sizeof(int));
		file->read((char*)&key_button1,sizeof(int));
		file->read((char*)&key_button2,sizeof(int));
		file->read((char*)&key_button3,sizeof(int));
		file->read((char*)&key_button4,sizeof(int));
		file->read((char*)&key_button5,sizeof(int));
		file->read((char*)&key_button6,sizeof(int));
		file->read((char*)&key_button7,sizeof(int));
		file->read((char*)&key_button8,sizeof(int));
		std::cout << "OK" << std::endl;
	}
	file->close();
	delete file;
}

void Input::saveConfiguration() const
{
	std::fstream *file;
	file = new std::fstream("data/input.cfg",std::ios::out|std::ios::binary);
	std::cout << "Saving input configuration... ";
	if(!file->is_open())
	{
		std::cout << "Error..." << std::endl;
	}
	else
	{
		file->write((char*)&key_start,sizeof(int));
		file->write((char*)&key_up,sizeof(int));
		file->write((char*)&key_down,sizeof(int));
		file->write((char*)&key_left,sizeof(int));
		file->write((char*)&key_right,sizeof(int));
		file->write((char*)&key_button1,sizeof(int));
		file->write((char*)&key_button2,sizeof(int));
		file->write((char*)&key_button3,sizeof(int));
		file->write((char*)&key_button4,sizeof(int));
		file->write((char*)&key_button5,sizeof(int));
		file->write((char*)&key_button6,sizeof(int));
		file->write((char*)&key_button7,sizeof(int));
		file->write((char*)&key_button8,sizeof(int));
		std::cout << "OK" << std::endl;
	}
	file->close();
	delete file;
}

bool Input::buttonStart()
{
	return key[key_start];
}

bool Input::buttonUp()
{
	return key[key_up];
}

bool Input::buttonDown()
{
	return key[key_down];
}

bool Input::buttonLeft()
{
	return key[key_left];
}

bool Input::buttonRight()
{
	return key[key_right];
}

bool Input::button1()
{
	return key[key_button1];
}

bool Input::button2()
{
	return key[key_button2];
}

bool Input::button3()
{
	return key[key_button3];
}

bool Input::button4()
{
	return key[key_button4];
}

bool Input::button5()
{
	return key[key_button5];
}

bool Input::button6()
{
	return key[key_button6];
}

bool Input::button7()
{
	return key[key_button7];
}

bool Input::button8()
{
	return key[key_button8];
}
