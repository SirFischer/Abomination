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
	if (mHead.get())
		mHead->SetPosition(mPosition);
	if (mTorso.get())
		mTorso->SetPosition(mPosition);
	if (mLegLeft.get())
		mLegLeft->SetPosition(mPosition);
	if (mLegRight.get())
		mLegRight->SetPosition(mPosition);
	if (mArmLeft.get())
		mArmLeft->SetPosition(mPosition);
	if (mArmRight.get())
		mArmRight->SetPosition(mPosition);
}



void			Entity::Update()
{
	mPosition += mVelocity;
	SetPosition(mPosition);
}

void			Entity::Render(Window* tWindow)
{
	if (mHead.get())
		mHead->Render(tWindow);
	if (mTorso.get())
		mTorso->Render(tWindow);
	if (mLegLeft.get())
		mLegLeft->Render(tWindow);
	if (mLegRight.get())
		mLegRight->Render(tWindow);
	if (mArmLeft.get())
		mArmLeft->Render(tWindow);
	if (mArmRight.get())
		mArmRight->Render(tWindow);
}