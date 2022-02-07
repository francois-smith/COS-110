#ifndef ASSIGNMENT_4_LAYER_H
#define ASSIGNMENT_4_LAYER_H
#define override;

#include <string>
#include <sstream>
#include <iostream>
#include "Message.h"

struct config{
    std::string encoding;
    std::string ip;
    std::string port;
    std::string DestIP;
    std::string computerName;
    std::string DestPort;
};

class Layer {
protected:
    std::string computerName;
    Layer* up;
    Layer* down;
public:
    Layer();
    virtual void execute(Message* message, bool sending = true)=0;
    virtual ~Layer();
    void setUp(Layer* up);
    virtual void configure(config settings);
    virtual void link(Layer* linkStack);
    Layer* getDown();
};

#endif //ASSIGNMENT_4_LAYER_H
