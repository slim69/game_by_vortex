#ifndef SOUS_MENU_H_
#define SOUS_MENU_H_
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"player.h"
#include"background.h"
#include"sauvgarde.h"
typedef struct{
SDL_Surface *background;

SDL_Rect pos_background;
}background_sousmenu;



typedef struct{
SDL_Surface *newgame;
SDL_Surface *continuer;
SDL_Surface *save;
SDL_Surface *quit;

SDL_Rect pos_newgame;
SDL_Rect pos_continuer;
SDL_Rect pos_save;
SDL_Rect pos_quit;
}bouton;


void init_background(background_sousmenu *back_sousmenu);
void initialise_bouton(bouton *b);
void afficher_background(SDL_Surface *screen,background_sousmenu *back_sousmenu);
void afficher_etat_initiale(SDL_Surface *screen,bouton *b);
void afficher1(SDL_Surface *screen,bouton *b);
void afficher2(SDL_Surface *screen,bouton *b);
void afficher3(SDL_Surface *screen,bouton *b);
void afficher4(SDL_Surface *screen,bouton *b);
void menu_pause(SDL_Surface *screen,bouton *b,background_sousmenu *back_sousmenu,pers *p,background *backg,int *doner,int *donner,int *done);
void free_bouton(bouton *b);
void free_background(background_sousmenu *back_sousmenu);
#endif /* SOUS_MENU_H_ */
