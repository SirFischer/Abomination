#include "Entity.hpp"

Entity::Entity(/* args */)
{
	try
	{
		mHead.reset(new BodyPart::Head());
		mTorso.reset(new BodyPart::Torso());
		mLegLeft.reset(new BodyPart::Leg());
		mLegRight.reset(new BodyPart::Leg());
		mArmLeft.reset(new BodyPart::Arm());
		mArmRight.reset(new BodyPart::Arm());
		mBodyParts[eBodyPart::HEAD] = mHead;
		mBodyParts[eBodyPart::TORSO] = mTorso;
		mBodyParts[eBodyPart::LEG_LEFT] = mLegLeft;
		mBodyParts[eBodyPart::LEG_RIGHT] = mLegRight;
		mBodyParts[eBodyPart::ARM_LEFT] = mArmLeft;
		mBodyParts[eBodyPart::ARM_RIGHT] = mArmRight;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

Entity::~Entity()
{

}

void			Entity::SetPosition(sf::Vector2f tPosition)
{
	mPosition = tPosition;
	for (auto &bodyPart : mBodyParts)
	{
		if (bodyPart.second.get())
			bodyPart.second->SetPosition(mPosition);
	}
}


void			Entity::Update()
{
	mPosition += mVelocity;
	SetPosition(mPosition);
	for (auto &bodyPart : mBodyParts)
	{
		if (bodyPart.second.get())
		{
			bodyPart.second->SetState(mState, mDirection);
			bodyPart.second->Update();
		}
	}
}

void			Entity::Render(Window* tWindow)
{
	for (auto &bodyPart : mBodyParts)
	{
		if (bodyPart.second.get())
			bodyPart.second->Render(tWindow);
	}
}