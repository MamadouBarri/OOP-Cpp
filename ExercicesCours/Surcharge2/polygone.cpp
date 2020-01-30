/****************************************************************************
 * Fichier: polygone.cpp
 * Auteur: Inconnu
 * Date: 
 * Mise a jour : 6 juin 2011
 * Description: Definition de la classe Polygone
 ****************************************************************************/

#include "polygone.h"



Polygone::Polygone()
	: points_()	// Constructeur par defaut d'un vecteur
{
	cout << "Construction d'un polygone" << endl;
}



Polygone::~Polygone()
{
	cout << "Destruction d'un polygone" << endl;

	for(unsigned int i=0; i< points_.size(); i++)
		delete points_[i];
}



void Polygone::ajouterPoint(double x, double y, double z)
{
	points_.push_back( new Point3d(x, y, z) );
}



void Polygone::afficher() const
{
	cout << "Les points du polygone : " << endl;

	for(unsigned int i=0; i< points_.size(); i++)
		cout << "   (" 
			<< points_[i]->getX() << ", "
			<< points_[i]->getY() << ", "
			<< points_[i]->getZ() << ")"
		<< endl;
}
//Constructeur par copie
Polygone::Polygone(const Polygone& autre) : points_(std::vector<Point3d*>())
{
	for (int i = 0; i < autre.points_.size(); i++)
	{
		//une deep copy du vecteur est necessaire
		ajouterPoint(
			autre.points_[i]->getX(),
			autre.points_[i]->getY(),
			autre.points_[i]->getZ());
	}
}

//Operateur d'affectation
Polygone& Polygone::operator= (const Polygone& poly)
{
	if (this != &poly)
	{
	//verifier si 
	//le operateur d'affectation doit aussi se faire avec une deep copie pour eviter les access a de la memoire desalloue
		for (int i = 0; i < poly.points_.size(); i++)
		{
			//au debut le vecteur est initilize par defaut a 0 
			ajouterPoint(
				poly.points_[i]->getX(),
				poly.points_[i]->getY(),
				poly.points_[i]->getZ());
		}
	}
	
	return *this;
}