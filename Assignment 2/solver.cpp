#include "solver.h"
using namespace std;

solver::solver(string games)
{
    numGames=0;
    int pos = 0, place = 0;
    string line, temp;
    ifstream inFile(games.c_str());

    if(inFile)
    {
        while(getline(inFile, line))
        {
            numGames++;
        }
    }

    boards = new board*[numGames];
    int* priorities = new int[numGames];
    for (int i = 0; i < numGames; ++i)
    {
        boards[i] = NULL;
        priorities[i] = 0;
    }

    ifstream readFile(games.c_str());
    if(readFile)
    {
        while(getline(readFile, line))
        {
            temp = line.substr(line.find(',')+1);
            stringstream ss(temp);
            ss >> priorities[place];

            pos = line.find(',');
            line.erase(pos, 2);
            boards[place] = new board(line);

            place++;
        }
    }

    for (int i = 0; i < numGames; ++i)
    {
        pos = 999;
        int val = 999;
        for (int j = 0; j < numGames; ++j)
        {
            if(priorities[j] < val)
            {
                val = priorities[j];
                pos = j;
            }
        }

        cout << "[" << priorities[pos] << "] ";
        --*boards[pos];

        priorities[pos] = 9999;
    }

    delete[] priorities;
}

solver::~solver()
{
    for (int i = 0; i < numGames; ++i)
    {
        delete boards[i];
    }
    delete[] boards;
    boards = NULL;

    cout << "Num Boards Deleted: " << numGames << endl;
}
