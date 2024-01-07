#include <graphics.h>
#include "obstacle.h"
#include "goal.h"
#include <iostream>
#include<math.h>
#include <fstream>
#include <string>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;
obstacle obs[15];
int n=0;
////////////// lecture des obstacles
void lecture()
{

		ifstream fichier("./Obstacle.obs");
	if(fichier)
{

	  string ligne; //Une variable pour stocker les lignes lues

    	while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
         {
         int esp1=ligne.find(' ',0);
         string x="";
         for(int i=0;i<esp1;i++)
         {
         	x=x+ligne.at(i);
		 }
		 // object from the class stringstream 
    stringstream ok1(x); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    int Xobs1 = 0; 
    ok1 >> Xobs1;
	 int esp2=ligne.find(' ',esp1+1); 
     x="";
         for(int i=esp1+1;i<esp2;i++)
         {
         	x=x+ligne.at(i);
		 }
	stringstream ok2(x); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    int Yobs1 = 0; 
    ok2 >> Yobs1;
    int r1=0;
    x="";
    for(int i=esp2+1;i<ligne.length();i++)
         {
         	x=x+ligne.at(i);
		 }
		stringstream ok3(x); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    ok3 >> r1;
    setcolor(RED);
    obs[n].Xobs=Xobs1;
    obs[n].Yobs=Yobs1;
    obs[n].Robs=r1;
    obs[n].drawObs();
	string str= "obs"+n; 
	
n++;
} 	
}

else cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

}

void colision(dessin* d,obstacle o)
 {///////////// gerer les cas de colision
	
	double dist =sqrt(pow(d->x-o.Xobs,2)+pow(d->y-o.Yobs,2));
	
	if(dist<abs(d->r+o.Robs)){
		cout<<"collision"<<endl;
		d->x=o.Xobs+(((d->x-o.Xobs)/dist)*(d->r+o.Robs));
		d->y=o.Yobs+(((d->y-o.Yobs)/dist)*(d->r+o.Robs));
	    d->wd+=0.1;
		
	}
	
}
void enregistrement(dessin* robot)
{////////////// gerer le stockage des position du robot
	string const nomFichier("./position.pts");
  
	ifstream fichier(nomFichier.c_str());

	  string Buffer = ""; //Variable contenant le texte à réécrire dans le fichier


    	
    	
	if(fichier)
{
	int cpt=0;
	  string ligne; //Une variable pour stocker les lignes lues
   int k=0;
	
	while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
{
    k++;
}
cout<<k<<endl;
fichier.close();
  
     int t=0; 
if(k>1000)t=1;
	ifstream file(nomFichier.c_str());
       string line;
    int Line = 0;
	
        while (getline( file, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            
            if(Line !=t) {	//Si la ligne atteinte est différente de la ligne à supprimer...
               Buffer += line + "\n";//On ajoute le contenu de la ligne dans le contenu à réécrire
			    //cout<<"tets"<<endl;
				}
        }
        
   file.close();
    ofstream monFlux(nomFichier.c_str());	
    monFlux<< Buffer; //On écris le texte dedans
   
        monFlux << "<" << robot->x << " >"<< "<" << robot->y << " >" << "<" << robot->x << " >"<< "<" << robot->wd << " >"<< "<" << robot->wg << " >"<< endl;
monFlux.close();
 
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}
int main() {
	//ecran
	initwindow(1600,700,"Test"); 
	lecture();
	
	// Coordinates of the mouse click
	int a,b;
	//creation du robot
	double x=250;
	double y=100;
	dessin robot(x,y);
	
	int c;
	goal g(700,300);
/////////////////////////////////////////////////////MENU

    while (1)
    {

    setbkcolor(15);
    setfillstyle(SOLID_FILL,0);
    floodfill(1,1,15);

////////////////////bouton manuel

    setcolor(BLACK);
    settextstyle(8, 0, 7);
    outtextxy(250,85,"MANUAL MODE");
    setbkcolor(15);
    setfillstyle(SOLID_FILL,0);
    floodfill(1,1,15);
/////////////////////bouton auto

    setcolor(BLACK);
    settextstyle(8, 0, 7);
    outtextxy(250,285,"AUTO MODE");
   
        delay(500);

    getmouseclick(WM_LBUTTONDOWN, a, b);

    cout << "The mouse was clicked at: ";

    cout << "x=" << a;

    cout << " y=" << b << endl;

    

    // Switch back to text mode:
if(250<a&&a<593&&285<b&&b<353){
	c=1;
break;	
}
if(250<a&&a<668&&85<b&&b<153){
	c=0;
break;	
}
    }
     
     
setbkcolor(0);
/////////////////////////////////////MANU
    if(c==0){
	while(1)
    {
	
   	if(abs(abs(robot.wd)-abs(robot.wg))>robot.W0MAX){//////////// eviter tourner dans le vide
	if(robot.wd<robot.wg){
		robot.wg-=robot.wg/3;
		robot.wd-=robot.wd/3;
	}
	if(robot.wd>robot.wg){
		robot.wg-=robot.wg/3;
		robot.wd-=robot.wd/3;
	}
	}
    cout<<"test"<<endl;
    
    		if(GetKeyState(VK_UP) & 0x8000){/////////// augmenter la vitesse
    			 	robot.wd+=0.5;
				   	robot.wg+=0.5;
    		         if(abs( abs(robot.wd) -abs(robot.wg)) >= robot.W0MAX){
					  robot.wd = robot.W0MAX; 
    		          robot.wg = robot.W0MAX;       } 
    		}
    			
			 
    		 
    	if(GetKeyState(VK_RIGHT) & 0x8000){/////////////tourner a droite
    	robot.wd+=0.5;
    		         if(abs( abs(robot.wd) -abs(robot.wg))>= robot.W0MAX){
					  robot.wd = robot.W0MAX; 
    		          robot.wg = robot.W0MAX;       } 
    	 	}
    	if(GetKeyState(VK_LEFT) & 0x8000){///////////////////tourner a gauche
    		robot.wg+=0.5;
    		         if( abs( abs(robot.wd) -abs(robot.wg))>= robot.W0MAX) {
					 robot.wd = robot.W0MAX; 
    		          robot.wg = robot.W0MAX; 
					 }       
					}
					
					
    	if(GetKeyState(VK_DOWN) & 0x8000){////////marche arierre
    		        	robot.wd-=0.5;
				   	robot.wg-=0.5;
    		         if( abs( abs(robot.wd) -abs(robot.wg))>= robot.W0MAX) {
					 robot.wd = robot.W0MAX; 
    		          robot.wg = robot.W0MAX; 
					 }       
					}
    
        cleardevice();
   
    
    	cout <<robot.wg<<endl;
    	cout <<robot.wd<<endl;
    
    	cout <<"///////////////"<<endl;
		g.drawGl();
    	robot.draw(robot.x,robot.y);
 
for(int i=0;i<15;i++){/////////////gestion des colision
colision(&robot, obs[i]);

	obs[i].drawObs();		
	
	}		

	delay(10);
		robot.deplacement();
/////////////////// cas ou le robot atteint le but
    	if(g.Win(&robot))break;
    	enregistrement(&robot);
    	
	}
	}
	
	
///////////////////// MODE AUTO
	if(c==1){
		while(1)
    {
        cleardevice();
    	cout <<robot.wg<<endl;
    	cout <<robot.wd<<endl;
    	cout <<"///////////////"<<endl;
		
		g.drawGl();
    	robot.draw(robot.x,robot.y);
    robot.automatiquement(g.x,g.y);

for(int i=0;i<15;i++){/////////////gestion colision
	colision(&robot, obs[i]);
	obs[i].drawObs();		
	
	}		
	delay(1);
		robot.deplacement();
/////////////// cas arriver au but
    	if(g.Win(&robot))break;
    	enregistrement(&robot);
    	
	}	
	}
cleardevice();

//win affichage
setbkcolor(0);

    while (1)
    {

    setbkcolor(15);
    setfillstyle(SOLID_FILL,0);
    floodfill(1,1,15);

////////////////////bouton manuel

    setcolor(RED);
    settextstyle(8, 0, 7);
    outtextxy(250,85,"YOU WIN");
    setbkcolor(15);
    setfillstyle(SOLID_FILL,0);
    floodfill(1,1,15);
/////////////////////bouton auto

    setcolor(BLACK);
    settextstyle(8, 0, 7);
    outtextxy(250,285,"Exit");
   
        delay(500);

    getmouseclick(WM_LBUTTONDOWN, a, b);

    cout << "The mouse was clicked at: ";

    cout << "x=" << a;

    cout << " y=" << b << endl;

    

    // Switch back to text mode:
if(250<a&&a<593&&285<b&&b<353){
	c=1;
break;	
}

    }
 
	return 0;
}


