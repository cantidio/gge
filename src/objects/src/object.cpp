#include "../include/object.hpp"
//#include "../include/object_lua.hpp"

Object::Object
(
	const std::string& pSpritePackName,
	const std::string& pAnimationPackName
)
{
//	setAfterImageMode(false,0,0);
//	mAfterImageMethod	= NULL;
	
	mSpritePackName		= pSpritePackName;
	mAnimationPackName	= pAnimationPackName;
	mAnimationHandler	= new Gorgon::AnimationHandler
	(
		ResourceManager::SpriteManager::load(mSpritePackName),
		ResourceManager::AnimationManager::load(mAnimationPackName)
	);
}

//TextWindowLua::registerFunctions(mScript);

Object::~Object()
{
	ResourceManager::SpriteManager::unload(mSpritePackName);
	ResourceManager::AnimationManager::unload(mAnimationPackName);
//	mLastPositions.clear();
//	mLastDirections.clear();
//	mLastSprites.clear();
	delete mAnimationHandler;
}

void Object::draw(const Gorgon::Point& mPosition, const Gorgon::Mirroring& pMirroring) const
{
/*	if(mAfterImageMethod != NULL)
	{
		const int size	= mLastSprites.size() - 1;
		const int limit	= (getAfterImageNumber()-1 > size) ? size + 1 : getAfterImageNumber();

		for(register int i = 0; i < limit ; ++i)
		{
			((this)->*mAfterImageMethod)(size - i);
		}
	}
*/
	mAnimationHandler->draw
	(
		Gorgon::Video::get(),
		(int)mPosition.getX(),
		(int)mPosition.getY(),
		pMirroring
	);
}

void Object::animationRunStep() 
{
	mAnimationHandler->playByStep();
}

int Object::getAnimationRealIndex(const int& pGroup, const int& pIndex) const
{
	return mAnimationHandler->getAnimationPack().getAnimationRealIndex(pGroup,pIndex);
}

void Object::changeAnimation(const int& pAnimation)
{
	mAnimationHandler->changeAnimation(pAnimation,true);
}

void Object::changeAnimation(const int& pGroup, const int& pIndex)
{
	mAnimationHandler->changeAnimation(pGroup,pIndex,true);
}

bool Object::animationIsPlaying() const
{
	return mAnimationHandler->isPlaying();
}

int Object::getAnimationOn() const
{
	return mAnimationHandler->getAnimationOn();
}

int Object::getAnimationOnGroup() const
{
	return mAnimationHandler->getAnimationOnGroup();
}

int Object::getAnimationOnIndex() const
{
	return mAnimationHandler->getAnimationOnIndex();
}

int Object::getFrameOn() const
{
	return mAnimationHandler->getFrameOn();
}

void Object::setFrameOn(const int& pFrame)
{
	mAnimationHandler->jumpToFrame(pFrame);
}

/*void Object::logic()
{
	mAnimationHandler->playByStep();

	if(mAfterImageDelayInUse % getAfterImageDelay() == 0)
	{
		mAfterImageDelayInUse = 0;
		if(getAfterImageEnabled())
		{
			if(mLastDirections.size() >= mAfterImageNumber)
			{
				mLastDirections.erase(mLastDirections.begin());
				mLastPositions.erase(mLastPositions.begin());
				mLastSprites.erase(mLastSprites.begin());
			}

			mLastDirections.push_back(mDirection);
			mLastPositions.push_back(mPosition);
			mLastSprites.push_back(&mAnimationHandler->getCurrentSprite());
		}
		else if(mLastDirections.size() > 0)
		{
			mAfterImageDelayInUse = 0;
			mLastDirections.erase(mLastDirections.begin());
			mLastPositions.erase(mLastPositions.begin());
			mLastSprites.erase(mLastSprites.begin());
		}
	}
	++mAfterImageDelayInUse;
	
}

void Object::drawAfterImageNormal(const int& pImage) const
{
	Gorgon::Video::get().drawSpriteRotetedFlipped
	(
		*mLastSprites[pImage],
		(int)mLastPositions[pImage].getX(),
		(int)mLastPositions[pImage].getY(),
		0,
		mLastDirections[pImage]
	);
}

void Object::drawAfterImageTransparent(const int& pImage) const
{
	Gorgon::Video::get().drawSpriteTransFlipped
	(
		*mLastSprites[pImage],
		(int)mLastPositions[pImage].getX(),
		(int)mLastPositions[pImage].getY(),
		mAfterImageTrans,
		mLastDirections[pImage]
	);
}

void Object::drawAfterImageAdd(const int& pImage) const
{
	Gorgon::Video::get().drawSpriteAdd
	(
		*mLastSprites[pImage],
		(int)mLastPositions[pImage].getX(),
		(int)mLastPositions[pImage].getY(),
		mAfterImageColorAdd,
		mAfterImageColorSub,
		mAfterImageTrans
	);
}

void Object::setAfterImageDelay(const int& pDelay)
{
	mAfterImageDelay = (pDelay > 0) ? pDelay : 1;
}

void Object::setAfterImageEnabled(const bool& pEnabled)
{
	mAfterImageEnabled = pEnabled;
}

void Object::setAfterImageMethodNormal()
{
	mAfterImageMethod = &Object::drawAfterImageNormal;
}

void Object::setAfterImageMethodAdd
(
	const Gorgon::Color&	pColorAdd,
	const Gorgon::Color&	pColorSub,
	const float&			pTrans
)
{
	mAfterImageColorAdd	= pColorAdd;
	mAfterImageColorSub	= pColorSub;
	mAfterImageTrans	= pTrans;
	mAfterImageMethod	= &Object::drawAfterImageAdd;
}

void Object::setAfterImageMethodTrans(const float& pTrans)
{
	mAfterImageTrans	= pTrans;
	mAfterImageMethod	= &Object::drawAfterImageTransparent;
}

void Object::setAfterImageMode
(
	const bool& pEnabled,
	const int& pDelay,
	const int& pImageNumber
)
{
	setAfterImageEnabled(pEnabled);
	setAfterImageDelay(pDelay);
	setAfterImageNumber(pImageNumber);
	mAfterImageDelayInUse = 0;
}

void Object::setAfterImageNumber(const int& pNumber)
{
	mAfterImageNumber = pNumber;
}

bool Object::getAfterImageEnabled() const
{
	return mAfterImageEnabled;
}

int Object::getAfterImageDelay() const
{
	return mAfterImageDelay;
}

int Object::getAfterImageNumber() const
{
	return mAfterImageNumber;
}
*/
