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
#include "event.h"

int main() {

	Event<std::string> onRed;
	Event<std::string> onBlue;

	auto handle =  [](std::string msg) {
		std::cout << "event handled!: " << msg << std::endl;
	};

	onRed >> onBlue >> handle;

	onRed.trigger("Roses are red!");
	onBlue.trigger("Violets are blue!");

	return 0;
}
