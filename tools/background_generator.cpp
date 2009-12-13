/*
 * File:   main.cpp
 * Author: aniquilator
 *
 * Created on December 12, 2009, 2:03 PM
 */
#include <gorgon++/gorgon.hpp>
#include <iostream>
#include <string>
#include <gsbge/src/background/include/background.hpp>
#include <math.h>
/*
 *
 */
using namespace std;
using namespace Gorgon;
void createSpritePackFromImage(const Image& pImage, const int& pTileSize,SpritePack* pSpritePack)
{
	Image* aux;
	bool isEqual;
	for(int h = pImage.getHeight() - pTileSize ; h > -1 ; h-=pTileSize)
    {
        for(int w = pImage.getWidth() - pTileSize ; w > -1; w-=pTileSize)
		{
			isEqual = false;
			aux		= new Image(pTileSize,pTileSize);
			aux->blitImage
			(
				pImage,
				0,
				0,
				w,
				h,
				pTileSize,
				pTileSize,
				false
			);
			if(!aux->isEmpty())
			{
				for(int i = pSpritePack->getSize() - 1; i > -1; --i)
				{
					if((*pSpritePack)[i] == (*aux))
					{
						isEqual = true;
						break;
					}
				}
				if(!isEqual)
				{
					pSpritePack->add
					(
						Sprite
						(
							*aux,
							0,
							pSpritePack->getSize()
						)
					);
				}
			}
			delete aux;
        }
    }
	cout << pSpritePack->getSize() <<" different tiles were found." << endl;
}

void createTileSheet( const int& pTileSize,const SpritePack* pSpritePack)
{
	const int rows = (int)sqrt(pSpritePack->getSize()) + 1;
	Image aux(pTileSize * rows + rows, pTileSize* rows + rows);
	aux.clear(0xFF00FF);
	int h,w,i;
	for(i = h = 0; h < rows && i < pSpritePack->getSize(); ++h)
	{
		for(int w = 0; w < rows && i < pSpritePack->getSize(); ++w,++i)
		{
			aux.drawImage((*pSpritePack)[i],w + pTileSize*w,h + pTileSize*h);
		}
	}
	//cout << "raiz: " <<  << endl;
	aux.save("lastsheet.bmp");
}

int doBackgroundFromImage(const string& pBgImageName, const int& pTileSize)
{
    Image bgImage(pBgImageName);
    Layer layer;
	SpritePack*		spritePack		= layer.getSpritePack();
	AnimationPack*	animationPack	= layer.getAnimationPack();
	Image* aux;
	bool isEqual;
	int pos;
	createSpritePackFromImage(bgImage,pTileSize,spritePack);

	for(int i = 0; i < spritePack->getSize(); ++i)
	{
		animationPack->add(Animation(0,i));
		(*animationPack)[i].add(Frame(0,i,-1));
	}
    
    for(int h = bgImage.getHeight() - pTileSize; h > -1 ; h-=pTileSize)
    {
        for(int w = bgImage.getWidth() - pTileSize; w > -1; w-=pTileSize)
		{
			isEqual = false;
			aux = new Image(pTileSize,pTileSize);
			aux->blitImage
			(
				bgImage,
				0,
				0,
				w,
				h,
				pTileSize,
				pTileSize,
				false
			);
			if(!aux->isEmpty())
			{
				for(int i = layer.getTileNumber() - 1; i > -1; --i)
				{
					if((*spritePack)[(*animationPack)[layer[i].getAnimation()][0].getIndex()] == *aux)
					{
						isEqual = true;
						layer[i].add(w,h);
					}
				}
				if(!isEqual)
				{
					for(int i = spritePack->getSize() - 1; i > -1; --i)
					{
						if((*spritePack)[i] == *aux)
						{
	//						cout << "addtile" << endl;
							layer.addTile
							(
								new Tile
								(
									*spritePack,
									*animationPack,
									i
								)
							);
							layer[layer.getTileNumber()-1].add(w,h);
							break;
						}
					}
				}
			}
			delete aux;
        }
    }
	layer.draw(Video::get(),10,10);
	Video::get().show();
	while(!key[KEY_ESC]);

	
	string spriteName		= pBgImageName;
	string animationName	= pBgImageName;
	string layerName		= pBgImageName;

	spriteName.append(".gspk");
	animationName.append(".gapk");
	layerName.append("_layer.lua");

	spritePack->save(spriteName);
	animationPack->save(animationName);
	layer.save(layerName);
	createTileSheet(pTileSize,spritePack);
	delete spritePack;
	delete animationPack;
}

int main(int argc, char** argv)
{
    string bgImageName;
    int tileSize;
	/*cout << "Digite quantas camadas o cenário possui: ";
	cin << bglayerNumber;
	for(int i = 0; i < bglayerNumber; ++i)
	{
	 cout << "Digite o nome da imagem do layer: " << i+1 << " do cenário: ";
	 cin >> s




	}*/
    cout << "Digite o nome da imagem do cenário: ";
    cin >> bgImageName;
    cout << endl;
    cout << "Digite o lado do tile a ser usado: ";
    cin >> tileSize;
    cout << endl;
    allegro_init();
	install_keyboard();
    Gorgon::Video::init("Background Generator",400,300);
    doBackgroundFromImage(bgImageName,tileSize);
	//doBackgroundFromImage("breakman.pcx",16);
    //breakman.bmp 16
    return (EXIT_SUCCESS);
}

