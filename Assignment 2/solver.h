#ifndef ASSIGNMENT_2_SOLVER_H
#define ASSIGNMENT_2_SOLVER_H

#include "board.h"

class solver {
private:
    int numGames;
    board** boards;
public:
    solver(std::string games);
    ~solver();
};

#endif //ASSIGNMENT_2_SOLVER_H
