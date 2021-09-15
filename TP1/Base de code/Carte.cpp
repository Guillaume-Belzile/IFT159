/**
* \file Carte.cpp
* \author Vincent Ducharme
* \brief Ce fichier contient la definition des methodes de la classe Carte d'un jeu de demineur
*/

#include "Carte.h"
#include "Utilities.h"

Carte::Carte(ifstream& fichierCarte)
{
    int ligne;
    int colonne;

    // 1. Lire le nombre de colonne de la carte
    fichierCarte >> colonne;
    // 2. Lire le nombre de ligne de la carte
    fichierCarte >> ligne;

    nbMines = 0;
    // 3. Pour toutes les lignes de la carte
    for (int i = 0; i < ligne; ++i)
    {
        // 3.1 Creer une nouvelle ligne dans la carte contenant les mines
        cases.push_back(vector<Case>());
        // 3.2 Creer une nouvelle ligne dans la carte contenant les cases ouvertes
        casesOuvertes.push_back(vector<bool>());

        // 3.3 Pour toutes les colonnes de la carte
        for (int j = 0; j < colonne; ++j)
        {
            int c;
            // 3.3.1 Lire la valeur de la carte
            fichierCarte >> c;
            // 3.3.2 Si c'est zero, ajouter une case libre dans la carte
            if (c == 0)
            {
                cases[i].push_back(Case::Libre);
            }
            // 3.3.3 Sinon, ajouter une mine dans la carte
            else
            {
                cases[i].push_back(Case::Mine);
                // 3.3.3.1 Incrementer le nombre de mine dans la carte
                nbMines++;
            }

            // 3.3.4 Ajouter une case fermee dans la carte des cases ouvertes
            casesOuvertes[i].push_back(false);
        }
    }

    // 4. Indiquer les cases contenant des nombres
    UpdateCarte();
}

/**
* \brief Methode qui ajoute les cases contenant des chiffres
* \param Aucun
* \return Aucun
*/
void Carte::UpdateCarte()
{
    // A completer
}

/**
* \brief Methode qui recupere le type d'une case
* \param Ligne de la case
* \param Colonne de la case
* \return Type de la case
*/
Case Carte::GetCase(int ligne, int colonne) const
{
    // 1. Si la position est dans a grille
    if (ligne >= 0 && ligne < GetNbLigne() && colonne >= 0 && colonne < GetNbColonne())
    {
        // 1.1 Retourne la valeur de la case demandee
        return cases[ligne][colonne];
    }

    // 2. Sinon retourne une case libre
    return Case::Libre;
}

/**
* \brief Methode qui calcule le nombre de mine adjacente a une case
* \param Ligne de la case
* \param Colonne de la case
* \return Nombre de mines
*/
int Carte::GetNbMinesAdjacentes(int ligne, int colonne) const
{
    // A completer
}

/**
* \brief Methode qui indique si une case est ouverte
* \param Ligne de la case
* \param Colonne de la case
* \return Vrai si la case est ouverte, faux autrement
*/
bool Carte::EstOuvert(int ligne, int colonne) const
{
	// A completer selon le pseudo code
    // 1. Si la case est dans la grille
        // 1.1 Retourne l'indicateur d'ouverture de la case

    // 2. Sinon, retourne faux
    return false;
}

/**
* \brief Methode qui ouvre une case de la carte
* \param Ligne de la case
* \param Colonne de la case
* \return Aucun
*/
void Carte::Ouvre(int ligne, int colonne)
{
	// A completer selon le pseudo code
    // 1. Si la case est dans la grille
        // 1.1 Indique que la case est ouverte
}

/**
* \brief Methode qui retourne le nombre de ligne de la carte
* \param Aucun
* \return Nombre de ligne
*/
int Carte::GetNbLigne() const
{
    return cases.size();
}

/**
* \brief Methode qui retourne le nombre de colonne de la carte
* \param Aucun
* \return Nombre de colonne
*/
int Carte::GetNbColonne() const
{
    if (cases.size() > 0)
    {
        return cases[0].size();
    }
    else
    {
        return 0;
    }
}

/**
* \brief Methode qui indique si les seules cases restantes a ouvrir sont les mines
* \param Aucun
* \return Indicateur de fin de partie
*/
bool Carte::EstFini() const
{
    int nbFermes = 0;
    // 1. Pour toutes les lignes
    for (int i = 0; i < GetNbLigne(); ++i)
    {
        // 1.1 Pour toutes les colonnes
        for (int j = 0; j < GetNbColonne(); ++j)
        {
            // 1.1.1 Si la case n'est pas ouverte
            if (!EstOuvert(i, j))
            {
                // 1.1.1.1 Incremente le nombre de case fermee
                nbFermes++;
            }
        }
    }

    // 2. Retourne vrai si le nombre de case fermee et egale au nombre de mine. Retourne faux autrement
    return nbFermes == nbMines;
}

/**
* \brief Operateur d'affichage sur un flux
* \param Flux sur lequel afficher
* \param Carte a afficher
* \return Flux sur lequel on a fait l'affichage
*/
ostream& operator<<(ostream& out, const Carte& carte)
{
    // Constantes
    const unsigned char FERME = 0xFE;
    const unsigned char MINE = 'X';

    // 1. Indique a la console d'ecrire en blanc
    Console::SetConsoleColor(Color::Blanc);

    // 2. Afficher la ligne indicative des colonnes
    // 2.1 Afficher l'espace du debut
    out << "    ";
    // 2.2 Si le nombre de ligne est plus grand que 9, ajouter un espace supplementaire
    if (carte.GetNbLigne() > 9)
    {
        out << " ";
    }

    // 2.3 Pour toutes les colonnes
    for (int j = 0; j < carte.GetNbColonne(); ++j)
    {
        // 2.3.1 Afficher le numero de la colonne
        out << j;
        // 2.3.2 Si le numero de la colonne est plus petit que 10, ajouter un espace
        if (j < 10)
        {
            out << " ";
        }
    }
    // 2.4 Faire un saut de ligne
    out << endl;

    // 2.5 Afficher la ligne de separation horizontale
    for (int j = 0; j < carte.GetNbColonne() + 4; ++j)
    {
        out << "--";
    }
    // 2.6 Faire un saut de ligne
    out << endl;

    // 3. Pour toutes les lignes de la carte
    for (int i = 0; i < carte.GetNbLigne(); ++i)
    {
        // 3.1 Afficher le numero de la ligne
        out << i;
        // 3.2 Si le numero de la ligne est plus petit que 10, ajouter un espace apres le nombre
        if (i < 10)
        {
            out << " ";
        }
        // 3.3 Afficher la ligne verticale de separation
        out << " | ";
        // 3.4 Pour toutes les colonnes de la ligne
        for (int j = 0; j < carte.GetNbColonne(); ++j)
        {
            // 3.4.1 Si la case est ouverte
            if (carte.EstOuvert(i, j))
            {
                // 3.4.1.1 Si la case est une mine, afficher le symbole de la mine
                if (carte.GetCase(i,j) == Case::Mine)
                {
                    out << MINE << ' ';
                }
                // 3.4.1.2 Sinon
                else
                {
                    // 3.4.1.2.1 Calculer le nombre de mines adjacentes
                    int mine = carte.GetNbMinesAdjacentes(i, j);
                    // 3.4.1.2.2 S'il y a des mines autour
                    if (mine > 0)
                    {
                        // 3.4.1.2.2.1 En fonction du nombre de mine, changer la couleur du terminal
                        if (mine == 1)
                        {
                            // En bleu pour une mine
                            Console::SetConsoleColor(Color::Bleu);
                        }
                        else if (mine == 2)
                        {
                            // En vert pour deux mines
                            Console::SetConsoleColor(Color::Vert);
                        }
                        else if (mine == 3)
                        {
                            // En rouge pour trois mines
                            Console::SetConsoleColor(Color::Rouge);
                        }
                        else if (mine == 4)
                        {
                            // En bleu fonce pour 4 mines
                            Console::SetConsoleColor(Color::BleuFonce);
                        }
                        else if (mine == 5)
                        {
                            // En magenta fonce pour 5 mines
                            Console::SetConsoleColor(Color::MagentaFonce);
                        }
                        else if (mine == 6)
                        {
                            // En rouge fonce pour 6 mines
                            Console::SetConsoleColor(Color::RougeFonce);
                        }
                        else if (mine == 7)
                        {
                            // En cyan fonce pour 7 mines
                            Console::SetConsoleColor(Color::CyanFonce);
                        }
                        else if (mine == 8)
                        {
                            // En jaune fonce pour 8 mines
                            Console::SetConsoleColor(Color::JauneFonce);
                        }
                        // 3.4.1.2.2.2 Afficher le nombre de mine
                        out << mine << " ";

                        // 3.4.1.2.2.3 Remettre la couleur a blanc
                        Console::SetConsoleColor(Color::Blanc);
                    }
                    // 3.4.1.2.3 Sinon, afficher une case vide
                    else
                    {
                        out << "  ";
                    }
                }
            }
            // 3.4.2 Sinon, affiche une case fermee
            else
            {
                out << FERME << " ";
            }
        }
        // 3.5 Afficher la ligne verticale de fin de carte, suivi d'un saut de ligne
        out << "| " << endl;
    }

    // 4. Pour toutes la largeur de la carte, afficher la ligne horizontale de fin de carte
    for (int j = 0; j < carte.GetNbColonne() + 3; ++j)
    {
        out << "--";
    }

    // 5. Si le nombre de ligne etait plus grand que 9, ajouter une ligne
    if (carte.GetNbLigne() > 9)
    {
        out << "-";
    }
    // 6. Faire un saut de ligne
    out << endl;

    // 7. Retourner le flux d'ecriture
    return out;
}