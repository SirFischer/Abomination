/*
 * File: BodyPartBase.hpp
 * Folder: BodyParts
 * File Created: Saturday, 6th March 2021 1:02:39 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:40:16 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "Entities/EntityState.hpp"
#include "Entities/EntityDirection.hpp"

class Window;

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
		void				SetPosition(const sf::Vector2f &tPosition);
		void				SetState(const eEntityState &tState, const eEntityDirection &tDirection);

		void				Update();
		void				Render(Window *tWindow);
	};
}

