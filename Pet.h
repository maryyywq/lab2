#pragma once
#include <iostream>
#include <string>
#include "Status.h"
#include "PetHouse.h"
#include "GameDay.h"
#include "Owner.h"
#include "Game.h"
#include "Medicine.h"
#include "Food.h"
#include "PetItem.h"
#include "Mood.h"

//����������� ����� �������
class Pet {
protected:
    std::string name;
    int age;
    Status status;

public:
    Pet() : name(""), age(0), status() {}
    Pet(const std::string& name, int age) : name(name), age(age), status() {}
    virtual ~Pet() = default; //����������� ���������� �� ���������

    //�������
    std::string getName() const { return name; }
    int getAge() const { return age; }
    Status getStatus() const { return status; }

    //�������
    void setName(const std::string& n) { name = n; }
    void setAge(int a) { age = a; }
    void setStatus(const Status& s) { status = s; }

    virtual void makeSound() const = 0; //����� ����������� �������

    void use(PetItem *item) {
        if (item->getType() == "Food") {
            int newSatiety = status.getSatiety() + item->getValue();
            status.setSatiety(newSatiety);
            if (status.getSatiety() == Status::maxSatiety) {
                status.setMood(HAPPY);
            }
            std::cout << name << " �������(�) " << item->getName() << " � ���(��) ����� ����������." << std::endl;
            makeSound(); //������� ������ ���� ����� ���
        }
        else if (item->getType() == "Medicine") {
            status.setHealth(status.getHealth() + item->getValue());
            if (status.getHealth() > Status::maxHealth) {
                status.setHealth(Status::maxHealth);
                status.setMood(HAPPY);
            }
            std::cout << name << " ������(�) " << item->getName() << " � ���(��) �������� ����������." << std::endl;
        }
    }

    void play(Game game) {
        if (status.getEnergy() >= game.getEnergyCost()) {
            status.setMood(HAPPY);
            status.setEnergy(status.getEnergy() - game.getEnergyCost());
            status.setSatiety(status.getSatiety() - satietyCost);
            std::cout << name << " �������(�) � ����� ��������(�)!" << std::endl;
            makeSound(); //������� ������ ���� ����� ����
        }
        else {
            std::cout << name << " ������� �����(�) ��� ����." << std::endl;
        }
    }

    void walk(Weather weather) {
        if (weather == STORM || weather == RAINY || weather == WINDY) {
            status.setMood(AFRAID);
            status.setHealth(status.getHealth() - healthCost);
            if (status.getHealth() < 0) status.setHealth(0);
            std::cout << name << " ���������(���) ��-�� ������ ������." << std::endl;
        }
        else {
            status.setMood(HAPPY);
            std::cout << name << " ������ � ������������ ������� �������." << std::endl;
        }
        status.setEnergy(status.getEnergy() - walkEnergyCost);
        status.setSatiety(status.getSatiety() - satietyCost);
        if (status.getEnergy() < 0) status.setEnergy(0);

        makeSound(); //������� ������ ���� ����� ��������
    }

    void sleep(PetHouse house) {
        status.setEnergy(status.getEnergy() + house.getComfortLevel());
        status.setSatiety(status.getSatiety() - sleepHungerCost);
        if (status.getEnergy() > Status::maxEnergy) {
            status.setEnergy(Status::maxEnergy);
        }

        if (status.getEnergy() >= 50) {
            std::cout << name << " ������ ��������(�)!" << std::endl;
            status.setMood(HAPPY);
        }
        else {
            std::cout << name << " �� ����� ������ ��������(�) :(" << std::endl;
            status.setMood(SAD);
        }
        makeSound(); //������� ������ ���� ����� ���
    }

    static const int walkEnergyCost = 5;
    static const int healthCost = 5;
    static const int satietyCost = 10;
    static const int sleepHungerCost = 40; 
};

std::ostream& operator<<(std::ostream& stream, const Pet& pet)
{
    stream << "��� �������: " << pet.getName() << std::endl;
    stream << "������� �������: " << pet.getAge() << std::endl;
    stream << "�������: " << pet.getStatus().getSatiety() << std::endl;
    stream << "�������: " << pet.getStatus().getEnergy() << std::endl;
    stream << "��������: " << pet.getStatus().getHealth() << std::endl;
    stream << "����������: " << getMoodString(pet.getStatus().getMood()) << std::endl;
    return stream;
}





