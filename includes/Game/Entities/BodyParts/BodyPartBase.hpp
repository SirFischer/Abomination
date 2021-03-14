#pragma once
#include "Window.hpp"
#include "Entities/EntityState.hpp"
#include "Entities/EntityDirection.hpp"

namespace BodyPart
{
	class BodyPartBase
	{
	protected:
		sf::Texture			mTexture;
		sf::Sprite			mSprite;

		eEntityState		mState;
		eEntityDirection	mDirection;

	public:
		BodyPartBase(/* args */) {}
		~BodyPartBase() {}

		void				SetTexture(sf::Texture	*tTexture);
		void				SetPosition(sf::Vector2f tPosition);
		void				SetState(eEntityState tState, eEntityDirection tDirection);

		void				Update();
		void				Render(Window *tWindow);
	};
}

