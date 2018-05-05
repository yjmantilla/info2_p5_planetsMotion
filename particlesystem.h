#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <vector>
#include "particle.h"
#include <math.h>
#include <string>
#include <fstream>

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
    ParticleSystem(double G=667384000000, double timeStep=0.001);
    double getG();
    void addParticle(Particle p);    
    double distanceBetweenParticles(Particle p1, Particle p2);
    double angleBetweenParticles(Particle p1,Particle p2);
    void updateParticleAcceleration(unsigned int i);
    void updateAccelerations();
    void updateParticleVelocity(unsigned int i);
    void updateVelocities();
    void updateParticlePosition(unsigned int i);
    void updatePositions();
    void deleteAccelerations();
    void evolveSystem(unsigned int numberOfSteps);
    std::string SystemState();
    void saveSystemStatesToFile(std::string filename, unsigned int numberOfStates);


};

#endif // PARTICLESYSTEM_H
