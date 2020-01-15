/*
 * Copyright (C) 2015    Raphaël Beamonte <raphael.beamonte@polymtl.ca>
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
 * course of École Polytechnique de Montréal.
 */

 /**********
  * ENONCE *
  **********
  * Ce programme a un problème, quel est-il ?
  * Proposez une façon de le corriger avec les pointeurs intelligents, et une
  * autre avec la gestion des exceptions.
  */

#include <iostream>
#include <stdexcept>
using namespace std;

class Creature
{
public:
    virtual ~Creature() {};
};

class Lutin : public Creature
{
public:
    Lutin() { cout << "Lutin::Lutin()" << endl; }
    ~Lutin() { cout << "Lutin::~Lutin()" << endl; }
};

class Gnome : public Creature
{
public:
    Gnome() { cout << "Gnome::Gnome()" << endl; }
    ~Gnome() { cout << "Gnome::~Gnome()" << endl; }
};

#define PLACES_AU_PAYS_DES_MERVEILLES 5
int places_occupees = 0;

Creature paysDesMerveilles[PLACES_AU_PAYS_DES_MERVEILLES];

void ajouterCreature(unique_ptr<Creature> nouveauVenu) {
    if (places_occupees < PLACES_AU_PAYS_DES_MERVEILLES) {
        paysDesMerveilles[places_occupees++] = *nouveauVenu;
    }
    else {
        throw overflow_error("Plus de place au pays des merveilles!");
    }
}

void peuplerLePaysDesMerveilles(int taille) {
    for (int i = 0; i < taille; i++) {
        unique_ptr<Creature> petitNouveau = nullptr;
        switch (i % 2) {
        case 0:
            petitNouveau.reset(new Lutin);
            break;
        case 1:
        default:
            petitNouveau.reset(new Gnome);
            break;
        }

        ajouterCreature(move(petitNouveau));
    }
}

int main() {
    int nb;
    cout << "Combien de créatures ajouter? " << endl;
    cin >> nb;

    try {
        peuplerLePaysDesMerveilles(nb);
        cout << "Le pays des merveilles a été peuplé!" << endl;
    }
    catch (const overflow_error & e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}