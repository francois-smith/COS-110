#ifndef ASSIGNMENT_4_APPLICATION_H
#define ASSIGNMENT_4_APPLICATION_H

#include "Layer.h"
#include "Presentation.h"

class Application : public Layer{
public:
    Application();
    void execute(Message *message, bool sending = true) override;
    void execute(std::string data, int contentLength);
};

#endif //ASSIGNMENT_4_APPLICATION_H
