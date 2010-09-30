#include "../include/tile.hpp"

Tile::Tile
(
	Gorgon::SpritePack&		pSpritePack,
	Gorgon::AnimationPack&	pAnimationPack,
	const int&				pAnimationNumber
)
{
	mAnimationHandler	= new Gorgon::AnimationHandler(pSpritePack, pAnimationPack);
	mAnimationHandler->optimize();
	mAnimationHandler->changeAnimation(pAnimationNumber,true);
}

Tile::Tile(const Tile& pOrig)
{
	mAnimationHandler	= new Gorgon::AnimationHandler(*pOrig.mAnimationHandler);
}

Tile::~Tile()
{
	if(mAnimationHandler != NULL)
	{
		delete mAnimationHandler;
	}
}

int Tile::getAnimation() const
{
	return mAnimationHandler->getAnimationOn();
}

void Tile::setAnimation(const int& pAnimation)
{
	mAnimationHandler->changeAnimation(pAnimation);
}

void Tile::logic()
{
	mAnimationHandler->playByStep();
}

void Tile::draw(const Gorgon::Point& pPosition)
{
	mAnimationHandler->draw
	(
		Gorgon::Video::get(),
		pPosition.getX(),
		pPosition.getY()
	);
}

