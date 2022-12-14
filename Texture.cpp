#include <iostream>
#include "Texture.h"
#include <GL/glut.h>
#include <stb_image.h>
#include "HeightMap.h"

Texture::Texture(const char* path) {
	loadTexture(path);
}

Texture::~Texture() {
	stbi_image_free(image);
}

void Texture::use() {
	if (!loaded)
	{
		std::cout << "WARNING: Trying to use a texture that wasn't loaded correctly" << std::endl;
		return;
	}
	if (image)
	{
		glEnable(GL_TEXTURE_2D);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	}
}


Pixel Texture::getPixelAt(int x, int y) 
{

	Pixel p;

	p.r = 255.0f;
	p.g = 255.0f;
	p.b = 0.0f;
	p.a = 255.0f;


	if (!loaded)
	{
		std::cout << "WARNING: Trying to access pixel data of a texture that wasn't loaded correctly" << std::endl;
		return p;
	}
	if (image)
	{
		unsigned char* pixelOffset = image + ((x + width * y) * channels);
		
		if (channels >= 1) p.r = static_cast<int>(pixelOffset[0]) / 255.0f;
		if (channels >= 2) p.g = static_cast<int>(pixelOffset[1]) / 255.0f;
		if (channels >= 3) p.b = static_cast<int>(pixelOffset[2]) / 255.0f;
		if (channels >= 4) p.a = static_cast<int>(pixelOffset[3]) / 255.0f;
	}


	return p;
}


void Texture::loadTexture(const char* path) {

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	stbi_set_flip_vertically_on_load(true);
	image = stbi_load(path, &width, &height, &channels, STBI_grey);  //desiredChannels
	if (image)
	{
		loaded = true;
		//std::cout << "NOTICE: Texture loaded successfully: " << std::endl;
		//std::cout << width << "x" << height << std::endl;

	}
	else {
		std::cout << "WARNING: Failed to load texture: " << path << std::endl;
	}

}