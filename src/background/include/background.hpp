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
#ifndef _GSBGE_BACKGROUND_
#define _GSBGE_BACKGROUND_
#include "layer.hpp"

/**
 * @defgroup	Background
 *
 * @author		Cantidio Oliveira Fontes
 * @since		18/03/2009
 * @version		28/05/2009
 * @details
 *				O módulo Background engloba todas as funcionalidades relacionadas
 *				à parte de cenários, camadas de cenários, tiles e a interação dos mesmos
 */

/**
 * Classe que representa um cenário
 *
 * @author	Cantidio Oliveira Fontes
 * @since	18/03/2009
 * @version	28/05/2009
 * @ingroup	Background
 */
class Background
{
	private:
		/**
		 * Script que comanda as ações do layer
		 */
		Gorgon::Lua* mScript;
		/**
		 * Vetor com os layers do background
		 */
		std::vector<Layer*> mLayers;
		/**
		 * Gravidade aplicado ao cenário
		 */
		double mGravity;
		/**
		 * Atrito exercido sobre os objetos quando não estão colidindo em nada
		 */
		double mVoidFriction;
		/**
		 * Posição x do background
		 */
		double mPosX;
		/**
		 * Posição y do background
		 */
		double mPosY;
		/**
		 * Largura do background
		 */
		int mWidth;
		/**
		 * Altura do cenário
		 */
		int mHeight;
		/**
		 * Variável que trava o scrooling do cenário
		 */
		bool mLockScrool;
	protected:
		/**
		 * Método para carregar as variáveis globais do cenário
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 */
		void loadGlobalVars();
		/**
		 * Carrega os layers do cenário
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 */
		void loadLayers();
		/**
		 * Método com os dados principais carregados monta o layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 */
		void setUp();
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	const int& pWidth	, largura do cenário
		 * @param	const int& pHeight	, altura do cenário
		 * @param	const int& pPosX	, posição x que o cenário se encontra
		 * @param	const int& pPosY	, posição y que o cenário se encontra
		 */
		Background
		(
			const int&		pWidth,
			const int&		pHeight,
			const double&	pPosX = 0,
			const double&	pPosY = 0
		);
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/03/2009
		 * @param	const std::string& pFileName, nome do arquivo de script do cenário
		 */
		Background(const std::string& pFileName);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 */
		~Background();
		/**
		 * Método para se adicionar um layer ao background
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	Layer* pLayer, layer a ser adicionado
		 */
		void addLayer(Layer* pLayer);
		/**
		 * Método que executa a lógica envolvida no background
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 */
		void logic();
		/**
		 * Método para se desenhar o cenário e todos objetos que o compõem
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	Gorgon::Sprite& sprite, sprite que o cenário será desenhado
		 */
		void draw(Gorgon::Sprite& pSprite);
		/**
		 * Método para salvar o background e seus componentes
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/03/2009
		 * @version	28/05/2009
		 * @param	const std::string& fileName, nome do arquivo a salvar
		 */
		void save(const std::string& pFileName) const;
		/**
		 * Método para carregar o cenário de um arquivo de script
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @param	const std::string& fileName, nome do arquivo de script
		 */
		void load(const std::string& pFileName);
		/**
		 * Método para trancar o scroll do cenário
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 */
		void scroolLock();
		/**
		 * Método para destrancar o scroll do cenário
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 */
		void scroolUnlock();
		/**
		 * Método para setar a posição x do cenário
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @param	const double& pPosX, posição no eixo x
		 */
		void setXPos(const double& pPosX);
		/**
		 * Método para setar a posição y do cenário
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @param	const double& pPosY, posição no eixo y
		 */
		void setYPos(const double& pPosY);
		/**
		 * Método para retornar a posição x do cenário
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @return	double
		 */
		double getXPos() const;
		/**
		 * Método para retornar a posição y do cenário
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @return	double
		 */
		double getYPos() const;

                /**
                 * Método para retornar o número de layers do cenário
                 *
                 * @author  Cantidio Oliveira Fontes
                 * @since   14/12/2009
                 * @version 14/12/2009
                 * @return  int
                 */
                int getLayerNumber() const;
                /**
                 * Operador
                 *
                 * @author  Cantídio Oliveira Fontes
                 * @since   14/12/2009
                 * @version 14/12/2009
                 * @param   const int& pPos, posicão a recuperar o Layer
                 * @return  const Layer&
                 */
                const Layer& operator [](const int& pPos) const;
                /**
                 * Operador
                 *
                 * @author  Cantídio Oliveira Fontes
                 * @since   14/12/2009
                 * @version 14/12/2009
                 * @param   const int& pPos, posicão a recuperar o Layer
                 * @return  Layer&
                 */
                Layer& operator [](const int& pPos);
};
#endif
