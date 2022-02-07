#include "train.h"


train::train(int size)
{
    this->trainSize = size;
    design = new component*[trainSize];
    for (int i = 0; i < trainSize; ++i)
    {
        design[i] = NULL;
    }
}

train::~train()
{
    int numCargo = 0, numPassengers = 0, numLocomotives = 0;

    for (int i = 0; i < trainSize; ++i)
    {
        if(design[i] != NULL)
        {
            switch(design[i]->getType())
            {
                case 'C': case 'c':
                    numCargo++;
                    break;

                case 'P': case 'p':
                    numPassengers++;
                    break;

                case 'L': case 'l':
                    numLocomotives++;
                    break;
            }
        }

        delete design[i];
        design[i] = NULL;
    }
    delete[] design;
    design = NULL;

    std::cout << "Number of Cargo Cars: " << numCargo << std::endl;
    std::cout << "Number of Passenger Cars: " << numPassengers << std::endl;
    std::cout << "Number of Locomotives: " << numLocomotives << std::endl;
}

std::ostream& operator<<(std::ostream& output, const train& t)
{
    std::string design;
    double efficiency = 0;
    int numCargo = 0, numPassengers = 0, numLocomotives = 0;

    for (int i = 0; i < t.trainSize; ++i)
    {
        if(t.design[i] != NULL)
        {
            design += t.design[i]->getType();
            efficiency += t.design[i]->calculateEfficiency();
            switch(t.design[i]->getType())
            {
                case 'C': case 'c':
                    numCargo++;
                    break;

                case 'P': case 'p':
                    numPassengers++;
                    break;

                case 'L': case 'l':
                    numLocomotives++;
                    break;
            }
        }
    }

    output << "DESIGN: " << design << std::endl <<  "Efficiency Rating: " << efficiency << std::endl <<
    "Cargo Cars: " << numCargo << std::endl << "Passenger Cars: " << numPassengers << std::endl <<
    "Locomotives: " << numLocomotives << std::endl;
    return output;
}

int train::addComponent(std::string comp)
{
    char type;
    std::string temp;
    double weight = 0, cost = 0, unknown = 0;
    int powerDrain = 0, pos;

    pos = comp.find(',');
    type = comp[0];
    comp.erase(0, pos+1);

    pos = comp.find(',');
    temp = comp.substr(0, pos);
    comp.erase(0, pos+1);
    std::stringstream sw(temp);
    sw >> weight;

    pos = comp.find(',');
    temp = comp.substr(0, pos);
    comp.erase(0, pos+1);
    std::stringstream sc(temp);
    sc >> cost;

    pos = comp.find(',');
    temp = comp.substr(0, pos);
    comp.erase(0, pos+1);
    std::stringstream sp(temp);
    sp >> powerDrain;

    std::stringstream su(comp);
    su >> unknown;

    for (int i = 0; i < trainSize; ++i)
    {
        if(design[i] == NULL)
        {
            switch(type)
            {
                case 'C': case 'c':
                   design[i] = new cargo(type, weight, cost, powerDrain, unknown);
                return i;

                case 'P': case 'p':
                    design[i] = new passenger(type, weight, cost, powerDrain, unknown);
                return i;

                case 'L': case 'l':
                    design[i] = new locomotive(type, weight, cost, powerDrain, unknown);
                return i;
            }
        }
    }

    return -1;
}

int train::removeComponent()
{
    if(this->trainSize == 0) return -1;

    for (int i = 0; i < this->trainSize; ++i)
    {
        if(this->design[i] != NULL)
        {
            delete design[i];
            design[i] = NULL;
            return i;
        }
    }

    return -1;
}
