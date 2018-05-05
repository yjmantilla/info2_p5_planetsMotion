#include "particlesystem.h"
#include "particle.h"
#include <math.h>
#include <string>
#include <iostream>

//ParticleSystem::ParticleSystem()
//{

//}

ParticleSystem::ParticleSystem(double G, double timeStep)
{
    this->G = G;
    this->timeStep = timeStep;
    this->time = 0;

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

double ParticleSystem::angleBetweenParticles(Particle p1, Particle p2)
{

    return atan2(p2.getYPosition()-p1.getYPosition(),p2.getXPosition()-p1.getXPosition());
}

void ParticleSystem::updateParticleAcceleration(unsigned int i)
{
    double dummyAcceleration;
    Particle dummyPi;
    Particle dummyPj;
    double dummyAngle;
    dummyPi=this->systemParticles.at(i);

    /*include the effect over particle i of all the other particles*/
    for(unsigned int j=0;j<this->systemParticles.size();j++)
    {
        if(j==i){continue;}//same particle, ignore
        else
        {
            /*auxiliar dummy variables so expresions are shorter, just for readability*/

            dummyPj=this->systemParticles.at(j);

            /*a_j->i = G*Mj/r^2*/
            dummyAcceleration=this->getG()*dummyPj.getMass()/pow(distanceBetweenParticles(dummyPi,dummyPj),2); //same for both components

            /*calculate angle to decompose the a vector*/
            /*order of atan2 is important, it changes the points completely*/
            dummyAngle = this->angleBetweenParticles(dummyPi,dummyPj);// why is this the correct order though? pj - pi

            /*For Debug*/
//            std::cout<<this->angleBetweenParticles(dummyPi,dummyPj)<<std::endl;
//            std::cout<<this->angleBetweenParticles(dummyPj,dummyPi)<<std::endl;

            /*we add to the accumulated acceleration (from previous particles) the current particle acceleration*/
            /*multiply by sin and cos for decomposition into x (costheta) and y (sintheta) components*/
            this->systemParticles.at(i).setXAcceleration(this->systemParticles.at(i).getXAcceleration()+dummyAcceleration*cos(dummyAngle));
            this->systemParticles.at(i).setYAcceleration(this->systemParticles.at(i).getYAcceleration()+dummyAcceleration*sin(dummyAngle));
        }
    }

}

void ParticleSystem::updateAccelerations()
{
    for(unsigned int i=0; i < this->systemParticles.size();i++)
    {
        this->updateParticleAcceleration(i);
    }
    return;
}

void ParticleSystem::updateParticleVelocity(unsigned int i)
{
    /*v=v0 + a*deltat*/
    this->systemParticles.at(i).setXVelocity(this->systemParticles.at(i).getXVelocity()+this->systemParticles.at(i).getXAcceleration()*this->timeStep);
    this->systemParticles.at(i).setYVelocity(this->systemParticles.at(i).getYVelocity()+this->systemParticles.at(i).getYAcceleration()*this->timeStep);
}

void ParticleSystem::updateVelocities()
{
    for(unsigned int i=0; i < this->systemParticles.size();i++)
    {
        this->updateParticleVelocity(i);
    }
    return;
}

void ParticleSystem::updateParticlePosition(unsigned int i)
{
    /* r = r0 + v0*deltat + 0.5*a*deltat^2 */
    this->systemParticles.at(i).setXPosition(this->systemParticles.at(i).getXPosition() + (this->systemParticles.at(i).getXVelocity()*this->timeStep)+ (this->systemParticles.at(i).getXAcceleration()*pow(timeStep,2)*0.5));
    this->systemParticles.at(i).setYPosition(this->systemParticles.at(i).getYPosition() + (this->systemParticles.at(i).getYVelocity()*this->timeStep)+ (this->systemParticles.at(i).getYAcceleration()*pow(timeStep,2)*0.5));
    return;
}

void ParticleSystem::updatePositions()
{

    for(unsigned int i=0; i < this->systemParticles.size();i++)
    {
        this->updateParticlePosition(i);
    }
    return;
}

void ParticleSystem::deleteAccelerations()
{
    for(unsigned int i=0; i < this->systemParticles.size();i++)
    {
        this->systemParticles.at(i).setXAcceleration(0);
        this->systemParticles.at(i).setYAcceleration(0);
    }
    return;
}

void ParticleSystem::evolveSystem(unsigned int numberOfSteps)
{
    std::string str;

    for(unsigned int i = 0; i < numberOfSteps; i++)
    {
        //this order is important
        this->updatePositions();    //calculate initial positions of next state
        this->updateVelocities();    //calculate initial velocities of next state
        this->deleteAccelerations(); //if we dont do this the accelerations get integrated (which is incorrect)
        this->updateAccelerations(); //calculate accelerations for the next state
        this->time=this->time+this->timeStep;
    }

}

std::string ParticleSystem::SystemState()
{
    std::string str;

    //basically time,x0,y0,x1,y1...xn,yn where the index is the particle number

    str.append(std::to_string(this->time));
    str.append(",");

    for(unsigned int i = 0; i < this->systemParticles.size(); i++)
    {
        str.append(std::to_string(this->systemParticles.at(i).getXPosition()));
        str.append(",");
        str.append(std::to_string(this->systemParticles.at(i).getYPosition()));
        str.append(",");
    }

    str.pop_back();//delete last ','
    return str;
}

void ParticleSystem::saveSystemStatesToFile(std::string filename, unsigned int numberOfStates)
{
        std::fstream ofs(filename,std::ifstream::out| std::fstream::trunc);

        /*headers of columns*/
        std::string str;
        str.append("time,");
        for(unsigned int i = 0; i < this->systemParticles.size(); i++)
        {

            str.append("x");
            str.append(std::to_string(i));
            str.append(",y");
            str.append(std::to_string(i));
            str.append(",");
        }

        str.pop_back(); //delete last ','

        ofs<<str<<std::endl;

        /*Print Initial State*/
        ofs<<this->SystemState()<<std::endl;

        /*Evolution of the system*/
        for (unsigned int i = 0; i < numberOfStates; i++)
        {
        this->evolveSystem(1);
        ofs<<this->SystemState(); //print current state
        if(i==numberOfStates-1){continue;}//last with no endline
        ofs<<std::endl;
        }


        ofs.close();
        std::cout<<"\nStates saved sucesfully in "<<filename<<"\n";

}

