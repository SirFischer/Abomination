/*
 * File: SoundPlayer.hpp
 * Folder: Audio
 * File Created: Monday, 1st March 2021 2:45:33 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:39:08 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include "Sound.hpp"
#include "ResourceManager.hpp"

class SoundPlayer : sf::NonCopyable
{
private:
    static std::map<eSound, std::string>		mSoundNames;
	static std::map<eSound, sf::Sound>			mSoundList;

    static float								mVolume;
	
	SoundPlayer(/* args */);
public:
    ~SoundPlayer();

	static void											Init();

    static void											Play(eSound tEffect);

    static void											StopSound(eSound tEffect);
    static void											StopSound();

	static void											SetPitch(eSound tEffect, float tPitch);
	static void											SetVolume(eSound tEffect, float tVolume);

    static sf::Sound									GetSound(eSound tEffect){return (mSoundList[tEffect]);}

};