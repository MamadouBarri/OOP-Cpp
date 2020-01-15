/****************************************************************************
 * Fichier: main.cpp
 * Auteur: William Bussiere
 * Date: 2 juin 2011
 * Description: Exercice facile d'allocation dynamique
 *				sur le theme des bonnes pratiques vis-a-vis des pointeurs.
 ****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int* nbTerrains   = new int(24);
	int* nbCommerces  = new int(31);
	int* nbEspaces = nullptr;

	if (nbEspaces == nullptr && nbTerrains != nullptr && nbCommerces != nullptr) {
		nbEspaces = new int(*nbTerrains + *nbCommerces);
	}
	else if(nbEspaces != nullptr && nbTerrains != nullptr && nbCommerces != nullptr){
		*nbEspaces = *nbTerrains + *nbCommerces;
	}

	if (nbEspaces != nullptr) {
		cout << "Nombre d'espaces a vendre : " << *nbEspaces << endl;
	}

	delete nbEspaces;

	int* nbMaisons = new int(16);
	int* nbParcs   = new int(28);
	nbTerrains = new int(*nbMaisons + *nbParcs);
	cout << "Nombre de terrains a vendre : " << *nbTerrains << endl;

	*nbParcs -= 7;
	nbTerrains = new int(*nbMaisons + *nbParcs);
	cout << "Nombre de terrains a vendre : " << *nbTerrains << " dont "
		<< *nbMaisons << " mainsons et "
		<< *nbParcs << " parcs." << endl;


	nbEspaces = new int( *nbTerrains + *nbCommerces);
	cout << "Nouveau nombre d'expaces : " << *nbEspaces << endl;;
	cout << endl;
	delete nbEspaces;
	delete nbTerrains;
	delete nbMaisons;
	delete nbParcs;
	delete nbCommerces;
	nbEspaces = nullptr;
	nbTerrains = nullptr;
	nbMaisons = nullptr;
	nbParcs = nullptr;
	nbCommerces = nullptr;
	return 0;
}