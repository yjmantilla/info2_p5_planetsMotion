#include <iostream>
#include "particle.h"
#include "particlesystem.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Particle p1(1,1,1,0,0,0,0);
    Particle p2(3,0,0,0,0,0,0);
    std::cout<<p1.getXPosition()<<"\n";
    ParticleSystem s1(4);
    std::cout<<s1.getG()<<"\n";
    s1.addParticle(p1);
    s1.addParticle(p2);

    std::cout<<s1.distanceBetweenParticles(p1,p2);
    return 0;
}
