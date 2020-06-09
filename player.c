#include "player.h"
//------------------------------------------------------------------------------------//

void initialiserperso(pers *p)
{
    p->depart= IMG_Load("position_choix.png");// position initiale du personnage
    // animation deplacement personnage a droite
    p->droite[0] = IMG_Load("position_droit1.png"); 
    p->droite[1] = IMG_Load("position_droit2.png");
    p->droite[2] = IMG_Load("position_droit3.png");
    p->droite[3] = IMG_Load("position_droit4.png");

    // animation deplacement personnage a gauche    
    p->gauche[0] = IMG_Load("position_gauche1.png");
    p->gauche[1] = IMG_Load("position_gauche2.png");
    p->gauche[2] = IMG_Load("position_gauche3.png");
    p->gauche[3] = IMG_Load("position_gauche4.png");

p->right=0;
p->left=0;

p->position_joueur.x=300;
p->position_joueur.y=405;
}
//------------------------------------------------------------------------------------//


void depart(SDL_Surface *screen, pers *p)
{
SDL_BlitSurface(p->depart,NULL,screen,&p->position_joueur);
}
//------------------------------------------------------------------------------------//


void droite(SDL_Surface *screen, pers *p,int a)
{
int q,r;
SDL_BlitSurface(p->droite[p->right],NULL,screen,&p->position_joueur);
q = a-p->position_joueur.x;
r = (a-p->position_joueur.x)%10;
if (q>=10)
    p->position_joueur.x+=10;
else
    p->position_joueur.x+=r;
    SDL_Delay(30);
    p->right++;
if(p->right==3)
   p->right=0; 
}
//------------------------------------------------------------------------------------//


void gauche(SDL_Surface *screen, pers *p,int a)
{
int q,r;
SDL_BlitSurface(p->gauche[p->left],NULL,screen,&p->position_joueur);
q = a-p->position_joueur.x;
r = (a-p->position_joueur.x)%10;
if (q>=10)
   p->position_joueur.x+=10;
else
   p->position_joueur.x+=r;
   p->position_joueur.x--;
   SDL_Delay(30);
   p->left++;
if(p->left==3)
   p->left=0;
}
//------------------------------------------------------------------------------------//
void bouger_droite(SDL_Surface *screen, pers *p)
{
SDL_BlitSurface(p->droite[p->right],NULL,screen,&p->position_joueur);
  p->position_joueur.x+=5;
  SDL_Delay(40);
  p->right++;
if(p->right==3)
  p->right=0;

}
//------------------------------------------------------------------------------------//



void bouger_gauche(SDL_Surface *screen, pers *p)
{
SDL_BlitSurface(p->gauche[p->left],NULL,screen,&p->position_joueur);
   p->position_joueur.x-=5;
   SDL_Delay(40);
   p->left++;
if(p->left==3)
   p->left=0;
}
//------------------------------------------------------------------------------------//

void condition_deplacement_souris(int *k,pers *p,int a,int *x)
{
	if(*k==1)
	if(a>p->position_joueur.x)
	*x=1;	
	else 
	if(a<p->position_joueur.x)
	*x=2;
	if(a==p->position_joueur.x)
	{*k=0;
	*x=0;}
}
//------------------------------------------------------------------------------------//


void liberer_personnage(pers *p)
{
   SDL_FreeSurface(p->gauche[p->left]);
   SDL_FreeSurface(p->droite[p->right]);
   SDL_FreeSurface(p->depart);
}
