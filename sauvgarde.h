#ifndef SAUVGARDE_H_
#define SAUVGARDE_H_
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"player.h"
#include"background.h"
void sauvgarde(char nomfich[],pers *p,background *backg);
void load(char nomfich[],pers *p,background *backg);
#endif /* SAUVGARDE_H_ */
