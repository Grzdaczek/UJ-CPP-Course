#include <iostream>
#include "Editor.h"
#include "Event.h"
#include "Snapshot.h"

int main() {

	Editor e;

	auto saveHandler = [](){
		std::cout << "text saved!" << std::endl;
	};
	
	auto restoreHandler = []() { 
		std::cout << "text restored!" << std::endl;
	};
	
	auto saveOrRestoreHandler = [](){
		std::cout << "text saved or restored!" << std::endl;
	};

	auto editHandler = [](std::string text) {
		std::cout << "text changed:\t" << text <<  std::endl;
	};

	e.onSave >> saveHandler;
	e.onRestore >> restoreHandler;
	e.onEdit >> editHandler;
	connect(e.onSave | e.onRestore, saveOrRestoreHandler);

	e.setText("Lorem ipsum");
	EditorSnapshot const* s = e.save();
	e.setText("Dolor sit amet");
	e.restore(s);

	std::cout << "text is:\t" << e.getText() << std::endl;

	return 0;
}
