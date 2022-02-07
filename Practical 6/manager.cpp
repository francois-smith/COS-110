#ifndef PRAC6_MANAGER_CPP
#define PRAC6_MANAGER_CPP

#include "manager.h"

template<class T>
manager<T>::manager(std::string input)
{
    string line, temp, name;
    T max = 0, index = 0;

    fstream inFile(input.c_str());
    if(inFile)
    {
        getline(inFile, line);
        stringstream ss(line);
        ss >> this->numTrains;

        trains = new train<T>*[numTrains];
        for (int i = 0; i < numTrains; ++i)
        {
            trains[i] = NULL;
        }

        while (getline(inFile, line))
        {
            temp = line.substr(line.find(',') + 1);
            stringstream sm(temp);
            sm >> max;

            name = line.substr(0, line.find(','));
            trains[index] = new train<T>(name, max);

            index++;
        }
    }
}

template<class T>
manager<T>::~manager()
{
    for (int i = 0; i < numTrains; ++i)
    {
        delete trains[i];
        trains[i] = NULL;
    }

    delete[] trains;
    trains = NULL;
}

template<class T>
void manager<T>::summarise()
{
    T total = 0;

    for (int i = 0; i < numTrains; ++i)
    {
         total += trains[i]->getCargoCap();
    }

    cout << "Total Current Storage: " << total << endl;
}

template<class T>
void manager<T>::loadTrain(int i, T load)
{
    if(i > numTrains || i < 0) return;
    else
    {
        trains[i]->loadCargo(load);
    }
}

#endif //PRAC6_MANAGER_CPP
