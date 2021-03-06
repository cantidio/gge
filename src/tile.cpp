#include "../include/tile.hpp"

Tile::Tile
(
	Gorgon::Graphic::SpritePack&	pSpritePack,
	Gorgon::Graphic::AnimationPack&	pAnimationPack,
	const int&						pAnimationNumber
)
{
	mAnimationHandler	= new Gorgon::Graphic::AnimationHandler(pSpritePack, pAnimationPack);
	mAnimationHandler->optimize();
	mAnimationHandler->changeAnimation(pAnimationNumber,true);
}

Tile::Tile(const Tile& pOrig)
{
	mAnimationHandler	= new Gorgon::Graphic::AnimationHandler(*pOrig.mAnimationHandler);
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

void Tile::draw(const Gorgon::Core::Point& pPosition)
{
	mAnimationHandler->draw( pPosition , 0, Gorgon::Graphic::Mirroring::Normal);
}

