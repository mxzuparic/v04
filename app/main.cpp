#include "app.h"
#include <iostream>

using namespace vsite::oop::v4;
// read animal id's (until 0) and display species name
// display total leg count
int main()
{
    leg_counter lc;
    int code;

    std::cout << "Unesite sifre zivotinja (0 za kraj):\n";
    while (true) {
        std::cin >> code;
        if (code == 0) break;

        auto a = animal_factory(code);
        if (a) {
            std::cout << a->species() << "\n";
            lc.add_animal(a.get());
        }
        else {
            std::cout << "Nepoznata sifra!\n";
        }
    }

    std::cout << "Ukupan broj nogu: " << lc.legs() << "\n";
}
