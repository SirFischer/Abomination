#include "BodyPartBase.hpp"

namespace BodyPart
{

	void			BodyPartBase::SetTexture(sf::Texture *tTexture)
	{
		if (!tTexture)
			return ;
		mTexture = *tTexture;
	}


	void			BodyPartBase::Render(Window *tWindow)
	{
		(void)(tWindow);
	}
	
}