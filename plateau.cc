#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <time.h>
#include <ctime>
#include "plateau.h"
#include "complement.h"
#include "pirate.h"

using namespace std;

/* ************************** Nom de la fonction ******************
* Nom_Fonction: InitPiece*

************************** Auteur , Dates *************************
*Nom/Date:BRETHEAU YANN, 25/11*

**************************Description **************************
*Cette fonction initie la valeur de chaque piece, que l'on place
ensuite dans chaque case de la matrice avec la fonction initiPlaeau*

************************** Entrées **************************
* La fonction utilise le i et le j de la fonction initPlateau
ainsi qu'un tableau déifnit dans initPlateau. Le tableau permet de
choisir aléatoirement la valeur de la piece et le i et le j servent
à placer certaines pièces comme le pirate et la pièce de 100*

**************************Sorties **************************
* La fonction renvoie une piece*
*********************************************************** */

piece initpiece(int i, int j, int tab[])
{
    piece pi;
    pi.x=i;
    pi.y=j;

    if(i == NB_CASES/2 && j == NB_CASES/2)
    {
        pi.valeur=-1;
    }

    else
    {
        int indice;

        do
        {
            indice=rand()%5;
        }

        while(tab[indice]==0);

//On fait un switch sur l'indice pour affecter une valeur a la piece



        switch(indice)
        {

        case 0:
            if(i!=3 || j !=3)
                pi.valeur=100;
            break;

        case 1:
            pi.valeur=50;
            break;

        case 2:
            pi.valeur=30;
            break;

        case 3:
            pi.valeur=20;
            break;

        case 4:
            pi.valeur=10;
            break;
        }

        tab[indice]--;
    }
    return pi;
}


/* ************************** Nom de la fonction ******************
* Nom_Fonction: InitPlateau*

************************** Auteur , Dates *************************
*Nom/Date:BRETHEAU YANN, 25/11*

**************************Description **************************
*Cette fonction initie les pieces dans chaques cases à l'aide
de la fonction initPice*

************************** Entrées **************************
* La fonction utilise une structre plateau composée de pièces*

**************************Sorties **************************
* La fonction ne retourne rien*
*********************************************************** */

void initPlateau(plateau &p)
{
    p.x=0;
    p.y=0;
    p.w=WIDTHTAB;
    p.h=WIDTHTAB;

    //Le tableau qui nous sert à conserver le nombre de pièce de chaque sorte

    int tab[5];
    tab[0]=1;
    tab[1]=5;
    tab[2]=14;
    tab[3]=14;
    tab[4]=14;

    for (int i=0; i<NB_CASES; i++)
    {
        for (int j=0; j<NB_CASES; j++)
        {
            //Pour chaque case on initie une pièce

            piece pi = initpiece(i,j,tab);
            p.matrice[i][j]=pi;
        }
    }
}

/* ************************** Nom de la fonction ******************
* Nom_Fonction: afficherPlateau*

************************** Auteur , Dates *************************
*Nom/Date:BRETHEAU YANN, 25/11*

**************************Description **************************
*Cette fonction affiche le plateau. Elle parcourt la matrice
et selon les valeurs présente dans les cases on fait un applysurface
de la pièce correspondante. Le i*59 et j*59 permettent d'avoire une piece carrée
de hauteur et largeur 59.*

************************** Entrées **************************
* La fonction prend en entrée le plateau initié anisi que tous les rectangles
de lectures et aussi tous les images a afficher*

**************************Sorties **************************
* La fonction ne retourne rien*
*********************************************************** */

void afficherplateau(plateau p,SDL_Surface *screen, SDL_Surface *piece,SDL_Surface *pirate1,SDL_Surface *pirate2,SDL_Rect lecture0,SDL_Rect lecture10,
                     SDL_Rect lecture20,SDL_Rect lecture30,SDL_Rect lecture50,SDL_Rect lecture100,SDL_Rect lecturePirate1,SDL_Rect lecturePirate2
                     ,SDL_Rect lecture)
{
    for (int i=0; i<NB_CASES; i++)
    {
        for (int j=0; j<NB_CASES; j++)
        {
            //On fait un switch sur la valeur de la case pour ensuite afficher la piece correspondant à la valeur

            switch(p.matrice[i][j].valeur)
            {
            case 0:
                applySurface(i*59,j*59,piece,screen,&lecture0);
                break;

            case -2:
                applySurface(i*59,j*59,pirate2,screen,&lecture);
                break;

            case -1:
                applySurface(i*59,j*59,pirate1,screen,&lecture);
                break;

            case 100:
                applySurface(i*59,j*59,piece,screen,&lecture100);
                break;

            case 50:
                applySurface(i*59,j*59,piece,screen,&lecture50);
                break;

            case 30:
                applySurface(i*59,j*59,piece,screen,&lecture30);
                break;

            case 20:
                applySurface(i*59,j*59,piece,screen,&lecture20);
                break;

            case 10:
                applySurface(i*59,j*59,piece,screen,&lecture10);
                break;
            }
        }
    }
}

/* ************************** Nom de la fonction ******************
* Nom_Fonction: joueur1Bonus*

************************** Auteur , Dates *************************
*Nom/Date:BRETHEAU YANN, 15/12*

**************************Description **************************
*Cette fonction permet de renvoyer la valeur du bonus à ajouter*

************************** Entrées **************************
* L fonction utilise le bonus actuel, au début il vaut 0*

**************************Sorties **************************
* La fonction retourne la valeur du bonus*
*********************************************************** */

int joueur1Bonus(int &bonusJoueur1)
{
    int pointsBonusJoueur1=0;
    if ( bonusJoueur1 < 4 ) bonusJoueur1++;
    if (bonusJoueur1 == 1)  pointsBonusJoueur1 = 10;
    else if (bonusJoueur1 == 2)  pointsBonusJoueur1 = 20;
    else if (bonusJoueur1 == 3)  pointsBonusJoueur1 = 40;
    else if (bonusJoueur1 == 4)  pointsBonusJoueur1 = 80;

    return pointsBonusJoueur1;
}

/* ************************** Nom de la fonction ******************
* Nom_Fonction: joueur2Bonus*

************************** Auteur , Dates *************************
*Nom/Date:BRETHEAU YANN, 15/12*

**************************Description **************************
*Cette fonction permet de renvoyer la valeur du bonus à ajouter*

************************** Entrées **************************
* L fonction utilise le bonus actuel, au début il vaut 0*

**************************Sorties **************************
* La fonction retourne la valeur du bonus*
*********************************************************** */

int joueur2Bonus(int &bonusJoueur2)
{
    int pointsBonusJoueur2=0;
    if ( bonusJoueur2 < 4 ) bonusJoueur2++; //On utilise un compteur pour les bonus différents
    if (bonusJoueur2 == 1)  pointsBonusJoueur2 = 10;
    else if (bonusJoueur2 == 2)  pointsBonusJoueur2 = 20;
    else if (bonusJoueur2 == 3)  pointsBonusJoueur2 = 40;
    else if (bonusJoueur2 == 4)  pointsBonusJoueur2 = 80;

    return pointsBonusJoueur2;
}
