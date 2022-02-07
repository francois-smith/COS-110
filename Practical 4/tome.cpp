#include "tome.h"
using namespace std;

tome::tome(string name, string author)
{
    this->tomeName = name;
    this->author = author;
    this->currSpells = 0;

    for (int i = 0; i < 10; ++i)
    {
        this->references[i] = "";
    }
}

tome::tome(string name, int tomeSize, string author, string* initialList)
{
    this->tomeName = name;
    this->author = author;
    this->currSpells = tomeSize;

    for (int i = 0; i < tomeSize; ++i)
    {
        this->references[i] = initialList[i];
    }
}

tome::~tome()
{

}

int tome::getTomeSize() const
{
    return this->currSpells;
}

std::string tome::getSpell(int i) const
{
    return this->references[i];
}

std::string tome::getName() const
{
    return this->tomeName;
}

std::string tome::getAuthor() const
{
    return this->author;
}

tome tome::operator+(const string& add)
{
    if(this->currSpells == 10)
    {
        return *this;
    }
    else
    {
        for (int i = 0; i < 10; ++i)
        {
            if(references[i] == "")
            {
                references[i] = add;
                currSpells++;
                return *this;
            }
        }
        return *this;
    }
}

tome tome::operator-(const string& sub)
{
    for (int i = 0; i < 10; ++i)
    {
        if(references[i] == sub)
        {
            references[i] = "";
            currSpells--;
            return *this;
        }
    }
    return *this;
}

tome& tome::operator=(const tome& oldTome)
{
    this->currSpells = oldTome.currSpells;
    this->tomeName = oldTome.tomeName;
    this->author = oldTome.author;

    for (int i = 0; i < 10; ++i)
    {
        this->references[i] = oldTome.references[i];
    }

    return *this;
}

bool tome::operator>(const tome& t)
{
    if(t.currSpells == this->currSpells)
    {
        return false;
    }

    if(this->currSpells > t.currSpells)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream &operator<<(ostream& output, const tome& t)
{
    string name = "Tome Name: " + t.tomeName;
    string author = "Author: " + t.author;
    string reference = "References: ";

    for (int i = 0; i < 10; ++i)
    {
        if(t.references[i] == "")
        {
            continue;
        }
        else
        {
            reference += t.references[i] + ", ";
        }
    }

    reference.erase(reference.length()-2);

    output << name << endl << author << endl << reference << endl;
    return output;
}

bool tome::operator<(const tome& t)
{
    if(t.currSpells == this->currSpells)
    {
        return false;
    }

    if(this->currSpells < t.currSpells)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool tome::operator==(const tome&t)
{
    bool same = true;
    string* temp = new string[10];

    for (int i = 0; i < 10; ++i)
    {
        temp[i] = t.references[i];
    }

    if(this->currSpells != t.currSpells)
    {
        delete[] temp;
        return false;
    }
    else
    {
        for (int i = 0; i < 10; ++i)
        {
            if(references[i] == "")
            {
                continue;
            }
            else
            {
                for (int j = 0; j < 10; ++j)
                {
                    if(references[i] == temp[j])
                    {
                        temp[j] = "";
                        goto outer;
                    }
                }
                same = false;
            }
            outer: continue;
        }

        delete[] temp;
        return same;
    }
}
