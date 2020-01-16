#include "Sphere.h"
#include <iostream>

Sphere::Sphere(const Point& centre, const double& rayon) : centre_(centre), rayon_(rayon)
{
}

Sphere::Sphere(const double& x, const double& y, const double& z, const double& rayon) : centre_(x, y, z), rayon_(rayon)
{
}

void Sphere::move(const double& dx, const double& dy, const double& dz)
{
	centre_.move(dx, dy, dz);
}

void Sphere::reinitialiser()
{
	centre_.reset();
}

void Sphere::print() const
{
	centre_.print();
	std::cout << "rayon : " << rayon_;
}

Point Sphere::getPoint() const
{
	return centre_;
}

double Sphere::getRayon() const
{
	return rayon_;
}

void Sphere::setPoint(Point point)
{
	centre_ = point;
}

void Sphere::setRayon(double rayon)
{
	rayon_ = rayon;
}
