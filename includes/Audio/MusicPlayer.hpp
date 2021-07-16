/*
 * File: MusicPlayer.hpp
 * Folder: Audio
 * File Created: Monday, 1st March 2021 2:45:33 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:38:46 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include <map>
#include "Music.hpp"
#include "SFML/Audio.hpp"

class MusicPlayer : sf::NonCopyable
{
private:
    sf::Music							mMusic;
    std::map<eMusic, std::string>		mFilenames;
    float								mVolume;
public:
    MusicPlayer(/* args */);
    ~MusicPlayer();

    void    Play(eMusic tTheme);
    void    Stop();

    void    SetPaused(bool tPaused);
    void    SetVolume(float tVolume);
};
