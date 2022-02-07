#ifndef ASSIGNMENT_4_TRANSPORT_H
#define ASSIGNMENT_4_TRANSPORT_H

#include "Layer.h"
#include "Network.h"

class Transport : public Layer{
private:
    std::string port;
    std::string DestPort;
public:
    Transport();
    void execute(Message *message, bool sending = true) override;
    void configure(config settings) override;
};

#endif //ASSIGNMENT_4_TRANSPORT_H
