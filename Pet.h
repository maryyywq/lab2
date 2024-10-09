#pragma once
#include <iostream>
#include <string>

const int MAX_ENERGY = 100;
const int MAX_HEALTH = 100;
const int MAX_SATIETY = 100;
const int MAX_COMFORT = 100;
const int ENERGY_COST = 5;
const int HEALTH_COST = 5;
const int SATIETY_COST = 10;
const int SLEEP_HUNGER_COST = 40;

// Определение настроения питомца
enum Mood {
    HAPPY,
    ANGRY,
    SAD,
    AFRAID
};

// Определение погоды
enum Weather {
    SUNNY,
    RAINY,
    WINDY,
    STORM
};

// Класс состояния питомца
class Status {
private:
    int satiety;
    int energy;
    int health;
    Mood mood;

public:
    Status() : satiety(MAX_SATIETY), energy(MAX_ENERGY / 2), health(MAX_HEALTH), mood(HAPPY) {}
    ~Status() = default; // Деструктор по умолчанию

    // Геттеры
    int getSatiety() const { return satiety; }
    int getEnergy() const { return energy; }
    int getHealth() const { return health; }
    Mood getMood() const { return mood; }

    // Сеттеры
    void setSatiety(int s) { satiety = (s > MAX_SATIETY) ? MAX_SATIETY : s; }
    void setEnergy(int e) { energy = (e > MAX_ENERGY) ? MAX_ENERGY : e; }
    void setHealth(int h) { health = (h > MAX_HEALTH) ? MAX_HEALTH : h; }
    void setMood(Mood m) { mood = m; }
};

// Абстрактный класс питомца
class Pet {
protected:
    std::string name;
    int age;
    Status status;

public:
    Pet() : name(""), age(0), status() {}
    Pet(const std::string& name, int age) : name(name), age(age), status() {}
    virtual ~Pet() = default; // Виртуальный деструктор по умолчанию

    // Геттеры
    std::string getName() const { return name; }
    int getAge() const { return age; }
    Status getStatus() const { return status; }

    // Сеттеры
    void setName(const std::string& n) { name = n; }
    void setAge(int a) { age = a; }
    void setStatus(const Status& s) { status = s; }

    virtual void makeSound() const = 0; // Чисто виртуальная функция
    void display() const {
        std::cout << "Имя питомца: " << name << std::endl;
        std::cout << "Возраст питомца: " << age << std::endl;
        std::cout << "Сытость: " << status.getSatiety() << std::endl;
        std::cout << "Энергия: " << status.getEnergy() << std::endl;
        std::cout << "Здоровье: " << status.getHealth() << std::endl;
        std::cout << "Настроение: " << getMoodString(status.getMood()) << std::endl;
    }

    void feed(int nutritionValue) {
        int newSatiety = status.getSatiety() + nutritionValue;
        status.setSatiety(newSatiety);
        if (status.getSatiety() == MAX_SATIETY) {
            status.setMood(HAPPY);
        }
        std::cout << name << " покушал(а) и его(ее) голод уменьшился.\n";
        makeSound(); // Питомец издает звук после еды
    }

    void play(int energyCost) {
        if (status.getEnergy() >= energyCost) {
            status.setMood(HAPPY);
            status.setEnergy(status.getEnergy() - energyCost);
            status.setSatiety(status.getSatiety() - SATIETY_COST);
            std::cout << name << " поиграл(а) и очень счастлив(а)!\n";
            makeSound(); // Питомец издает звук после игры
        }
        else {
            std::cout << name << " слишком устал(а) для игры.\n";
        }
    }

    void heal(int healingPower) {
        status.setHealth(status.getHealth() + healingPower);
        if (status.getHealth() > MAX_HEALTH) {
            status.setHealth(MAX_HEALTH);
            status.setMood(HAPPY);
        }
        std::cout << name << " принял(а) лекарства и его(ее) здоровье улучшилось.\n";
    }

    void walk(Weather weather) {
        if (weather == STORM || weather == RAINY || weather == WINDY) {
            status.setMood(AFRAID);
            status.setHealth(status.getHealth() - HEALTH_COST);
            if (status.getHealth() < 0) status.setHealth(0);
            std::cout << name << " испугался(ась) из-за плохой погоды.\n";
        }
        else {
            status.setMood(HAPPY);
            std::cout << name << " гуляет и наслаждается хорошей погодой.\n";
        }
        status.setEnergy(status.getEnergy() - ENERGY_COST);
        status.setSatiety(status.getSatiety() - SATIETY_COST);
        if (status.getEnergy() < 0) status.setEnergy(0);

        makeSound(); // Питомец издает звук после прогулки
    }

    void sleep(int comfortLevel) {
        status.setEnergy(status.getEnergy() + comfortLevel);
        status.setSatiety(status.getSatiety() - SLEEP_HUNGER_COST);
        if (status.getEnergy() > MAX_ENERGY) {
            status.setEnergy(MAX_ENERGY);
        }

        if (status.getEnergy() >= 50) {
            std::cout << name << " хорошо отдохнул!\n";
            status.setMood(HAPPY);
        }
        else {
            std::cout << name << " не очень хорошо отдохнул :(\n";
            status.setMood(SAD);
        }
        makeSound(); // Питомец издает звук после сна
    }

private:
    std::string getMoodString(Mood mood) const {
        switch (mood) {
        case HAPPY: return "счастлив(а)";
        case ANGRY: return "злится";
        case SAD: return "грустный(ая)";
        case AFRAID: return "боится";
        default: return "нейтральное настроение";
        }
    }
};

// Класс кошки
class Cat : public Pet {
public:
    Cat() : Pet() {}
    Cat(const std::string& name, int age) : Pet(name, age) {}
    ~Cat() = default; // Деструктор по умолчанию

    void makeSound() const override {
        std::cout << name << " говорит: Мяу!" << std::endl;
    }
};

// Класс собаки
class Dog : public Pet {
public:
    Dog() : Pet() {}
    Dog(const std::string& name, int age) : Pet(name, age) {}
    ~Dog() = default; // Деструктор по умолчанию

    void makeSound() const override {
        std::cout << name << " говорит: Гав!" << std::endl;
    }
};

// Класс еды
class Food {
private:
    std::string foodName;
    int nutritionValue;
    int cost;

public:
    Food() : foodName(""), nutritionValue(0), cost(0) {}
    Food(const std::string& foodName, int nutritionValue, int cost)
        : foodName(foodName), nutritionValue(nutritionValue), cost(cost) {}
    ~Food() = default; // Деструктор по умолчанию

    // Геттеры
    std::string getFoodName() const { return foodName; }
    int getNutritionValue() const { return nutritionValue; }
    int getCost() const { return cost; }

    // Сеттеры
    void setFoodName(const std::string& fn) { foodName = fn; }
    void setNutritionValue(int nv) { nutritionValue = nv; }
    void setCost(int c) { cost = c; }
};

// Класс лекарства
class Medicine {
private:
    std::string medicineName;
    int healingPower;
    int cost;

public:
    Medicine() : medicineName(""), healingPower(0), cost(0) {}
    Medicine(const std::string& medicineName, int healingPower, int cost)
        : medicineName(medicineName), healingPower(healingPower), cost(cost) {}
    ~Medicine() = default; // Деструктор по умолчанию

    // Геттеры
    std::string getMedicineName() const { return medicineName; }
    int getHealingPower() const { return healingPower; }
    int getCost() const { return cost; }

    // Сеттеры
    void setMedicineName(const std::string& mn) { medicineName = mn; }
    void setHealingPower(int hp) { healingPower = hp; }
    void setCost(int c) { cost = c; }
};

// Класс игры
class Game {
private:
    std::string gameName;
    int funValue;
    int energyCost;

public:
    Game() : gameName(""), funValue(0), energyCost(0) {}
    Game(const std::string& gameName, int funValue, int energyCost)
        : gameName(gameName), funValue(funValue), energyCost(energyCost) {}
    ~Game() = default; // Деструктор по умолчанию

    // Геттеры
    std::string getGameName() const { return gameName; }
    int getFunValue() const { return funValue; }
    int getEnergyCost() const { return energyCost; }

    // Сеттеры
    void setGameName(const std::string& gn) { gameName = gn; }
    void setFunValue(int fv) { funValue = fv; }
    void setEnergyCost(int ec) { energyCost = ec; }
};

// Класс хозяина
class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;

public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
        : ownerName(ownerName), ownerAge(ownerAge), money(money) {}
    ~Owner() = default; // Деструктор по умолчанию

    // Геттеры
    std::string getOwnerName() const { return ownerName; }
    int getOwnerAge() const { return ownerAge; }
    int getMoney() const { return money; }

    // Сеттеры
    void setOwnerName(const std::string& on) { ownerName = on; }
    void setOwnerAge(int oa) { ownerAge = oa; }
    void setMoney(int m) { money = m; }
};

// Класс дома питомца
class PetHouse {
private:
    std::string houseName;
    std::string address;
    int comfortLevel;

public:
    PetHouse() : houseName(""), address(""), comfortLevel(0) {}
    PetHouse(const std::string& houseName, const std::string& address, int comfortLevel)
        : houseName(houseName), address(address), comfortLevel(comfortLevel) {}
    ~PetHouse() = default; // Деструктор по умолчанию

    // Геттеры
    std::string getHouseName() const { return houseName; }
    std::string getAddress() const { return address; }
    int getComfortLevel() const { return comfortLevel; }

    // Сеттеры
    void setHouseName(const std::string& hn) { houseName = hn; }
    void setAddress(const std::string& a) { address = a; }
    void setComfortLevel(int cl) { comfortLevel = cl; }
};

// Класс игрового дня
class GameDay {
private:
    int dayNumber;
    Weather weather;

public:
    GameDay() : dayNumber(0), weather(SUNNY) {}
    GameDay(int dayNumber, Weather weather)
        : dayNumber(dayNumber), weather(weather) {}
    ~GameDay() = default; // Деструктор по умолчанию

    // Геттеры
    int getDayNumber() const { return dayNumber; }
    Weather getWeather() const { return weather; }

    // Сеттеры
    void setDayNumber(int dn) { dayNumber = dn; }
    void setWeather(Weather w) { weather = w; }
};
