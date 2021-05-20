#include "Editor.h"

EditorSnapshot const* Editor::save() {
	EditorSnapshot* snap = new EditorSnapshot();
	snap->_target = this;
	snap->_text = this->_text;
	return snap;
}

void Editor::restore(EditorSnapshot const* s) {
	_text = s->_text;
}
