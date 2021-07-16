/*
 * File: Object.cpp
 * Folder: Map
 * File Created: Monday, 15th March 2021 5:16:16 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:25:47 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#include "Object.hpp"

void			Object::SetSignature(uint32_t tSignature)
{
	mSignature = tSignature;
}

void			Object::SetPosition(const sf::Vector2f &tPosition)
{
	mPosition = tPosition;
}
