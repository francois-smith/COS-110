#ifndef PRAC_8_DLIST_H
#define PRAC_8_DLIST_H

#include <cstdlib>
#include "train.h"
#include "trainCar.h"
#include "dispatch.h"

class dList;
std::ostream& operator<<(std::ostream& output, const dList& t);

class dList {
private:
    dispatch* head;
    int size;
    int rS;
public:
    dList(int rS);
    ~dList();
    dispatch* getHead() const;
    int getSize() const;
    dispatch* getItem(int i);
    std::string firstOrder();
    friend std::ostream& operator<<(std::ostream& output, const dList& t);
    void addOrder(std::string newOrder);
    void validateTrain();
    void shuffleOrders();
};

#endif //PRAC_8_DLIST_H
