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
// #include <vector>
#include "editor.h"
#include "event.h"
#include "editorSnapshot.h"
#include "abstractSnapshot.h"

//#############################################################################

int main() {

	std::cout << "Hello World" << std::endl;

	Editor e;

	return 0;
}
