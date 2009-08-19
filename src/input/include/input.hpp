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
#include <gorgon++/include/core/gorgon_log.hpp>
#include <allegro.h>
#include <iostream>
#include <fstream>
/**
 * Classe responsável por tratar a entrada de dados
 *
 * @author	Cantidio Oliveira Fontes
 * @since	16/03/2009
 * @version	28/05/2009
 * @ingroup	Input
 * @todo	Aceitar joystick
 * @todo	Aceitar mais de um player
 */
class Input
{
	private:
		/**
		 * Ponteiro para a instância da classe
		 */
		static Input* mSingleton;
		/**
		 * Código da tecla de start no teclado
		 */
		int mKey_start;
		/**
		 * Código da tecla direcional para cima no teclado
		 */
		int mKey_up;
		/**
		 * Código da tecla direcional para baixo no teclado
		 */
		int mKey_down;
		/**
		 * Código da tecla direcional para esquerda no teclado
		 */
		int mKey_left;
		/**
		 * Código da tecla direcional para direita no teclado
		 */
		int mKey_right;
		/**
		 * Código da tecla de botão1 no teclado
		 */
		int mKey_button1;
		/**
		 * Código da tecla de botão2 no teclado
		 */
		int mKey_button2;
		/**
		 * Código da tecla de botão3 no teclado
		 */
		int mKey_button3;
		/**
		 * Código da tecla de botão4 no teclado
		 */
		int mKey_button4;
		/**
		 * Código da tecla de botão5 no teclado
		 */
		int mKey_button5;
		/**
		 * Código da tecla de botão6 no teclado
		 */
		int mKey_button6;
		/**
		 * Código da tecla de botão7 no teclado
		 */
		int mKey_button7;
		/**
		 * Código da tecla de botão8 no teclado
		 */
		int mKey_button8;
	protected:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		Input();
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		virtual ~Input();
		/**
		 * Método que carrega a configuração de botões
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		void loadConfiguration();
		/**
		 * Método que salva a configuração de botões
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		void saveConfiguration() const;
		/**
		 * Método que cria uma configuração de botões padrão
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		void createDefaultConfiguration();
	public:
		/**
		 * Método para instânciar a classe caso a mesma ainda não tenha sido instânciada
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		static void init();
		/**
		 * Método para destruir a instância da classe
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		static void halt();
		/**
		 * Método para retornar a instância da classe
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 */
		static Input& get();

		/**
		 * Método que retorna verdadeiro caso o botão start esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonStart();
		/**
		 * Método que retorna verdadeiro caso o botão direcional para cima esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonUp();
		/**
		 * Método que retorna verdadeiro caso o botão direcional direito esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonRight();
		/**
		 * Método que retorna verdadeiro caso o botão direcional para baixo esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonDown();
		/**
		 * Método que retorna verdadeiro caso o botão direcional esquerdo esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool buttonLeft();
		/**
		 * Método que retorna verdadeiro caso o botão1 esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button1();
		/**
		 * Método que retorna verdadeiro caso o botão2 esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button2();
		/**
		 * Método que retorna verdadeiro caso o botão3 esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button3();
		/**
		 * Método que retorna verdadeiro caso o botão4 esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button4();
		/**
		 * Método que retorna verdadeiro caso o botão5 esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button5();
		/**
		 * Método que retorna verdadeiro caso o botão6 esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button6();
		/**
		 * Método que retorna verdadeiro caso o botão7 esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button7();
		/**
		 * Método que retorna verdadeiro caso o botão8 esteja pressionado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	16/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool button8();
};

#endif
