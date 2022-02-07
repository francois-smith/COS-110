#include "train.h"

train::train(std::string config)
{
    std::string copy = config;
    int pos, val = 0;
    head = NULL;

    std::string temp;
    while ((pos = copy.find(',')) != std::string::npos)
    {
        temp = copy.substr(0, pos);
        std::stringstream ss(temp);
        ss >> val;
        trainCar* newCar = new trainCar(val);
        if(!head)
        {
            head = newCar;
        }
        else
        {
            trainCar* trainPtr = head;
            while(trainPtr->next)
            {
                trainPtr = trainPtr->next;
            }
            trainPtr->next = newCar;
        }
        copy.erase(0, pos + 1);
    }


    std::stringstream ss(copy);
    ss >> val;
    trainCar* newCar = new trainCar(val);
    if(!head)
    {
        head = newCar;
    }
    else
    {
        trainCar* trainPtr = head;
        while(trainPtr->next)
        {
            trainPtr = trainPtr->next;
        }
        trainPtr->next = newCar;
    }
}

train::~train()
{
    trainCar* trainPtr = head;
    while(trainPtr)
    {
        head = head->next;
        delete trainPtr;
        trainPtr = head;
    }
}

int train::calcTotalCost()
{
    int total = 0;
    trainCar* trainPtr = head;
    while (trainPtr)
    {
        total += trainPtr->getCost();
        trainPtr = trainPtr->next;
    }

    std::cout << "Total Train Cost: " << total << std::endl;
    return total;
}

void train::addCar(int newCost)
{
    trainCar* newCar = new trainCar(newCost);
    if(!head)
    {
        head = newCar;
    }
    else
    {
        trainCar* trainPtr = head;
        while(trainPtr->next)
        {
            trainPtr = trainPtr->next;
        }
        trainPtr->next = newCar;
    }

    this->size++;
}
