#include "Object.hpp"

void			Object::SetSignature(uint32_t tSignature)
{
	mSignature = tSignature;
}

void			Object::SetPosition(const sf::Vector2f &tPosition)
{
	mPosition = tPosition;
}
