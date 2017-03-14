#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<iostream>
#include<cstdlib>
using namespace std;



const int NB_CASES=7;

struct piece
{
    int valeur;
    int x;
    int y;
};

struct plateau
{
    piece matrice[NB_CASES][NB_CASES];
    int x;
    int y;
    int w;
    int h;
};

piece initpiece(int i, int j, int tab[]);
void initPlateau(plateau &p);
void afficherplateau(plateau p,SDL_Surface *screen, SDL_Surface *piece,SDL_Surface *pirate1,SDL_Surface *pirate2,SDL_Rect lecture0,SDL_Rect lecture10,
                     SDL_Rect lecture20,SDL_Rect lecture30,SDL_Rect lecture50,SDL_Rect lecture100,SDL_Rect lecturePirate1,SDL_Rect lecturePirate2
                     ,SDL_Rect lecture);
void coordPirate(plateau p, int &ip, int &jp);
bool deplacementValide(plateau p, int &x, int &y, int ip, int jp);
void coordPirate(plateau p, int &ip, int &jp);
int changerJoueur(plateau p, int ip, int jp);
int joueur1Bonus(int &bonusJoueur1);
int joueur2Bonus(int &bonusJoueur2);


#endif // PIECE_H_INCLUDED
