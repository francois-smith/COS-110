#ifndef ASSIGNMENT_4_PRESENTATION_H
#define ASSIGNMENT_4_PRESENTATION_H

#include "Layer.h"
#include "Transport.h"

class Presentation : public Layer{
private:
    std::string encoding;
public:
    Presentation();
    void execute(Message *message, bool sending = true) override;
    void configure(config settings) override;
};

#endif //ASSIGNMENT_4_PRESENTATION_H
