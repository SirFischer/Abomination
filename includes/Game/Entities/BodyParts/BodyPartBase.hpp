#pragma once
#include "Window.hpp"

namespace BodyPart
{
	class BodyPartBase
	{
	protected:
		sf::Texture		mTexture;
		sf::Sprite		mSprite;

	public:
		BodyPartBase(/* args */) {}
		~BodyPartBase() {}

		void			SetTexture(sf::Texture	*tTexture);
		void			SetPosition(sf::Vector2f tPosition);

		void			Render(Window *tWindow);
	};
}

