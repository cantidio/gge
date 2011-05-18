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
 *  Copyright (C) 2008-2010  Gorgon Team
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
#include "sprite_manager.hpp"
#include "animation_manager.hpp"
//#include "core/include/text_window_lua.hpp"

/**
 * @defgroup	Objects
 *
 * @author		Cantidio Oliveira Fontes
 * @since		11/03/2009
 * @version		26/01/2010
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
 * @version	29/09/2010
 * @ingroup	Objects
 */
class Object
{
	protected:
		std::string mSpritePackName;							/**<< Nome do arquivo de sprites do objeto*/
		std::string mAnimationPackName;							/**<< Nome do arquivo de animações do objeto*/
		std::string mColisionPackName;							/**<< Nome do arquivo de colisões do objeo*/
		std::string mPaletteName;								/**<< Nome do arquivo da paleta de cores do objeto*/
		Gorgon::Graphic::Palette* mPalette;						/**<< Ponteiro para a paleta de cores do objeto*/
		Gorgon::Graphic::AnimationHandler* mAnimationHandler;	/**<< Handler de animação do objeto*/
		
//		void (Object::*mAfterImageMethod)(const int&)const;		/**<< Ponteiro para o método de renderização das afterImages*/
//		bool mAfterImageEnabled;								/**<< Variável que guarda se o sistema de afterImages está habilitado*/
//		int	mAfterImageDelay;									/**<< Delay das afterImages*/
//		int mAfterImageNumber;									/**<< Número de afterImages*/
//		int mAfterImageDelayInUse;								/**<< Delay atual das afterImages*/
//		Gorgon::Color mAfterImageColorAdd;						/**<< Cor a ser adicionada no método de add*/
//		Gorgon::Color mAfterImageColorSub;						/**<< Cor a ser subtraída no método de add*/
//		float mAfterImageTrans;									/**<< Porcentagem de transparência das afterImages*/
//		std::vector<Gorgon::Core::Point>			mLastPositions;		/**<< Variável que guarda as ultimas posições do objeto*/
//		std::vector<Gorgon::Mirroring>		mLastDirections;	/**<< Variável que guarda as últimas direções do objeto*/
//		std::vector<const Gorgon::Sprite*>	mLastSprites;		/**<< Variável que guarda os ponteiros dos últimos sprites usados*/
		
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	12/03/2009
		 * @version	29/09/2010
		 * @param	const std::string& pSpriteFile, arquivo com o pacote de sprites
		 * @param	const std::string& pAnimationFile, arquivo com o pacote de animaćões
		 */
		Object
		(
			const std::string& pSpriteFile,
			const std::string& pAnimationFile
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
		 * @version	29/09/2010
		 * @param	const Core::Point&		pPosition	, posicão a desenhar o objeto
		 * @param	const Mirroring&	pMirroring	, espelhamento a desenhar o objeto
		 */
		void draw(const Gorgon::Core::Point& mPosition, const Gorgon::Graphic::Mirroring& pMirroring) const;

		/**
		 * Método que realiza as operações lógicas do objeto
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	11/03/2009
		 * @version	28/05/2009
		 */
		//void logic();

		/**
		 * Método para rodar 1 passo da animaćão
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	29/09/2010
		 * @version	29/09/2010
		 */
		void animationRunStep();
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
		 * @since	29/09/2010
		 * @version	29/09/2010
		 * @param	const int& pFrame, novo frame
		 * @return	void
		 */
		void setFrameOn(const int& pFrame);
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
		 * Método que retorna o grupo da animaćão que está tocando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/01/2010
		 * @version	26/01/2010
		 * @return	int
		 */
		int getAnimationOnGroup() const;
		/**
		 * Método que retornar o índice da animaćão que está tocando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/01/2010
		 * @version	26/01/2010
		 * @return	int
		 */
		int getAnimationOnIndex() const;
		/**
		 * Método para setar o método de afterImage para Normal
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 */
//		void setAfterImageMethodNormal();
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
//		void setAfterImageMethodAdd
//		(
//			const Gorgon::Color&	pColorAdd,
//			const Gorgon::Color&	pColorSub,
//			const float&			pTrans
//		);
		/**
		 * Método para setar o método de afterImage para Transparent
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const float& pTrans , porcentagem da transparência
		 */
//		void setAfterImageMethodTrans(const float& pTrans);
		/**
		 * Método para abilitar ou desabilitar as AfterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const bool& pEnabled, se está habilitado ou não
		 */
//		void setAfterImageEnabled(const bool& pEnabled);
		/**
		 * Método para setar o delay em gameticks das afterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pDelay , delay em gameticks entre uma afterImage e outra
		 */
//		void setAfterImageDelay(const int& pDelay);
		/**
		 * Método para setar o Número de afterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pNumber, número de afterImages
		 */
//		void setAfterImageNumber(const int& pNumber);
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
//		void setAfterImageMode
//		(
//			const bool& pEnabled,
//			const int& pDelay,
//			const int& pImageNumber
//		);
		/**
		 * Método para retornar se o sistema de afterImages está habilitado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @return	bool
		 */
//		bool getAfterImageEnabled() const;
		/**
		 * Método para retornar o delay das afterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @return	int
		 */
//		int getAfterImageDelay() const;
		/**
		 * Método para retornar o número de afterImages
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @return	int
		 */
//		int getAfterImageNumber() const;
	protected:
		/**
		 * Método para desenhar uma afterImage usando o método Normal
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pImage, número da imagem no buffer  a desenhar
		 */
//		void drawAfterImageNormal(const int& pImage) const;
		/**
		 * Método para desenhar uma afterImage usando o método de transparencia
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pImage, número da imagem no buffer  a desenhar
		 */
//		void drawAfterImageTransparent(const int& pImage) const;
		/**
		 * Método para desenhar uma afterImage usando o método de Add
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	26/06/2009
		 * @version	26/06/2009
		 * @param	const int& pImage, número da imagem no buffer  a desenhar
		 */
//		void drawAfterImageAdd(const int& pImage) const;
};
#endif
