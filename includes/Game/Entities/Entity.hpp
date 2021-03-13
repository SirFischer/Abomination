#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.hpp"
#include "ResourceManager.hpp"
#include "BodyParts/BodyParts.hpp"
#include "Event/EventHandler.hpp"

class Entity
{
protected:
	//BodyParts
	std::shared_ptr<BodyPart::Head>		mHead;
	std::shared_ptr<BodyPart::Torso>	mTorso;
	std::shared_ptr<BodyPart::Arm>		mArmLeft;
	std::shared_ptr<BodyPart::Arm>		mArmRight;
	std::shared_ptr<BodyPart::Leg>		mLegLeft;
	std::shared_ptr<BodyPart::Leg>		mLegRight;

	//mechanics
	sf::Vector2f						mPosition = sf::Vector2f(0, 0);
	sf::Vector2f						mVelocity = sf::Vector2f(0, 0);
	sf::Vector2f						mAcceleration = sf::Vector2f(0.5, 0.5);

	sf::FloatRect						mHitBox; //?

public:
	Entity(/* args */);
	~Entity();

	void				SetPosition(sf::Vector2f tPosition);

	void				Update();
	void				Render(Window* tWindow);
};