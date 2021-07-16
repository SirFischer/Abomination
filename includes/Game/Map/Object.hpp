/*
 * File: Object.hpp
 * Folder: Map
 * File Created: Monday, 15th March 2021 5:10:38 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:41:24 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include <SFML/Graphics.hpp>

#include "ResourceManager/ResourceManager.hpp"

class Object
{
private:
	uint32_t		mSignature;
	sf::Vector2f	mPosition;

public:
	Object(/* args */) {}
	~Object() {}

	/**
	 *	Setters
	 **/
	void			SetSignature(uint32_t tSignature);
	void			SetPosition(const sf::Vector2f &tPosition);

	/**
	 *	Getters
	 **/
	uint32_t		GetSignature() {return (mSignature);}
	sf::Vector2f	GetPosition() {return (mPosition);}
};