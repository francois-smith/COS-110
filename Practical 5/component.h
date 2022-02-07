#ifndef PRAC5_COMPONENT_H
#define PRAC5_COMPONENT_H
#define override

class component {
private:
    double weight;
    int powerDrain;
    double cost;
    char type;
public:
    component();
    component(char type, double weight, double cost, int powerDrain);
    double getWeight();
    double getCost();
    int getPowerDrain();
    char getType();
    virtual ~component();
    virtual double calculateEfficiency()=0;
};

#endif //PRAC5_COMPONENT_H
