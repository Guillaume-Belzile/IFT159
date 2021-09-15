/**
* \file Carte.h
* \author Vincent Ducharme
* \brief Ce fichier contient la definition de la classe representant la carte d'un jeu de demineur
*/

#ifndef _CARTE_H_
#define _CARTE_H_

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

enum Case
{
    Chiffre,
    Libre,
    Mine
};

class Carte
{
    vector<vector<bool> > casesOuvertes;
    vector<vector<Case> > cases;

    int nbMines;

    void UpdateCarte();
public:
    Carte(ifstream&);

    Case GetCase(int ligne, int colonne) const;
    int GetNbMinesAdjacentes(int ligne, int colonne) const;
    int GetNbLigne() const;
    int GetNbColonne() const;
    void Ouvre(int ligne, int colonne);
    bool EstOuvert(int ligne, int colonne) const;
    bool EstFini() const;

    friend ostream& operator<<(ostream& out, const Carte& carte);
};

ostream& operator<<(ostream& out, const Carte& carte);

#endif
