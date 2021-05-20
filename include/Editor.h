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
	Event<> onRestore;
	Event<std::string> onEdit;

	EditorSnapshot const* save() override;
	void restore(EditorSnapshot const* s) override;

	std::string getText();
	void setText(std::string text);

private:
	std::string _text;

};

#endif // _EDITOR_H
