#pragma once

class Telephone
{
public :
	Telephone();
	~Telephone();
	int getNumero() const;
	void setNumero(int numero);
	int getPoste() const;
	void setPoste(int poste);
	void afficher() const;
	bool appeler(int numero, int poste);
	Telephone* repondre() const;
private :
	bool enLigne_;
	Telephone* connexion_;
	int numero_;
	int poste_;
};