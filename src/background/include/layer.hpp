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
#ifndef _GSBGE_LAYER_
#define _GSBGE_LAYER_
#include "../../resource_manager/include/sprite_manager.hpp"
#include "../../resource_manager/include/animation_manager.hpp"
#include "../../objects/include/object.hpp"
#include "tile.hpp"
#include <vector>

/**
 * Classe que representa uma camada de um cenário
 *
 * @author	Cantidio Oliveira Fontes
 * @since	17/03/2009
 * @version	28/05/2009
 * @ingroup	Background
 */
class Layer
{
	private:
		/**
		 * Nome do arquivo de script do layer
		 */
		std::string mScriptName;
		/**
		 * Nome do arquivo de sprites do layer
		 */
		std::string mSpritePackName;
		/**
		 * Nome do arquivo de animações do layer
		 */
		std::string mAnimationPackName;
		/**
		 * Ponteiro para o spritePack do layer
		 */
		Gorgon::SpritePack* mSpritePack;
		/**
		 * Ponteiro para o animationPack do layer
		 */
		Gorgon::AnimationPack* mAnimationPack;
		/**
		 * Script que comanda as ações do layer
		 */
		Gorgon::Lua* mScript;
		/**
		 * Vetor com os tiles do layer
		 */
		std::vector<Tile*>	mTiles;
		/**
		 * Vetor com os objetos do cenário
		 */
		std::vector<Object*> mObjects;
		/**
		 * Velocidade de deslocamento horizontal do layer
		 */
		double mXScrollSpeed;
		/**
		 * Velocidade de deslocamento vertical do layer
		 */
		double mYScrollSpeed;
	protected:
		/**
		 * Carrega as variáveis globais da classe
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 */
		void loadGlobalVars();
		/**
		 * Carrega os tiles do layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 */
		void loadTiles();
		/**
		 * Método que carrega os objetos do layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 */
		void loadObjects();
		/**
		 * Método com os dados principais carregados monta o layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 */
		void setUp();
	public:
		
		Layer(const Layer& pOrig);
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	const double& pXScrollSpeed,	velocidade de deslocamento horizontal do layer
		 * @param	const double& pYScrollSpeed,	velocidade de deslocamento vertical do layer
		 */
		Layer(const double& pXScrollSpeed=1,const double& pYScrollSpeed=1);
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @param	const std::string& pScriptName, nome do script do layer
		 */
		Layer(const std::string& pScriptName);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 */
		~Layer();
		/**
		 * Método para descrever o layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/03/2009
		 * @version	28/05/2009
		 */
		void describe() const;
		/**
		 * Método para se adicionar um Object ao layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	Object* pObject, Object a ser adicionado
		 */
		void addObject(Object* pObject);
		/**
		 * Método para se adicionar um Tile ao Layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	Tile* pTile, Tile a ser adicionado
		 */
		void addTile(Tile* pTile);
		/**
		 * Método para retornar a posição x real do layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	const int& pPosX, posição x
		 * @return	int
		 */
		int getRealPosX(const int& pPosX) const;
		/**
		 * Método para retornar a posição y real do layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	const int& pPosY, posição y
		 * @return	int
		 */
		int getRealPosY(const int& pPosY) const;
		/**
		 * Método que executa a lógica envolvida no layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 */
		void logic();
		/**
		 * Método para se desenhar o layer
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	17/03/2009
		 * @version	28/05/2009
		 * @param	Gorgon::Sprite& sprite, sprite que o layer será desenhado
		 * @param	const int& posX, posição x que o layer será desenhado
		 * @param	const int& posY, posição y que o layer será desenhado
		 */
		void draw
		(
			Gorgon::Sprite& sprite,
			const int& posX,
			const int& posY
		);
		/**
		 * Método para salvar os dados da camada em um script lua
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/03/2009
		 * @version	28/05/2009
		 * @param	const std::string& pFileName, nome do arquivo a salvar
		 */
		void save(const std::string& pFileName) const;
		/**
		 * Método para se carregar o layer de um arquivo de script
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/03/2009
		 * @version	28/05/2009
		 * @param	const std::string& pFileName, nome do arquivo a carregar
		 */
		void load(const std::string& pFileName);
};
#endif
