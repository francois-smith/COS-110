#ifndef ASSIGNMENT_2_BOARD_H
#define ASSIGNMENT_2_BOARD_H

#include "piece.h"
#include <fstream>

class board {
private:
    int numWhitePieces;
    int numBlackPieces;
    piece** whitePieces;
    piece** blackPieces;
    std::string** chessboard;
    std::string move;
    char sideToMove;
    board& operator++();

public:
    board(std::string pieceList);
    ~board();
    board& operator--();
    bool checkIfPieceHasCheck(std::string pieceType, int xPos, int yPos, int kingX, int kingY);
};

#endif //ASSIGNMENT_2_BOARD_H
