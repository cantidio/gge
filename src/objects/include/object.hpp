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
#ifndef _GSBGE_OBJECT_
#define	_GSBGE_OBJECT_
#include <gorgon++/gorgon.hpp>
#include "resource_manager/include/sprite_manager.hpp"
#include "resource_manager/include/animation_manager.hpp"
#include "core/include/text_window_lua.hpp"

/**
 * @defgroup	Objects
 *
 * @author		Cantidio Oliveira Fontes
 * @since		11/03/2009
 * @version		26/06/2009
 * @details
 *				O módulo Objects engloba todas as funcionalidades relacionadas
 *				à parte de objetos e entidades relacionadas e derivadas dos mesmos
 */
class Layer;
/**
 * Classe que representa um objeto interativo
 *
 * @author	Cantidio Oliveira Fontes
 * @since	11/03/2009
 * @version	26/06/2009
 * @ingroup	Objects
 */
class Object
{
	protected:
		/**
		 * Nome do arquivo de sprites do objeto
		 */
		std::string mSpritePackName;
		/**
		 * Nome do arquivo de animações do objeto
		 */
		std::string mAnimationPackName;
		/**
		 * Nome do arquivo de colisões do objeo
		 */
		std::string mColisionPackName;
		/**
		 * Nome do arquivo da paleta de cores do objeto
		 */
		std::string mPaletteName;
		/**
		 * Ponteiro para o spritePack do objeto
		 */
		Gorgon::SpritePack* mSpritePack;
		/**
		 * Ponteiro para o animationPack do objeto
		 */
		Gorgon::AnimationPack* mAnimationPack;
		/**
		 * Ponteiro para a paleta de cores do objeto
		 */
		Gorgon::Palette* mPalette;
		/**
		 * Script que comanda as ações do objeto
		 */
		Gorgon::Lua* mScript;
		/**
		 * Layer que o Object se encontra
		 */
		Layer* mLayer;
		/**
		 * Handler de animação do objeto
		 */
		Gorgon::AnimationHandler* mAnimationHandler;
		/**
		 * Direção do objeto
		 */
		Gorgon::Mirroring mDirection;
		/**
		 * Nome do objeto
		 */
		std::string mName;
		/**
		 * ID do objeto
		 */
		std::string mId;
		/**
		 * Localização do objeto no plano xy
		 */
		Gorgon::Point mPosition;
		/**
		 * Ponteiro para o método de renderização das afterImages
		 */
		void (Object::*mAfterImageMethod)(const int&)const;
		/**
		 * Variável que guarda se o sistema de afterImages está habilitado
		 */
		bool mAfterImageEnabled;
		/**
		 * Delay das afterImages
		 */
		int	mAfterImageDelay;
		/**
		 * Número de afterImages
		 */
		int mAfterImageNumber;
		/**
		 * Delay atual das afterImages
		 */
		int mAfterImageDelayInUse;
		/**
		 * Cor a ser adicionada no método de add
		 */
		Gorgon::Color mAfterImageColorAdd;
		/**
		 * Cor a ser subtraída no método de add
		 */
		Gorgon::Color mAfterImageColorSub;
		/**
		 * Porcentagem de transparência das afterImages
		 */
		float mAfterImageTrans;
		/**
		 * Variável que guarda as ultimas posições do objeto
		 */
		std::vector<Gorgon::Point>			mLastPositions;
		/**
		 * Variável que guarda as últimas direções do objeto
		 */
		std::vector<Gorgon::Mirroring>		mLastDirections;
		/**
		 * Variável que guarda os ponteiros dos últimos sprites usados
		 */
		std::vector<const Gorgon::Sprite*>	mLastSprites;
		
		/**
		 * Método Construtor vazio
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	17/12/2009
		 * @param	Layer* pLayer, layer que o objeto se encontra
		 */
		Object(Layer* pLayer = NULL);
		/**
		 * Método para carregar as variáveis globais de um objeto declaradas no script
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 */
		void loadGlobalVars();
		/**
		 * Método para preparar o objeto com as informações já recolhidas
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 */
		void setUp();
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @version	28/05/2009
		 * @param	const std::string&		pScriptName	, nome do script do objeto
		 * @param	const Gorgon::Point&	pPosition	, posição do objeto no eixo xy
		 * @param	Layer*					pLayer		, layer em que o objeto está presente
		 */
		Object
		(
			const std::string& pScriptName,
			const Gorgon::Point& pPosition = Gorgon::Point(0,0),
			Layer* pLayer = NULL
		);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @version	28/05/2009
		 */
		virtual ~Object();
		/**
		 * Método para desenhar o objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @version	21/06/2009
		 */
		void draw() const;
		/**
		 * Método que realiza as operações lógicas do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @version	28/05/2009
		 */
		void logic();
		void setLayer(Layer* pLayer);
		Layer* getLayer();
		/**
		 * Método para setar o espelhamento do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 * @param	const Gorgon::Mirroring& pMirroring, espelhamento
		 */
		void setMirroring(const Gorgon::Mirroring& pMirroring);
		/**
		 * Método para retornar o espelhamento do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 * @return	Gorgon::Mirroring
		 */
		Gorgon::Mirroring getMirroring() const;
		/**
		 * Método para setar a posição do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 * @param	const double& pPosX, nova posição no eixo x
		 */
		//void setXPosition(const double& pPosX);
		/**
		 * Método para setar a posição y do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 * @param	const double& pPosY, nova posição no eixo y
		 */
		//void setYPosition(const double& pPosY);
		/**
		 * Método para setar a posição do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 * @param	const Gorgon::Point& pPosition, nova posição no eixo xy
		 */
		void setPosition(const Gorgon::Point& pPosition);
		/**
		 * Método para adicionar um valor a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	17/12/2009
		 * @param	const Gorgon::Point& pPosition, valor a ser adicionado a posição
		 */
		void addPosition(const Gorgon::Point& pPosition);
		/**
		 * Método para subtrair um valor a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	31/03/2009
		 * @version	17/12/2009
		 * @param	const Gorgon::Point& pPosition, valor a ser subtraido a posição
		 */
		void subPosition(const Gorgon::Point& pPosition);
		/**
		 * Método para retornar a posição x do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 * @return	Gorgon::Point
		 */
		Gorgon::Point getPosition() const;
		/**
		 * Método para retornar o índice real de uma animação
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/06/2009
		 * @version	18/06/2009
		 * @param	const int& pGroup , grupo da animação que deseja-se obter o índice real
		 * @param	const int& pIndex , índice da animação que deseja-se obter o índice real
		 * @return	int
		 */
		int getAnimationRealIndex(const int& pGroup, const int& pIndex) const;
		/**
		 * Método para mudar a animação atuante do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 * @param	const int& pAnimation, nova animação
		 */
		void changeAnimation(const int& pAnimation);
		/**
		 * Método para mudar a animação atuante do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	09/06/2009
		 * @version	09/06/2009
		 * @param	const int& pGroup, grupo da nova animação
		 * @param	const int& pIndex, índice da nova animação
		 */
		void changeAnimation(const int& pGroup, const int& pIndex);
		/**
		 * Método para saber se a animação do objeto está tocando
		 *
		 * @author	Cantídio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	28/05/2009
		 * @return	bool
		 */
		bool animationIsPlaying() const;
		/**
		 * Método que retorna a animação que está tocando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @version	28/05/2009
		 * @return	int
		 */
		int getAnimationOn() const;
		/**
		 * Método que retorna o frame atual da animação que está tocando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	14/03/2009
		 * @version	28/05/2009
		 * @return	int
		 */
		int getFrameOn() const;
		/**
		 * Método para setar o método de afterImage para Normal
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 */
		void setAfterImageMethodNormal();
		/**
		 * Método para setar o método de afterImage para add
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const Gorgon::Color&	pColorAdd	, cor a adicionar
		 * @param	const Gorgon::Color&	pColorSub	, cor a subtrair
		 * @param	const float&			pTrans		, porcentagem da transparência
		 */
		void setAfterImageMethodAdd
		(
			const Gorgon::Color&	pColorAdd,
			const Gorgon::Color&	pColorSub,
			const float&			pTrans
		);
		/**
		 * Método para setar o método de afterImage para Transparent
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const float& pTrans , porcentagem da transparência
		 */
		void setAfterImageMethodTrans(const float& pTrans);
		/**
		 * Método para abilitar ou desabilitar as AfterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const bool& pEnabled, se está habilitado ou não
		 */
		void setAfterImageEnabled(const bool& pEnabled);
		/**
		 * Método para setar o delay em gameticks das afterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pDelay , delay em gameticks entre uma afterImage e outra
		 */
		void setAfterImageDelay(const int& pDelay);
		/**
		 * Método para setar o Número de afterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pNumber, número de afterImages
		 */
		void setAfterImageNumber(const int& pNumber);
		/**
		 * Método que seta o modo de AfterImage
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @final	26/06/2009
		 * @param	const bool& pEnabled		, se está abilitado
		 * @param	const int&	pDelay			, delay entre as imagens
		 * @param	const int&	pImageNumber	, número de afterImages
		 */
		void setAfterImageMode
		(
			const bool& pEnabled,
			const int& pDelay,
			const int& pImageNumber
		);
		/**
		 * Método para retornar se o sistema de afterImages está habilitado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @return	bool
		 */
		bool getAfterImageEnabled() const;
		/**
		 * Método para retornar o delay das afterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @return	int
		 */
		int getAfterImageDelay() const;
		/**
		 * Método para retornar o número de afterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @return	int
		 */
		int getAfterImageNumber() const;
	protected:
		/**
		 * Método para desenhar uma afterImage usando o método Normal
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pImage, número da imagem no buffer  a desenhar
		 */
		void drawAfterImageNormal(const int& pImage) const;
		/**
		 * Método para desenhar uma afterImage usando o método de transparencia
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pImage, número da imagem no buffer  a desenhar
		 */
		void drawAfterImageTransparent(const int& pImage) const;
		/**
		 * Método para desenhar uma afterImage usando o método de Add
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pImage, número da imagem no buffer  a desenhar
		 */
		void drawAfterImageAdd(const int& pImage) const;
};
#endif
