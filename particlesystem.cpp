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

    for(unsigned int j=0;j<this->systemParticles.size();j++)
    {
        if(j==i){continue;}
        else
        {
            dummyPj=this->systemParticles.at(j);
            dummyAcceleration=this->getG()*dummyPj.getMass()/pow(distanceBetweenParticles(dummyPi,dummyPj),2);
            dummyAngle = this->angleBetweenParticles(dummyPi,dummyPj);// why is this the correct order though? pj - pi
//            std::cout<<this->angleBetweenParticles(dummyPi,dummyPj)<<std::endl;
//            std::cout<<this->angleBetweenParticles(dummyPj,dummyPi)<<std::endl;

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

        this->updatePositions();
        this->updateVelocities();        
        this->deleteAccelerations();
        this->updateAccelerations();
        this->time=this->time+this->timeStep;
    }

}

std::string ParticleSystem::SystemState()
{
    std::string str;

    str.append(std::to_string(this->time));
    str.append(",");

    for(unsigned int i = 0; i < this->systemParticles.size(); i++)
    {
        str.append(std::to_string(this->systemParticles.at(i).getXPosition()));
        str.append(",");
        str.append(std::to_string(this->systemParticles.at(i).getYPosition()));
        str.append(",");
    }

    str.pop_back();
    return str;
}

void ParticleSystem::saveSystemStatesToFile(std::string filename, unsigned int numberOfStates)
{
        std::fstream ofs(filename,std::ifstream::out| std::fstream::trunc);


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

        str.pop_back();

        ofs<<str<<std::endl;

        ofs<<this->SystemState()<<std::endl;

        for (unsigned int i = 0; i < numberOfStates; i++)
        {
        this->evolveSystem(1);
        ofs<<this->SystemState();
        if(i==numberOfStates-1){continue;}//last with no endline
        ofs<<std::endl;
        }


        ofs.close();
        std::cout<<"\nStates saved sucesfully in "<<filename<<"\n";

}

