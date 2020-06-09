#include "collision.h"

SDL_Color getRGB(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}


//------------------------------------------------------------------------------------//

int colbackgroundRight(masque *back_masque,pers *p)
{
    int x1,y1;
    int x2,y2;
    int x3,y3;
    SDL_Surface *masque=NULL;
    masque=back_masque->masque;
    x1=p->position_joueur.x+p->position_joueur.w;
    y1=p->position_joueur.y;

    x2=p->position_joueur.x+p->position_joueur.w;
    y2=p->position_joueur.y+p->position_joueur.h/2;

    x3=p->position_joueur.x+p->position_joueur.w;
    y3=p->position_joueur.y+p->position_joueur.h;

    SDL_Color color1=getRGB(masque,x1,y1);
    SDL_Color color2=getRGB(masque,x2,y2);
    SDL_Color color3=getRGB(masque,x3,y3);

    if((color1.r==0 && color1.g==0 && color1.b==0)||(color2.r==0 && color2.g==0 && color2.b==0)||(color3.r==0 && color3.g==0 && color3.b==0))
        return(1);
   else
        return(0);
}
//--------------------------------------------------------------------------------//
void init_ttf_alerte(alerte *ttf_alerte)
{
SDL_Color couleurViloet={0,0,0};
TTF_Init();
ttf_alerte->police=TTF_OpenFont("font_temps.ttf",25);
ttf_alerte->texte =TTF_RenderText_Blended(ttf_alerte->police,"!!!ATTENTION MAUVAISE DIRECTION!!!!", couleurViloet);
ttf_alerte->position_texte.x=0;
ttf_alerte->position_texte.y=50;
}
void texte_ttf_alerte(SDL_Surface *screen,alerte *ttf_alerte)
{
SDL_BlitSurface(ttf_alerte->texte, NULL, screen, &ttf_alerte->position_texte);
}

