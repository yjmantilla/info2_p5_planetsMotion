#include <iostream>
#include "particle.h"
#include "particlesystem.h"
#define NUMBER_OF_STATES 10000

int main()
{
    /*System 1*/

    /*Create Particles*/
    Particle p10(70,0,-7000,2,0,0,0);
    Particle p11(70000,0,0,0,0,0,0);
    Particle p12(25,4000,5000,-1.6,1.2,0,0);

    /*Create System 1*/
    ParticleSystem s1(1,1);

    /*Add Particles To System 1*/
    s1.addParticle(p10);
    s1.addParticle(p11);
    s1.addParticle(p12);

    /*Save System 1 States To File*/
    s1.saveSystemStatesToFile("system1.csv",NUMBER_OF_STATES);

    /*------------------------------------*/

    /*System 2*/

    /*Create Particles*/

    Particle p20(50000,0,0,0,0,0,0);
    Particle p21(70,-5000,0,0,-2,0,0);
    Particle p22(70,5000,0,0,2,0,0);
    Particle p23(70,0,-5000,2,0,0,0);
    Particle p24(70,0,5000,-2,0,0,0);

    /*Create System 2*/
    ParticleSystem s2(1,1);

    /*Add Particles To System 2*/
    s2.addParticle(p20);
    s2.addParticle(p21);
    s2.addParticle(p22);
    s2.addParticle(p23);
    s2.addParticle(p24);

    /*Save System 2 States To File*/
    s2.saveSystemStatesToFile("system2.csv",NUMBER_OF_STATES);



    return 0;
}
