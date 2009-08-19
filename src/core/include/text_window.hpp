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
#ifndef _TEXT_WINDOW_
#define _TEXT_WINDOW_
#include <gorgon++/include/graphic/gorgon_image.hpp>
#include <gorgon++/include/graphic/gorgon_video.hpp>

/**
 * Classe que representa uma janela de texto
 *
 * @author	Cantidio Oliveira Fontes
 * @since	10/07/2009
 * @version	10/07/2009
 */
class TextWindow : public Gorgon::Image
{
	private:
		/**
		 * Variável que representa a instância única da classe
		 */
		static TextWindow* mSingleton;
		/**
		 * Variável que guarda a cor do texto a ser escrito
		 */
		Gorgon::Color mTextColor;

		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	10/07/2009
		 * @version	10/07/2009
		 * @param	const int&				pWidth	, largura da janela
		 * @param	const int&				pHeight	, altura da janela
		 * @param	const Gorgon::Color&	pColor	, cor de escrita na janela
		 */
		TextWindow
		(
			const int& pWidth,
			const int pHeight,
			const Gorgon::Color& pColor
		);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	10/07/2009
		 * @version	10/07/2009
		 */
		~TextWindow();
	public:
		/**
		 * Método para iniciar a instância única da classe
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	10/07/2009
		 * @version	10/07/2009
		 * @param	const int&				pWidth	, largura da janela
		 * @param	const int&				pHeight	, altura da janela
		 * @param	const Gorgon::Color&	pColor	, cor da escrita da janela
		 */
		static void init
		(
			const int& pWidth			= 160,
			const int pHeight			= 120,
			const Gorgon::Color& pColor = Gorgon::Color(255,255,255)
		);
		/**
		 * Método para destruir a instância única da classe
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	10/07/2009
		 * @version	10/07/2009
		 */
		static void halt();
		/**
		 * Método para retornar a instância da classe
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	10/07/2009
		 * @version	10/07/2009
		 * @return	TextWindow&
		 */
		static TextWindow& get();
		/**
		 * Método para adicionar uma string a janela
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	10/07/2009
		 * @version	10/07/2009
		 * @param	const std::string& pString, string a ser adicionada a janela
		 */
		void add(const std::string& pString);
		/**
		 * Método para adicionar uma string formatada a janela
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	10/07/2009
		 * @version	10/07/2009
		 * @param	const char* pText	, string formatada estilo printf
		 * @param	..., argumentos da string
		 */
		void add(const char* pText, ...);
		/**
		 * Método para mostrar a janela no vídeo
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	10/07/2009
		 * @version	10/07/2009
		 */
		void show() const;
};
#endif
