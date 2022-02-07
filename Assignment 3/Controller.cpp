#include "Controller.h"
using namespace std;

Controller::Controller(std::string filePath)
{
    string line, tempNum, tempId, tempType;
    int pos, index = 0;

    ifstream inFile(filePath.c_str());
    if(inFile)
    {
        getline(inFile, line);
        tempNum = line.substr(line.find(':') + 1);
        stringstream sn(tempNum);
        sn >> numBabushkas;

        babushkaArr = new Babushka*[numBabushkas];
        for (int i = 0; i < numBabushkas; ++i)
        {
            babushkaArr[i] = NULL;
        }

        while(getline(inFile, line))
        {
            pos = line.find(':');
            tempType = line.substr(0, pos);
            line.erase(0, pos+1);

            pos = line.find(':');
            tempId = line.substr(0, pos);
            line.erase(0, pos+1);

            unsigned char* arr = new unsigned char[10];
            for(int i =0; i < 10; i++)
            {
                arr[i] = tempId[i];
            }


            if(tempType == "gold")
            {
                unsigned char xorValue = line[0];
                babushkaArr[index] = new GoldBabushka(arr, xorValue);
            }

            if(tempType == "yellow")
            {
                babushkaArr[index] = new YellowBabushka(arr);
            }

            if(tempType == "green")
            {
                unsigned int displacement;
                stringstream sd(line);
                sd >> displacement;
                babushkaArr[index] = new GreenBabushka(arr, displacement);
            }

            if(tempType == "red")
            {
                unsigned int rotation;
                stringstream sr(line);
                sr >> rotation;
                babushkaArr[index] = new RedBabushka(arr, rotation);
            }

            if(tempType == "lightblue")
            {
                unsigned int amount;
                stringstream sa(line);
                sa >> amount;
                babushkaArr[index] = new LightBlueBabushka(arr, amount);
            }

            if(tempType == "darkblue")
            {
                unsigned int amount;
                stringstream sa(line);
                sa >> amount;
                babushkaArr[index] = new DarkBlueBabushka(arr, amount);
            }

            index++;
        }
    }
}

Controller::~Controller()
{
    for (int i = 0; i < this->numBabushkas; ++i)
    {
        if(this->babushkaArr[i] != NULL)
        {
            delete babushkaArr[i];
            babushkaArr[i] = NULL;
        }
    }
    delete[]  babushkaArr;
    babushkaArr = NULL;
}

ReturnStruct Controller::decrypt(const unsigned char* array, int size)
{
    try
    {
        ReturnStruct returnStruct;
        unsigned char* decryptionArray = new unsigned char[size];
        for (int i = 0; i < size; ++i)
        {
            decryptionArray[i] = array[i];
        }

        returnStruct.returnArray = decryptionArray;
        returnStruct.arraySize = size;

        printArray(returnStruct.returnArray, size);

        for (int i = numBabushkas - 1; i > -1; --i)
        {
            babushkaArr[i]->decrypt(returnStruct.returnArray, returnStruct.arraySize);
            returnStruct = reduceArray(returnStruct.returnArray, returnStruct.arraySize,babushkaArr[i]->getId(), babushkaArr[i]->getIdLength());
            printArray(returnStruct.returnArray, returnStruct.arraySize);
        }

        return returnStruct;
    }
    catch(BabushkaException& e)
    {
        throw ControllerException(e, "decrypt exception");
    }
}

ReturnStruct Controller::encrypt(const unsigned char *array, int size)
{
    try
    {
        ReturnStruct returnStruct;
        unsigned char* encryptionArr = new unsigned char[size];
        for (int i = 0; i < size; ++i)
        {
            encryptionArr[i] = array[i];
        }

        returnStruct.returnArray = encryptionArr;
        returnStruct.arraySize = size;

        printArray(returnStruct.returnArray, size);

        for (int i = 0; i < numBabushkas; ++i)
        {
            returnStruct = expandArray(returnStruct.returnArray, returnStruct.arraySize,babushkaArr[i]->getId(), babushkaArr[i]->getIdLength());
            babushkaArr[i]->encrypt(returnStruct.returnArray, returnStruct.arraySize);
            printArray(returnStruct.returnArray, returnStruct.arraySize);
        }

        return returnStruct;
    }
    catch(BabushkaException& e)
    {
        throw ControllerException(e, "encrypt exception");
    }
}

ReturnStruct Controller::expandArray(unsigned char* array, int currentSize, const unsigned char *id, int idSize)
{
    int newSize = currentSize+(idSize*2);
    ReturnStruct returnStruct;
    unsigned char* newArray = new unsigned char[newSize];
    for (int i = 0; i < idSize; ++i)
    {
        newArray[i] = id[i];
    }

    for (int i = 10; i < currentSize+idSize; ++i)
    {
        newArray[i] = array[i-10];
    }

    for (int i = currentSize+idSize; i < currentSize+20; ++i)
    {
        newArray[i] = id[i-currentSize-10];
    }

    returnStruct.arraySize = newSize;
    returnStruct.returnArray = newArray;

    delete[] array;
    array = NULL;

    return returnStruct;
}

ReturnStruct Controller::reduceArray(unsigned char *array, int currentSize, const unsigned char* expectedId, int idSize)
{
    ReturnStruct returnStruct;
    int newSize = currentSize - (idSize*2);
    if(newSize < 0)
    {
        throw ControllerException("size exception");
    }
    else
    {
        for (int i = 0; i < idSize; ++i)
        {
            if(array[i] != expectedId[i])
            {
                throw ControllerException("id mismatch exception");
            }
        }

        unsigned char* newArray = new unsigned char[newSize];
        for (int i = 10; i < currentSize - 10; ++i)
        {
            newArray[i-10] = array[i];
        }

        returnStruct.returnArray = newArray;
        returnStruct.arraySize = newSize;

        delete[] array;
        array = NULL;

        return returnStruct;
    }
}

void Controller::printArray(unsigned char* array, int size)
{
    string outputString;
    for (int i = 0; i < size; ++i)
    {
        outputString += array[i];
        outputString += ',';
    }
    outputString.erase(outputString.size()-1, 1);

    cout << "[" << outputString << "]" << endl;
}
