/*
 * File: Entity.hpp
 * Folder: Entities
 * File Created: Saturday, 6th March 2021 12:48:24 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:10:20 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

#include "ResourceManager.hpp"
#include "BodyParts/BodyParts.hpp"
#include "EntityState.hpp"
#include "EntityDirection.hpp"
#include "Event/EventHandler.hpp"

//Pimpl
class Window;

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
	typedef std::map<eBodyPart, std::shared_ptr<BodyPart::BodyPartBase>> BodyParts;

	//BodyParts
	std::shared_ptr<BodyPart::Head>		mHead;
	std::shared_ptr<BodyPart::Torso>	mTorso;
	std::shared_ptr<BodyPart::Arm>		mArmLeft;
	std::shared_ptr<BodyPart::Arm>		mArmRight;
	std::shared_ptr<BodyPart::Leg>		mLegLeft;
	std::shared_ptr<BodyPart::Leg>		mLegRight;
	BodyParts							mBodyParts;  //LIST FORM FOR EASY LISTING WHEN PERFORMING ACTIONS ON ALL PARTS (yes i'm lazy)

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

	void								SetPosition(const sf::Vector2f &tPosition);

	void								Update();
	void								Render(Window* tWindow);
};