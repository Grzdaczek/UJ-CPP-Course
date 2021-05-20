#ifndef _EDITOR_H
#define _EDITOR_H

#include <string>
#include "event.h"
#include "abstractSnapshot.h"
#include "editorSnapshot.h"

class Editor : public AbstractSnapshotable<EditorSnapshot>{

public:
	Event<> onSave;
	Event<> onEdit;
	Event<> onRestore;

	EditorSnapshot const* save() override;
	void restore(EditorSnapshot const* s) override;

private:
	std::string _text;

};

#endif // _EDITOR_H
