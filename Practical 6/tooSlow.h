#ifndef PRAC6_TOOSLOW_H
#define PRAC6_TOOSLOW_H
#define override

#include <exception>

class tooSlow : std::exception{
public:
    const char* what() const throw() override
    {
        return "TOO SLOW";
    };
};


#endif //PRAC6_TOOSLOW_H
