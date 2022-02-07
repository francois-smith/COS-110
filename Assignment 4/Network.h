#ifndef ASSIGNMENT_4_NETWORK_H
#define ASSIGNMENT_4_NETWORK_H

#include "Layer.h"
#include "Datalink.h"

class Network : public Layer{
private:
    std::string ip;
    std::string DestIP;
public:
    Network();
    void execute(Message *message, bool sending = true) override;
    void configure(config settings) override;
};

#endif //ASSIGNMENT_4_NETWORK_H
