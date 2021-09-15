#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <cstdlib>

#if defined(_WIN32)
    #include <Windows.h>
    #ifdef max
        #undef max
    #endif
#else
#include <string>
#endif

using namespace std;

enum Color
{
    BleuFonce = 1,
    VertFonce = 2,
    CyanFonce = 3,
    RougeFonce = 4,
    MagentaFonce = 5,
    JauneFonce = 6,
    BlancFonce = 7,
    Gris = 8,
    Bleu = 9,
    Vert = 10,
    Cyan = 11,
    Rouge = 12,
    Magenta = 13,
    Jaune = 14,
    Blanc = 15
};

class Console
{
public:
    /**
    * \brief Change la couleur d'affichage a l'ecran
    * \param Couleur a utilise
    * \return Aucun
    * \note Cette fonction contient du code specifique au systeme d'exploitation utilise.
    */
    static void SetConsoleColor(Color c)
    {
#if defined(_WIN32)
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (int)c);
#else
        std::string color = "\033[0m";
        switch (c)
        {
        case BleuFonce:
            color = "\033[2;34;40m";
            break;
        case VertFonce:
            color = "\033[2;32;40m";
            break;
        case CyanFonce:
            color = "\033[2;36;40m";
            break;
        case RougeFonce:
            color = "\033[2;31;40m";
            break;
        case MagentaFonce:
            color = "\033[2;35;40m";
            break;
        case JauneFonce:
            color = "\033[2;33;40m";
            break;
        case BlancFonce:
            color = "\033[2;37;40m";
            break;
        case Gris:
            color = "\033[2;37;40m";
            break;
        case Bleu:
            color = "\033[0;34;40m";
            break;
        case Vert:
            color = "\033[0;32;40m";
            break;
        case Cyan:
            color = "\033[0;36;40m";
            break;
        case Rouge:
            color = "\033[0;31;40m";
            break;
        case Magenta:
            color = "\033[0;35;40m";
            break;
        case Jaune:
            color = "\033[1;33;40m";
            break;
        case Blanc:
            color = "\033[0;37;40m";
            break;
        }
        cout << color;
#endif
    }

    /**
    * \brief Efface completement l'ecran
    * \param Aucun
    * \return Aucun
    * \note Cette fonction contient du code specifique au systeme d'exploitation utilise.
    */
    static void ClearScreen()
    {
#if defined(_WIN32)
        std::system("cls");
#else
        // Assume POSIX
        std::system("clear");
#endif
    }
};

#endif
