#include "../include/tile.hpp"

Tile::Tile
(
	Gorgon::SpritePack& spritePack,
	Gorgon::AnimationPack& animationPack,
	const int& animationNumber
)
{
	animationHandler=new Gorgon::AnimationHandler(spritePack,animationPack);
	animationHandler->optimize();
	animationHandler->changeAnimation(animationNumber,true);
}

Tile::Tile(const Tile& orig)
{
	animationHandler= new Gorgon::AnimationHandler(*orig.animationHandler);
	for(int i=0; i<orig.posX.size(); ++i)
	{
		posX.push_back(orig.posX[i]);
		posY.push_back(orig.posY[i]);
	}
}

Tile::~Tile()
{
	posX.clear();
	posY.clear();
	if(animationHandler!=NULL)
		delete animationHandler;
}

void Tile::describe() const
{
	std::cout << "Tile Describer" << std::endl;
	std::cout << "Memory SprPack:" << &animationHandler->getSpritePack() << std::endl;
	std::cout << "Memory AniPack:" << &animationHandler->getAnimationPack()<< std::endl;
	std::cout << "Animation:" << animationHandler->getAnimationOn() << std::endl;
	std::cout << "Positions:" << std::endl;
	for(int i=0; i<posX.size(); ++i)
	{
		std::cout << "posX: " << posX[i] << " posY: " << posY[i] << std::endl;
	}
}

int Tile::getAnimation() const
{
	return animationHandler->getAnimationOn();
}

int Tile::getXPostion(const int& index) const
{
	if(index<posX.size())
	{
		return posX[index];
	}
	return 0;
}

int Tile::getYPostion(const int& index) const
{
	if(index<posY.size())
	{
		return posY[index];
	}
	return 0;
}

int Tile::getSize() const
{
	return posX.size();
}

void Tile::add(const int& x, const int& y)
{
	posX.push_back(x);
	posY.push_back(y);
}

void Tile::logic()
{
	this->animationHandler->playByStep();
}

void Tile::draw
(
	Gorgon::Sprite& sprite,
	const int& x,
	const int& y
)
{
	for(int i=0; i<posX.size(); ++i)
	{
		animationHandler->draw
		(
			sprite,
			x+posX[i],
			y+posY[i]
		);
	}
}
