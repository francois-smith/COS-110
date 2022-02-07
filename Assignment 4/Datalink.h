#ifndef ASSIGNMENT_4_DATALINK_H
#define ASSIGNMENT_4_DATALINK_H

#include "Layer.h"
#include "Physical.h"

class Datalink : public Layer{
public:
    Datalink();
    void execute(Message *message, bool sending = true) override;
};

#endif //ASSIGNMENT_4_DATALINK_H
