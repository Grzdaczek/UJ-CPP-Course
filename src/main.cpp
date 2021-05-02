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
*/

#include <iostream>
#include "Publisher.h"

class Logger: public Observer {
public:
	void notify(Publisher* publisher) {
		std::cout << "Notified\n";
	}
};

class Counter: public Observer {
private:
	int count;
public:
	Counter() {
		this->count = 0;
	}

	void notify(Publisher* publisher) {
		this->count++;
		std::cout << "Count:" << this->count << std::endl;
	}
};

//=============================================================================

int main() {

	Logger* logger = new Logger();
	Publisher* publisher = new Publisher();
	Counter counter;

	logger->subscribe(publisher);
	counter.subscribe(publisher);
	publisher->notify();
	publisher->notify();


	return 0;
}
