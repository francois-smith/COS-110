#include "dList.h"

dList::dList(int rS)
{
    this->head = NULL;
    this->size = 0;
    this->rS = rS;
    srand(this->rS);
}

dList::~dList()
{
    dispatch* listPtr = head;
    while(listPtr)
    {
        head = head->next;
        delete listPtr;
        listPtr = head;
    }
}

dispatch *dList::getHead() const
{
    return this->head;
}

int dList::getSize() const
{
    return this->size;
}

dispatch* dList::getItem(int i)
{
    if(this->size == 0 || i < 0 || i > this->size) return NULL;
    else
    {
        dispatch* listPtr = head;
        for (int j = 0; j < i; ++j)
        {
            listPtr = listPtr->next;
        }

        return listPtr;
    }
}

std::string dList::firstOrder()
{
    std::string first = "90928989089082098439082498290482042";

    if(!head)
    {
        return first;
    }
    else
    {
        dispatch* listPtr = head;
        while (listPtr)
        {
            if(listPtr->getOrder() < first)
            {
                first = listPtr->getOrder();
            }
            listPtr = listPtr->next;
        }

        return first;
    }
}

std::ostream &operator<<(std::ostream& output, const dList& t)
{
    std::string sOutput;

    dispatch* listPtr = t.head;
    while (listPtr)
    {
        sOutput = sOutput + listPtr->getOrder();
        listPtr = listPtr->next;
        sOutput += ',';
    }
    sOutput.erase(sOutput.length() - 1, 1);

    output << sOutput << std::endl;
    return output;
}

void dList::addOrder(std::string newOrder)
{
    dispatch* newNode = new dispatch(newOrder);
    dispatch* listPtr = head;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        if(newOrder <= firstOrder())
        {
            while (listPtr->next)
            {
                listPtr = listPtr->next;
            }
            listPtr->next = newNode;
        }
        else
        {
            listPtr = head;
            head = newNode;
            newNode->next = listPtr;
        }
    }

    size++;
}

void dList::validateTrain()
{
    if (head == NULL)
    {
        std::cout << "Invalid" << std::endl;
        return;
    }

    dispatch* temp = head;
    head = head->next;

    train* Train = new train(temp->getOrder());
    if(Train->calcTotalCost() < 50)
    {
        std::cout << "Valid" << std::endl;
    }
    else
    {
        std::cout << "Invalid" << std::endl;
    }

    delete temp;
    delete Train;
}

void dList::shuffleOrders()
{
    int num = rand()% this->size;

    dispatch* listPtr = head;
    dispatch* oldList = head;

    if (num > 1)
    {
        for (int i = 1; i <= num; ++i) {
            listPtr = listPtr->next;
        }
        head = listPtr;

        while (listPtr->next)
        {
            listPtr = listPtr->next;
        }
        listPtr->next = oldList;

        for (int i = 1; i <= num-1; ++i) {
            oldList = oldList->next;
        }
        oldList->next = NULL;
    }
}
