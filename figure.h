#include <graphics.h>
#ifndef FIGURE_H
#define FIGURE_H
class figure
{
public:
	double x, y,r;
public:	
    figure();
    ~figure();
    figure(double x0, double y0);
  
    void rotation(double theta, double x0, double y0);
    
    void deplacement(double x0,double y0);
};
#endif	

