
#include <numeric>
#include <iostream>
#include "Fraction.h"
Fraction::Fraction(long num = 0, long denum = 0)
	: numerateur_(num)
	, denominateur_(denum) 
{
	std::cout << "construction(" << num << ", " << denum << ")\n";
}

long Fraction::getNumerateur() const
{
	return numerateur_;
}

long Fraction::getDenominateur() const
{
	return denominateur_;
}

double Fraction::getReel() const
{
	return double(numerateur_) / denominateur_;
}


Fraction Fraction::operator+(const Fraction& fract) const
{

	return Fraction(
		numerateur_ * fract.denominateur_ + fract.numerateur_ * denominateur_, denominateur_ * fract.denominateur_
	).simplifier();
}

Fraction& Fraction::simplifier() {
	int pgcd = std::gcd(numerateur_, denominateur_);
	numerateur_ /= pgcd;
	denominateur_ /= pgcd;
	return *this;

}

//Fraction Fraction::operator+(const long& entier) const
//{
//	return Fraction(numerateur_ + entier * denominateur_, denominateur_);
//}

std::ostream& operator<<(std::ostream& o, const Fraction& f) {
	o << f.numerateur_ << "/" << f.denominateur_;
	return o;
}

