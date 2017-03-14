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

#endif // PIRATE_H_INCLUDED
