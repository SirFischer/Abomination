#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.hpp"
#include "BodyParts/BodyParts.hpp"

class Entity
{
protected:
	std::shared_ptr<BodyPart::Head>		mHead;
	std::shared_ptr<BodyPart::Torso>	mTorso;
	std::shared_ptr<BodyPart::Arm>		mArmLeft;
	std::shared_ptr<BodyPart::Arm>		mArmRight;
	std::shared_ptr<BodyPart::Leg>		mLegLeft;
	std::shared_ptr<BodyPart::Leg>		mLegRight;

public:
	Entity(/* args */);
	~Entity();

	void				Update();
	void				Render(Window* tWindow);
};