#ifndef _EVENT_H
#define _EVENT_H

#include <unordered_set>
#include <vector>

template<typename... T>
class Event {
	
public:
	typedef void(*handler_func)(T...);
	
	Event();
	Event(const Event& other);
	~Event();
	
	void trigger(T... args) const;
	void attach(const handler_func& h);
	void attach(const Event<T...>& e);
	void detach(const handler_func& h);
	void detach(const Event<T...>& e);
	
private:
	std::unordered_set<handler_func>* _handlers;
	std::unordered_set<Event<T...>*>* _repeaters;
	
};

//#############################################################################
// Implementation below, not in separate cpp file due to linking and issues.

template<typename D, typename... T>
void connect(Event<T...>& left, D& right) {
	left.attach(right);
}

template<typename D, typename... T>
void connect(std::vector<Event<T...>*> left, D& right) {
	for(auto e : left) e->attach(right);
}

template<typename D, typename... T>
void disconnect(Event<T...>& left, D& right) {
	left.detach(right);
}

template<typename D, typename... T>
void disconnect(std::vector<Event<T...>*> left, D& right) {
	for(auto e : left) e->detach(right);
}

template<typename D, typename... T>
D& operator>>(Event<T...>& event, D& other) {
	connect(event, other);
	return other;
}

template<typename... T>
std::vector<Event<T...>*> operator|(Event<T...>& left, Event<T... >& right) {
	std::vector<Event<T...>*> vec;
	vec.push_back(&left);
	vec.push_back(&right);
	return vec;
}

//#############################################################################

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
void Event<T...>::attach(const handler_func& h) {
	_handlers->insert(h);
}

template<typename... T>
void Event<T...>::attach(const Event<T...>& e) {
	_repeaters->insert((Event<T...>*)&e);
}

template<typename... T>
void Event<T...>::detach(const handler_func& h) {
	_handlers->erase(h);
}

template<typename... T>
void Event<T...>::detach(const Event<T...>& e) {
	_repeaters->erase((Event<T...>*)&e);
}

#endif // _EVENT_H