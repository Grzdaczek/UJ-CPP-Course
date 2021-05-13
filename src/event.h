#ifndef _EVENT_H
#define _EVENT_H

#include <functional>
#include <unordered_set>


template<typename... T>
class Event {
	
	public:
	
	typedef void(*handler_func)(T...);

	Event() {
		_handlers = new std::unordered_set<handler_func>;
		_repeaters = new std::unordered_set<Event<T...>*>;
	};

	Event(const Event& other) {
		_handlers->clear();
		_repeaters->clear();
	}

	~Event() {
		delete _handlers;
		delete _repeaters;
	}

	void trigger(T... args) const {
		for (const auto& h: *_handlers) h(args...);
		for (const auto& r: *_repeaters) r->trigger(args...);
	}

	void connect(const handler_func& h) {
		_handlers->insert(h);
	}

	void connect(const Event<T...>& e) {
		// if(&e == this) throw "error: the event cannot trigger itself";
		_repeaters->insert((Event<T...>*)&e);
	}

	void disconnect(const handler_func& h) {
		_handlers->erase(h);
	}

	void disconnect(const Event<T...>& e) {
		_repeaters->erase((Event<T...>*)&e);
	}

	template<typename D>
	D& operator>>(D& other) {
		connect(other);
		return other;
	}

	private:

	std::unordered_set<handler_func>* _handlers;
	std::unordered_set<Event<T...>*>* _repeaters;
	
};

#endif // _EVENT_H