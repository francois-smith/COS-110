#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//starting variables
string line = "";
int rows = 0, cols = 0, r = 0, c = 0, row;

int main()
{
  //Sets input file variable
  ifstream inFile("data.txt");

//check if input file is vallid
  if(inFile)
  {
    //first pass over all lines to get amount of rows
    //to create first part if dynamic array
    while(getline(inFile, line))
    {
      rows ++;
    }
  }

  //creates the double pointer to rows
  string** dataArray = new string*[rows];
  //creates another dynamic array to store amount of cols for each row
  int* rowSizes = new int[rows];

  //resets the input file for another read cycle
  ifstream inFile2("data.txt");

  if(inFile2)
  {
    r = 0;
    //for every line until end of document
    while (getline(inFile2, line))
    {
      //counter for amount of columns
      cols = 0;

      stringstream s1(line);
      vector<string> v1;
      //loop through line to find the commas and amount of columns to create
      while(s1.good())
      {
        string num;
        getline(s1, num, ',');
        stringstream s2(num);
        v1.push_back(num);
        cols++;
      }

      //create array of strings pointed to by dynamic row
      dataArray[r] = new string[cols];
      //sets  column amount in 1D dynamic array
      rowSizes[r] = cols;

      //preps for second pass through of line to actually store the values of
      //the line into respective places
      c = 0;
      stringstream s3(line);
      vector<string> v2;

      while(s3.good())
      {
        string val;
        getline(s3, val, ',');
        stringstream s4(val);
        v2.push_back(val);
        //adds item to S2D array
        s4 >> dataArray[r][c];
        c++;
      }
      r++;
    }


    string* hold;
    int temp;
    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < rows-1; j++)
        {
          if(stoi(dataArray[i][0])<stoi(dataArray[j][0]))
          {
            hold = dataArray[j];
            dataArray[j] = dataArray[i];
            dataArray[i] = hold;

            temp = rowSizes[j];
            rowSizes[j] = rowSizes[i];
            rowSizes[i] = temp;
          }
        }
    }

    for (r = 0; r < rows; r++)
    {
      line = "";
      for (c = 0; c < rowSizes[r]; c++)
      {
        line = line + dataArray[r][c] + ",";
      }
      string output = line.substr(0, line.size()-1);
      //line = line + dataArray[r][];
      cout << output << endl;
    }

    //Deletes columns of the 2D array
    for(int i = 0; i < rows; i++)
    {
        delete[] dataArray[i];
    }

    //Deletes the 2D  array
    delete[] dataArray;
    //Deletes the 1D array that hold amount of columns of each row
    delete[] rowSizes;
  }

  return 0;
}
