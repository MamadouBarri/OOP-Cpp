/*
 * Copyright (C) 2009    Angelo Rossi <angelo.rossi@polymtl.ca>
 * Copyright (C) 2015    Rapha�l Beamonte <raphael.beamonte@polymtl.ca>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation  and/or other materials provided with the distribution.
 * 3. Neither the names of the copyright holders nor the names of any
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * This file has been created for the purpose of the INF1010
 * course of �cole Polytechnique de Montr�al.
 */

 /**********
  * ENONCE *
  **********
  * � partir de la classe "Point" qui vous est fournie:
  * - Ajouter les const manquants --
  * - Optimiser l'initialisation des attributs --
  * - Optimiser le passage des param�tres --
  * - Combiner les quatre constructeurs gr�ce aux param�tres par d�faut --
  *
  * Cr�er la classe Sphere, compos�e d'un Point (son centre) et d'un
  * double (son rayon). La classe Sphere doit permettre:
  * - Sa construction par d�faut (centre 0,0,0 et rayon 1)
  * - Sa construction avec sp�cification des coordonn�es (double, double
  *   double) de son centre et de son rayon (double)
  * - Sa construction avec sp�cification de son centre (Point) et de
  *   son rayon (double) --
  * - D'�tre d�plac�e (en d�pla�ant son centre) via la m�thode move() --
  * - De r�initialiser la position de la sph�re (en d�pla�ant son centre) --
  *   via la m�thode reset() --
  * - D'afficher les attributs de la sph�re gr�ce � la m�thode print() --
  * N'oubliez pas les get/set lorsque n�cessaire.
  * Commentez correctement les .h (prendre exemple sur Point.h)
  */

#include <iostream>
using namespace std;

#include "Point.h"
#include "Sphere.h"

int main()
{
    /* Point */
    Point p1; // constructeur par defaut (coordonnees (0,0,0) par defaut)
    Point p2(1, 2, 3); // constructeur par parametre (coordonnees (1,2,3))

    //Affichage des coordonnees:
    cout << "coordonnees du p1 "; p1.print();
    cout << "coordonnees du p2 "; p2.print();

    //on bouge le p1
    p1.move(10, 20, 30);

    //on reset le p2
    p2.reset();

    //Affichage des coordonnees:
    cout << "coordonnees du p1 "; p1.print();
    cout << "coordonnees du p2 "; p2.print();


    /* Sphere */
    Sphere sphere1; // Constructeur par defaut
    Sphere sphere2(2.1, 8, 7, 12); // Constructeur par param�tres
    Sphere sphere3(p1, 20.76); // Constructeur par param�tres

    sphere1.print();
    sphere2.print();
    sphere3.print();

    return 0;
}