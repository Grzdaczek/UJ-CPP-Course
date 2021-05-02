#include "Publisher.h"

void Observer::subscribe(Publisher *p) {
    p->observers.push_back(this);
}

void Publisher::notify() {
	for (auto it = this->observers.begin(); it != this->observers.end(); ++it) {
		(*it)->notify(this);
	}
}