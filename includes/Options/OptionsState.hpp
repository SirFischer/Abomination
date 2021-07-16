/*
 * File: OptionsState.hpp
 * Folder: Options
 * File Created: Monday, 1st March 2021 2:45:33 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:41:56 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"
#include "SoundPlayer.hpp"

class OptionsState : public State
{
private:
	mf::Button		*mSoundTestBtn;
	mf::Button		*mQuitBtn;

public:
	OptionsState(Window *tWindow);
	~OptionsState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

