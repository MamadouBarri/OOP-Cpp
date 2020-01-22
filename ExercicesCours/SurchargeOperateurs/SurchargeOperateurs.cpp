#include <iostream>
#include "Fraction.h"
#include <numeric>
#include <algorithm>
#include <iostream>



//il ne s'agit pas d'une fonction membre
Fraction operator+(int entier, const Fraction& f) {
    return f + entier;
}


int main()
{
    Fraction f1 = Fraction(1, 2);
    Fraction f2 = Fraction(1, 4);
    Fraction somme = f1+ f2;
    std::cout << f1 << " + " << f2 << " = " << somme;
}
