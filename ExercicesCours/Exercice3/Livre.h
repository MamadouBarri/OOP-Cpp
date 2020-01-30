#ifndef _LIVRE_H_
#define _LIVRE_H_

#include "Chapitre.h"
#include <vector>

using namespace std;

class Livre
{
public:
	Livre(int nbChapitres);
	~Livre();
	//constructeur de copie
	Livre(const Livre& autreLivre);
	//operateur d'affectation
	Livre& operator=(const Livre& autreLivre);
private:
	vector<Chapitre*> tabChapitres_;
};

#endif // _LIVRE_H_
