#include "particlesystem.h"
#include "particle.h"
#include <math.h>

//ParticleSystem::ParticleSystem()
//{

//}

ParticleSystem::ParticleSystem(double G)
{
    this->G = G;
    //first update accelerations of all particles
}

double ParticleSystem::getG()
{
    return this->G;
}

void ParticleSystem::addParticle(Particle p)
{
    this->systemParticles.push_back(p);
    return;
}

double ParticleSystem::distanceBetweenParticles(Particle p1, Particle p2)
{
    return sqrt(pow(p2.getXPosition()-p1.getXPosition(),2)+pow(p2.getYPosition()-p1.getYPosition(),2));
}

void ParticleSystem::updateAccelerations()
{
    //for(unsigned int i=0; this->systemParticles.size();i++)
    {

    }
}
