#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <time.h>
#include <ctime>
#include "complement.h"

using namespace std;


SDL_Surface *loadImageWithColorKey(string filename, int r, int g, int b)
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );

        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, r, g, b );

            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }
    //Return the optimized image
    return optimizedImage;
}

void showMessageScreen(string message,int x,int y,
                       TTF_Font *font,int fontSize,SDL_Color textColor,SDL_Surface* &screen)
{
    string mot="";
    string space=" ";
    int i=0,j;
    SDL_Surface *mes=NULL;

    j = message.find(space);
    while( j != string::npos )
    {
        mot=message.substr(i,j-i);
        if(mot != "")
        {
            mes=TTF_RenderText_Solid(font,mot.c_str(),textColor);
            applySurface(x,y,mes,screen,NULL);
            x+=mes->w;
            SDL_FreeSurface(mes);
        }
        x+=fontSize;
        i=j+1;
        j = message.find(space,i);
    }

    mot=message.substr(i);
    mes=TTF_RenderText_Solid(font,mot.c_str(),textColor);
    applySurface(x,y,mes,screen,NULL);
    SDL_FreeSurface(mes);
}

void applySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}

/* ************************** Nom de la fonction ******************
* Nom_Fonction: victoire*

************************** Auteur , Dates *************************
*Nom/Date:BRETHEAU YANN, 14/12*

**************************Description **************************
*Cette fonction permet de savoir qu'on un joueur gagne*

************************** Entrées **************************
* La fonction utilise les scores des deux joueurs*

**************************Sorties **************************
* La fonction retourne un entier de la meme maniere que la fonction
changerJoueur*
*********************************************************** */

int victoire(int scoreJoueur1, int scoreJoueur2)
{
    int victoire =0;

    if(scoreJoueur1 >= 500)
    {
        victoire=1;
    }

     if(scoreJoueur2 >= 500)
    {
        victoire=2;
    }

    return victoire;
}
