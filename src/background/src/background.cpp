
#include <string>

#include "../include/background.hpp"

Background::Background
(
	const int& width,
	const int& height,
	const int& posX,
	const int& posY
)
{
	this->width		= width;
	this->height	= height;
	this->posX		= posX;
	this->posY		= posY;
}

Background::~Background()
{
	layers.clear();
}

void Background::addLayer(Layer& layer)
{
	layers.push_back(layer);
}

void Background::logic()
{
	for(int i=0; i<layers.size(); ++i)
	{
		layers[i].logic();
	}
}

void Background::draw(Gorgon::Sprite& sprite)
{
	for(int i=0; i<layers.size(); ++i)
	{
		layers[i].draw(sprite,posX,posY);
	}
}

void Background::save(const std::string& fileName) const
{
	std::fstream file(fileName.c_str(),std::ios::out);
	
	if(file.is_open())
	{
		file << "--Background Script File just modify if you know what you are doing" << std::endl;
		file << "--width of the background" << std::endl;
		file << "width	= " << width << std::endl;
		file << "--height of the background" << std::endl;
		file << "height	= " << height << std::endl;
		file << "--init x position" << std::endl;
		file << "posX	= " << posX << std::endl;
		file << "--init y position" << std::endl;
		file << "posY	= " << posY << std::endl;
		file << "--vector with the layers of the background" << std::endl;
		file << "layers	= {";
		if(layers.size()>0)
		{
			file << std::endl;
			for(int i=0; i<layers.size(); ++i)
			{
				std::stringstream layerName;
				layerName << fileName.substr(0,fileName.find(".")) << "_layer" << i << fileName.substr(fileName.find("."),fileName.length()-1);
				
				file << "\t\"" << layerName.str() << "\"," << std::endl;
				layers[i].save(layerName.str());
			}
		}
		file << "}" << std::endl << std::endl;
		file << "function logic()" << std::endl;
		file << "\t--Put your background logic here" << std::endl;
		file << "end" << std::endl << std::endl;
	}
	else
	{
		std::cout <<"Erro ao salvar cenário!\n";
	}
	file.close();
}



