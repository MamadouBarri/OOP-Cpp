/****************************************************************************
 * Fichier: Vecteur.cpp
 * Auteurs: - Georges Abou-Khalil
 *          -
 *          -
 * Date: 16 sept 2008
 * Description: Implémentation de la classe Vecteur
 ****************************************************************************/

#include "Vecteur.h"
#include <iostream>

using namespace std;

/****************************************************************************
 * Fonction: Vecteur::Vecteur
 * Description: Constructeur par paramètre
 * Paramètres: - unsigned int taille: la taille du vecteur
 * Retour: aucune
 ****************************************************************************/
Vecteur::Vecteur(unsigned int taille)
: taille_(taille)
{
	// On évite une taille de 0
	if (taille_ == 0) {
		taille_ = 1;
	}

	ptr_ = new int[taille_];
}


//definir le destructeur

Vecteur::~Vecteur()
{
    delete ptr_;
    ptr_ = nullptr;
}

//Definir le constructeur par copie
Vecteur::Vecteur(const Vecteur& autreVec)
{
    //on doit effectuer une deep copie puisquon ne veut pas que apres avoir copier un vecteur, 
    //les modifications sur l'un affecte egaelement lautre
    //il faut donc manuellement copier les items des tableaux

    //on peut copier la taille
    taille_ = autreVec.getTaille();
    //deep copie du tableau
    //allouer la taille necessaire pour faire la copie
    ptr_ = new int[taille_];
    for (int i = 0; i < taille_; i++)
    {
        //ceci marche pas car on fait simplement copier les 
        //on doit donc faire une deep copy
        //refernce d'un enter = refenrece d'un autre entier, on fait la copie
        ptr_[i] = autreVec.ptr_[i];
    }
}

Vecteur& Vecteur::operator=(const Vecteur& autreVec)
{
    //on doit faire une deep copie et ne pas seulement transfermer le pointeur
    if (this != &autreVec)//lorsque l'objet auquel on affecte n'est pas le meme que affecter parce quon va liberer de la memoire
    {
        //puisque ptr est un pointeur vers un array, on doit specifier qu'il faut delete
        delete[] ptr_;
        taille_ = autreVec.taille_;
        ptr_ = new int[taille_];
        for (int i = 0; i < taille_; i++)
        {
            ptr_[i] = autreVec.ptr_[i];
        }
    }
    return *this;
}

/****************************************************************************
 * Fonction: Vecteur::getTaille
 * Description: Retourne la taille du vecteur
 * Paramètres: aucun
 * Retour: (unsigned int) la taille du vecteur
 ****************************************************************************/
unsigned int Vecteur::getTaille() const
{
	return taille_;
}

/****************************************************************************
 * Fonction: Vecteur::operator[]
 * Description: Retourne une case du vecteur
 * Paramètres: - unsigned int i: indice de la case désirée
 * Retour: (int&) référence vers la case
 ****************************************************************************/
int& Vecteur::operator[](unsigned int i)
{
	return ptr_[i];
}

/****************************************************************************
 * Fonction: Vecteur::afficher
 * Description: affiche le vecteur à l'écran
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
void Vecteur::afficher() const
{
	cout << "[ ";
	for (unsigned int i = 0; i < taille_; i++) {
		cout << ptr_[i] << " ";
	}
	cout << "]" << endl;
}
