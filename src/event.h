#ifndef _EVENT_H
#define _EVENT_H

#include <functional>
#include <map>

template<typename... T>
class Event {
	public:
	
	typedef std::function<void(T...)> handler_t;
	typedef int key_t;

	Event() {
		_keyCounter = 0;
	};

	Event(const Event& other) {
		_handlers.clear();
		_keyCounter = 0;
	}

	void operator>>(const handler_t& handler) {
		connect(handler);
	}

	void emit(T... args) const {
		for (auto const& [key, handler] : _handlers) {
			handler(args...);
		}
	}

	key_t connect(const handler_t& handler) {
		key_t key = _nextKey();
		_handlers.insert({key, handler});
		return key;
	}

	void disconnect(const key_t& key) {
		// _handlers.erase()
	}

	private:

	std::map<key_t, handler_t> _handlers;
	key_t _keyCounter;

	key_t _nextKey() {
		return _keyCounter++;
	}

};

#endif // _EVENT_H