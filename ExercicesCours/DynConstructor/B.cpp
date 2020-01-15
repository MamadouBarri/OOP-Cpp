#include "B.h"
#include <iostream>

void B::afficher() const {
	std::cout << attribut_;
}

B::B(int p) {
	attribut_ = p;	
}