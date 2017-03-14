#ifndef COMPLEMENT_H_INCLUDED
#define COMPLEMENT_H_INCLUDED

#include<iostream>
#include<cstdlib>
using namespace std;

const int SCREEN_HEIGHT = 520;
const int SCREEN_WIDTH = 780;
const int SCREEN_BPP = 32;
const int WIDTHTAB = 427;

SDL_Surface *loadImageWithColorKey(string filename, int r, int g, int b);
void showMessageScreen(string message,int x,int y,
                       TTF_Font *font,int fontSize,SDL_Color textColor,SDL_Surface* &screen);
void applySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip);
int victoire(int scoreJoueur1, int scoreJoueur2);


#endif // COMPLEMENT_H_INCLUDED
