#include "dList.h"

using namespace std;

int main() {
    dList* d = new dList(1234);

    d->addOrder("11");
    d->addOrder("4,5,6");
    d->addOrder("7,8");
    d->addOrder("1,2,3");

    cout << *d;
    d->shuffleOrders();
    cout << *d;

    for (int k = 0; k < 5; k++) {
        d->validateTrain();
    }
    delete d;
    return 0;
}
/*
7,8,4,5,6,11,1,2,3
11,1,2,3,7,8,4,5,6
Total Train Cost: 11
Valid
11 processed
11 removed
Total Train Cost: 6
Valid
1,2,3 processed
1 removed
2 removed
3 removed
Total Train Cost: 15
Valid
7,8 processed
7 removed
8 removed
Total Train Cost: 15
Valid
4,5,6 processed
4 removed
5 removed
6 removed
Invalid
*/