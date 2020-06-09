#include "background.h"
void initialiser_background_masque(masque *back_masque)
{

back_masque->masque=IMG_Load("mask.png");


back_masque->position_masque.x=0;
back_masque->position_masque.y=0;

back_masque->position_masque.w = back_masque->masque->w;
back_masque->position_masque.h = back_masque->masque->h;
}

//-------------------------------------------------------------//
void initialiser_background(background *backg)
{
backg->background=IMG_Load("background.png");

backg->position_fond.x=0;
backg->position_fond.y=0;

backg->position_fond.w = backg->background->w;
backg->position_fond.h = backg->background->h;
}
//--------------------------------------------------------------//
void affiche_masque(SDL_Surface *screen, masque *back_masque)
{
SDL_BlitSurface(back_masque->masque,&back_masque->position_masque,screen,NULL);
}
//-------------------------------------------------------------//
//-------------------------------------------------------------//

void showBckg (SDL_Surface * screen, background *backg)
{
SDL_BlitSurface(backg->background,&backg->position_fond,screen,NULL);

}


//-------------------------------------------------------------//


void scrolling_gauche(background *backg)
{
if (backg->position_fond.x != 0)
backg->position_fond.x-=20;
}
//--------------------------------------------------------------//
void scrolling_masque_droite(masque *back_masque)
{
if(back_masque->position_masque.w -back_masque->position_masque.x !=1200)
back_masque->position_masque.x+=20;
}

//-------------------------------------------------------------//
void scrolling_masque_gauche(masque *back_masque)
{
if(back_masque->position_masque.x !=0)
back_masque->position_masque.x-=20;
}
//---------------------------------------------------------------//
void scrolling_droite(background *backg)
{
if(backg->position_fond.w - backg->position_fond.x !=1200)
backg->position_fond.x+=20;
}

//------------------------------------------------------------//
void liberer_masque(masque *back_masque)
{
SDL_FreeSurface(back_masque->masque);
}
//-------------------------------------------------------------//

void liberebackg(background *backg)
{
SDL_FreeSurface(backg->background);
}
//-------------------------------------------------------------//
