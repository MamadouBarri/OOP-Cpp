#ifndef _VECTEUR_H_
#define _VECTEUR_H_

class Vecteur
{
public:
	Vecteur(unsigned int taille);
	Vecteur(const Vecteur& autreVec);
	~Vecteur();

	Vecteur& operator=(const Vecteur& autreVec);

	unsigned int getTaille() const;
	int& operator[](unsigned int i);

	void afficher() const;

private:
	int* ptr_;
	unsigned int taille_;
};

#endif // _VECTEUR_H_