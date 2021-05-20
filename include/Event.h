#ifndef _EVENT_H
#define _EVENT_H

#include <unordered_set>

template<typename... T>
class Event {
	
public:
	typedef void(*handler_func)(T...);
	
	Event();
	Event(const Event& other);
	~Event();
	
	void trigger(T... args) const;
	void connect(const handler_func& h);
	void connect(const Event<T...>& e);
	void disconnect(const handler_func& h);
	void disconnect(const Event<T...>& e);
	template<typename D> D& operator>>(D& other);
	
private:
	std::unordered_set<handler_func>* _handlers;
	std::unordered_set<Event<T...>*>* _repeaters;
	
};

//#############################################################################
// Implementation below, not in separate cpp file due to linking and issues.

template<typename... T>
Event<T...>::Event() {
	_handlers = new std::unordered_set<handler_func>;
	_repeaters = new std::unordered_set<Event<T...>*>;
};

template<typename... T>
Event<T...>::Event(const Event& other) {
	_handlers->clear();
	_repeaters->clear();
}

template<typename... T>
Event<T...>::~Event() {
	delete _handlers;
	delete _repeaters;
}

template<typename... T>
void Event<T...>::trigger(T... args) const {
	for (const auto& h: *_handlers) h(args...);
	for (const auto& r: *_repeaters) r->trigger(args...);
}

template<typename... T>
void Event<T...>::connect(const handler_func& h) {
	_handlers->insert(h);
}

template<typename... T>
void Event<T...>::connect(const Event<T...>& e) {
	// if(&e == this) throw "error: the event cannot trigger itself";
	_repeaters->insert((Event<T...>*)&e);
}

template<typename... T>
void Event<T...>::disconnect(const handler_func& h) {
	_handlers->erase(h);
}

template<typename... T>
void Event<T...>::disconnect(const Event<T...>& e) {
	_repeaters->erase((Event<T...>*)&e);
}

template<typename... T>
template<typename D>
D& Event<T...>::operator>>(D& other) {
	connect(other);
	return other;
}

#endif // _EVENT_H