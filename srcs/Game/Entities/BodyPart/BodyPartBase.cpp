/*
 * File: BodyPartBase.cpp
 * Folder: BodyPart
 * File Created: Thursday, 11th March 2021 6:13:48 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:24:44 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#include "BodyPartBase.hpp"
#include "Window.hpp"

namespace BodyPart
{

	void			BodyPartBase::SetTexture(sf::Texture *tTexture)
	{
		if (!tTexture)
			return ;
		mTexture = *tTexture;
		mSprite.setTexture(mTexture);
	}


	void			BodyPartBase::SetPosition(const sf::Vector2f &tPosition)
	{
		mSprite.setPosition(tPosition);
	}

	void			BodyPartBase::SetState(const eEntityState &tState, const eEntityDirection &tDirection)
	{
		mState = tState;
		mDirection = tDirection;
	}

	void			BodyPartBase::Update()
	{
		
	}

	void			BodyPartBase::Render(Window *tWindow)
	{
		tWindow->Draw(mSprite);
	}
	
}