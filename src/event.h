#ifndef _EVENT_H
#define _EVENT_H

#include <functional>
#include <map>

template<typename... T>
class Event {
	public:
	
	typedef std::function<void(T...)> handler_t;
	typedef int key_t;

	// Signal() = default;
	// ~Signal() = default;

	void emit(T... args) {
		for (auto const& [key, handler] : _handlers) {
			handler(args...);
		}
	}

	key_t connect(handler_t const& handler) {
		key_t key = _nextKey();
		_handlers.insert({key, handler});
		return key;
	}

	void disconnect(key_t key) {
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