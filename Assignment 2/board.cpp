#include "board.h"
using namespace std;

board& board::operator++()
{
    string temp;
    int pos, pieceX, pieceY, newX, newY;

    pos = move.find(',');
    temp = move.substr(0, pos);
    move.erase(0, pos + 1);
    stringstream spx(temp);
    spx >> pieceX;

    pos = move.find(',');
    temp = move.substr(0, pos);
    move.erase(0, pos + 1);
    stringstream spy(temp);
    spy >> pieceY;


    pos = move.find(',');
    temp = move.substr(0, pos);
    move.erase(0, pos + 1);
    stringstream snx(temp);
    snx >> newX;

    stringstream sny(move);
    sny >> newY;

    if(sideToMove == 'b')
    {
        for (int i = 0; i < numBlackPieces; ++i)
        {
            if(blackPieces[i]->getX() == pieceX && blackPieces[i]->getY() == pieceY)
            {
                blackPieces[i]->setX(newX);
                blackPieces[i]->setY(newY);
                break;
            }
        }
    }

    if(sideToMove == 'w')
    {
        for (int i = 0; i < numWhitePieces; ++i)
        {
            if(whitePieces[i]->getX() == pieceX &&whitePieces[i]->getY() == pieceY)
            {
                whitePieces[i]->setX(newX);
                whitePieces[i]->setY(newY);
                break;
            }
        }
    }

    return *this;
}

board::board(string pieceList)
{
    numBlackPieces = 0;
    numWhitePieces = 0;
    int currWhitePiece = 0, currBlackPiece = 0;

    string line, temp, sideTemp, typeTemp;
    int pos, xTemp, yTemp;

    chessboard = new string*[8];
    for (int i = 0; i < 8; ++i)
    {
        chessboard[i] = new string[8];
    }

    for (int r = 0; r < 8; ++r)
    {
        for (int c = 0; c < 8; ++c)
        {
            chessboard[r][c] = "-";
        }
    }

    ifstream inFile(pieceList.c_str());
    if(inFile)
    {
        getline(inFile, line);
        getline(inFile,line);

        while(getline(inFile, line)) {
            pos = line.find(',');
            sideTemp = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            typeTemp = line.substr(0, pos);
            line.erase(0, pos + 1);

            if (sideTemp[0] == 'b') {
                numBlackPieces++;
            }

            if (sideTemp[0] == 'w') {
                numWhitePieces++;
            }
        }
    }

    whitePieces = new piece*[numWhitePieces];
    blackPieces = new piece*[numBlackPieces];

    for (int i = 0; i < numWhitePieces; ++i)
    {
        whitePieces[i] = NULL;
    }
    for (int i = 0; i < numBlackPieces; ++i)
    {
        blackPieces[i] = NULL;
    }

    fstream readFile(pieceList.c_str());
    if(readFile)
    {
        getline(readFile, line);
        sideToMove = line[0];

        getline(readFile, line);
        move = line;

        while(getline(readFile, line))
        {
            pos = line.find(',');
            sideTemp = line.substr(0, pos);
            line.erase(0, pos+1);

            pos = line.find(',');
            typeTemp = line.substr(0, pos);
            line.erase(0, pos+1);

            pos = line.find(',');
            temp = line.substr(0, pos);
            line.erase(0, pos+1);
            stringstream sx(temp);
            sx >> xTemp;

            stringstream sy(line);
            sy >> yTemp;

            if(sideTemp[0] == 'b')
            {
                if(typeTemp == "king")
                {
                    chessboard[xTemp][yTemp] = "bK";
                }
                else
                {
                    chessboard[xTemp][yTemp] = "b";
                    chessboard[xTemp][yTemp].append(typeTemp, 0, 1);
                }

                blackPieces[currBlackPiece] = new piece(typeTemp, 'b', xTemp, yTemp);

                currBlackPiece++;
            }

            if(sideTemp[0] == 'w')
            {
                if(typeTemp == "king")
                {
                    chessboard[xTemp][yTemp] = "wK";
                }
                else
                {
                    chessboard[xTemp][yTemp] = "w";
                    chessboard[xTemp][yTemp].append(typeTemp, 0, 1);
                }

                whitePieces[currWhitePiece] = new piece(typeTemp, 'w', xTemp, yTemp);

                currWhitePiece++;
            }
        }
    }
}

board::~board()
{
    for (int i = 0; i < numBlackPieces; ++i)
    {
        delete blackPieces[i];
        blackPieces[i] = NULL;
    }
    delete[] blackPieces;

    for (int i = 0; i < numWhitePieces; ++i)
    {
        delete whitePieces[i];
        whitePieces[i] = NULL;
    }
    delete[] whitePieces;

    for (int i = 0; i < 8; ++i)
    {
        delete[] chessboard[i];
        chessboard[i] = NULL;
    }
    delete[] chessboard;

    int total = numWhitePieces + numBlackPieces;
    cout << "Num Pieces Removed: " << total << endl;
}

board& board::operator--()
{
    int xKing, yKing;
    ++*this;

    switch (sideToMove)
    {
        case 'w':

            for (int r = 0; r < 8; ++r)
            {
                for (int c = 0; c < 8; ++c)
                {
                    if(chessboard[r][c] == "bK")
                    {
                        xKing = r;
                        yKing = c;
                    }
                }
            }

            for(int i = 0; i < numWhitePieces; i++)
            {
                for (int r = xKing - 1; r <= xKing + 1; ++r)
                {
                    for (int c = yKing -1; c <= yKing + 1; ++c)
                    {
                        if (checkIfPieceHasCheck(whitePieces[i]->getPieceType(), whitePieces[i]->getX(), whitePieces[i]->getY(), r, c))
                        {
                            cout << "Success: Checkmate of b King at [" << xKing << "," << yKing << "]" << endl;
                            return *this;
                        }
                    }
                }
            }

            cout << "Failed: No Checkmate of b King" << endl;
            return *this;

        case 'b':

            for (int r = 0; r < 8; ++r)
            {
                for (int c = 0; c < 8; ++c)
                {
                    if(chessboard[r][c] == "wK")
                    {
                        xKing = r;
                        yKing = c;
                        break;
                    }
                }
            }

            for (int i = 0; i < numBlackPieces; ++i)
            {
                for (int r = xKing; r < 3; ++r)
                {
                    for (int c = yKing; c < 3; ++c)
                    {
                        if (checkIfPieceHasCheck(blackPieces[i]->getPieceType(), blackPieces[i]->getX(), blackPieces[i]->getY(), r, c))
                        {
                            cout << "Success: Checkmate of w King at [" << xKing << "," << yKing << "]" << endl;
                            return *this;
                        }
                    }
                }
            }

            cout << "Failed: No Checkmate of w King" << endl;
            return *this;
    }

    return *this;
}

bool board::checkIfPieceHasCheck(string pieceType, int xPos, int yPos, int kingX, int kingY)
{   
    if(pieceType == "pawn")
    {
        switch(sideToMove) {
            case 'b':

                if((xPos + 1 == kingX) && ((yPos - 1 == kingY) || (yPos + 1 == kingY)))
                {
                    return true;
                }
                return false;

            case 'w':

                if((xPos - 1 == kingX) && ((yPos - 1 == kingY) || (yPos + 1 == kingY)))
                {
                    return true;
                }
                return false;
        }
    }

    if(pieceType == "rook")
    {
        if (yPos == kingY)
        {
            return true;
        }

        if (xPos == kingX)
        {
            return true;
        }
    }

    if(pieceType == "knight")
    {
        if((xPos + 2 == kingX) && ((yPos+1 == kingY) || (yPos-1 == kingY)))
        {
            return true;
        }

        if((xPos - 2 == kingX) && ((yPos+1 == kingY) || (yPos-1 == kingY)))
        {
            return true;
        }

        if((yPos + 2 == kingY) && ((xPos+1 == kingX) || (xPos-1 == kingX)))
        {
            return true;
        }

        if((yPos - 2 == kingY) && ((xPos+1 == kingX) || (xPos-1 == kingX)))
        {
            return true;
        }

        return false;
    }

    if(pieceType == "bishop")
    {
        int temp = 1;
        if(xPos > kingX)
        {
            for (int i = xPos - 1; i >= kingX; --i)
            {
                if(i == kingX && ((yPos+temp == kingY) || (yPos-temp == kingY)))
                {
                    return true;
                }
                temp++;
            }
        }
        else
        {
            for (int i = xPos + 1; i <= kingX; ++i)
            {
                if(i == kingX && ((yPos+temp == kingY) || (yPos-temp == kingY)))
                {
                    return true;
                }
                temp++;
            }
        }
    }

    if(pieceType == "queen")
    {
        int temp = 1;
        if(xPos > kingX)
        {
            for (int i = xPos - 1; i >= kingX; --i)
            {
                if(i == kingX && ((yPos+temp == kingY) || (yPos-temp == kingY)))
                {
                    return true;
                }
                temp++;
            }
        }
        else
        {
            for (int i = xPos + 1; i <= kingX; ++i)
            {
                if(i == kingX && ((yPos+temp == kingY) || (yPos-temp == kingY)))
                {
                    return true;
                }
                temp++;
            }
        }

        if (yPos == kingY)
        {
            return true;
        }

        if (xPos == kingX)
        {
            return true;
        }

    }
    return false;
}
