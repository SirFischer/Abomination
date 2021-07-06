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