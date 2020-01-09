

class Point3D
{
public:
	//constructeur par defaut
	Point3D();
	//constructeur parametres
	Point3D(double x, double y, double z);
	//accesseurs
	double getX() const;
	double getY() const;
	double getZ() const;
	//modificateurs
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	void   move(double x, double y, double z);
	void   reset();
	void   imprimmer();
private:
	double x_;
	double y_;
	double z_;

};