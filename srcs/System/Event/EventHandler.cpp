/*
 * File: EventHandler.cpp
 * Folder: Event
 * File Created: Wednesday, 3rd March 2021 1:23:47 pm
 * Author: Marek Fischer
 * -----
 * Last Modified: Friday, 16th July 2021 9:27:02 am
 * Modified By: Marek Fischer 
 * -----
 * Copyright - 2021 Deep Vertic, Deep Vertic
 */

#include "EventHandler.hpp"

EventHandler::tEventStateList		EventHandler::mEventStates = EventHandler::tEventStateList();
EventHandler::tBindingMapList		EventHandler::mBindingMap = EventHandler::tBindingMapList();

void						EventHandler::Init()
{

}

void						EventHandler::LoadDefaultBindings()
{
	BindKey(sf::Keyboard::Tab, eEvent::OPEN_CONSOLE);
	BindKey(sf::Keyboard::Enter, eEvent::CONFIRM);
	BindKey(sf::Keyboard::D, eEvent::WALK_RIGHT);
	BindKey(sf::Keyboard::A, eEvent::WALK_LEFT);
	BindKey(sf::Keyboard::W, eEvent::WALK_UP);
	BindKey(sf::Keyboard::S, eEvent::WALK_DOWN);

	BindButton(sf::Mouse::Left, eEvent::ATTACK);
}

void						EventHandler::HandleEvent(sf::Event &tEvent)
{
	//handle events
	switch (tEvent.type)
	{
		case sf::Event::KeyPressed:
			if (mBindingMap.count(tEvent.key.code))
				mEventStates[mBindingMap[tEvent.key.code]] = true;
		break;
		case sf::Event::KeyReleased:
			if (mBindingMap.count(tEvent.key.code))
				mEventStates[mBindingMap[tEvent.key.code]] = false;
		break;
		case sf::Event::MouseButtonPressed:
			if (mBindingMap.count(tEvent.key.code + EVENTHANDLER_BUTTON_OFFSET))
				mEventStates[mBindingMap[tEvent.key.code + EVENTHANDLER_BUTTON_OFFSET]] = true;
		break;
		case sf::Event::MouseButtonReleased:
			if (mBindingMap.count(tEvent.key.code + EVENTHANDLER_BUTTON_OFFSET))
				mEventStates[mBindingMap[tEvent.key.code + EVENTHANDLER_BUTTON_OFFSET]] = false;
		break;
		default:
		break;
	}
}

void						EventHandler::BindKey(sf::Keyboard::Key tKey, eEvent tEvent)
{
	mBindingMap[(u_int32_t)tKey] = tEvent;
}

void						EventHandler::BindButton(sf::Mouse::Button tButton, eEvent tEvent)
{
	mBindingMap[((u_int32_t)tButton) + EVENTHANDLER_BUTTON_OFFSET] = tEvent;
}

void						EventHandler::SetEventState(eEvent tEvent, bool tState)
{
	mEventStates[tEvent] = tState;
}

bool						EventHandler::GetEventState(eEvent tEvent)
{
	return (mEventStates[tEvent]);
}