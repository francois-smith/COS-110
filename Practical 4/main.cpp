#include <iostream>
#include "tome.h"
using namespace std;

int main()
{
    string* list1 = new string[3];
    list1[0] = "Hex Curse";
    list1[1] = "Summon Ice Golem";
    list1[2] = "Fireball Theory";

    string* list2 = new string[2];
    list2[0] = "Summon Ice Golem";
    list2[1] = "Fireball Theory";

    tome* tome1 = new tome("Hexes and Incantations, A Study", 3, "Swaddles, D. Pines", list1);
    tome* tome2 = new tome("Hexes and Incantations, A Study", 2, "Swaddles, D. Pines", list2);

    tome* tomeEqual = tome2;
    *tomeEqual + "IceVein";

    cout << *tomeEqual << endl;

    delete tome1;
    delete tome2;
    delete[] list1;
    delete[] list2;
}
