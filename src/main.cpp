/* 

1. Projekt obiektowy:
	- klasy
	- konstruktory, destruktory
- konstruktor kopiujący
	- deklaracja przyjaciela
	- dziedziczenie
	- polimorfizm
	- klasa abstrakcyjna
	- czysto wirtualne metody

2. STL
- szablony
- iteratory
- algorytmy

3. C++
- zakresowa pętla for
- własny szablon klasy (lub funkcji)
- przeciążanie operatorów
- wyjątki
- plik .h z deklaracja i .cpp z definicją metod - linker

*/

#include <iostream>
#include "Editor.h"
#include "Event.h"
#include "Snapshot.h"

//#############################################################################

int main() {

	Editor e;
	EditorSnapshot const* snap;

	auto saveHandler = [](){
		std::cout << "text saved!" << std::endl;
	};
	auto restoreHandler = []() { 
		std::cout << "text restored!" << std::endl;
	};
	auto editHandler = [](std::string text) {
		std::cout << "text changed:\t" << text <<  std::endl;
	};

	connect(e.onSave, saveHandler);
	connect(e.onRestore, restoreHandler);
	connect(e.onEdit, editHandler);

	e.setText("Lorem ipsum");
	snap = e.save();
	e.setText("dolor sit amet");
	e.restore(snap);

	std::cout << "Text is:\t" << e.getText() << std::endl;

	return 0;
}
