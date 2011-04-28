/*
 * File:   main.cpp
 * Author: aniquilator
 *
 * Created on December 12, 2009, 2:03 PM
 */
#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/image_loader/magick++/gorgon_image_loader.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;
using namespace Gorgon;

#define LM " >> "
#define MSG cout << LM

typedef struct
{
	Point	position;
	int		animation;
}Tile;

typedef struct
{
	int tileWidth;
	int tileHeight;
	SpritePack		sprite;
	AnimationPack	animation;
	string imageName;
	vector<Tile> tiles;
}Layer;

typedef struct
{
	string name;
	int width;
	int height;
	int layerNumber;
	vector<Layer> layers;
}BG;
/**
 * Function that generates a tilesheet with the Layer's tiles
 *
 * @author	Cantidio Oliveira Fontes
 * @since	14/10/2010
 * @version	16/10/2010
 * @param	const string& pImageName, tilesheet image's name
 * @param	Layer& pLayer, the layer that will generate the tilesheet
 */
void createTileSheet(const string& pImageName, Layer& pLayer)
{
	const int rows = (int)sqrt(pLayer.sprite.getSize()) + 1;
	Image aux(pLayer.tileWidth * rows + rows, pLayer.tileHeight* rows + rows);
	aux.clear(0xFF00FF);
	int h,w,i;
	for(i = h = 0; h < rows && i < pLayer.sprite.getSize(); ++h)
	{
		for(int w = 0; w < rows && i < pLayer.sprite.getSize(); ++w,++i)
		{
			aux.drawImage
			(
				pLayer.sprite[i],
				w + pLayer.tileWidth * w,
				h + pLayer.tileHeight * h
			);
		}
	}
	aux.save(pImageName);
}
/**
 * Function that generates the layer based in the image registered in it
 *
 * @author	Cantidio Oliveira Fontes
 * @since	14/10/2010
 * @version	16/10/2010
 * @param	Layer& pLayer, the layer that will be populate
 * @details
 *			This function generates the tiles, the SpritePack
 * and the AnimationPack of the Layer
 */
void createBgLayerFromImage(Layer& pLayer)
{
	Image image(pLayer.imageName);
	register int h,w,i;

	for(h = 0; h < image.getHeight(); h+=pLayer.tileHeight)
	{
		for(w = 0; w < image.getWidth(); w+=pLayer.tileWidth)
		{
			Image	tileimg(pLayer.tileWidth, pLayer.tileHeight);
			Tile	tile;
			tile.position = Point(w,h);
			tileimg.blitImage
			(
				image,
				0, 0, w, h,
				pLayer.tileWidth,
				pLayer.tileHeight
			);
			if(!tileimg.isEmpty()) //só adiciona ao pacte se o tile possuir algum conteúdo
			{
				for(i = 0; i < pLayer.sprite.getSize(); ++i)
				{
					if(pLayer.sprite[i] == tileimg) // já temos um tile igual no pacote
						break;
				}
				if(i >= pLayer.sprite.getSize())
				{
					pLayer.sprite.add(Sprite(tileimg,w,h));
					pLayer.animation.add(Animation(w,h));
					pLayer.animation[i].add(Frame(w,h,-1));
				}
				tile.animation = i;
				pLayer.tiles.push_back(tile);

				Video::get().drawImage(tileimg,w,h);
				Video::get().show();
			}
		}
	}
	while(!key[KEY_ESC])
	{
		Video::get().drawImage(image,0,0);
		Video::get().show();
	}
}
/**
 * Function that creates the Layer
 *
 * @author	Cantidio Oliveira Fontes
 * @since	14/10/2010
 * @version	16/10/2010
 * @param	const string& pLayerName	, the name of the Layer
 * @param	Layer& pLayer				, the Layer to be populated
 * @param	Script::Lua& pLua			, the lua script to generate the code
 */
void createBgLayer
(
	const string&	pLayerName,
	Layer&			pLayer,
	Script::Lua&	pLua
)
{
	string aux = pLayerName;
	aux.insert(aux.length(), ".lua");
	Core::File file(aux, ios::out);
	string spritepack		= pLayerName;
	string animationpack	= pLayerName;
	spritepack.insert(spritepack.length(),".gspk");
	animationpack.insert(animationpack.length(),".gapk");
	
	string tiles = ""; //gera o código dos tiles
	for(int i = 0; i < pLayer.tiles.size(); ++i)
	{
		tiles.insert
		(
			tiles.length(),
			pLua.function
			(
				"make_tile",
				Script::LuaParam
				(
					"ddd",//d-> number
					pLayer.tiles[i].animation,
					(int)pLayer.tiles[i].position.getX(),
					(int)pLayer.tiles[i].position.getY()
				),
				1
			).getStringValue()
		);
	}
	
	file << pLua.function
	(
		"make_Layer_class",
		Script::LuaParam
		(
			"ssss",		//s->string
			pLayerName.c_str(),
			spritepack.c_str(),
			animationpack.c_str(),
			tiles.c_str()
		),
		1
	).getStringValue() << endl;
	
	pLayer.sprite.save(spritepack);
	pLayer.animation.save(animationpack);
	
	//createTileSheet( spritepack.insert(spritepack.length(),".bmp"), pLayer);
	
	file.close();	
}
/**
 * Function that creates the background
 *
 * @author	Cantidio Oliveira Fontes
 * @since	16/10/2010
 * @version	16/10/2010
 * @param	BG&				pBG		, the background to be created
 * @param	Script::Lua&	pLua	, the lua script to generate the code
 */
void createBg(BG& pBg, Script::Lua& pLua)
{
	string aux = pBg.name;
	aux.insert(pBg.name.length(),".lua");
	Core::File file(aux, ios::out);
	
	for(int i = 0; i < pBg.layerNumber; ++i)
	{
		stringstream layerName;
		layerName << pBg.name << "_layer_" << (i + 1);
		file << "include(\"" << layerName.str() << ".lua\")" << endl;
		
		createBgLayerFromImage(pBg.layers[i]);
		createBgLayer(layerName.str(), pBg.layers[i], pLua);
	}
	file << endl;
	file << pLua.function
	(
		"make_BG_class",
		Script::LuaParam
		(
			"sddd",		//s->string d-> number
			pBg.name.c_str(),
			pBg.width,
			pBg.height,
			pBg.layerNumber
		),
		1
	).getStringValue() << endl;
	file.close();
}

void strNormalize(string& pBgName)
{
	for(size_t found = pBgName.find(" "); found != string::npos; found = pBgName.find(" "))
	{
		pBgName.replace(found, 1, "_");
	}
}

int main(int argc, char** argv)
{
    string bgImageName;
    int tileSize;
    BG bg;
	Script::Lua lua;
	lua.loadScript("background_generator.lua");
	lua.loadScript("background_generator_msg.lua");
	
	allegro_init();
	install_keyboard();
	
	ImageLoader::setLoader(new ImageLoaderMagick());
    Gorgon::Video::init("Background Generator",640,480);
	
	MSG << lua.getStringVar("msg_welcome") << endl;
	MSG << lua.getStringVar("msg_input_bg_name") << ":" << endl;
	MSG;   getline(cin, bg.name); strNormalize(bg.name);
	MSG << lua.getStringVar("msg_input_bg_width") << ":" << endl;
	MSG;   cin >> bg.width;
	MSG << lua.getStringVar("msg_input_bg_height") << ":" << endl;
	MSG;   cin >> bg.height;
	MSG << lua.getStringVar("msg_input_bg_layer_number") << ":" << endl;
	MSG;   cin >> bg.layerNumber;
	
	for(int i = 0; i < bg.layerNumber; ++i)
	{
		Layer layer;
		MSG << lua.getStringVar("msg_processing_bg_layer") << ": " << (i+1) << endl;
		MSG << lua.getStringVar("msg_input_bg_layer_tile_width") << ":" << endl;
		MSG;   cin >> layer.tileWidth;
		MSG << lua.getStringVar("msg_input_bg_layer_tile_height") << ":" << endl;
		MSG;   cin >> layer.tileHeight;
		MSG << lua.getStringVar("msg_input_bg_layer_image_name") << ":" << endl;
		cin.ignore(INT_MAX,'\n');
		MSG;   getline(cin, layer.imageName);
		bg.layers.push_back(layer);
	}
	
	MSG << lua.getStringVar("msg_creating_bg_script") << "..." << endl;
	
	createBg(bg,lua);
	
	MSG << lua.getStringVar("msg_done") << endl;
    return 0;
}

