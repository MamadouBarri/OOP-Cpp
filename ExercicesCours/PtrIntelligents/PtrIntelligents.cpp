#include <iostream>
#include <string>

#include <memory>

#include <vector>
using namespace std;


class Livre
{
public:
	Livre(string titre, string auteur)
		: titre_(titre), auteur_(auteur) {}

	string getTitre()  const { return titre_; }
	string getAuteur() const { return auteur_; }

private:
	string titre_;
	string auteur_;
};


class BibliothequeElectronique
{
public:
	void ajouterLivre(shared_ptr<Livre> livre)
	{
		livres_.push_back(livre);
	}
	shared_ptr<Livre> prendreCopie(string titre)
	{
		unsigned int i = 0;

		while (i < livres_.size())
		{
			if (livres_[i]->getTitre() == titre)
				return livres_[i];
			++i;
		}

		return 0;
	}
private:
	vector<shared_ptr<Livre>> livres_;
};

int main()
{
	BibliothequeElectronique* biblio = new BibliothequeElectronique();

	biblio->ajouterLivre(make_shared<Livre>("La fin de Cheri", "Colette"));
	biblio->ajouterLivre(make_shared<Livre>("L'amour dure trois ans", "Frederic Beigbeder"));
	biblio->ajouterLivre(make_shared<Livre>("J'irai cracher sur vos tombes", "Boris Vian"));
	biblio->ajouterLivre(make_shared<Livre>("Truismes", "Marie Darrieussecq"));

	cout << "J'irai cracher sur vos tombes" << endl;
	cout << biblio->prendreCopie("J'irai cracher sur vos tombes")->getAuteur() << endl;

	delete biblio;

	return 0;
}