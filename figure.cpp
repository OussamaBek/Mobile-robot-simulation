#include "figure.h"
#include <graphics.h>
#include <iostream>
#include<math.h>
#include<conio.h>

figure::~figure() {};
figure::figure()
{
	x=(rand()%200)+300;
	y=(rand()%200)+100;
	r=(rand()%50);
};
figure::figure(double x0, double y0){
	x=x0;
	y=y0;
};

void figure::deplacement(double x0,double y0)
{
		x+=x0;
		y+=y0;
		
};
	
	void figure::rotation(double theta,double x0,double y0)
{//////////////// rotation 
	    deplacement(-x0,-y0);	
		double om=sqrt(pow(x,2)+pow(y,2));
		double x1=x;
		double y1=y;
		x=((x1*cos(theta))-(y1*sin(theta)));
		y=((x1*sin(theta))+(y1*cos(theta)));
		deplacement(x0,y0);
};

