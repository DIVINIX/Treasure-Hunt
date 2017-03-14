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
#include "pirate.h"
#include "complement.h"

using namespace std;

ostringstream score1;
ostringstream score2;

int main(int argc, char* argv[])
{

/* ---------- DONNES POUR LE TEXTES ---------- */

    TTF_Init();
    TTF_Font *fonts;
    SDL_Color textColor= {0,0,0};
    int fontSize=35;
    string police="Hawaii_Killer.ttf";
    fonts = TTF_OpenFont(police.c_str(),fontSize);

    //Aléatoire
    srand(time(NULL));
    SDL_Event event;

/* ---------- LES SDL_SURFACES DU JEUX ---------- */

    //L'écran
    SDL_Surface *screen;

    //Les surfaces pour le menu
    SDL_Surface *menu;
    SDL_Surface *button;

    //Les surfaces pour les éléments du jeux
    SDL_Surface *piece;
    SDL_Surface *imgpirate;
    SDL_Surface *flag;

    //Les surfaces pour les pirates
    SDL_Surface *pirate1;
    SDL_Surface *pirate2;

    //Les surfaces pour les bonus
    SDL_Surface *bonus0;
    SDL_Surface *bonus1;
    SDL_Surface *bonus2;
    SDL_Surface *bonus3;
    SDL_Surface *bonus4;

    //Les surfaces pour les victoires
    SDL_Surface *victoireJoueur1;
    SDL_Surface *victoireJoueur2;


/* ---------- LES VARIABLES ---------- */

    //Les booléens pour les bonus du joueur 1
    bool afficherJoueur1Bonus0 = true;
    bool afficherJoueur1Bonus1 = false;
    bool afficherJoueur1Bonus2 = false;
    bool afficherJoueur1Bonus3 = false;
    bool afficherJoueur1Bonus4 = false;

    //Les booléens pour les bonus du joueur 2
    bool afficherJoueur2Bonus0 = true;
    bool afficherJoueur2Bonus1 = false;
    bool afficherJoueur2Bonus2 = false;
    bool afficherJoueur2Bonus3 = false;
    bool afficherJoueur2Bonus4 = false;

    //Le booléen pour quitter le jeux
    bool play = false;
    //Le booléen pour jouer
    bool quit = false;

    //Les entiers pour les scores et geréer les bonus
    int scoreJoueur1 = 0;
    int scoreJoueur2 = 0;
    int premierBonusJoueur1 = 0;
    int premierBonusJoueur2 = 0;
    int bonusJoueur1 = 0 ;
    int bonusJoueur2 = 0 ;

/* ---------- INITIATIONS DU PLATEAU  ---------- */

    plateau grille;
    initPlateau(grille);

/* ---------- LES SDL_RECT DE POSITIONNEMENT ---------- */


    //Position pour les fonds d'écrans
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;

    //Position pour les 4 drapeaux de pirates
    SDL_Rect positionFlag1;
    positionFlag1.x = 70;
    positionFlag1.y = 433;

    SDL_Rect positionFlag2;
    positionFlag2.x = 240;
    positionFlag2.y = 433;

    SDL_Rect positionFlag3;
    positionFlag3.x = 410;
    positionFlag3.y = 433;

    SDL_Rect positionFlag4;
    positionFlag4.x = 580;
    positionFlag4.y = 433;

    //Position pour les bonues du joueur 1
    SDL_Rect positionJoueur1Bonus;
    positionJoueur1Bonus.x = 420;
    positionJoueur1Bonus.y = 160;

    //Position pour les bonues du joueur 2
    SDL_Rect positionJoueur2Bonus;
    positionJoueur2Bonus.x = 620;
    positionJoueur2Bonus.y = 160;

    //Position pour l'image de victoire
    SDL_Rect positionVictoire;
    positionVictoire.x = 200;
    positionVictoire.y = 50;

/* ---------- LES SDL_RECT DE LECTURE DANS LES IMAGES ---------- */

    //Pour les pirates
    SDL_Rect lecture;
    lecture.x = 0;
    lecture.y = 0;
    lecture.w = 59;
    lecture.h = 59;

    //Pour le bouton play
    SDL_Rect lecturePlay;
    lecturePlay.x = 40;
    lecturePlay.y = 5;
    lecturePlay.w = 210;
    lecturePlay.h = 60;

    //Pour le bouton quit
    SDL_Rect lectureQuit;
    lectureQuit.x = 30;
    lectureQuit.y = 139;
    lectureQuit.w = 210;
    lectureQuit.h = 60;

    //Pour après le passage du pirate
    SDL_Rect lecture0;
    lecture0.x = 0;
    lecture0.y = 185;
    lecture0.w = 59;
    lecture0.h = 59;

    //Pour la pièce de 10
    SDL_Rect lecture10;
    lecture10.x = 0;
    lecture10.y = 0;
    lecture10.w = 59;
    lecture10.h = 59;

    //Pour la pièce de 20
    SDL_Rect lecture20;
    lecture20.x = 60;
    lecture20.y = 0;
    lecture20.w = 59;
    lecture20.h = 59;

    //Pour la pièce de 30
    SDL_Rect lecture30;
    lecture30.x = 120;
    lecture30.y = 0;
    lecture30.w = 59;
    lecture30.h = 59;

    //Pour la pièce de 50
    SDL_Rect lecture50;
    lecture50.x = 180;
    lecture50.y = 0;
    lecture50.w = 59;
    lecture50.h = 59;

    //Pour la pièce de 100
    SDL_Rect lecture100;
    lecture100.x = 240;
    lecture100.y = 0;
    lecture100.w = 59;
    lecture100.h = 59;

    //Pour l'image du pirate 1
    SDL_Rect lecturePirate1;
    lecturePirate1.x = 59;
    lecturePirate1.y = 184;
    lecturePirate1.w = 59;
    lecturePirate1.h = 59;

    //Pour l'image du pirate
    SDL_Rect lecturePirate2;
    lecturePirate2.x = 120;
    lecturePirate2.y = 184;
    lecturePirate2.w = 59;
    lecturePirate2.h = 59;

    //Pour l'image du pirate 1 au dessus des scores
    SDL_Rect lectureImgPirate1;
    lectureImgPirate1.x = 0;
    lectureImgPirate1.y = 0;
    lectureImgPirate1.w = 90;
    lectureImgPirate1.h = 100;

    //Pour l'image du pirate  au dessus des scores
    SDL_Rect lectureImgPirate2;
    lectureImgPirate2.x = 100;
    lectureImgPirate2.y = 0;
    lectureImgPirate2.w = 90;
    lectureImgPirate2.h = 100;

    SDL_Init(SDL_INIT_EVERYTHING);

    /* ---------- LE CHARGEMENT DES IMAGES---------- */

    //l'écran
    screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);

    //Les images du menu
    menu = SDL_LoadBMP("menu.bmp");
    button = loadImageWithColorKey("bouttons.bmp",0,255,255);

    //Les images du jeu
    piece = loadImageWithColorKey("pieces.bmp",0,255,255);
    imgpirate = loadImageWithColorKey("piratesSprite2.bmp",0,255,255);
    flag = SDL_LoadBMP("flag.bmp");

    //Les images des pirates
    pirate1 = SDL_LoadBMP("pirate1.bmp");
    pirate2 = SDL_LoadBMP("pirate2.bmp");

    //Les images des bonus
    bonus0 = SDL_LoadBMP("bonus0.bmp");
    bonus1 = SDL_LoadBMP("bonus1.bmp");
    bonus2 = SDL_LoadBMP("bonus2.bmp");
    bonus3 = SDL_LoadBMP("bonus3.bmp");
    bonus4 = SDL_LoadBMP("bonus4.bmp");

    //Les images de victoires
    victoireJoueur1 = SDL_LoadBMP("gagne1.bmp");
    victoireJoueur2 = SDL_LoadBMP("gagne2.bmp");


    while(quit == false)
    {
        if ( play == false ) // On test si on a pas appuyer sur jouer, pour que ca ne tourne pas en boucle derrière
        {
            //Le menu pour jouer ou quitter

            SDL_BlitSurface(menu,NULL,screen,&positionFond);
            applySurface(500,170,button,screen,&lecturePlay);
            applySurface(500,270,button,screen,&lectureQuit);
        }

        while(SDL_PollEvent(&event))
        {
            if( event.type == SDL_MOUSEBUTTONDOWN && play == false) //On test si on a pas encore cliqué sur jouer
            {
                int x;
                int y;
                SDL_GetMouseState(&x,&y); //On recupère les coordonées de la souris

                //On test si on a cliqué sur le bouton jouer
                if( (( x > 500) && ( x < 710) && ( y > 170 ) && ( y < 230 )) )
                {
                    play = true;
                }

                //On test si on a cliqué sur le bouton quitter
                if( (( x > 500) && ( x < 710) && ( y > 270 ) && ( y < 330 )) )
                {
                    quit = true;
                }
            }

            else if(event.type == SDL_MOUSEBUTTONDOWN && play == true) //On test si on est en train de jouer
            {
                int x;
                int y;
                SDL_GetMouseState(&x,&y); //On recupère les coordonées de la souris
                int ip;
                int jp;

                coordPirate(grille,ip,jp);

                //Si le déplacement est valide alors le pirate bouge
                if(deplacementValide(grille,x,y,ip,jp))
                {
                    //Si c'est le tour du joueur1 on rentre dans la boucle
                    if(grille.matrice[ip][jp].valeur == -1)
                    {
                        //On fait les tests du bonus par rapport à la dernière case sur laquelle on a cliqué
                        if(grille.matrice[x/60][y/60].valeur == premierBonusJoueur1)
                        {
                            int valeurBonusJoueur1 = joueur1Bonus(bonusJoueur1); //On récupère la valeur du bonus
                            scoreJoueur1 = grille.matrice[x/60][y/60].valeur + valeurBonusJoueur1 + scoreJoueur1; //On augmente le score du joueur 1

                            /* ---------- TESTE POUR L'AFFICHAGE DES BONUS ---------- */

                            if(valeurBonusJoueur1 == 10 )
                            {
                                afficherJoueur1Bonus0 = false;
                                afficherJoueur1Bonus1 = true;
                            }

                            if(valeurBonusJoueur1 == 20 )
                            {
                                afficherJoueur1Bonus1 = false;
                                afficherJoueur1Bonus2 = true;
                            }

                            if(valeurBonusJoueur1 == 40 )
                            {
                                afficherJoueur1Bonus2 = false;
                                afficherJoueur1Bonus3 = true;
                            }

                            if(valeurBonusJoueur1 == 80 )
                            {
                                afficherJoueur1Bonus3 = false;
                                afficherJoueur1Bonus4 = true;
                            }
                        }

                        else
                        {
                            //Le joueur n'a pas cliqué sur la même case que précédemment
                            bonusJoueur1 = 0; //On réinitiale le compteur du bonus
                            scoreJoueur1 += grille.matrice[x/60][y/60].valeur;

                            //On désactive les images de tous les bonus et on remet celle ou il n'y en a pas
                            afficherJoueur1Bonus0 = true;
                            afficherJoueur1Bonus1 = false;
                            afficherJoueur1Bonus2 = false;
                            afficherJoueur1Bonus3 = false;
                            afficherJoueur1Bonus4 = false;
                        }
                        //On récupère la valeur de la case où le joueur 1 à cliqué
                        premierBonusJoueur1 = grille.matrice[x/60][y/60].valeur;
                    }

                    /* ---------- TOUR DU JOUEUR 2 ---------- */
                    else
                    {
                        if(grille.matrice[x/60][y/60].valeur == premierBonusJoueur2)
                        {
                            int valeurBonusJoueur2=joueur1Bonus(bonusJoueur2); //On récupère la valeur du bonus
                            scoreJoueur2 = grille.matrice[x/60][y/60].valeur + valeurBonusJoueur2 + scoreJoueur2; //On augmente le score du joueur 2

                            /* ---------- TESTE POUR L'AFFICHAGE DES BONUS ---------- */

                            if(valeurBonusJoueur2 == 10 )
                            {
                                afficherJoueur2Bonus0 = false;
                                afficherJoueur2Bonus1 = true;
                            }

                            if(valeurBonusJoueur2 == 20 )
                            {
                                afficherJoueur2Bonus1 = false;
                                afficherJoueur2Bonus2 = true;
                            }

                            if(valeurBonusJoueur2 == 40 )
                            {
                                afficherJoueur2Bonus2 = false;
                                afficherJoueur2Bonus3 = true;
                            }

                            if(valeurBonusJoueur2 == 80 )
                            {
                                afficherJoueur2Bonus3 = false;
                                afficherJoueur2Bonus4 = true;
                            }
                        }

                        else
                        {
                            //Le joueur n'a pas cliqué sur la même case que précédemment
                            bonusJoueur2=0; //On réinitiale le compteur du bonus
                            scoreJoueur2 += grille.matrice[x/60][y/60].valeur;

                            //On désactive les images de tous les bonus et on remet celle ou il n'y en a pas
                            afficherJoueur2Bonus0 = true;
                            afficherJoueur2Bonus1 = false;
                            afficherJoueur2Bonus2 = false;
                            afficherJoueur2Bonus4 = false;

                        }
                        //On récupère la valeur de la case où le joueur2 à cliqué
                        premierBonusJoueur2 = grille.matrice[x/60][y/60].valeur;
                    }

                    //On change de joueur
                    grille.matrice[x/60][y/60].valeur = changerJoueur(grille,ip,jp);

                    //On met la valeur à 0 de la où était le pirate
                    grille.matrice[ip][jp].valeur=0;
                }
            }
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        /* ---------- LANCEMENT DU JEU ---------- */

        if(play ==true && victoire(scoreJoueur1,scoreJoueur2) == 0) // Si on a cliquer sur jouer
        {
            //Score du joueur 1 à afficer
            score1.flush();
            score1.str("");
            score1 <<  scoreJoueur1;

            //Score du joueur 2 à afficer
            score2.flush();
            score2.str("");
            score2 <<  scoreJoueur2;
            //On repmplit le background en blanc
            SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,255,255,255));

            //On afiche les drapeaux
            SDL_BlitSurface(flag,NULL,screen,&positionFlag1);
            SDL_BlitSurface(flag,NULL,screen,&positionFlag2);
            SDL_BlitSurface(flag,NULL,screen,&positionFlag3);
            SDL_BlitSurface(flag,NULL,screen,&positionFlag4);

            //On affiche les pirates au dessus des scores
            applySurface(433,20,imgpirate,screen,&lectureImgPirate1);
            applySurface(650,20,imgpirate,screen,&lectureImgPirate2);

            //On affiche les scores
            showMessageScreen(score1.str(),465,130,fonts,fontSize,textColor,screen);
            showMessageScreen(score2.str(),675,130,fonts,fontSize,textColor,screen);

            //On affiche le plateau
            afficherplateau(grille,screen,piece,pirate1,pirate2,lecture0,lecture10,lecture20,lecture30,lecture50,lecture100,lecturePirate1,
                            lecturePirate2,lecture);

            /* ---------- AFFICHAGE DES BONUS ---------- */

            //Bonus du joueur 1

            if(afficherJoueur1Bonus0 == true)
            {
                SDL_BlitSurface(bonus0,NULL,screen,&positionJoueur1Bonus);
            }

            if(afficherJoueur1Bonus1 == true)
            {
                SDL_BlitSurface(bonus1,NULL,screen,&positionJoueur1Bonus);
            }

            if(afficherJoueur1Bonus2 == true)
            {
                SDL_BlitSurface(bonus2,NULL,screen,&positionJoueur1Bonus);
            }
            if(afficherJoueur1Bonus3 == true)
            {
                SDL_BlitSurface(bonus3,NULL,screen,&positionJoueur1Bonus);
            }
            if(afficherJoueur1Bonus4 == true)
            {
                SDL_BlitSurface(bonus4,NULL,screen,&positionJoueur1Bonus);
            }

            //Bonus du joueur 2

            if(afficherJoueur2Bonus0 == true)
            {
                SDL_BlitSurface(bonus0,NULL,screen,&positionJoueur2Bonus);
            }

            if(afficherJoueur2Bonus1 == true)
            {
                SDL_BlitSurface(bonus1,NULL,screen,&positionJoueur2Bonus);
            }
            if(afficherJoueur2Bonus2 == true)
            {
                SDL_BlitSurface(bonus2,NULL,screen,&positionJoueur2Bonus);
            }
            if(afficherJoueur2Bonus3 == true)
            {
                SDL_BlitSurface(bonus3,NULL,screen,&positionJoueur2Bonus);
            }

            if(afficherJoueur2Bonus4 == true)
            {
                SDL_BlitSurface(bonus4,NULL,screen,&positionJoueur2Bonus);
            }
        }

        /* ---------- AFFICHAGE DEIMAGES DE VICTOIRES ---------- */

        if(victoire(scoreJoueur1,scoreJoueur2) == 1)
        {
            SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,255,255,255));
            SDL_BlitSurface(victoireJoueur1,NULL,screen,&positionVictoire);
        }

        if(victoire(scoreJoueur1,scoreJoueur2) == 2)
        {
            SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,255,255,255));
            SDL_BlitSurface(victoireJoueur2,NULL,screen,&positionVictoire);
        }

        SDL_Flip(screen);
    }

    SDL_FreeSurface(screen);
    SDL_Quit();
    return EXIT_SUCCESS;
}
