#include <string>
#include <iostream>
#include <fstream>
#include <graphics.h>
#ifndef OBSTACLE_H
#define OBSTACLE_H
class obstacle
{
	public:
	double Xobs ,Yobs,Robs;
	obstacle();
	obstacle(double Xobs0,double Yobs0,double Robs0);
	~obstacle();
	void drawObs();
};
#endif	
