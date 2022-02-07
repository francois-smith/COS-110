#ifndef FACTORY_H
#define  FACTORY_H

#include "drone.h"
#include <string>

class factory
{
private:
    drone** list;
    std::string fID;
    std::string oID;
    int level = 1;
    int droneLimit;
    int currNumDrones;
public:
    factory(std::string fID, std::string oID, int droneLimit);
    factory(std::string fID, std::string oID, drone** drones, int droneLimit, int currNumDrones);
    ~factory();
    void levelUp();
    int addDrone(drone *d);
    int removeDrone(std::string name);
    std::string getFID();
    std::string getOID();
    int getCurrSize();
    int getLimit();
    void printDrones(std::string s);
};
#endif
