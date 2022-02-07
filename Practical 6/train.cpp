#ifndef PRAC6_TRAIN_CPP
#define PRAC6_TRAIN_CPP

#include "train.h"
#include "storageFull.h"
#include "storageEmpty.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
train<T>::train()
{

}

template<class T>
train<T>::~train()
{
    cout << "Dispatch Name: " << this->name << endl;
    cout << "Current Storage: " << this->currStorage << endl;
    cout << "Storage Max: " << this->storageCap << endl;
}

template<class T>
train<T>::train(std::string name, T storageCap) {
    this->name = name;
    this->currStorage = 0;
    this->storageCap = storageCap;
}

template<class T>
std::string train<T>::getName()
{
    return this->name;
}

template<class T>
T train<T>::getCargoCap()
{
    return this->storageCap;
}

template<class T>
T train<T>::getCurrCargo()
{
    return this->currStorage;
}

template<class T>
void train<T>::loadCargo(T cargo)
{
    if(this->currStorage + cargo > this->storageCap)
    {
        throw storageFull();
    }
    else
    {
        this->currStorage += cargo;
    }

    cout << "Capacity: " << this->currStorage << endl;
}

template<class T>
void train<T>::unloadCargo(T cargo)
{
    if(this->currStorage < cargo)
    {
        throw storageEmpty();
    }
    else
    {
        this->currStorage -= cargo;
    }

    cout << "Capacity: " << this->currStorage << endl;
}

#endif //PRAC6_TRAIN_CPP
