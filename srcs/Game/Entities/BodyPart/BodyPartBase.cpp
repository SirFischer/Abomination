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


	void			BodyPartBase::SetPosition(sf::Vector2f tPosition)
	{
		mSprite.setPosition(tPosition);
	}

	void			BodyPartBase::SetState(eEntityState tState, eEntityDirection tDirection)
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