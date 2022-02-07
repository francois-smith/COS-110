#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class ingredient {
private:
    std::string name;
    int dangerRating;
public:
    ingredient(std::string name, int dangerRating);
    ingredient(const ingredient* newIngredient);
    ingredient(const ingredient& newIngredient);
    ~ingredient();
    int getDanger();
    std::string getName();
};
#endif //INGREDIENT_H
