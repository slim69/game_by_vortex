#ifndef PLAYER_H_
#define PLAYER_H_
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

struct personnage
{
    SDL_Surface *gauche[4];
    SDL_Surface *droite[4];
    SDL_Surface *depart;
    int left;
    int right;

    SDL_Rect position_joueur;
    SDL_Rect position_joueur_relative;
};
typedef struct personnage pers;

void initialiserperso(pers *p);
void depart(SDL_Surface *screen, pers *p);
void droite(SDL_Surface *screen, pers *p,int a);
void gauche(SDL_Surface *screen, pers *p,int a);
void bouger_droite(SDL_Surface *screen, pers *p);
void bouger_gauche(SDL_Surface *screen, pers *p);
void condition_deplacement_souris(int *k,pers *p,int a,int *x);
void liberer_personnage(pers *p);

#endif // PLAYER_H_
