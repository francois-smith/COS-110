#ifndef PRAC6_STORAGEEMPTY_H
#define PRAC6_STORAGEEMPTY_H
#define override

#include <exception>

class storageEmpty : public std::exception{
public:
    const char * what() const throw() override
    {
        return "STORAGE EMPTY";
    };
};


#endif //PRAC6_STORAGEEMPTY_H
