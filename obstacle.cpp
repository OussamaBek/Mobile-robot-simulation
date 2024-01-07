#include "obstacle.h"
#include <string>
#include <iostream>
#include <graphics.h>
#include <fstream>
#include <cstdlib>

#include <sstream> 
using namespace std; 
obstacle::obstacle()
{
	Xobs =Yobs=Robs=0;
}

obstacle::obstacle(double Xobs0,double Yobs0,double Robs0){
	
	Xobs=Xobs0;
	Yobs=Yobs0;
	Robs=Robs0;	
}

obstacle::~obstacle()
{
	
}



void obstacle:: drawObs()
{   setcolor(RED);
	double x=Xobs;
	double y=Yobs;
	double r=Robs;
	circle(x,y,r);
	
}
