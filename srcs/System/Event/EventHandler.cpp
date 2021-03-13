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
		default:
		break;
	}
}

void						EventHandler::BindKey(sf::Keyboard::Key tKey, eEvent tEvent)
{
	mBindingMap[(u_int32_t)tKey] = tEvent;
}

void						EventHandler::SetEventState(eEvent tEvent, bool tState)
{
	mEventStates[tEvent] = tState;
}

bool						EventHandler::GetEventState(eEvent tEvent)
{
	return (mEventStates[tEvent]);
}