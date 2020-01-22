// Cours1.cpp 
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;
class Matrice {
public:
    Matrice(int hauteur = 0, int largeur = 0);
    const double& acceder(int ligne, int colonne) const;
    double& acceder(int ligne, int colonne);
        //getters
    int getHauteur() const;
    int getLargeur() const;
    void changerDimensions(int hauteur, int largeur);
private:
    int accederInterne(int ligne, int colonne) const;
    int hauteur_;
    int largeur_;
    //lorsque l'objet est const on peut modifier les valeurs pointe mais pas le pointeur 
    vector<double> valeurs_;//
};

void Matrice::changerDimensions(int hauteur, int largeur) 
{
    Matrice copie(hauteur, largeur);
    for (int i = 0; i < min(hauteur, hauteur_); i++)
        for (int j = 0; j < min(largeur, largeur_); j++)
            copie.acceder(i, j) = acceder(i, j);
    hauteur_ = hauteur;
    largeur_ = largeur;
    valeurs_ = move(copie.valeurs_);
    //la copie est detrurie a la fin de laccolade car variable locale
}

int Matrice::getHauteur() const {
    return hauteur_;
}

int Matrice::getLargeur() const {
    return largeur_;
}

Matrice::Matrice(int hauteur, int largeur) :
    hauteur_(hauteur),
    largeur_(largeur),
    valeurs_(hauteur_* largeur_)
{
}

int Matrice::accederInterne(int ligne, int colonne) const {
    return (ligne * largeur_ + colonne);
}

const double& Matrice::acceder(int ligne, int colonne) const {
    return accederInterne(ligne, colonne);
}

double& Matrice::acceder(int ligne, int colonne) {
    return valeurs_[accederInterne(ligne, colonne)];
}

void afficherValeurMatrice(const Matrice& matrice) {
        cout << matrice.acceder(2, 5) << endl;
}

void modifierMatrice(Matrice& matrice) {
    matrice.acceder(2, 5) +=10;
    //puisque cest une copie qui se termine dans le bloc -> le destructeur est appele pour matrice donc desalloue
}


//copie automatiquement le vecteur
void calculer(Matrice matrice) {
    matrice.acceder(2, 5) += 100;
    cout << matrice.acceder(2, 5) << endl;
}

Matrice copierMatrice(const Matrice& matrice){
    Matrice copie(matrice.getHauteur(), matrice.getLargeur());
    for (int i = 0; i < copie.getHauteur(); i++) {
        for (int j = 0; j < copie.getLargeur(); j++) {
            copie.acceder(i, j) = matrice.acceder(i, j);
        }
    }
    return copie;
}

int main()
{
    Matrice matrice(20,30);
    matrice.acceder(2, 5) = 4;
    matrice.acceder(3, 2) = 120;
    modifierMatrice(matrice);
    afficherValeurMatrice(matrice);
    //un move implicite est fait a chaque fois puisquon ne va pas lacceder une autre fois : return et passage par parametres sont des move explicite meme avec un shared pointer -- > depend pas du type
    calculer(matrice);
    cout << matrice.acceder(2, 5 ) << endl;
    matrice.changerDimensions(5, 6);
    cout << matrice.acceder(2, 5) << endl;
    //ici le destructeur est encore appelle et donc on desalloue de la memoire deja desalloue
}

