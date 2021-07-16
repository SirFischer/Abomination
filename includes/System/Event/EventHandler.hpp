/*
 * File: EventHandler.hpp
 * Folder: Event
 * File Created: Wednesday, 3rd March 2021 1:23:11 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Thursday, 15th July 2021 9:38:13 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#pragma once

#include <map>
#include <functional>
#include <iostream>
#include <SFML/Graphics.hpp>

#define EVENTHANDLER_BUTTON_OFFSET 1000

class EventHandler
{
 public:
 	enum class eEvent {
		//MOVEMENT
		WALK_LEFT,
		WALK_RIGHT,
		WALK_UP,
		WALK_DOWN,

		//ACTIONS
		ATTACK,

		//MISC
		OPEN_CONSOLE,
		CONFIRM
	};

	typedef std::map<EventHandler::eEvent, bool>			tEventStateList;
	typedef std::map<u_int32_t, EventHandler::eEvent>			tBindingMapList;
private:
	EventHandler(/* args */) {}
	~EventHandler() {}

	static tEventStateList		mEventStates;
	static tBindingMapList		mBindingMap;

public:
	static void					Init();
	static void					LoadDefaultBindings();
	static void					HandleEvent(sf::Event &tEvent);

	static void					BindKey(sf::Keyboard::Key tKey, eEvent tEvent);
	static void					BindButton(sf::Mouse::Button tButton, eEvent tEvent);
	static void					SetEventState(eEvent tEvent, bool tState);
	static bool					GetEventState(eEvent tEvent);
};