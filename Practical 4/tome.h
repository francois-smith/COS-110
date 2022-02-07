#ifndef PRAC4_TOME_H
#define PRAC4_TOME_H

#include <string>
#include <cstring>
#include <iostream>

class tome;
std::ostream& operator<<(std::ostream& output, const tome& t);

class tome {
private:
    std::string references[10];
    std::string tomeName;
    std::string author;
    int currSpells;
public:
    tome(std::string name, std::string author);
    tome(std::string name, int tomeSize, std::string author, std::string* initialList);
    ~tome();
    int getTomeSize() const;
    std::string getSpell(int i) const;
    std::string getName() const;
    std::string getAuthor() const;
    friend std::ostream& operator<<(std::ostream& output, const tome& t);
    tome operator+(const std::string& add);
    tome operator-(const std::string& sub);
    tome& operator=(const tome& oldTome);
    bool operator>(const tome& t);
    bool operator<(const tome& t);
    bool operator==(const tome& t);
};
#endif //PRAC4_TOME_H
