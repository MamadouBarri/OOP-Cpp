/****************************************************************************
 * Fichier: Compteur.h
 * Auteurs: - Georges Abou-Khalil
 *          -
 *          -
 * Date: 16 sept 2008
 * Description: D�finition de la classe Compteur
 ****************************************************************************/

#ifndef _COMPTEUR_H_
#define _COMPTEUR_H_

class Compteur
{
public:
	Compteur(int nb = 0);
    //Constructeur de copie
    Compteur(const Compteur& autreCompteur);
    Compteur& operator= (const Compteur& autreCompteur);
    //Destructeur
    ~Compteur();
	int getNb() const;

	Compteur& inc();
	Compteur& dec();



private:
	int* ptrNb_;
};

#endif // _COMPTEUR_H_