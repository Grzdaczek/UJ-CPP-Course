#ifndef _EDITOR_H
#define _EDITOR_H

#include <string>
#include "Event.h"
#include "Snapshot.h"

class EditorSnapshot;

#include "EditorSnapshot.h"

class Editor : public AbstractSnapshotable<EditorSnapshot>{

public:
	Event<> onSave;
	Event<> onEdit;
	Event<> onRestore;

	EditorSnapshot const* save() override;
	void restore(EditorSnapshot const* s) override;

	std::string _text;

// private:
	// std::string _text;

};

#endif // _EDITOR_H
