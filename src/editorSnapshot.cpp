#include "editorSnapshot.h"
#include "editor.h"

void EditorSnapshot::restore() {

}

EditorSnapshot const* Editor::save() {
	return new EditorSnapshot();
}
