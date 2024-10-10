#pragma once
#include <string>

class PetItem {
protected:
    std::string name;
    int value;
    int cost;

public:
    PetItem() : name(""), value(0), cost(0) {}
    PetItem(const std::string& n, int v, int c)
        : name(name), value(v), cost(c) {}
    virtual ~PetItem() = default; //Деструктор по умолчанию

    //Геттеры
    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getCost() const { return cost; }

    //Сеттеры
    void setName(const std::string& fn) { name = fn; }
    void setValue(int nv) { value = nv; }
    void setCost(int c) { cost = c; }

    virtual std::string getType() = 0;
};