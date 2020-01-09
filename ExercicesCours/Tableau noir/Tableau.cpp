#include "Tableau.h"

//Declare all the functions of header file

//Constructors
Tableau::Tableau() {
	caracteres_ = "";
	salete_ = 0;
	saleteSeuil_ = 30;
}

Tableau::Tableau(string caracteres, int salete, int saleteSeuil) {
	caracteres_ = caracteres;
	salete_ = salete;
	saleteSeuil_ = saleteSeuil;
}

//Destructeur
Tableau::~Tableau() {
	cout << "Destruction du tableau" << endl;
}

string Tableau::getCaracteres() const {
	return caracteres_;
}

int Tableau::getSalete() const {
	return salete_;
}

int Tableau::getSaleteSeuil() const {
	return saleteSeuil_;
}

void Tableau::ajouterCaracteres(string caracteres) {
	caracteres_ += caracteres;
}

void Tableau::setSaleteSeuil(int saleteSeuil) {
	saleteSeuil_ = saleteSeuil;
}

bool Tableau::estSale() {
	return (salete_ >= saleteSeuil_);
}

void Tableau::effacer() {
	cout << "Talbeau efface" << endl;
	salir(caracteres_.size());
	caracteres_ = "";
}

void Tableau::laver() {
	cout << "Tableau lave" << endl;
	salete_ = 0;
	caracteres_ = "";
}

//Methode privee
void Tableau::salir(unsigned int nbCharacteres) {
	salete_ += nbCharacteres / 2 + 1;
}
