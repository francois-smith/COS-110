#include <iostream>
#include "train.h"

int main() {
    train* Train = new train(5);

    Train->addComponent("l,90.1,775.1,14,1000");
    std::cout << *Train << std::endl;

    delete Train;
    return 0;
}
