#include "goal.h"
#include <string>
#include <iostream>
#include <graphics.h>
#include <fstream>
#include <cstdlib>
#include <sstream> 
#include<math.h>
using namespace std; 
goal::goal()
{
	x =y=0;
	r=50;
}

goal::goal(double x0,double y0){
	
	x=x0;
	y=y0;
	r=50;	
}

goal::~goal()
{
	
}


void goal:: drawGl()
{   setcolor(GREEN);
	double x0=this->x;
	double y0=this->y;
	double r0=this->r;
	circle(x0,y0,r0);
	
}

bool goal::Win(dessin* robot)
{////////////////verifier si le robot à atteint le but
	double dist =sqrt(pow(robot->x-this->x,2)+pow(robot->y-this->y,2));
	int t=(robot->r+this->r)/2;
	if(dist<(abs(t))){
		cleardevice();
		outtextxy(100, 100, "YOU WIN"); 
		return true;
}
return false;
}
