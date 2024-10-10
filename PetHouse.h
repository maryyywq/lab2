#pragma once
#include <string>

//Класс дома питомца
class PetHouse {
private:
    std::string houseName;
    std::string address;
    int comfortLevel;

public:
    PetHouse() : houseName(""), address(""), comfortLevel(0) {}
    PetHouse(const std::string& houseName, const std::string& address, int comfortLevel)
        : houseName(houseName), address(address), comfortLevel(comfortLevel) {}
    ~PetHouse() = default; //Деструктор по умолчанию

    //Геттеры
    std::string getHouseName() const { return houseName; }
    std::string getAddress() const { return address; }
    int getComfortLevel() const { return comfortLevel; }

    //Сеттеры
    void setHouseName(const std::string& hn) { houseName = hn; }
    void setAddress(const std::string& a) { address = a; }
    void setComfortLevel(int cl) { comfortLevel = (cl > maxComfort) ? maxComfort : cl; }

    static const int maxComfort = 100;
};