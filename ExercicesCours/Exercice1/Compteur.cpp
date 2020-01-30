/****************************************************************************
 * Fichier: Compteur.cpp
 * Auteurs: - Georges Abou-Khalil
 *          -
 *          -
 * Date: 16 sept 2008
 * Description: Implémentation de la classe Compteur
 ****************************************************************************/

#include "Compteur.h"
#include <iostream>

using namespace std;

/****************************************************************************
 * Fonction: Compteur::Compteur
 * Description: Constructeur par paramètre
 * Paramètres: - unsigned int nb: la valeur initiale du compteur
 * Retour: aucune
 ****************************************************************************/
Compteur::Compteur(int nb)
{
	ptrNb_ = new int(nb);
}

//constructeur par copie, on fait une deep copie pour eviter les memoires partages et les fuites de memoires
Compteur::Compteur(const Compteur& autreCompteur) : ptrNb_(new int(autreCompteur.getNb()))
{}

//destructeur
Compteur::~Compteur()
{
    delete ptrNb_;
}

//operateur d'affectation
Compteur& Compteur::operator=(const Compteur& autreCompteur)
{
    //verifier que le parametre n'est pas le meme objet pointe par this
    if (this != &autreCompteur)
    {
        //liberer lancienne memoire
        delete ptrNb_;
        //on fait une deep copie pour eviter les fuites de memoires et les memoires partages
        ptrNb_ = new int(autreCompteur.getNb());
    }
    return  *this;
}

/****************************************************************************
 * Fonction: Compteur::getNb
 * Description: retourne la valeur du compteur
 * Paramètres: aucun
 * Retour: (int) la valeur du compteur
 ****************************************************************************/
int Compteur::getNb() const
{
	return *ptrNb_;
}

/****************************************************************************
 * Fonction: Compteur::inc
 * Description: incrémente le compteur
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Compteur& Compteur::inc()
{
	(*ptrNb_)++;
	return *this;
}

/****************************************************************************
 * Fonction: Compteur::dec
 * Description: decrémente le compteur
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Compteur& Compteur::dec()
{
	(*ptrNb_)--;
	return *this;
}
