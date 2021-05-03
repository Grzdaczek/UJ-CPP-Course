/* 

1. Projekt obiektowy:
- klasy
- konstruktory, destruktory
- konstruktor kopiujący
- deklaracja przyjaciela
- dziedziczenie
- polimorfizm
- klasa abstrakcyjna
- czysto wirtualne metody

2. STL
- szablony
- iteratory
- algorytmy

3. C++
- zakresowa pętla for
- własny szablon klasy (lub funkcji)
- przeciążanie operatorów
- wyjątki
- plik .h z deklaracja i .cpp z definicją metod - linker

*/

#include <iostream>
#include <vector>

//=============================================================================

template <typename E> 
class EmiterBase {
	public:
	
	typedef E EventType;
	typedef void(*EventHandler)(EventType);
	
	friend class Puppeteer;
	
	void on(EventType et, EventHandler h) {
		EventListener listener = {et, h};
		this->_listeners.push_back(listener);
	}

	protected:

	void emit(EventType e) {
		this->invokeHandlers(e);
	}

	private:

	typedef struct {
		EventType type;
		EventHandler handler;
	} EventListener;
	
	std::vector<EventListener> _listeners;
	// std::string _label;

	void invokeHandlers(EventType e) {
		for (auto l : _listeners) {
			if(l.type == e) l.handler(e);
		}
	}

};

//=============================================================================

class Puppeteer {
	public:
	template <typename E>
	static void emit(EmiterBase<E>* emiter, E event) {
		emiter->emit(event);
	}
};

//=============================================================================

namespace DeviceEvent {
	
	enum __DeviceEventEnum {
		READY, 
		BUSY,
	};

}

class Device : public EmiterBase <DeviceEvent::__DeviceEventEnum> {
	public:
};

//=============================================================================

void eventHandler(Device::EventType event) {
	std::cout << "Event handled! " << event << std::endl;
}

int main() {

	auto d = new Device();
	d->on(DeviceEvent::BUSY, eventHandler);
	Puppeteer::emit(d, DeviceEvent::BUSY);

	return 0;
}
