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

	Event<int> onTest;

	onTest >> [](int num) {
		std::cout << "onTest event: " << num << std::endl;
	};

	Event<int> onTestCopy = onTest;

	onTest.emit(42);
	onTestCopy.emit(56);

	return 0;
}
