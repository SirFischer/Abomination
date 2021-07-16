/*
 * File: Player.hpp
 * Folder: Game
 * File Created: Saturday, 6th March 2021 12:48:11 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:41:42 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

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