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
	
	e._text = "Lorem";
	std::cout << e._text << std::endl;

	EditorSnapshot const* snap = e.save();

	e._text = "Ipsum";
	std::cout << e._text << std::endl;

	// e.restore(snap);
	snap->restore();

	std::cout << e._text << std::endl;

	return 0;
}
