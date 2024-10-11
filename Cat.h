#pragma once
#include <string>
#include "Pet.h"

//����� �����
class Cat : public Pet {
public:
    Cat() : Pet() {}
    Cat(const std::string& name, int age) : Pet(name, age) {}
    ~Cat() = default; //���������� �� ���������

    void makeSound() const override {
        std::cout << name << " �������: ���!" << std::endl;
    }
};