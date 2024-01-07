# Mobile-robot-simulation
It simulates the movement of a mobile robot, acting only on the angular velocities of its two wheels. It will have to reach a maximum number of goals over a pre-determined period of time, while avoiding obstacles in the environment so as not to be slowed down. To achieve this, we'll be using Dev-c++, and the following libraries:
* graphics.h
* iostream
* math.h
* conio.h
* fstream
* string
  
## Data dictionary :
The project is divided into several classes. 
variables and functions of each file.
### Class figure (figure.h and figure.cpp) :
* x,y: circle center coordinates
* r: circle radius
* void rotation(double theta, double x0, double y0): method for rotating 
the object by an angle theta around a point(x0,y0)
* void deplacement(double x0,double y0): function for moving the circle 
circle to(x+x0,y+y0)
