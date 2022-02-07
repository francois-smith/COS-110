#ifndef ASSIGNMENT_4_PHYSICAL_H
#define ASSIGNMENT_4_PHYSICAL_H

#include "Layer.h"

class Physical : public Layer{
private:
    Physical* next;
public:
    Physical();
    void execute(Message *message, bool sending = true) override;
    ~Physical();
    void link(Layer* LinkStack);
    Physical* getNext();
    void setNext(Physical* newNext);
    void configure(config settings) override;
};

#endif //ASSIGNMENT_4_PHYSICAL_H
