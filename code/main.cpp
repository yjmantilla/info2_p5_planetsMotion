#include <iostream>
#include "particle.h"
#include "particlesystem.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Particle p1(70,0,-7000,2,0,0,0);
    Particle p2(70000,0,0,0,0,0,0);
    Particle p3(25,4000,5000,-1.6,1.2,0,0);

    std::cout<<p1.getXPosition()<<"\n";

    ParticleSystem s1(1,1);
    std::cout<<s1.getG()<<"\n";

    s1.addParticle(p3);
    s1.addParticle(p2);
    s1.addParticle(p1);
//123 g
//132 g
//231 g
//213 g
//312 g
//321
//    std::cout<<s1.distanceBetweenParticles(p1,p2)<<std::endl;
//    std::cout<<s1.angleBetweenParticles(p1,p2)<<std::endl;
//    std::cout<<s1.angleBetweenParticles(p2,p1)<<std::endl;


    std::cout<<s1.SystemState()<<std::endl;

//    for (unsigned int i = 0; i < 200; i++)
//    {
//    s1.evolveSystem(1);
//    std::cout<<s1.SystemState()<<std::endl;
//    }

    s1.saveSystemStatesToFile("system1.csv",10000);

    return 0;
}
