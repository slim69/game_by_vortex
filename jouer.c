#include"jouer.h"

void jouer(pers *p,background *backg,background_sousmenu *back_sousmenu,bouton *b,masque *back_masque,SDL_Surface *screen,int *doner,alerte *ttf_alerte)
{
static int k=0;
static int x=0;
int a;
int donner=1;
int done=1;
int z;
while(donner)
{SDL_Event event;

affiche_masque(screen,back_masque);
showBckg(screen,backg);
switch(x)
{
case 0:
depart(screen,p); //position de depart
break;
case 1:
droite(screen,p,a); //deplacement à droite avec souris
break;
case 2:
gauche(screen,p,a); //deplacement à gauche avec souris
break;
case 3:
bouger_droite(screen,p); //deplacement à droite avec clavier
scrolling_masque_droite(back_masque);
scrolling_droite(backg); //scrolling
break;
case 4:
bouger_gauche(screen,p); //deplacement à gauche avec clavier
scrolling_masque_gauche(back_masque);
scrolling_gauche(backg); //scrolling
break;
}//fin switch x
if(colbackgroundRight(back_masque,p)==1)
{texte_ttf_alerte(screen,ttf_alerte);}

condition_deplacement_souris(&k,p,a,&x); //condition deplacement avec souris

                      while(SDL_PollEvent(&event))
                      {     switch(event.type)
                            {
                            case SDL_QUIT:
                               donner=0;
			       *doner=0;
                               break;

                            case SDL_MOUSEBUTTONUP:
                                if((event.button.button==SDL_BUTTON_LEFT))    
                            	 {   
                                 a=event.button.x; 
				 k=1;
                                 }                                    
                               break;

			   case SDL_KEYDOWN:
				if (event.key.keysym.sym==SDLK_RIGHT)
				x=3;
				else
				if (event.key.keysym.sym==SDLK_LEFT)
				x=4;      
				else
				if(event.key.keysym.sym==SDLK_ESCAPE)
				{
				done=1;
				menu_pause(screen,b,back_sousmenu,p,backg,doner,&donner,&done);
				}
			      break;

			   case SDL_KEYUP:
			        if(event.key.keysym.sym==SDLK_RIGHT)
			        x=0;
			        else
			        if(event.key.keysym.sym==SDLK_LEFT)
			        x=0;
			     break;
			    }//fin switch event
		      }//fin while poll
SDL_Flip(screen);
}//fin done
Mix_ResumeMusic();
screen=SDL_SetVideoMode(1565,850,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
}

