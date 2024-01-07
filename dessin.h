#include <graphics.h>
#include "figure.h"
#ifndef DESSIN_H
#define DESSIN_H
class dessin : public figure
{
public:
	double r;////////////////rayon
	static const double D=0.05;////////////////distance entre les roue
    static const double R0=0.02;////////////////rayon d'une roue
    static const double t=0.1;////////////////intervale du temps
    static const double W0MAX=10;////////////////vitesse angulaires max entre les roues
    const float Dw0Max = 2.0f;////////////////Acceleration angulaire maximum des roues 
    double alp;////////////////reoriontation pendant t
    double wd,wg;//////////////vitesse angulaire respectivement de la roue droite et gauche
    double dr;////////////////distance parcorue pendant t
    
public:
    dessin(){
    x=0;y=0;r=25;
    wg=1.5,wd=1.5;
    alp=0;
	}
    ~dessin();
    dessin(double x0,double y0) {
    x=x0;
    y=y0;
     r=25;
     wg=2,wd=2;
     alp=0;
	}
    void draw(double x,double y);
    void deplacement();
    void automatiquement(double xG,double yG);
};
#endif	
