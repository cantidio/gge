#include "../include/tile.hpp"

Tile::Tile
(
	Gorgon::SpritePack&		pSpritePack,
	Gorgon::AnimationPack&	pAnimationPack,
	const int&				pAnimationNumber
)
{
	mAnimationHandler = new Gorgon::AnimationHandler(pSpritePack,pAnimationPack);
	mAnimationHandler->optimize();
	mAnimationHandler->changeAnimation(pAnimationNumber,true);
}

Tile::Tile(const Tile& pOrig)
{
	mAnimationHandler= new Gorgon::AnimationHandler(*pOrig.mAnimationHandler);
	for(int i = 0; i < pOrig.mPosX.size(); ++i)
	{
		mPosX.push_back(pOrig.mPosX[i]);
		mPosY.push_back(pOrig.mPosY[i]);
	}
}

Tile::~Tile()
{
	mPosX.clear();
	mPosY.clear();

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
	std::cout << "Positions:"		<<	std::endl;

	for(int i=0; i < mPosX.size(); ++i)
	{
		std::cout << "posX: " << mPosX[i] << " posY: " << mPosY[i] << std::endl;
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

int Tile::getXPosition(const int& pIndex) const
{
	if(pIndex < mPosX.size())
	{
		return mPosX[pIndex];
	}
	return 0;
}

int Tile::getYPosition(const int& pIndex) const
{
	if(pIndex < mPosY.size())
	{
		return mPosY[pIndex];
	}
	return 0;
}

void Tile::setPosition
(
	const int& pIndex,
	const int& pPosX,
	const int& pPosY
)
{
	if(pIndex < mPosY.size())
	{
		mPosX[pIndex] = pPosX;
		mPosY[pIndex] = pPosY;
	}
}

int Tile::getSize() const
{
	return mPosX.size();
}

void Tile::add(const int& pPosX, const int& pPosY)
{
	mPosX.push_back(pPosX);
	mPosY.push_back(pPosY);
}

void Tile::remove(const int& pIndex)
{
	mPosX.erase(mPosX.begin() + pIndex);
}

void Tile::logic()
{
	mAnimationHandler->playByStep();
}

void Tile::draw
(
	Gorgon::Sprite&	pSprite,
	const int&		pPosX,
	const int&		pPosY
)
{
	for(int i=0; i < mPosX.size(); ++i)
	{
		mAnimationHandler->draw
		(
			pSprite,
			pPosX + mPosX[i],
			pPosY + mPosY[i]
		);
	}
}
