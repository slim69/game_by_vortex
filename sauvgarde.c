#include"sauvgarde.h"
#include"player.h"
#include"background.h"

void sauvgarde(char nomfich[],pers *p,background *backg)
{
FILE *fiche=NULL;
fiche=fopen("sauvgarde.bin","wb");
if(fiche!=NULL)
{
fwrite(&p,sizeof(pers),1,fiche);
//fwrite(&backg,sizeof(background),1,fiche);
}
fclose(fiche);
}

void load(char nomfich[],pers *p,background *backg)
{
FILE *fiche;
pers perso;
background backo;

fiche=fopen("sauvgarde.bin","rb");
while(!EOF)
{
fread(&perso,sizeof(pers),1,fiche);
fread(&backo,sizeof(background),1,fiche);
    p->depart= perso.depart;
    // animation deplacement personnage a droite
    p->droite[0] = perso.droite[0];
    p->droite[1] = perso.droite[1];
    p->droite[2] = perso.droite[2];
    p->droite[3] = perso.droite[3];

    // animation deplacement personnage a gauche    
    p->gauche[0] = perso.gauche[0];
    p->gauche[1] = perso.gauche[1];
    p->gauche[2] = perso.gauche[2];
    p->gauche[3] = perso.gauche[3];


backg->background=backo.background;
backg->position_fond.x=backo.position_fond.x;
backg->position_fond.y=backo.position_fond.y;

backg->position_fond.w=backo.position_fond.w; 
backg->position_fond.h=backo.position_fond.h;


p->right=perso.right;
p->left=perso.left;
p->position_joueur.x=perso.position_joueur.x;
p->position_joueur.y=perso.position_joueur.y;
}
fclose(fiche);
}
