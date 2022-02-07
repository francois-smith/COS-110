#include "ingredient.h"
using namespace std;

ingredient::ingredient(string name, int dangerRating)
{
    this->dangerRating = dangerRating;
    this->name = name;
}

ingredient::ingredient(const ingredient *newIngredient)
{
    this->dangerRating = newIngredient->dangerRating;
    this->name = newIngredient->name;
}

ingredient::ingredient(const ingredient &newIngredient)
{
    this->dangerRating = newIngredient.dangerRating;
    this->name = newIngredient.name;
}

ingredient::~ingredient()
{

}

int ingredient::getDanger()
{
    return this->dangerRating;
}

std::string ingredient::getName()
{
    return this->name;
}
