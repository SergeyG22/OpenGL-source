#include "parameters.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


void Parameters::load_texture(std::string name_texture)
{
	sf::Image data_img;
	data_img.loadFromFile(name_texture);
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 128, 128, 0, GL_RGBA, GL_UNSIGNED_BYTE, data_img.getPixelsPtr());
}
