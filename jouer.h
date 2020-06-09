#ifndef JOUER_H_
#define JOUER_H_
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
#include "background.h"
#include"sous_menu.h"
#include"collision.h"
void jouer(pers *p,background *backg,background_sousmenu *back_sousmenu,bouton *b,masque *back_masque,SDL_Surface *screen,int *doner,alerte *ttf_alerte);

#endif // JOUER_H_
