#pragma once

#include <map>
#include <functional>
#include <SFML/Graphics.hpp>


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
	static void					SetEventState(eEvent tEvent, bool tState);
	static bool					GetEventState(eEvent tEvent);
};