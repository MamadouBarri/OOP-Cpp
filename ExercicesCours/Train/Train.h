#pragma once

class Personne;

class Train
{
public:
	//Constructeurs
	Train();
	//Destructeur
	~Train();
	//accesseurs
	double    getVitesse() const;
	int       getNbPersonnesABord() const;
	Personne* getChauffeur() const;
	double    getEtat() const;

	//methodes publiques
	void avancer(double vitesse);
	void arreter();
	void PrendreTrain(Personne* personne);
	void entretenir();
	void assignerChauffeur(Personne* chauffeur);
private:
	//methodes privees
	void accelerer();
	void freiner();
	double vitesse_ = 0.0;
	int nbPersonnesABord_;
	Personne* chauffeur_;
	double etat_;
};

