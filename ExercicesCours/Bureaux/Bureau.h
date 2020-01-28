#pragma once
#include "Classeur.h"
#include "Imprimante.h"
class Bureau
{
public:
	Bureau(Classeur classeur, Imprimante* imprimante)
	:	classeur_(classeur)
	,	imprimante_(imprimante)
	{}

	~Bureau() 
	{
		//on ne delete pas le pointeur car plusieurs Bureaux peuvent partager la meme imprimante 
	}
private :
	Classeur classeur_;
	Imprimante* imprimante_;
};

