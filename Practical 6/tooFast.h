#ifndef PRAC6_TOOFAST_H
#define PRAC6_TOOFAST_H
#define override

#include <exception>

class tooFast : public std::exception{
public:
    const char * what() const throw() override
    {
        return "SPEED LIMIT EXCEEDED";
    };
};

#endif //PRAC6_TOOFAST_H
