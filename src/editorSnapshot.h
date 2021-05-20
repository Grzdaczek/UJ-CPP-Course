#ifndef _EDITOR_SNAPSHOT_H
#define _EDITOR_SNAPSHOT_H

#include <string>
#include "event.h"
#include "abstractSnapshot.h"

// class Editor;

class EditorSnapshot : public AbstractSnapshot {

public:
	// friend class Editor;
	void restore();

private:
	// Editor* _target;
	std::string _text;
};

#endif // _EDITOR_SNAPSHOT_H
