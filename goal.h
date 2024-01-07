#include <string>
#include <iostream>
#include <fstream>
#include "dessin.h"
#include <graphics.h>
#ifndef GOAL_H
#define GOAL_H
class goal
{
	public:
	double x ,y,r;
	goal();
	goal(double x0,double y0);
	~goal();
	void drawGl();
	bool Win(dessin* robot);
};
#endif	
