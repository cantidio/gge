/*
 *
 *  ____              __       __          __
 * /\  _`\           /\ \     /\ \      __/\ \__
 * \ \ \L\ \     __  \ \ \____\ \ \____/\_\ \ ,_\  ____
 *  \ \ ,  /   /'__`\ \ \ '__`\\ \ '__`\/\ \ \ \/ /\_ ,`\
 *   \ \ \\ \ /\ \L\.\_\ \ \L\ \\ \ \L\ \ \ \ \ \_\/_/  /_
 *    \ \_\ \_\ \__/.\_\\ \_,__/ \ \_,__/\ \_\ \__\ /\____\
 *     \/_/\/ /\/__/\/_/ \/___/   \/___/  \/_/\/__/ \/____/
 *
 *  Copyright (C) 2008-2009  Gorgon Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
#ifndef _GSBGE_INPUT_
#define	_GSBGE_INPUT_
#include <gorgon++/gorgon.hpp>
#include <iostream>
#include <fstream>
/**
 * Class responsable to deal with user input
 *
 * @author	Cantidio Oliveira Fontes
 * @since	16/03/2009
 * @version	27/10/2010
 * @ingroup	Input
 * @todo	Aceitar joystick
 * @todo	Aceitar mais de um player
 */
class Input
{
	private:
		static Input* mSingleton;/**< Pointer to the instance of the class */
		Gorgon::Input::Keyboard* mKeyboard;/**<< pointer to the keyboard*/
		int mKey_start;		/**< Code of the key for buttonStart*/
		int mKey_up;		/**< Code of the key for buttonUp*/
		int mKey_down;		/**< Code of the key for buttonDown*/
		int mKey_left;		/**< Code of the key for buttonLeft*/
		int mKey_right;		/**< Code of the key for buttonRight*/
		int mKey_button1;	/**< Code of the key for button1*/
		int mKey_button2;	/**< Code of the key for button2*/
		int mKey_button3;	/**< Code of the key for button3*/
		int mKey_button4;	/**< Code of the key for button4*/
		int mKey_button5;	/**< Code of the key for button5*/
		int mKey_button6;	/**< Code of the key for button6*/
		int mKey_button7;	/**< Code of the key for button7*/
		int mKey_button8;	/**< Code of the key for button8*/
	protected:
		/**
		 * Constructor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		Input();
		/**
		 * Destructor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		virtual ~Input();
		/**
		 * Method that loads the buttons's configuration
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		void loadConfiguration();
		/**
		 * Method that saves the buttons's configuration
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		void saveConfiguration() const;
		/**
		 * Method that creates a default configuration for the buttons
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		void createDefaultConfiguration();
	public:
		/**
		 * Method to destroy the singleton instance of the class
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		static void halt();
		/**
		 * Method to return the singleton instance of the class
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		static Input& get();
		/**
		 * Method that returns true if the buttonStart is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonStart();
		/**
		 * Method that returns true if the buttonUp is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonUp();
		/**
		 * Method that returns true if the buttonRight is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonRight();
		/**
		 * Method that returns true if the buttonDown is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonDown();
		/**
		 * Method that returns true if the buttonLeft is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonLeft();
		/**
		 * Method that returns true if the button1 is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button1();
		/**
		 * Method that returns true if the button2 is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button2();
		/**
		 * Method that returns true if the button3 is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button3();
		/**
		 * Method that returns true if the button4 is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button4();
		/**
		 * Method that returns true if the button5 is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button5();
		/**
		 * Method that returns true if the button6 is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button6();
		/**
		 * Method that returns true if the button7 is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button7();
		/**
		 * Method that returns true if the button8 is pressed
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button8();
		/**
		 * Method that cleans the keybuffer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	27/10/2010
		 * @version	27/10/2010
		 */
		void cleanKeyBuffer();
		void update();
};

#endif
