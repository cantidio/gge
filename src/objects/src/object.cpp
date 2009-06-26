
#include <vector>

#include "../include/object.hpp"
#include "../include/object_lua.hpp"

Object::Object()
{
	setAfterImageMode(false,0,0);
	mAfterImageMethod = NULL;
	mScript = new Gorgon::Lua("data/object/object.lua");
}

void Object::loadGlobalVars()
{
	mName				= mScript->getStringVar("name");
	mSpritePackName		= mScript->getStringVar("sprite");
	mAnimationPackName	= mScript->getStringVar("animation");
	mColisionPackName	= mScript->getStringVar("colision");
	mPaletteName		= mScript->getStringVar("palette");
	mXPulse				= mScript->getNumericVar("xPulse");
	mYPulse				= mScript->getNumericVar("yPulse");
	mXPulseMax			= mScript->getNumericVar("xPulseMax");
	mGravityAffected	= mScript->getBooleanVar("gravityAffected");
	setAfterImageMode(false,0,0);
}

void Object::setUp()
{
	loadGlobalVars();
	mScript->function("getObject",Gorgon::LuaParam("n",this));
	ObjectLua::registerFunctions(mScript);
	mSpritePack			= ResourceManager::SpriteManager::load(mSpritePackName);
	mAnimationPack		= ResourceManager::AnimationManager::load(mAnimationPackName);
	mAnimationHandler	= new Gorgon::AnimationHandler(*mSpritePack,*mAnimationPack);
}

Object::Object(const std::string& pScriptName,const Gorgon::Point& pPosition)
{
	setPosition(pPosition);
	setAfterImageMode(false,0,0);
	mAfterImageMethod = NULL;
	mScript	= new Gorgon::Lua("data/object/object.lua");
	mScript->loadScript(pScriptName);
	setUp();
}

Object::~Object()
{
	ResourceManager::SpriteManager::unload(mSpritePackName);
	ResourceManager::AnimationManager::unload(mAnimationPackName);
	mLastPositions.clear();
	mLastDirections.clear();
	mLastSprites.clear();
	delete mAnimationHandler;
}

void Object::setMirroring(const Gorgon::Mirroring& pMirroring)
{
	mDirection = pMirroring;
}

Gorgon::Mirroring Object::getMirroring() const
{
	return mDirection;
}

void Object::setXPosition(const double& pPosX)
{
	mPosition.setX(pPosX);
}

void Object::setYPosition(const double& pPosY)
{
	mPosition.setY(pPosY);
}

void Object::setPosition(const Gorgon::Point& pPosition)
{
	mPosition = pPosition;
}

void Object::addXPosition(const double& pPosX)
{
	mPosition.addX(pPosX);
}

void Object::addYPosition(const double& pPosY)
{
	mPosition.addY(pPosY);
}

	void Object::addPosition(const double& pPosX,const double& pPosY)
{
	mPosition.addX(pPosX);
	mPosition.addY(pPosY);
}

void Object::subXPosition(const double& pPosX)
{
	mPosition.subX(pPosX);
}

void Object::subYPosition(const double& pPosY)
{
	mPosition.subY(pPosY);
}

void Object::subPosition(const double& pPosX,const double& pPosY)
{
	mPosition.subX(pPosX);
	mPosition.subY(pPosY);
}

double Object::getXPosition() const
{
	return mPosition.getX();
}

double Object::getYPosition() const
{
	return mPosition.getY();
}

void Object::draw() const
{
	if(mAfterImageMethod != NULL)
	{
		const int size	= mLastSprites.size() - 1;
		const int limit	= (getAfterImageNumber()-1 > size) ? size + 1 : getAfterImageNumber();

		for(register int i = 0; i <limit ; ++i)
		{
			((this)->*mAfterImageMethod)(size - i);
		}
	}
	
	mAnimationHandler->draw
	(
		Gorgon::Video::get(),
		(int)mPosition.getX(),
		(int)mPosition.getY(),
		mDirection
	);
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

int Object::getFrameOn() const
{
	return mAnimationHandler->getFrameOn();
}

void Object::logic()
{
	mScript->function("logic");
	mAnimationHandler->playByStep();

	if(mAfterImageDelayInUse%getAfterImageDelay() == 0)
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
		else if(mLastDirections.size()>0)
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
	Gorgon::Video::get().drawSpriteTrans
	(
		*mLastSprites[pImage],
		(int)mLastPositions[pImage].getX(),
		(int)mLastPositions[pImage].getY(),
		mAfterImageTrans
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
	mAfterImageDelay = (pDelay>0) ? pDelay : 1;
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