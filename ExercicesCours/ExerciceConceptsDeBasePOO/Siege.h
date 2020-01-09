#pragma once
#include<string>


using namespace std;

class Siege
{
public:
	Siege();
	Siege(int nbPersonnes, int nbPattes, string nomCommun);
	~Siege(); //Destructeur ne peut pas avoir de parametres
	int getNbPersonnes() const;
	int getNbPattes() const;
	string getNomCommun() const;
	void setNbPersonnes(int nbPersonnes);
	void setNbPattes(int nbPattes);
	void setNomCommun(string nomCommun);
private:
	int nbPersonnes_;
	int nbPattes_;
	string nomCommun_;

};
//Getters

int Siege::getNbPersonnes() const {
	return nbPersonnes_;
}

int Siege::getNbPattes() const {
	return nbPersonnes_;
}

string Siege::getNomCommun() const {
	return nomCommun_;
}

//Setters

void Siege::setNbPersonnes(int nombrePersonnes) {
	nbPersonnes_ = nombrePersonnes;
}

void Siege::setNbPattes(int nbPattes) {
	nbPattes_ = nbPattes;
}

void Siege::setNomCommun(string nomCommun) {
	nomCommun_ = nomCommun;
}

//Constructeur par defaut
Siege::Siege() {
	nbPersonnes_ = 1;
	nbPattes_ = 4;
	nomCommun_ = "chaise";
}

//Constructeur avec parametres
Siege::Siege(int nbPersonnes, int nbPattes, string nomCommun) {
	nbPersonnes_ = nbPersonnes;
	nbPattes_ = nbPattes;
	nomCommun_ = nomCommun;
}

//Destructeur
Siege::~Siege() {
	
}

