#include "Object.hpp"

void			Object::LoadTextureFromFile(std::string tPath)
{
	sf::Texture *tex = ResourceManager::LoadTexture(tPath);
	LoadTextureFromFile(tex);
}

void			Object::LoadTextureFromFile(sf::Texture *tTexture)
{
	if (!tTexture)
	{
		std::cout << "Failed to load texture... (Class Object) Pointer == " << (uint32_t)tTexture << std::endl;
		return ;
	}
	mTexture = *tTexture;
	mSprite.setTexture(mTexture);
}