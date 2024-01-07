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
### Class dessin (dessin.h and dessin.cpp) :
(inherits from class figure(public inheritance)
* r :robot radius
* D=0.05 : distance between wheels
* R0=0.02 : radius of a wheel
* t=0.1 :time interval
* W0MAX=10 : maximum angular velocity between wheels
* Dw0Max = 2.0f : maximum angular acceleration of wheels 
* alp :reorientation during t
* wd,wg :angular velocity of right and left wheel respectively
* dr :distance covered during t
* void draw(double x,double y): function for drawing the robot
* void deplacement() : function to move the robot using the angular velocities of the wheels
* void automatiquement(double xG,double yG) : function for moving the robot using angular speeds
  
