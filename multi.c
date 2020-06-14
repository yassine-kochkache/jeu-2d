#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include "perso.h"
#include "enemie.h"

void initialiser_background(background *back)
{
back->calque=NULL;
back->image=NULL;
back->calque=IMG_Load("calque.png");
back->image=IMG_Load("background.png");
back->positionback.x=0;
back->positionback.y=0;
back->positionback2.x=0;
back->positionback2.y=0;
back->positionback2.h=450;
back->positionback2.w=1600;

back->calque2=NULL;
back->image2=NULL;
back->calque2=IMG_Load("calque.png");
back->image2=IMG_Load("background.png");
back->cam1.x=0;
back->cam1.y=450;
back->poscam1.x=0;
back->poscam1.y=0;
back->poscam1.h=450;
back->poscam1.w=1600;
}

void initialiser_evan(hero *hero)
{
			hero->image_hero[0]=IMG_Load("1.png");
			hero->image_hero[1]=IMG_Load("2.png");
			hero->image_hero[2]=IMG_Load("3.png");
			hero->image_hero[3]=IMG_Load("4.png");
			hero->image_hero[4]=IMG_Load("5.png");
                        hero->num=0;
                        hero->pos_hero2.x=10;
		        hero->pos_hero2.y=250;
                        hero->score=0;
                        hero->vie=5;
                        hero->mouv=0;
}
void initialiser_evan1(hero *hero) 
{
			hero->image_hero2[0]=IMG_Load("111.png");
			hero->image_hero2[1]=IMG_Load("22.png");
	                hero->image_hero2[2]=IMG_Load("33.png");
                        hero->image_hero2[3]=IMG_Load("44.png");
                        hero->image_hero2[4]=IMG_Load("55.png");
		        hero->num2=0;
		        hero->pos_hero.x=10;
                        hero->pos_hero.y=700;
                        hero->score2=0;
                        hero->vie2=5; 
                        hero->mouv2=0;
}

void Affiche_back(background back,SDL_Surface *ecran)
{
SDL_BlitSurface(back.image,&(back.positionback2),ecran,&(back.positionback));
SDL_BlitSurface(back.image2,&(back.poscam1),ecran,&(back.cam1));
}
void afficher_hero(hero hero,SDL_Surface *ecran)
       {
		
		SDL_BlitSurface(hero.image_hero[hero.num],NULL,ecran,&(hero.pos_hero2));
                SDL_BlitSurface(hero.image_hero2[hero.num2],NULL,ecran,&(hero.pos_hero));
       }


int deplacement1(hero *hero,SDL_Event *event)
{ 	
	   	 	 SDL_WaitEvent(event);
	 	switch (event->type)
	        {
	        
	        case SDL_KEYDOWN:
	            switch (event->key.keysym.sym)
	            {
	           
	            case SDLK_RIGHT: 
			
                 hero->pos_hero2.x+=5;
                 hero->mouv=1;
                 break;
	            case SDLK_LEFT: 
            
                      hero->pos_hero2.x-=5;
                      hero->mouv=2;         
	                break;
	           
	            }
	        break;
               }
return hero->mouv;
}
int deplacement2(hero *hero,SDL_Event *event){
	         
	   
	 	 SDL_WaitEvent(event);
	 	switch (event->type)
	        {
	        
	        case SDL_KEYDOWN:
	            switch (event->key.keysym.sym)
	            {
	           
	            case SDLK_d: 
			hero->pos_hero.x+=5;
                    hero->mouv2=1; 
                 
	               
                       break;
	            case SDLK_q: 
            
                      hero->pos_hero.x-=5;   
                       hero->mouv2=2;         
	                break;
	            
	            }
	            break;
               }
 return  hero->mouv2;
}
void scrolling1 (hero *hero,background *back,int d,int co)
{

switch(d)
{

case 1:

if(co==0)
{
if ((back->positionback2.x<7340)&&(hero->pos_hero2.x>=800))
{
                back->positionback2.x+=5;
                hero->pos_hero2.x=800;
}
if(hero->pos_hero2.x==4940)
{
back->positionback2.x==4940;
while (hero->pos_hero2.x<7340)
{
hero->pos_hero2.x+=5;
}
}
}

break;
case 2:

if(co==0)
{
if ((back->positionback2.x>0)&&((hero->pos_hero2.x<800)||(hero->pos_hero2.x>6540)))
{
                back->positionback2.x-=5;
}                
}
break;
}
}

void scrolling2 (hero *hero,background *back,int d2,int co)
{

switch(d2)
{

case 1:

if(co==0)
{
if ((back->poscam1.x<7340)&&(hero->pos_hero.x>=800))
{
                back->poscam1.x+=5;
                hero->pos_hero.x=800;
}
}

break;
case 2:

if(co==1)
{
if ((back->poscam1.x>0)&&((hero->pos_hero.x<800)||(hero->pos_hero.x>6540)))
{
                back->poscam1.x-=5;
}
}                

break;
}
}

SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
SDL_Color color ;
Uint32 col = 0 ;
char* pPosition = ( char* ) surface->pixels ;
pPosition += ( surface->pitch * y ) ;
pPosition += ( surface->format->BytesPerPixel * x ) ;
memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;
SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
return ( color ) ;
} 


int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col;
  
col=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+220);

   printf("%d    %d   /////////// \n",posperso.x+100+posmap.x+601,posperso.y+220 );
  printf("%d    %d   %d\n",col.r,col.b,col.g );
  
if ((col.r==0)&&(col.b==0)&&(col.g==0))
  return 1;
else 
{
return 0;
}
}
int collision_Parfaite2(SDL_Surface *calque2,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col;
  
col=GetPixel(calque2,posperso.x+100+posmap.x,posperso.y+220);


   printf("%d    %d   /////////// \n",posperso.x+100+posmap.x+601,posperso.y+220 );
  printf("%d    %d   %d\n",col.r,col.b,col.g );
  
if ((col.r==0)&&(col.b==0)&&(col.g==0))
  return 1;
else 
{
return 0;
}
}


Enemy InitEnemy1(Enemy Ennemie,int x, int y)
{
  Ennemie.image[0]=IMG_Load("rpg1.png");
  Ennemie.image[1]=IMG_Load("rpg2.png");
  Ennemie.image[2]=IMG_Load("rpg3.png");
  Ennemie.Hit=IMG_Load("rpg4.png");

  Ennemie.image2[0]=IMG_Load("rpd1.png");
  Ennemie.image2[1]=IMG_Load("rpd2.png");
  Ennemie.image2[2]=IMG_Load("rpd3.png");
  Ennemie.imageActuel=Ennemie.image[0];
  Ennemie.position.x=x;
  Ennemie.position.y=y;
  Ennemie.positionO=Ennemie.position;
  Ennemie.frame=0;
  Ennemie.direction=0;
  return Ennemie;
}
Enemy InitEnemy(Enemy Ennemie,int x, int y)
{
  Ennemie.image[0]=IMG_Load("rpg1.png");
  Ennemie.image[1]=IMG_Load("rpg2.png");
  Ennemie.image[2]=IMG_Load("rpg3.png");
  Ennemie.Hit=IMG_Load("rpg4.png");

  Ennemie.image2[0]=IMG_Load("rpd1.png");
  Ennemie.image2[1]=IMG_Load("rpd2.png");
  Ennemie.image2[2]=IMG_Load("rpd3.png");
  Ennemie.imageActuel=Ennemie.image[0];
  Ennemie.position.x=x;
  Ennemie.position.y=y;
  Ennemie.positionO=Ennemie.position;
  Ennemie.frame=0;
  Ennemie.direction=0;
  return Ennemie;
}
void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen)
{
  SDL_BlitSurface(Ennemie.imageActuel,NULL,screen,&Ennemie.position);
}
void  AfficherEnemy1(Enemy Ennemie,SDL_Surface *screen)
{
  SDL_BlitSurface(Ennemie.imageActuel,NULL,screen,&Ennemie.position);
}


Enemy AnimateEnemy(Enemy Ennemie,int stat)
{
  if (Ennemie.frame==2) {
    Ennemie.frame=0;
  }
  else
  Ennemie.frame++;
	if (Ennemie.direction==1)
 	 	Ennemie.imageActuel=Ennemie.image[Ennemie.frame];
	else if(Ennemie.direction==0)
	 	 Ennemie.imageActuel=Ennemie.image2[Ennemie.frame];
  if(stat==1)
    Ennemie.imageActuel=Ennemie.Hit;
  return Ennemie;

}
Enemy AnimateEnemy1(Enemy Ennemie,int stat)
{
  if (Ennemie.frame==2) {
    Ennemie.frame=0;
  }
  else
  Ennemie.frame++;
	if (Ennemie.direction==1)
 	 	Ennemie.imageActuel=Ennemie.image[Ennemie.frame];
	else if(Ennemie.direction==0)
	 	 Ennemie.imageActuel=Ennemie.image2[Ennemie.frame];
  if(stat==1)
    Ennemie.imageActuel=Ennemie.Hit;
  return Ennemie;

}
Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage,int *stat,int mouvment)
{

int distance;

  if(Ennemie.position.x>=personnage.x)
    distance=Ennemie.position.x-personnage.x;
  else
    distance=personnage.x-Ennemie.position.x;
if(distance<50)*stat=1;
else *stat=0;
    if(distance<200)
      {
        if(Ennemie.position.x>=personnage.x)
          Ennemie.direction=0;
        else
          Ennemie.direction=1;
      }

      else
    {  if(Ennemie.positionO.x+200<=Ennemie.position.x)
          Ennemie.direction=0;

      if(Ennemie.positionO.x-200>=Ennemie.position.x)

        Ennemie.direction=1;}


      if(Ennemie.direction==1)
      {
        Ennemie.position.x+=4;
      }
      if(Ennemie.direction==0)
      {
        Ennemie.position.x-=4;
      }
      
      if(mouvment==1){
      	Ennemie.position.x-=5;
      	Ennemie.positionO.x-=5;
      }
      if (mouvment==2)	{

      	Ennemie.position.x+=5;
      	Ennemie.positionO.x+=5;
      }
      if ((mouvment==3)&&(personnage.y>50)){
        
       
}
  return Ennemie;
}
Enemy MoveEnemy1(Enemy Ennemie,SDL_Rect personnage,int *stat1,int mouvment)
{

int distance;

  if(Ennemie.position.x>=personnage.x)
    distance=Ennemie.position.x-personnage.x;
  else
    distance=personnage.x-Ennemie.position.x;
if(distance<50)*stat1=1;
else *stat1=0;
    if(distance<200)
      {
        if(Ennemie.position.x>=personnage.x)
          Ennemie.direction=0;
        else
          Ennemie.direction=1;
      }

      else
    {  if(Ennemie.positionO.x+200<=Ennemie.position.x)
          Ennemie.direction=0;

      if(Ennemie.positionO.x-200>=Ennemie.position.x)

        Ennemie.direction=1;}


      if(Ennemie.direction==1)
      {
        Ennemie.position.x+=4;
      }
      if(Ennemie.direction==0)
      {
        Ennemie.position.x-=4;
      }
     
      if(mouvment==1){
      	Ennemie.position.x-=5;
      	Ennemie.positionO.x-=5;
      }
      if (mouvment==2)	{

      	Ennemie.position.x+=5;
      	Ennemie.positionO.x+=5;
      }
      if ((mouvment==3)&&(personnage.y>50)){
         
}
  return Ennemie;
}



