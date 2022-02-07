#ifndef ASSIGNMENT_2_PIECE_H
#define ASSIGNMENT_2_PIECE_H

#include <string>
#include <iostream>
#include <sstream>

class piece;
std::ostream& operator<<(std::ostream& output, const piece& t);

class piece {
private:
    std::string pieceType;
    char side;
    int xPos;
    int yPos;
public:
    piece();
    piece(piece* newPiece);
    piece(std::string pType, char side, int x, int y);
    ~piece();
    char getSide();
    std::string getPieceType();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    friend std::ostream& operator<<(std::ostream& output, const piece& t);
    void operator[](int pos);
    piece& operator+(std::string move);
};

#endif //ASSIGNMENT_2_PIECE_H
