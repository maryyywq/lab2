#pragma once
#include <string>

//Класс хозяина
class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;

public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
        : ownerName(ownerName), ownerAge(ownerAge), money(money) {}
    ~Owner() = default; //Деструктор по умолчанию

    //Геттеры
    std::string getOwnerName() const { return ownerName; }
    int getOwnerAge() const { return ownerAge; }
    int getMoney() const { return money; }

    //Сеттеры
    void setOwnerName(const std::string& on) { ownerName = on; }
    void setOwnerAge(int oa) { ownerAge = oa; }
    void setMoney(int m) { money = m; }
};