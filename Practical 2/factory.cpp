#include "factory.h"
using namespace std;

factory::factory(string fID, string oID, int droneLimit)
{
    this->fID = fID;
    this->oID = oID;
    this->droneLimit = droneLimit;
    this->level = 1;
    this->currNumDrones = 0;
    list = new drone*[droneLimit];
    for(int i = 0; i < this->droneLimit; i++)
    {
        list[i] = nullptr;
    }
}

factory::factory(string fID, string oID, drone** drones, int droneLimit, int currNumDrones)
{
    this->fID = fID;
    this->oID = oID;
    this->level = 1;
    this->droneLimit = droneLimit;
    this->currNumDrones = currNumDrones;

    list = new drone*[droneLimit];
    for(int i = 0; i < currNumDrones; i++)
    {
        this->list[i] = drones[i];
    }
}

factory::~factory()
{
    for(int i = 0; i < this->droneLimit; i++)
    {
        if(this->list[i] != nullptr)
        {
            delete list[i];
            list[i] = nullptr;
        }
    }
    delete[] list;
    list = nullptr;
}

void factory::levelUp()
{
    this->level++;
}

int factory::addDrone(drone* d)
{
    if(this->currNumDrones == this->droneLimit)
    {
        return -1;
    }
    else
    {
        for(int i = 0; i < this->droneLimit; i++)
        {
            if(this->list[i] == nullptr)
            {
                this->currNumDrones++;
                list[i] = new drone(d->getName(), d->getType(), d->getHP()*this->level, d->getEnergy()*this->level);
                return i;
            }
        }
    }

    return -1;
}

int factory::removeDrone(string name)
{
    int index = -1;

    for(int i = 0; i < droneLimit; i++)
    {
        if(this->list[i] != nullptr)
        {
            if(this->list[i]->getName() == name)
            {
                delete this->list[i];
                this->list[i] = nullptr;
                this->currNumDrones--;
                return i;
            }
        }
    }

    return index;
}

string factory::getFID()
{
    return this->fID;
}

string factory::getOID()
{
    return this->oID;
}

int factory::getCurrSize()
{
    return this->currNumDrones;
}

int factory::getLimit()
{
    return this->droneLimit;
}

void factory::printDrones(string s)
{
    cout << "Factory ID: " + this->fID << endl;
    cout << "OID: " + this->oID << endl;
    cout << "Number of Drones: " + to_string(currNumDrones) << endl;
    cout << "Drone Limit: " + to_string(this->droneLimit) << endl;

    string rank = "";
    for(int i = 0; i < this->level; i++)
    {
        rank = rank + "*";
    }
    cout << "Rank: " + rank << endl;

    if(currNumDrones != 0)
    {
        int energy = 0;
        for(int i = 0; i < this->droneLimit; i++)
        {
            if(this->list[i] != nullptr)
            {
                energy = energy + this->list[i]->getEnergy();
            }
        }
        cout << "Energy Level: " + to_string(energy) << endl;

        if((s != "hp") && (s != "m"))
        {
            return;
        }

        string* names = new string[this->currNumDrones];
        int* hps = new int[this->currNumDrones];
        int* energies = new int[this->currNumDrones];
        int index = 0;

        for(int i = 0; i < this->droneLimit; i++)
        {
            if(this->list[i] != nullptr)
            {
                names[index] = this->list[i]->getName();
                hps[index] = this->list[i]->getHP();
                energies[index] = this->list[i]->getEnergy();
                index++;
            }
        }

        if(s == "hp")
        {
            for(int i = 0; i < this->currNumDrones; i++)
            {
                for(int j = i + 1; j < this->currNumDrones; j++)
                {
                    string temp;
                    if(hps[j] < hps[i])
                    {
                        temp = names[i];
                        names[i] = names[j];
                        names[j] = temp;
                    }
                }
            }
        }

        if(s == "m")
        {
            for(int i = 0; i < this->currNumDrones; i++)
            {
                for(int j = i + 1; j < this->currNumDrones; j++)
                {
                    string temp;
                    if(energies[j] > energies[i])
                    {
                        temp = names[i];
                        names[i] = names[j];
                        names[j] = temp;
                    }
                }
            }
        }

        for(int i = 0; i < this->currNumDrones; i++)
        {
            cout << names[i] << endl;
        }

        delete[] hps;
        delete[] energies;
        delete[] names;
    }
}
