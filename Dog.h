#pragma once
#include <string>
#include "Pet.h"

//����� ������
class Dog : public Pet {
public:
    Dog() : Pet() {}
    Dog(const std::string& name, int age) : Pet(name, age) {}
    ~Dog() = default; //���������� �� ���������

    void makeSound() const override {
        std::cout << name << " �������: ���!" << std::endl;
    }
};