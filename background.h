#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{
    SDL_Surface *background;
    SDL_Rect position_fond;
}background;
typedef struct
{
  SDL_Surface *masque;
  SDL_Rect position_masque;
}masque;

void initialiser_background(background *backg);
void initialiser_background_masque(masque *back_masque);
void affiche_masque(SDL_Surface *screen, masque *back_masque);
void showBckg (SDL_Surface * screen, background *backg);
void scrolling_droite(background *backg);
void scrolling_masque_droite(masque *back_masque);
void scrolling_masque_gauche(masque *back_masque);
void scrolling_gauche(background *backg);
void liberebackg(background *backg);
void liberer_masque(masque *back_masque);
#endif // BACKGROUND_H_
