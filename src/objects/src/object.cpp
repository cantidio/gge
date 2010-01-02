#include "../include/object.hpp"
#include "../include/object_lua.hpp"

Object::Object(Layer* pLayer)
{
	setAfterImageMode(false,0,0);
	mAfterImageMethod	= NULL;
	mScript				= new Gorgon::Lua("data/object/class_object.lua");
	mLayer				= pLayer;
}

Object::Object
(
	const std::string&		pScriptName,
	const Gorgon::Point&	pPosition,
	Layer*					pLayer
)
{
	setPosition(pPosition);
	setAfterImageMode(false,0,0);
	mAfterImageMethod	= NULL;
	mLayer				= pLayer;
	mScript				= new Gorgon::Lua("data/object/class_object.lua");
	mScript->loadScript(pScriptName);
	setUp();
}

void Object::setUp()
{
	loadGlobalVars();
	mScript->function("script_object_setPointer",Gorgon::LuaParam("n",this));
	ObjectLua::registerFunctions(mScript);
	TextWindowLua::registerFunctions(mScript);
	mSpritePack			= ResourceManager::SpriteManager::load(mSpritePackName);
	mAnimationPack		= ResourceManager::AnimationManager::load(mAnimationPackName);
	mAnimationHandler	= new Gorgon::AnimationHandler(*mSpritePack,*mAnimationPack);
}

void Object::loadGlobalVars()
{
	mName				= mScript->function("script_object_getName",Gorgon::LuaParam(),1)->getStringValue();
	mId					= mScript->function("script_object_getId",Gorgon::LuaParam(),1)->getStringValue();
	mSpritePackName		= mScript->function("script_object_getSpritePack",Gorgon::LuaParam(),1)->getStringValue();
	mAnimationPackName	= mScript->function("script_object_getAnimationPack",Gorgon::LuaParam(),1)->getStringValue();

	//mColisionPackName	= mScript->getStringVar("colision");
	//mPaletteName		= mScript->getStringVar("palette");
	setAfterImageMode(false,0,0);
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

void Object::setLayer(Layer* pLayer)
{
	mLayer = pLayer;
}

Layer* Object::getLayer()
{
	return mLayer;
}

void Object::setMirroring(const Gorgon::Mirroring& pMirroring)
{
	mDirection = pMirroring;
}

Gorgon::Mirroring Object::getMirroring() const
{
	return mDirection;
}

void Object::setPosition(const Gorgon::Point& pPosition)
{
	mPosition = pPosition;
}

void Object::addPosition(const Gorgon::Point& pPosition)
{
	mPosition += pPosition;
}

void Object::subPosition(const Gorgon::Point& pPosition)
{
	mPosition -= pPosition;
}

Gorgon::Point Object::getPosition() const
{
	return mPosition;
}

void Object::draw() const
{
	if(mAfterImageMethod != NULL)
	{
		const int size	= mLastSprites.size() - 1;
		const int limit	= (getAfterImageNumber()-1 > size) ? size + 1 : getAfterImageNumber();

		for(register int i = 0; i < limit ; ++i)
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
	mScript->function("script_object_logic");
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