#ifndef PRAC6_STORAGEFULL_H
#define PRAC6_STORAGEFULL_H
#define override

#include <exception>

class storageFull : public std::exception{
public:
    const char * what() const throw() override
    {
        return "STORAGE FULL";
    }
};

#endif //PRAC6_STORAGEFULL_H
