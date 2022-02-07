#ifndef PRAC6_TROLLEY_H
#define PRAC6_TROLLEY_H

#include <string>

class trolley {
private:
    int speed;
    std::string name;
public:
    trolley();
    ~trolley();
    trolley(std::string name);
    int getSpeed();
    void increaseSpeed(int s);
};

#endif //PRAC6_TROLLEY_H
