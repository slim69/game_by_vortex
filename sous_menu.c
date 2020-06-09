#include"sous_menu.h"
void init_background(background_sousmenu *back_sousmenu)
{
back_sousmenu->background=IMG_Load("fenetre.png");
back_sousmenu->pos_background.x=0;
back_sousmenu->pos_background.y=0;
}

void initialise_bouton(bouton *b)
{
b->newgame=NULL;
b->continuer=NULL;
b->save=NULL;
b->quit=NULL;

b->pos_newgame.x=70;
b->pos_newgame.y=80;

b->pos_continuer.x=70;
b->pos_continuer.y=150;

b->pos_save.x=70;
b->pos_save.y=225;

b->pos_quit.x=70;
b->pos_quit.y=300;
}


void afficher_background(SDL_Surface *screen,background_sousmenu *back_sousmenu)
{
SDL_BlitSurface(back_sousmenu->background, NULL, screen, &back_sousmenu->pos_background);
}

void afficher_etat_initiale(SDL_Surface *screen,bouton *b)
{
b->newgame = IMG_Load("newgame_sous_menu1.png");
SDL_BlitSurface(b->newgame, NULL, screen, &b->pos_newgame);
b->continuer = IMG_Load("continue_sous_menu1.png");
SDL_BlitSurface(b->continuer, NULL, screen, &b->pos_continuer);
b->save = IMG_Load("save_sous_menu1.png");
SDL_BlitSurface(b->save, NULL, screen, &b->pos_save);
b->quit=IMG_Load("quit_sous_menu1.png");
SDL_BlitSurface(b->quit, NULL, screen, &b->pos_quit);
}


void afficher1(SDL_Surface *screen,bouton *b)
{
b->newgame = IMG_Load("newgame_sous_menu2.png");
SDL_BlitSurface(b->newgame, NULL, screen, &b->pos_newgame);
b->continuer = IMG_Load("continue_sous_menu1.png");
SDL_BlitSurface(b->continuer, NULL, screen, &b->pos_continuer);
b->save = IMG_Load("save_sous_menu1.png");
SDL_BlitSurface(b->save, NULL, screen, &b->pos_save);
b->quit=IMG_Load("quit_sous_menu1.png");
SDL_BlitSurface(b->quit, NULL, screen, &b->pos_quit);
}

void afficher2(SDL_Surface *screen,bouton *b)
{
b->newgame = IMG_Load("newgame_sous_menu1.png");
SDL_BlitSurface(b->newgame, NULL, screen, &b->pos_newgame);
b->continuer = IMG_Load("continue_sous_menu2.png");
SDL_BlitSurface(b->continuer, NULL, screen, &b->pos_continuer);
b->save = IMG_Load("save_sous_menu1.png");
SDL_BlitSurface(b->save, NULL, screen, &b->pos_save);
b->quit=IMG_Load("quit_sous_menu1.png");
SDL_BlitSurface(b->quit, NULL, screen, &b->pos_quit);
}


void afficher3(SDL_Surface *screen,bouton *b)
{
b->newgame = IMG_Load("newgame_sous_menu1.png");
SDL_BlitSurface(b->newgame, NULL, screen, &b->pos_newgame);
b->continuer = IMG_Load("continue_sous_menu1.png");
SDL_BlitSurface(b->continuer, NULL, screen, &b->pos_continuer);
b->save = IMG_Load("save_sous_menu2.png");
SDL_BlitSurface(b->save, NULL, screen, &b->pos_save);
b->quit=IMG_Load("quit_sous_menu1.png");
SDL_BlitSurface(b->quit, NULL, screen, &b->pos_quit);
}


void afficher4(SDL_Surface *screen,bouton *b)
{
b->newgame = IMG_Load("newgame_sous_menu1.png");
SDL_BlitSurface(b->newgame, NULL, screen, &b->pos_newgame);
b->continuer = IMG_Load("continue_sous_menu1.png");
SDL_BlitSurface(b->continuer, NULL, screen, &b->pos_continuer);
b->save = IMG_Load("save_sous_menu1.png");
SDL_BlitSurface(b->save, NULL, screen, &b->pos_save);
b->quit=IMG_Load("quit_sous_menu2.png");
SDL_BlitSurface(b->quit, NULL, screen, &b->pos_quit);
}

void menu_pause(SDL_Surface *screen,bouton *b,background_sousmenu *back_sousmenu,pers *p,background *backg,int *doner,int *donner,int *done)
{
//int done=1;
static int x=0;
SDL_Event event;
while(*done)
{

afficher_background(screen,back_sousmenu);


switch(x)
{
case 0:
afficher_etat_initiale(screen,b);
break;
case 1:
afficher1(screen,b);
break;
case 2:
afficher2(screen,b);
break;
case 3:
afficher3(screen,b);
break;
case 4:
afficher4(screen,b);
break;
}//fin switch x

		while(SDL_PollEvent(&event))
		{
		switch(event.type)
        		{
			case SDL_QUIT:
      	  		 *done=0;
			*doner=0;
			*donner=0;
       			 break;
			case SDL_MOUSEMOTION:
			if(event.motion.x>=70&& event.motion.x<=80+134 && event.motion.y>=80 && event.motion.y<=90+53)
 			 {
			 x=1;	
		 	 }
	        	 else 
                	 if(event.motion.x>=70 && event.motion.x<=80+134&&event.motion.y>=150 && event.motion.y<=160+53)
			 {
               		 x=2;	
	        	 }
                 	 else 
                 	 if(event.motion.x>=70 && event.motion.x<=80+134 && event.motion.y>=225 && event.motion.y<=235+53)
		 	 {
			 x=3;	
			 }
			 else
			 if(event.motion.x>=70 && event.motion.x<=80+134 && event.motion.y>=300 && event.motion.y<=310+53)
			 {
			 x=4;
			 }
			 else
			 {
			 x=0;
			 }
			break;
			case SDL_MOUSEBUTTONUP:
  		        if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=70 && event.motion.x<=80+134 && event.motion.y>=300 && event.motion.y<=310+53))
  	     	        {
                 	*done=0;
		        *doner=1;  
			*donner=0;              	
			}
                 	else 
			if((event.button.button==SDL_BUTTON_LEFT)&&event.motion.x>=70 && event.motion.x<=80+134&&event.motion.y>=150 && event.motion.y<=160+53)
			{            
			*done=0;
			}
			else
                 	if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=70 && event.motion.x<=70+134 && event.motion.y>=225 && event.motion.y<=235+53))
	         	{
		 	sauvgarde("sauvgarde.bin",p,backg);
                 	}
			break;
			case SDL_KEYDOWN:
      			if(event.key.keysym.sym == SDLK_DOWN)
			{
         	 	x++;
                 	
                  	if(x==5)
                     	x=1;		
                 	}
                 	else 
                 	if(event.key.keysym.sym == SDLK_UP)
		 	{ 
                  	if(x==0)
                     	x=5;
		     	x--;
                            
		 	}
 		 	else 
                 	if(((event.key.keysym.sym == SDLK_RETURN) && (x==4)) ||((event.key.keysym.sym == SDLK_KP_ENTER) && (x==4)))
                 	{
                 	*done=0;
			*doner=1;
			*donner=0;
                 	}
			else
			if(((event.key.keysym.sym == SDLK_RETURN) && (x==2)) ||((event.key.keysym.sym == SDLK_KP_ENTER) && (x==2)))
			{
			*done=0;
			}
		 	else
		 	if(((event.key.keysym.sym == SDLK_RETURN) && (x==3)) ||((event.key.keysym.sym == SDLK_KP_ENTER) && (x==3)))
		 	{
		 	sauvgarde("sauvgarde.bin",p,backg);
                 	}
			break;
			}//fin switch event
		}//fin poll event



SDL_Flip(screen);
}//fin done
}

void free_bouton(bouton *b)
{
SDL_FreeSurface(b->newgame);
SDL_FreeSurface(b->continuer);
SDL_FreeSurface(b->save);
SDL_FreeSurface(b->quit);
}

void free_background(background_sousmenu *back_sousmenu)
{
SDL_FreeSurface(back_sousmenu->background);
}

