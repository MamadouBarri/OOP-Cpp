#include "Livre.h"

Livre::Livre(int nbChapitres)
{
	for (int i = 0; i < nbChapitres; i++) {
		tabChapitres_.push_back(new Chapitre());
	}
}

Livre::~Livre()
{
	for (int i = 0; i < tabChapitres_.size(); i++) {
		delete tabChapitres_[i];
	}
}

//constructeur par copie

Livre::Livre(const Livre& autreLivre)
{
	//on veut faire une deep copy
	//creer un nouveau vecteur avec la meme taille que autre livre
	//on peut juste utiliser push back a la place de acceder les vecteur avec []
	//tabChapitres_ = std::vector<Chapitre*>(autreLivre.tabChapitres_.size()); use less because vector with 0 elements is created and you dont need to assing
	for (int i = 0; i < tabChapitres_.size(); i++)
	{
		Chapitre* chap = new Chapitre(autreLivre.tabChapitres_[i]->getNom(), autreLivre.tabChapitres_[i]->getNbPages());
		tabChapitres_.push_back(chap);
	}
}

//surcharge de l'operateur d'affectation

Livre& Livre::operator=(const Livre& autreLivre)
{
	//verifier si ce nest pas le meme objet 
	if (this != &autreLivre)
	{
		//desallouer la memoire du vecteur de pointeurs
		for (int i = 0; i < tabChapitres_.size(); i++)
		{
			delete tabChapitres_[i];
		}
		tabChapitres_.clear();
		tabChapitres_ = std::vector<Chapitre*>(autreLivre.tabChapitres_.size());
		for (int i = 0; i < tabChapitres_.size(); i++)
		{
			tabChapitres_[i] = new Chapitre(autreLivre.tabChapitres_[i]->getNom(), autreLivre.tabChapitres_[i]->getNbPages());
		}
		return *this;
	}
}
