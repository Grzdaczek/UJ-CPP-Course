#include "EditorSnapshot.h"

void EditorSnapshot::restore() const {
	_target->restore(this);
}
