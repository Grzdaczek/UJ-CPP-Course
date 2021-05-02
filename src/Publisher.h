#ifndef _PUBLISHER_H
#define _PUBLISHER_H
#include <vector>

class Publisher;

class Observer {
public:
	virtual void notify(Publisher *publisher) = 0;
	void subscribe(Publisher *p);
};

class Publisher {
private:
	std::vector<Observer*> observers;
public:
	friend void Observer::subscribe(Publisher *p);
	void notify();
};

#endif