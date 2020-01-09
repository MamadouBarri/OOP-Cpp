//accesseurs
#include "Point3D.h"
#include <iostream>
//Constructeurs

Point3D::Point3D() {
	x_ = 0;
	y_ = 0;
	z_ = 0;
}

Point3D::Point3D(double x, double y, double z) {
	x_ = x;
	y_ = y;
	z_ = z;
}

//Methodes publiques

void Point3D::setX(double x) {
	x_ = x;
}

void Point3D::setY(double y) {
	y_ = y;
}
void Point3D::setZ(double z) {
	z_ = z;
}

double Point3D::getX() const {
	return x_;
}

double Point3D::getY() const {
	return y_;
}

double Point3D::getZ() const {
	return z_;
}

void Point3D::move(double x, double y, double z) {
	x_ = x;
	y_ = y;
	z_ = z;
}

void Point3D::reset() {
	x_ = 0;
	y_ = 0;
	z_ = 0;
}

void Point3D::imprimmer() {
	std::cout << "x:" << x_ << " y:" << y_ << " z:" << z_;
}