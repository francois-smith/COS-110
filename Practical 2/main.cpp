#include "drone.h"
#include "factory.h"

int main()
{
    drone* drone1 = new drone("Mega Tank Drone", "Tank", 300, 1000);
    drone* drone2 = new drone("Small Tank", "Tank", 50, 200);
    drone* drone3 = new drone("Commander Drone", "Rover", 500, 2000);

    factory* testFactory = new factory("001", "001", 10);

    testFactory->levelUp();

    cout << testFactory->addDrone(drone1) << endl;
    cout << testFactory->addDrone(drone2) << endl;
    cout << testFactory->addDrone(drone3) << endl;

    testFactory->printDrones("m");

    delete testFactory;
    return 0;
}
