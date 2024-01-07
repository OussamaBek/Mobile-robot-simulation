//#include "figure.h"
#include "dessin.h"
#include<math.h>
#include <graphics.h>
#include <iostream>
using namespace std;

dessin::~dessin(){
};

void dessin::draw(double x,double y){////////////////dessiner le robot
	setcolor(4);
	 figure cercle(x,y);

	 circle(cercle.x,cercle.y,r);
	 setcolor(1);
	 //roues droites
	figure ligneD(cercle.x,cercle.y+(r/2));
	figure f1(ligneD.x-r/3,ligneD.y);
	f1.rotation(alp,x,y);
	figure f2(ligneD.x+r/3,ligneD.y);
	f2.rotation(alp,x,y);
	line(f1.x,f1.y,f2.x,f2.y);
	//roues gauches
	figure ligneG(cercle.x,y-(r/2));
	figure f3(ligneG.x-r/3,ligneG.y);
	f3.rotation(alp,x,y);
	figure f4(ligneG.x+r/3,ligneG.y);
	f4.rotation(alp,x,y);
	line(f3.x,f3.y,f4.x,f4.y);
	 //direction du robot
	figure ligne(cercle.x,y);
	line(ligne.x,ligne.y,ligne.x+r*cos(alp),ligne.y+ (int)r*sin(alp));
	 
/**	 
  *----------------------TRIANGLE DANS LE CERCLE----------------------------
***/
        
line(x + (int)r*cos(alp - (M_PI/2)),y+ (int)r*sin(alp - (M_PI/2)), x + (int)r*cos(alp),y+ (int)r*sin(alp));
    
line(x + (int)r*cos(alp), y+ (int)r*sin(alp), x+ (int)r*cos(alp+ (M_PI/2)), y+ (int)r*sin(alp + (M_PI/2)));

line(x + (int)r*cos(alp- (M_PI/2)), y+ (int)r*sin(alp - (M_PI/2)), x+ (int)r*cos(alp+ (M_PI/2)),y+ (int)r*sin(alp+ (M_PI/2))); 


setcolor(WHITE);
	 
	 
};
void dessin::deplacement(){////////////////deplacement avec les vitesse angulaire
	
	double x0=this->x;
	double y0=this->y;
	double Dd=wd*t*R0;
	double Dg=wg*t*R0;
	dr=(Dd+Dg)/2;
	x+=dr*25;
	double dalp=(Dd-Dg)/D;
	alp+=dalp*3.14/180;
	rotation(alp,x0,y0);
};
void dessin::automatiquement(double xG,double yG){
	
	
		if(abs(abs(wd)-abs(wg))>W0MAX){//////////// eviter tourner dans le vide
	if(wd<wg){
		wg=2.2;
		wd=2;
	}
	if(wd>wg){
		wg=2;
		wd=2.2;
	}
	}
////////////////creation de 2 vecteur
	double u[4]={x,y,x+r*cos(alp),y+ (int)r*sin(alp)};
	double v[4]={x,y,xG,yG};
////////////////angle entre les 2 vecteurs
	double Theta=atan2((u[2]-u[0])*(v[3]-v[1])-(u[3]-u[1])*(v[2]-v[0]),(u[2]-u[0])*(v[2]-v[0])-(u[3]-u[1])*(v[3]-v[1]));
 /*   double sinT=sin(Theta);
     double cosT=cos(Theta);

*/


		            cout << "Direction"<<endl;
					cout<<"--------------->"<<Theta<<endl;
				if(Theta<0){
					if(Theta + M_PI/2 > 0.5){
						wg += 0.1;
						wd -= 0.1;
						cout<<"gauche*"<<endl;
					}
					else if(Theta + M_PI/2 < -0.5){
						wg += 0.2;
						wd -= 0.2;
						cout<<"droite*"<<endl;
					}
					else{
					    wg=1.9;
						wd=1.5;
						
						cout<<"devant*"<<endl;
					}
				}else if(Theta>0){
					
					if(Theta - M_PI/2 > 0.5){
						wg -= 0.1;
						wd += 0.1;
						cout<<"gauche"<<endl;
					}
					else if(Theta - M_PI <-0.5){
					    wg -= 0.1;
					    wd += 0.1;
						cout<<"droite"<<endl;
						
						
					}
					else{
						wg=1.5;
						wd=1.9;
					
						cout<<"direct"<<endl;
					}
					
					
					
				}
			
	
};
