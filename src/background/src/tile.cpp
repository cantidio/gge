#include "../include/tile.hpp"

Tile::Tile
(
	Gorgon::SpritePack&		pSpritePack,
	Gorgon::AnimationPack&	pAnimationPack,
	const int&				pAnimationNumber,
	const Gorgon::Point&	pPosition,
	Layer*					pLayer
)
{
	mPosition			= pPosition;
	mLayer				= pLayer;
	mAnimationHandler	= new Gorgon::AnimationHandler(pSpritePack,pAnimationPack);
	mAnimationHandler->optimize();
	mAnimationHandler->changeAnimation(pAnimationNumber,true);
}

Tile::Tile(const Tile& pOrig)
{
	mAnimationHandler	= new Gorgon::AnimationHandler(*pOrig.mAnimationHandler);
	mPosition			= pOrig.mPosition;
	mLayer				= pOrig.mLayer;
}

Tile::~Tile()
{
	if(mAnimationHandler != NULL)
	{
		delete mAnimationHandler;
	}
}

void Tile::describe() const
{
	std::cout << "Tile Describer"	<<	std::endl;
	std::cout << "Memory SprPack:"	<<	&mAnimationHandler->getSpritePack()		<< std::endl;
	std::cout << "Memory AniPack:"	<<	&mAnimationHandler->getAnimationPack()	<< std::endl;
	std::cout << "Animation:"		<<	mAnimationHandler->getAnimationOn()		<< std::endl;
	std::cout << "Position:"		<<	std::endl;
	mPosition.describe();
}

Layer* Tile::getLayer()
{
	return mLayer;
}

int Tile::getAnimation() const
{
	return mAnimationHandler->getAnimationOn();
}

void Tile::setAnimation(const int& pAnimation)
{
	mAnimationHandler->changeAnimation(pAnimation);
}

Gorgon::Point Tile::getPosition() const
{
	return mPosition;
}

void Tile::setPosition(const Gorgon::Point& pPosition)
{
	mPosition = pPosition;
}

void Tile::logic()
{
	mAnimationHandler->playByStep();
}

void Tile::draw(Gorgon::Sprite&	pSprite,const Gorgon::Point& pPosition)
{
	mAnimationHandler->draw
	(
		pSprite,
		mPosition.getX() + pPosition.getX(),
		mPosition.getY() + pPosition.getY()
	);
}
