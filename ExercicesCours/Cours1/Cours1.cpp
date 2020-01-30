// Cours1.cpp 
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;
class Matrice {
public:
    Matrice(int hauteur = 0, int largeur = 0);
    Matrice(const Matrice& mat);
    const double& acceder(int ligne, int colonne) const;
    double& acceder(int ligne, int colonne);

    const double& operator()(int ligne, int colonne) const;
    double& operator()(int ligne, int colonne);

        //getters
    int getHauteur() const;
    int getLargeur() const;
    void changerDimensions(int hauteur, int largeur);
    Matrice operator+ (const Matrice& a) const;
    Matrice& operator=(const Matrice& autre);
    Matrice& operator=(Matrice&& autre);
private:
    int accederInterne(int ligne, int colonne) const;
    int hauteur_;
    int largeur_;
    //lorsque l'objet est const on peut modifier les valeurs pointe mais pas le pointeur 
    std::unique_ptr<double[]> valeurs_;//
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


void afficherAddition(const Matrice& a, const Matrice& b)
{

}

Matrice Matrice::operator+(const Matrice& b) const 
{
    assert(largeur_ == b.largeur_ && hauteur_ == b.hauteur_);
    Matrice nouvelleMatrice = Matrice(hauteur_, largeur_);
    const Matrice& a = *this;
    for (int hauteur = 0; hauteur < hauteur_; hauteur++)
        for (int largeur = 0; largeur < largeur_; largeur++)
            nouvelleMatrice(hauteur, largeur) = a(hauteur, largeur) + b(hauteur, largeur);
    return nouvelleMatrice;
        
}

Matrice& Matrice::operator=(const Matrice& autre)
{
    if (this != &autre)
    {
        assert(hauteur_ == autre.hauteur_ && largeur_ == autre.largeur_ && "Les tailles des matrices doivent etre identiques");
        Matrice copie(autre.getHauteur(), autre.getLargeur());
        for (int i = 0; i < hauteur_ * largeur_; i++)
        {
            valeurs_[i] = autre.valeurs_[i];
        }
    }
    return *this;
}

Matrice& Matrice::operator=(Matrice&& autre)
{
    if (this != &autre)
    {
        assert(hauteur_ == autre.hauteur_ && largeur_ == autre.largeur_ && "Les tailles des matrices doivent etre identiques");
        Matrice copie(autre.getHauteur(), autre.getLargeur());
        for (int i = 0; i < hauteur_ * largeur_; i++)
        {
            valeurs_[i] = autre.valeurs_[i];
        }
    }
    return *this;
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
    valeurs_(std::make_unique<double[]>(hauteur_* largeur_))
{
}

Matrice::Matrice(const Matrice& mat) : Matrice(mat.largeur_, mat.hauteur_)
{
    for (int i = 0; i < largeur_ * hauteur_; i++)
        valeurs_[i] = mat.valeurs_[i];
}

int Matrice::accederInterne(int ligne, int colonne) const {
    return valeurs_[ligne * largeur_ + colonne];
}

ostream& operator<< (ostream& o, const Matrice& m)
{
    for (int i = 0; i < m.getHauteur(); i++) {
        for (int j = 0; j < m.getLargeur(); j++) {
            o << m.acceder(i, j) << " ";
        }
    o << endl;
    }
    return o;
}


const double& Matrice::acceder(int ligne, int colonne) const {
    return accederInterne(ligne, colonne);
}

double& Matrice::acceder(int ligne, int colonne) {
    return valeurs_[accederInterne(ligne, colonne)];
}

const double& Matrice::operator()(int ligne, int colonne) const
{
    return acceder(ligne, colonne);
}

double& Matrice::operator()(int ligne, int colonne)
{
    return acceder(ligne, colonne);
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
    Matrice b(7, 8);
    Matrice matrice(7, 8);
    Matrice c(7, 8);
    
    //affectation entre des objets
    c = b;
    cout << c << endl;
    matrice(1,1) = 5;
    matrice(3, 3) = 5;
    std::cout << matrice + b << endl;
    //ici le destructeur est encore appelle et donc on desalloue de la memoire deja desalloue
}

