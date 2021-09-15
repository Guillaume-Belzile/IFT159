/**
* \file main.cpp
* \author Vincent Ducharme
* \brief Ce fichier contient un jeu de Démineur
*/

#include "Carte.h"
#include "Utilities.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

/**
* \brief Programme principal pour le jeu Demineur
* \param Aucun
* \return Aucun
*/
int main()
{
    // Prototypes (? http://www.cplusplus.com/articles/yAqpX9L8/)
    bool OuvreCase(Carte& carte, int ligne, int colonne);

    string nomFichierCarte;

    // 1. Lire le nom du fichier contenant la carte de jeu
    cout << "Entrez le nom du fichier contenant la carte : ";
    cin >> nomFichierCarte;

    // 2. Ouvrir le fichier
    ifstream fichierCarte(nomFichierCarte);
    // 3. Tant que le nom du fichier est different de "quitter" et que le fichier demande n'a pas pus etre ouvert
    while (nomFichierCarte != "quitter" && !fichierCarte.is_open())
    {
        // 3.1 Afficher un message d'erreur
        cout << "Fichier introuvable!" << endl << "Entrez le nom du fichier contenant la carte : ";
        // 3.2 Redemander un nom de fichier
        cin >> nomFichierCarte;
        // 3.3 Tenter d'ouvrir a nouveau le fichier
        fichierCarte.open(nomFichierCarte);
    }

    // 4. Si le fichier a bien ete ouvert
    if (fichierCarte.is_open())
    {
        // 4.1 Creer la carte a partir du fichier
        Carte carte(fichierCarte);

        //4.2 Afficher la carte
        cout << carte;

        int ligne = 0;
        int colonne = 0;
        // 4.3 Tant qu'on ne veut pas quitter
        while (ligne != -1)
        {
            // 4.3.1 Lire la ligne a essayer
            cout << "Entrez la ligne : ";
            // 4.3.2 Tant qu'on ne lit pas un nombre entier
            while (!(cin >> ligne))
            {
                // 4.3.2.1 Afficher un message d'erreur et redemander le numero de ligne
                cout << "Erreur! Vous devez entrer une nombre entier! " << endl << "Entrez la ligne : ";
                // 4.3.2.2 Vider le tampon de lecture
                cin.clear();
                // 4.3.2.3 Ignorer tous les caracteres deja entres
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // 4.3.3 Si la ligne est negative
            if (ligne < 0)
            {
                // 4.3.3.1 On quitte le jeu
                return 0;
            }

            // 4.3.4 Lire la colonne a essayer
            cout << "Entrez la colonne : ";
            // 4.3.5 Tant qu'on ne lit pas un nombre entier
            while (!(cin >> colonne))
            {
                // 4.3.5.1 Afficher un message d'erreur et redemander le numero de colonne
                cout << "Erreur! Vous devez entrer une nombre entier! " << endl << "Entrez la colonne : ";
                // 4.3.5.2 Vider le tampon de lecture
                cin.clear();
                // 4.3.5.3 Ignorer tous les caracteres deja entres
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // 4.3.6 Effacer tout l'ecran
            Console::ClearScreen();

            // 4.3.7 Ouvre la case demande, si on ne peut pas
            if (!OuvreCase(carte, ligne, colonne))
            {
                // 4.3.7.1 Affiche un message d'erreur et indique de quitter le jeu
                ligne = -1;
                cout << "Vous avez touche une mine!!!" << endl;
            }
            // 4.3.8 Sinon, si on vient de terminer la partie
            else if(carte.EstFini())
            {
                // 4.3.8.1 Affiche un message de felicitation et indique de quitter le jeu
                ligne = -1;
                cout << "Vous avez gagne!" << endl;
            }

            // 4.3.9 Affiche la carte
            cout << carte;
        }
    }

    return 0;
}

/**
* \brief Fonction recursive permettant d'ouvrir toutes les cases vides adjacente a une case
* \param La carte de jeu
* \param La ligne de la case a ouvrir
* \param La colonne de la case a ouvrir
* \return Vrai si on a pu ouvrir les case, faux si on a touche une mine
*/
bool OuvreCase(Carte& carte, int ligne, int colonne)
{
	// A completer selon le pseudo code
    // 1. Si la position est dans la grille
        // 1.1 Si la position est deja ouverte
            // 1.1.1 On retourne vrai

        // 1.2 On ouvre la case demandee

        // 1.3 Si la case ouverte est une mine
            // 1.3.1 On retourne faux

        // 1.4 Si la case ouverte ne contient pas de mine, ni de nombre (c'est une case libre)
            // Ici, on n'a pas besoin du resultat puisqu'on est certain de ne pas ouvrir de mine

            // 1.4.1 On ouvre la case en haut a gauche
            // 1.4.2 On ouvre la case en haut
            // 1.4.3 On ouvre la case en haut a droite
            // 1.4.4 On ouvre la case a gauche
            // 1.4.5 On ouvre la case a droite
            // 1.4.6 On ouvre la case en bas a gauche
            // 1.4.7 On ouvre la case en bas
            // 1.4.8 On oubre la case en bas a droite

    // 2. On retourne vrai
	return true;
}