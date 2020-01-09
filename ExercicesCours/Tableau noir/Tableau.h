#pragma once
#ifndef _TABLEAU_H_
#define _TABLEAU_H_

#include <string>
#include <iostream>

using namespace std;
class Tableau
{
public :
	//Constructeur defaut
	Tableau();
	Tableau(string caracteres, int salete, int seuilSalete);
	//Destructeur
	~Tableau();

	//accesseurs 
	string getCaracteres() const;
	int getSalete() const;
	int getSaleteSeuil() const;

	//modificateurs
	void ajouterCaracteres(string caracteres);
	void setSaleteSeuil(int seuil);

	//tableau doit etre lave
	bool estSale();
	void effacer();
	void laver();

private:
	//Salie le tableau
	void salir(unsigned int nbCaracteres);
	//Attributs
	string caracteres_;
	int salete_;
	int saleteSeuil_;
};

#endif