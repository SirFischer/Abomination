/*
 * File: Window.hpp
 * Folder: System
 * File Created: Monday, 1st March 2021 2:36:54 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:37:59 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "mfGUI.hpp"
#include "SFML/Graphics/View.hpp"

class Window
{
private:
	sf::RenderWindow	mWindow;
	/****************************
	 * Change window title here *
	 ****************************/
	std::string			mTitle = "Abomination";
	
	bool				mFullscreen = false;
	sf::VideoMode		mMode = sf::VideoMode(1600, 900);

public:
					Window(/* args */);
					~Window();

	sf::View 			mView;


	/**
	 * Creation and destruction of window
	 **/
	void			Create();
	void			Destroy();


	/**
	 * Basic drawing utilities
	 **/
	void			Draw(sf::Drawable &tDrawable);
	void			Clear();
	void			Clear(sf::Color tColor);
	void			Render();

	/**
	 * Events
	 **/
	bool			HandleEvent(sf::Event &tEvent);


	/**
	 * Controls
	 **/
	void			ToggleFullscreen();
	void			ChangeResolution(int tWidth, int tHeight);
	void			HideCursor();
	void			ShowCursor();

	/**
	 * Camera
	 **/
	void			SetView(sf::View tView);

	void			SetDefaultView();

	bool			IsOpen(){return (mWindow.isOpen());}

	void			ResetView(bool tResize);
};
