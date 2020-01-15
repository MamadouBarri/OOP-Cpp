#include "A.h"
#include <iostream>

void A::afficher() const {
	attribut_->afficher();
}

A::A(int p) {
	attribut_ = new B(p);
}