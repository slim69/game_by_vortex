#include"menu.h"
int main (void)
{
int doner=1;
static int x=0;
SDL_Surface *screen=NULL;
background_menu back;
texte ttf;
alerte ttf_alerte;
bouton_menu bm;
bouton_setting bs;
pers p;
background backg;

background_sousmenu back_sousmenu;
bouton b;

masque back_masque;
Mix_Chunk *son;

Mix_Music *musique ;



SDL_Init(SDL_INIT_VIDEO);

screen=SDL_SetVideoMode(1565,850,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("LOST IN VR", NULL);
SDL_Event event;



   if (screen==NULL)
   {
    printf("error: %s ",SDL_GetError());
    exit(EXIT_FAILURE);
   }
   if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
   {
   printf("%s",Mix_GetError());
   }      

musique=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(musique,-1);
son = Mix_LoadWAV("click.wav");

//initialiser
init_background_menu(&back);
init_ttf(&ttf);
init_bouton(&bm);
initialiser_bouton_setting(&bs);

//initialiser
initialiser_background_masque(&back_masque);
//initialiser_background(&backg);
//initialiserperso(&p);
initialise_bouton(&b);
init_background(&back_sousmenu);
init_ttf_alerte(&ttf_alerte);
//-------------------//
//----------------------


while(doner)
{

animer_background(screen,&back);
texte_ttf(screen,&ttf);

switch(x)
{
case 0:
afficher_bouton_normal(screen,&bm);
break;
case 1:
afficher_menu1(screen,&bm);
break;
case 2:
afficher_menu2(screen,&bm);
break;
case 3:
afficher_menu3(screen,&bm);
break;
case 4:
afficher_menu4(screen,&bm);
break;
}//fin switch x

		while(SDL_PollEvent(&event))
		{
		switch(event.type)
        		{
			case SDL_QUIT:
      	  		 doner=0;
       			 break;
			case SDL_MOUSEMOTION:
			if(event.motion.x>=550&& event.motion.x<=560+471 && event.motion.y>=330 && event.motion.y<=340+59)
 			 {
			 x=1;	
		 	 }
	        	 else 
                	 if(event.motion.x>=550 && event.motion.x<=560+471&&event.motion.y>=450 && event.motion.y<=460+59)
			 {
               		 x=2;	
	        	 }
                 	 else 
                 	 if(event.motion.x>=550 && event.motion.x<=560+471 && event.motion.y>=570 && event.motion.y<=580+59)
		 	 {
			 x=3;	
			 }
			 else
			 if(event.motion.x>=550 && event.motion.x<=560+471 && event.motion.y>=690 && event.motion.y<=700+49)
			 {
			 x=4;
			 }
			 else
			 {
			 x=0;
			 }
			break;
			case SDL_MOUSEBUTTONUP:
			if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=550&& event.motion.x<=560+471 && event.motion.y>=330 && event.motion.y<=340+59))
			{
			screen=SDL_SetVideoMode(1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
			Mix_PauseMusic();
			load("sauvgarde.bin",&p,&backg);
			jouer(&p,&backg,&back_sousmenu,&b,&back_masque,screen,&doner,&ttf_alerte);
			}			
			else
			if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=550 && event.motion.x<=560+471&&event.motion.y>=450 && event.motion.y<=460+59))
			{screen=SDL_SetVideoMode(1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
			Mix_PauseMusic();
			initialiserperso(&p);
			initialiser_background(&backg);
			jouer(&p,&backg,&back_sousmenu,&b,&back_masque,screen,&doner,&ttf_alerte);}			
			else
  		        if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=600 && event.motion.x<=610+206 && event.motion.y>=700 && event.motion.y<=710+66))
  	     	        {
		 	Mix_PlayChannel(-1, son, 0);
                 	doner=0;
                 	}
                 	else 
                 	if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=550 && event.motion.x<=550+471 && event.motion.y>=570 && event.motion.y<=580+59))
	         	{
		 	Mix_PlayChannel(-1, son, 0);
                 	settings(screen,son,musique,&bs,&doner);
                 	}
			break;
			case SDL_KEYDOWN:
      			if(event.key.keysym.sym == SDLK_DOWN)
			{
         	 	x++;
                 	Mix_PlayChannel(-1, son, 0);
                  	if(x==5)
                     	x=1;		
                 	}
                 	else 
                 	if(event.key.keysym.sym == SDLK_UP)
		 	{ 
                  	if(x==0)
                     	x=5;
		     	x--;
                     	Mix_PlayChannel(-1, son, 0);        
		 	}
 		 	else 
			if(((event.key.keysym.sym == SDLK_RETURN) && (x==1)) ||((event.key.keysym.sym == SDLK_KP_ENTER) && (x==1)))
			{
			screen=SDL_SetVideoMode(1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
			Mix_PauseMusic();
			load("sauvgarde.bin",&p,&backg);
			jouer(&p,&backg,&back_sousmenu,&b,&back_masque,screen,&doner,&ttf_alerte);
			}			
			else
			if(((event.key.keysym.sym == SDLK_RETURN) && (x==2)) ||((event.key.keysym.sym == SDLK_KP_ENTER) && (x==2)))
			{screen=SDL_SetVideoMode(1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
			Mix_PauseMusic();
			initialiserperso(&p);
			initialiser_background(&backg);
			jouer(&p,&backg,&back_sousmenu,&b,&back_masque,screen,&doner,&ttf_alerte);}		
			else
                 	if(((event.key.keysym.sym == SDLK_RETURN) && (x==4)) ||((event.key.keysym.sym == SDLK_KP_ENTER) && (x==4)))
                 	{
		 	Mix_PlayChannel(-1, son, 0);
                 	doner=0;
                 	}
		 	else
		 	if(((event.key.keysym.sym == SDLK_RETURN) && (x==3)) ||((event.key.keysym.sym == SDLK_KP_ENTER) && (x==3)))
		 	{
		 	Mix_PlayChannel(-1, son, 0);
                 	settings(screen,son,musique,&bs,&doner);
                 	}
			break;
			}//fin switch event
		}//fin poll event



SDL_Flip(screen);
}//fin done 
Mix_FreeChunk(son);          
SDL_FreeSurface(screen);
liberer_bouton(&bm);
free_surface_background(&back);
liberer_ttf(&ttf);
Mix_FreeMusic(musique);
Mix_CloseAudio();
liberer_bouton_setting(&bs);
liberer_personnage(&p);
liberebackg(&backg);
free_bouton(&b);
free_background(&back_sousmenu);
liberer_masque(&back_masque);
TTF_Quit();
SDL_Quit();
return EXIT_SUCCESS;
}
