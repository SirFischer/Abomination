#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

#include "Window.hpp"
#include "ResourceManager.hpp"
#include "BodyParts/BodyParts.hpp"
#include "EntityState.hpp"
#include "EntityDirection.hpp"
#include "Event/EventHandler.hpp"

class Entity
{
protected:
	enum class							eBodyPart
	{
										HEAD,
										TORSO,
										ARM_LEFT,
										ARM_RIGHT,
										LEG_LEFT,
										LEG_RIGHT
	};

	//BodyParts
	std::shared_ptr<BodyPart::Head>		mHead;
	std::shared_ptr<BodyPart::Torso>	mTorso;
	std::shared_ptr<BodyPart::Arm>		mArmLeft;
	std::shared_ptr<BodyPart::Arm>		mArmRight;
	std::shared_ptr<BodyPart::Leg>		mLegLeft;
	std::shared_ptr<BodyPart::Leg>		mLegRight;
	std::map<eBodyPart, std::shared_ptr<BodyPart::BodyPartBase>>	mBodyParts;  //LIST FORM FOR EASY LISTING WHEN PERFORMING ACTIONS ON ALL PARTS (yes i'm lazy)

	//Mechanics
	sf::Vector2f						mPosition = sf::Vector2f(0, 0);
	sf::Vector2f						mVelocity = sf::Vector2f(0, 0);
	sf::Vector2f						mAcceleration = sf::Vector2f(0.5, 0.5);

	sf::FloatRect						mHitBox; //?

	//States
	eEntityState						mState = eEntityState::IDLE;
	eEntityDirection					mDirection = eEntityDirection::RIGHT;

public:
	Entity(/* args */);
	~Entity();

	void				SetPosition(sf::Vector2f tPosition);

	void				Update();
	void				Render(Window* tWindow);
};