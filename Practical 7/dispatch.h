#ifndef PRAC_8_DISPATCH_H
#define PRAC_8_DISPATCH_H

#include <string>
#include <iostream>

class dispatch {
private:
    std::string order;
public:
    dispatch* next;
    dispatch(std::string o);
    ~dispatch();
    std::string getOrder();
};

#endif //PRAC_8_DISPATCH_H
