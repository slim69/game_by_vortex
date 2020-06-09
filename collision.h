#ifndef COLLISION_H_
#define COLLISION_H_
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"player.h"
#include "background.h"
typedef struct
{
	SDL_Surface *texte;
	SDL_Rect position_texte;
	TTF_Font *police;
}alerte;

SDL_Color getRGB(SDL_Surface *pSurface,int x,int y);
int colbackgroundRight(masque *back_masque,pers *p);
void init_ttf_alerte(alerte *ttf_alerte);
void texte_ttf_alerte(SDL_Surface *screen,alerte *ttf_alerte);

#endif /* COLLISION_H_ */
