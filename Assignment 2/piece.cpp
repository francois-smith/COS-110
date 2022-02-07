#include "piece.h"
using namespace std;

piece::piece()
{

}

piece::piece(piece* newPiece)
{
    this->pieceType = newPiece->pieceType;
    this->side = newPiece->side;
    this->xPos = newPiece->xPos;
    this->yPos = newPiece->yPos;
}

piece::piece(std::string pType, char side, int x, int y)
{
    this->pieceType = pType;
    this->side = side;
    this->xPos = x;
    this->yPos = y;
}

piece::~piece()
{
    cout << "(" << xPos << "," << yPos << ") " << side << " " << pieceType << " deleted" << endl;
}

char piece::getSide()
{
    return side;
}

std::string piece::getPieceType()
{
    return pieceType;
}

int piece::getX()
{
    return xPos;
}

int piece::getY()
{
    return yPos;
}

void piece::setX(int x)
{
    this->xPos = x;
}

void piece::setY(int y)
{
    this->yPos = y;
}

void piece::operator[](int pos)
{
    if(pos < 0 || pos > 1)
    {
        cout << "Invalid Index" << endl;
        return;
    }

    if(pos == 0)
    {
        cout << "x coord: " << xPos << endl;
    }

    if(pos == 1)
    {
        cout << "y coord: " << yPos << endl;
    }
}

piece& piece::operator+(string move)
{
    string xTemp, yTemp;
    int x, y;
    yTemp = move.substr(move.find(',') + 1);
    int pos = move.find(',');
    xTemp = move.substr(0, pos);

    istringstream sx(xTemp);
    istringstream sy(yTemp);
    sx >> x;
    sy >> y;

    if((x >= 0 && x <= 7) && (y >= 0 && y <= 7))
    {
        this->xPos = x;
        this->yPos = y;
        return *this;
    }
    else
    {
        return *this;
    }
}

std::ostream& operator<<(std::ostream& output, const piece& t)
{
    output << t.side << " " << t.pieceType << " at " << "[" << t.xPos << "," << t.yPos << "]" << endl;
    return output;
}