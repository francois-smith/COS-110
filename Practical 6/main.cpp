#include <iostream>
#include "manager.h"
#include "trolley.h"
#include "train.h"
#include "tooFast.h"
#include "tooSlow.h"
int main()
{
    manager<int> karl("input.txt");

    cout << "====Manager Summarise Function====" << endl;
    karl.summarise();

    cout << "====load 23 to capacity of 24====" << endl;
    karl.loadTrain(0,23);

    cout << "====Overload train====" << endl;
    karl.loadTrain(1,50);

    cout << "====Test Trolley Time====" << endl;
    trolley wheeley("Woolworths Trolley");

    cout << "====Speed is too fast====" << endl;
    int speed = 10000;
    try
    {
        if (speed > 100) throw tooFast();
        if (speed < 20) throw tooSlow();

        wheeley.increaseSpeed(speed);
    }
    catch (tooFast& e)
    {
        cout << e.what();
    }
    catch (tooSlow& e)
    {
        cout << e.what();
    }

    cout << wheeley.getSpeed() << endl;

    cout << "====Speed is too slow====" << endl;
    int speed2 = 10;
    try
    {
        if (speed2 > 100) throw tooFast();
        if (speed2 < 20) throw tooSlow();

        wheeley.increaseSpeed(speed);
    }
    catch (tooFast& e)
    {
        cout << e.what();
    }
    catch (tooSlow& e)
    {
        cout << e.what();
    }

    cout << wheeley.getSpeed() << endl;

    cout << "====Speed is allowed====" << endl;
    int speed3 = 50;
    try
    {
        if (speed3 > 100) throw tooFast();
        if (speed3 < 20) throw tooSlow();

        wheeley.increaseSpeed(speed3);
    }
    catch (tooFast& e)
    {
        cout << e.what();
    }
    catch (tooSlow& e)
    {
        cout << e.what();
    }
    cout << wheeley.getSpeed() << endl;
    return 0;
}
