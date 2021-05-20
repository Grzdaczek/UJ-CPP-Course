#include "Editor.h"

EditorSnapshot const* Editor::save() {
	EditorSnapshot* snap = new EditorSnapshot();
	snap->_target = this;
	snap->_text = this->_text;

	onSave.trigger();
	return snap;
}

void Editor::restore(EditorSnapshot const* s) {
	_text = s->_text;

	onRestore.trigger();
}

std::string Editor::getText() {
	return _text;
}

void Editor::setText(std::string text) {
	_text = text;
	onEdit.trigger(_text);
}