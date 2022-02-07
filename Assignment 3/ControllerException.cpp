#include "ControllerException.h"
using namespace std;

ControllerException::ControllerException(std::string customMessage)
{
    this->hasBabushka = false;
    this->customMessage = customMessage;
    this->babushkaException = 0;
}

ControllerException::ControllerException(BabushkaException& babushkaException, std::string customMessage)
{
    this->customMessage = customMessage;
    this->babushkaException = &babushkaException;
    this->hasBabushka = true;
}

void ControllerException::printMessage()
{
    cout << customMessage << endl;
    if(hasBabushka && this->babushkaException != 0)
    {
        this->babushkaException->printMessage();
    }
}
