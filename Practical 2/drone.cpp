#include "drone.h"
using namespace std;

drone::drone(string name, string type, int hp, double energy)
{
    this->name = name;
    this-> type = type;
    this->hp = hp;
    this->energy = energy;
};

drone::~drone()
{
    cout << this->name + " deleted" << endl;
}

string drone::getName()
{
    return this->name;
}

string drone::getType()
{
    return this->type;
}

int drone::getHP()
{
    return this->hp;
}

double drone::getEnergy()
{
    return this->energy;
}

void drone::print()
{
    cout << "Name: " + this->name << endl;
    cout << "Type: " + this->type << endl;
    cout << "HP: " + to_string(this->hp) << endl;
    int energy = this->energy;
    cout << "Energy: " + to_string(energy) << endl;
}
