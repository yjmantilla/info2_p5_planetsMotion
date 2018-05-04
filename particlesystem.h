#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <vector>
#include "particle.h"
#include <math.h>

class ParticleSystem
{
public:

    //attributes
    std::vector <Particle> systemParticles;
    double timeStep;
    double time;
    double G;

    //methods
//    ParticleSystem();
    ParticleSystem(double G=667384000000);
    double getG();
    void addParticle(Particle p);
    void evolveSystem();
    double distanceBetweenParticles(Particle p1, Particle p2);
    void updateAccelerations();
    void updateVelocities();
    void updatePositions();

};

#endif // PARTICLESYSTEM_H
