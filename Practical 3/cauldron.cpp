#include "cauldron.h"
using namespace std;

cauldron::cauldron(string ingredientList, int maxIngredients)
{
    string line, nameOfIngredient, danger;

    this->maxIngredients = maxIngredients;
    this->numIngredients = 0;

    ifstream inFile(ingredientList.c_str());
    if(inFile.good())
    {
        ingredients = new ingredient*[maxIngredients];
        for (int i = 0; i < maxIngredients; i++)
        {
            ingredients[i] = NULL;
        }

        while(getline(inFile, line))
        {
            if(this->numIngredients < this->maxIngredients)
            {
                stringstream stringStreamLine(line);
                getline(stringStreamLine, nameOfIngredient, ',');

                getline(stringStreamLine, danger, ',');

                int dangerRating;
                stringstream stringStreamDanger(danger);
                stringStreamDanger >> dangerRating;

                ingredients[numIngredients] = new ingredient(nameOfIngredient, dangerRating);
                this->numIngredients++;
            }
        }
    }
}

cauldron::cauldron(const cauldron *oldCauldron)
{
    this->numIngredients = oldCauldron->numIngredients;
    this->maxIngredients = oldCauldron->maxIngredients;
    this->ingredients = new ingredient*[oldCauldron->maxIngredients];
    for (int i = 0; i < maxIngredients; i++)
    {
        if(oldCauldron->ingredients[i] != NULL)
        {
            this->ingredients[i] = new ingredient(oldCauldron->getIngredient(i)->getName(), oldCauldron->getIngredient(i)->getDanger());
        }
    }
}

void cauldron::operator=(const cauldron &oldCauldron)
{
    if(this->ingredients != NULL)
    {
        for (int i = 0; i < this->maxIngredients; i++)
        {
            if(ingredients[i] != NULL)
            {
                delete ingredients[i];
                ingredients[i] = NULL;
            }
        }

        delete[] ingredients;
    }
    this->numIngredients = oldCauldron.numIngredients;
    this->maxIngredients = oldCauldron.maxIngredients;

    ingredients = new ingredient*[oldCauldron.maxIngredients];
    for (int i = 0; i < maxIngredients; i++)
    {
        if(oldCauldron.getIngredient(i) != NULL)
        {
            ingredients[i] = new ingredient(oldCauldron.getIngredient(i)->getName(), oldCauldron.getIngredient(i)->getDanger());
        }
        else
        {
            ingredients[i] = NULL;
        }
    }
}

cauldron::~cauldron()
{
    for (int i = 0; i < this->maxIngredients; i++)
    {
        if(this->ingredients[i] != NULL)
        {
            delete this->ingredients[i];
        }
    }

    delete[] this->ingredients;
    this->ingredients = NULL;
}

void cauldron::print()
{
    int maxDanger = -1, minDanger = 99999;
    double averageDanger = 0.0, totalDanger = 0.0;
    for (int i = 0; i < this->maxIngredients; i++)
    {
        if(this->ingredients[i] != NULL)
        {
            totalDanger += this->ingredients[i]->getDanger();

            if(this->ingredients[i]->getDanger() < minDanger)
            {
                minDanger = this->ingredients[i]->getDanger();
            }

            if(this->ingredients[i]->getDanger() > maxDanger)
            {
                maxDanger = this->ingredients[i]->getDanger();
            }
        }
    }

    averageDanger = totalDanger/this->numIngredients;

    cout << "Number of Ingredients: " << numIngredients << endl;
    cout << "Average Danger Rating: " << averageDanger << endl;
    cout << "Maximum Danger Rating: " << maxDanger << endl;
    cout << "Minimum Danger Rating: " << minDanger << endl;
}

int cauldron::getMax() const
{
    return this->maxIngredients;
}

int cauldron::getCurr() const
{
    return this->numIngredients;
}

ingredient *cauldron::getIngredient(int a) const
{
    return this-> ingredients[a];
}

int cauldron::addIngredient(std::string in, int dR)
{
    if(this->numIngredients == this->maxIngredients)
    {
        int newMax = this->maxIngredients + 1;

        ingredient** newIngredientList = new ingredient*[newMax];
        for (int i = 0; i < this->maxIngredients; i++)
        {
            newIngredientList[i] = new ingredient(this->ingredients[i]);
            delete ingredients[i];
        }
        newIngredientList[newMax-1] = new ingredient(in, dR);

        delete[] ingredients;
        this->ingredients = newIngredientList;
        numIngredients++;
        maxIngredients++;
        return maxIngredients;
    }
    else
    {
        for(int i = 0; i < this->maxIngredients; i++)
        {
            if(this->ingredients[i] == NULL)
            {
                this->numIngredients++;
                this->ingredients[i] = new ingredient(in, dR);
                return i;
            }
        }
    }
}

void cauldron::removeIngredient(int in)
{
    if(in < this->maxIngredients && in > 0)
    {
        if(this->ingredients[in] != NULL)
        {
            delete this->ingredients[in];
            this->ingredients[in] = NULL;
            numIngredients--;
        }
    }
}

void cauldron::distillPotion(cauldron &currCauldron, std::string *list, int numRemove)
{
    for(int i = 0; i < numRemove; i++)
    {
        for (int j = 0; j < currCauldron.maxIngredients; j++)
        {
            if(currCauldron.ingredients[j] != NULL)
            {
                if(currCauldron.ingredients[j]->getName() == list[i])
                {
                    removeIngredient(j);
                    break;
                }
            }
        }
    }
}

void cauldron::listIngredients()
{
    for (int i = 0; i < this->maxIngredients; i++)
    {
        if(this->ingredients[i] != NULL)
        {
            cout << this->ingredients[i]->getName() << endl;
        }
    }
}
