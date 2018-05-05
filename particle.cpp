#include "particle.h"

//Particle::Particle()
//{

//}

Particle::Particle(double m, double x0, double y0, double vx0, double vy0, double ax0, double ay0)
{
    this->setMass(m);
    this->setXPosition(x0);
    this->setYPosition(y0);
    this->setXVelocity(vx0);
    this->setYVelocity(vy0);
    this->setXAcceleration(ax0);
    this->setYAcceleration(ay0);
    return;
}

double Particle::getXPosition()
{
    return this->xPosition;
}

double Particle::getYPosition()
{
    return this->yPosition;
}

double Particle::getXVelocity()
{
    return this->xVelocity;
}

double Particle::getYVelocity()
{
    return this->yVelocity;
}

double Particle::getXAcceleration()
{
    return this->xAcceleration;
}

double Particle::getYAcceleration()
{
    return this->yAcceleration;
}

double Particle::getMass()
{
    return this->mass;
}

void Particle::setXPosition(double xPosition)
{
    this->xPosition =  xPosition;
    return;
}

void Particle::setYPosition(double yPosition)
{
    this->yPosition = yPosition;
    return;
}

void Particle::setXVelocity(double xVelocity)
{
    this->xVelocity = xVelocity;
    return;
}

void Particle::setYVelocity(double yVelocity)
{
    this->yVelocity = yVelocity;
    return;
}

void Particle::setXAcceleration(double xAcceleration)
{
    this->xAcceleration = xAcceleration;
    return;
}

void Particle::setYAcceleration(double yAcceleration)
{
    this->yAcceleration = yAcceleration;
}

void Particle::setMass(double mass)
{
    this->mass = mass;
}



