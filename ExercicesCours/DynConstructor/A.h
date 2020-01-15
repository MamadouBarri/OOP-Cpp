#pragma once
#include "B.h"
class A
{
public:
	A(int p = 0);
	void afficher() const;
private:
	B* attribut_;
};

