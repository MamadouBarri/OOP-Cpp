// Imprimante.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class CartoucheEncre
{
public:
    CartoucheEncre(float niveau) {
        niveau_ = niveau;
    }
    float getNiveau() const { return niveau_; }
    void afficher() const
    {
        cout << " " << getNiveau() << " % encore" << endl;
    }
private :
    float niveau_;

};

class BacFeuilles
{
public:
    BacFeuilles(int nbFeuilles)
    {
        nbFeuilles_ = nbFeuilles;
    }
    int getNbFeuille() const
    {
        return nbFeuilles_;
    }
    void afficher() const {
        cout << " " << getNbFeuille() << " feuilles" << endl;
    }
private :   
    int nbFeuilles_;
};


class Imprimante
{
public :
    Imprimante(float niveauEncore, int nbFeuilles)
        : encreNoir_(niveauEncore), bacFeuilles_(nbFeuilles) {}
    void afficher() const {
        cout << "Etat de l'imprimante :" << endl;
        encreNoir_.afficher();
        bacFeuilles_.afficher();
    }
private :
    CartoucheEncre encreNoir_;
    BacFeuilles bacFeuilles_;
};

int main()
{
    std::cout << "Hello World!\n";
}
