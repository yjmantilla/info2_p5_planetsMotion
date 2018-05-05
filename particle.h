#ifndef PARTICLE_H
#define PARTICLE_H


class Particle
{
private:
    //attributes
    double xPosition;
    double yPosition;
    double xVelocity;
    double yVelocity;
    double xAcceleration;
    double yAcceleration;
    double mass;

public:
    //methods
//    Particle();
    Particle(double m=1,double x0=0,double y0=0,double vx0=0,double vy0=0,double ax0=0,double ay0=0);

    double getXPosition();
    double getYPosition();
    double getXVelocity();
    double getYVelocity();
    double getXAcceleration();
    double getYAcceleration();
    double getMass();

    void setXPosition(double xPosition);
    void setYPosition(double yPosition);
    void setXVelocity(double xVelocity);
    void setYVelocity(double yVelocity);
    void setXAcceleration(double xAcceleration);
    void setYAcceleration(double yAcceleration);
    void setMass(double mass);



};

#endif // PARTICLE_H
