#ifndef _EDITOR_SNAPSHOT_H
#define _EDITOR_SNAPSHOT_H

class Editor;

#include "Editor.h"

class EditorSnapshot : public AbstractSnapshot {

public:
	friend class Editor;
	void restore() const;

private:
	EditorSnapshot() = default;
	std::string _text;
	Editor* _target;
};

#endif // _EDITOR_SNAPSHOT_H
