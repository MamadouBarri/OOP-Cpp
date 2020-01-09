// Cours1.cpp 
#include <iostream>


class Matrice {
public:
    Matrice(int hauteur = 0, int largeur = 0);
    ~Matrice();
    double& acceder(int ligne, int colonne);
private:
    int hauteur_;
    int largeur_;
    double* valeurs_;
};

Matrice::Matrice(int hauteur, int largeur) {
     hauteur_ = hauteur;
     largeur_ = largeur;
     valeurs_ = new double[hauteur_ * largeur_];
}

double& Matrice::acceder(int ligne, int colonne) {
    return valeurs_[ligne * largeur_ + colonne];
}

Matrice::~Matrice() {
    delete[] valeurs_;
}
using namespace std;
int main()
{
    Matrice matrice(20,30);
    Matrice m;
    matrice.acceder(2, 5) = 5;
    matrice.acceder(3, 2) = 120;
    cout << matrice.acceder(2, 5 ) << endl;
    cout << matrice.acceder(3, 2) << endl;
}

