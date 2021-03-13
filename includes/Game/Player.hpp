#pragma once

#include "Entities/Entity.hpp"

class Player : public Entity
{
private:
public:
	Player(/* args */);
	~Player();

	void		Update();
};