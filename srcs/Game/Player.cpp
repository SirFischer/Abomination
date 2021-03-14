#include "Player.hpp"

Player::Player()
{
	mHead->SetTexture(ResourceManager::LoadTexture("assets/textures/Head.png"));
	mTorso->SetTexture(ResourceManager::LoadTexture("assets/textures/Torso.png"));
	mArmRight->SetTexture(ResourceManager::LoadTexture("assets/textures/RightArm.png"));
	mArmLeft->SetTexture(ResourceManager::LoadTexture("assets/textures/LeftArm.png"));
	mLegRight->SetTexture(ResourceManager::LoadTexture("assets/textures/RightFoot.png"));
	mLegLeft->SetTexture(ResourceManager::LoadTexture("assets/textures/LeftFoot.png"));
}

Player::~Player()
{

}

void		Player::Update()
{
	if (EventHandler::GetEventState(EventHandler::eEvent::WALK_RIGHT))
		mVelocity.x += mAcceleration.x; //replace with move right
	if (EventHandler::GetEventState(EventHandler::eEvent::WALK_LEFT))
		mVelocity.x -= mAcceleration.x; //replace with move left
	if (EventHandler::GetEventState(EventHandler::eEvent::WALK_UP))
		mVelocity.y -= mAcceleration.y; //replace with move up
	if (EventHandler::GetEventState(EventHandler::eEvent::WALK_DOWN))
		mVelocity.y += mAcceleration.y; //replace with move down
	if (EventHandler::GetEventState(EventHandler::eEvent::ATTACK))
	{
		std::cout << "ATTACKED" << std::endl;
		EventHandler::SetEventState(EventHandler::eEvent::ATTACK, false);
	}
	Entity::Update();
	mVelocity.x *= 0.9;
	mVelocity.y *= 0.9;

}
