#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <time.h>
#include <ctime>
#include "pirate.h"
#include "plateau.h"

using namespace std;

/* ************************** Nom de la fonction ******************
* Nom_Fonction: coordPirate*

************************** Auteur , Dates *************************
*Nom/Date:BRETHEAU YANN, 01/12*

**************************Description **************************
*Cette fonction permet de trouver l'emplacement du pirate*

************************** Entrées **************************
*La fonction utilise le plateau de jeu ainsi que de entiers
où seront stockés les coordonnées du pirate*

**************************Sorties **************************
* La fonction ne retourne rien car les entiers sont passés en paramètres*
*********************************************************** */

void coordPirate(plateau p, int &ip, int &jp)
{
    //On parcourt la matrice  la recherche du pirate et on recupère ses coordonées

    for (int i=0; i<NB_CASES; i++)
    {
        for (int j=0; j<NB_CASES; j++)
        {
            if(p.matrice[i][j].valeur == -1 || p.matrice[i][j].valeur == -2)
            {
                ip=i;
                jp=j;
            }
        }
    }
}

/* ************************** Nom de la fonction ******************
* Nom_Fonction: deplacementValide*

************************** Auteur , Dates *************************
*Nom/Date:BRETHEAU YANN, 14/12, troisième versions finie le 14/12*

**************************Description **************************
*Cette fonction permet de savoir si le deplacement du pirate ets possible ou non
, à savoir verticalement, horizontalement, pas hors du plateau et ni la ou le pirate est
et la ou le pirate a été*

************************** Entrées **************************
* La fonction utilise les cooordonées cartésiennes ainsi que les coordonées
du pirate*

**************************Sorties **************************
* La fonction retourne un booléen pour pouvoir faire un test par la siute*
*********************************************************** */

bool deplacementValide(plateau p, int &x, int &y, int ip, int jp)
{
    bool possible = false;

    //On transforme des coordonées cartésiennes en coordonées utilisables par rapport à la matrice

    int xdest=x/60;
    int ydest=y/60;

    //Test pour le déplacement vertical et hprizontal

    if( (ydest == jp && xdest != ip) || (xdest == ip && jp!=ydest))
    {
        possible = true;
    }

    /*Test pour ne pas aller sur une case vide, le test pour ne pas aller sur la case du pirate étant deja fait dans la condition
    pour le déplacement vertical et horizontal*/

    if(p.matrice[x/60][y/60].valeur == 0)
    {
        possible = false;
    }

    return possible;
}

/* ************************** Nom de la fonction ******************
* Nom_Fonction: changerJoueur*

************************** Auteur , Dates *************************
*Nom/Date:BRETHEAU YANN, 13/12*

**************************Description **************************
*Cette fonction permet de changer de joueur*

************************** Entrées **************************
* La fonction utilise les coordonées de la ou ést le pirate,
en fonction de cela le pirate change*

**************************Sorties **************************
* La fonction retourne un entier et suivant cette valeur le pirate changera
pour le pirate -1 ou -2. J'ai choisi un int car le booléen ne permet pas
de d'avoir plusieurs possibiliés pour fair edes tests par la suite*
*********************************************************** */

int changerJoueur(plateau p, int ip, int jp)
{
    int joueur;

    //Basique, on regarde le vameur du joueur actuelle et on la change

    if(p.matrice[ip][jp].valeur==-1)
    {
        joueur=-2;
    }
    else
    {
        joueur=-1;
    }
    return joueur;
}
