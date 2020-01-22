class Fraction {
public:
	Fraction(long num, long denum);
	long getNumerateur() const;
	long getDenominateur() const;
	double getReel() const;
	Fraction operator+ (const Fraction& fract) const;
	Fraction operator+(const long& entier) const;
	friend std::ostream& operator<<(std::ostream& o, const Fraction& f);
private:
	long numerateur_;
	long denominateur_;
	Fraction& simplifier();
};
