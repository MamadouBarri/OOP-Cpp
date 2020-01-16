#pragma once
#include "Point.h"
class Sphere
{
public:
	Sphere(const Point& centre ,const double& rayon = 1.0); // deux constructeur
	Sphere(const double& x,const double& y,const double& z, const double& rayon);
	void move(const double& dx,const double& dy, const double& dz);
	void reinitialiser();
	void print() const;
	Point getPoint() const;
	double getRayon() const;
	void setPoint(Point point);
	void setRayon(double rayon);
private:
	Point centre_;
	double rayon_;
};

