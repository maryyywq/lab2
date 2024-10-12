#include <Windows.h>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Football.h"
#include "LaserPointer.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "������ �� ������������ �������:" << std::endl;

    //������� ���������
    Owner owner("�����", 19, 500);

    //������� ��� ��� ��������
    PetHouse petHouse("������ ������� �������", "������, 59", 75);

    //������� ��������
    Cat myCat("��������", 3);
    Dog myDog("�����", 5);

    //������� ���� ��� ��������
    Game catGame("���������", 20, 15);
    Game dogGame("�����", 25, 10);

    //������� ��� ��� ��������
    Food catFood("���� ��� �����", 20, 5);
    Food dogFood("���� ��� �����", 30, 8);

    //������� ����������� ��� ��������
    Medicine medicine("���������", 15, 10);

    //������� ������
    std::cout << "������� ���� �� ��������:" << std::endl;
    myCat.walk(SUNNY);
    myDog.walk(RAINY);

    //������� ���������� � ��������
    std::cout << std::endl << "���������� � ��������:" << std::endl;
    std::cout << myCat << std::endl;
    std::cout << myDog;

    //������� ����
    std::cout << std::endl << "������� ����:" << std::endl;
    myCat.use(&catFood);
    myDog.use(&dogFood);

    //������� ���������� � ��������
    std::cout << std::endl << "���������� � ��������:" << std::endl;
    std::cout << myCat << std::endl;
    std::cout << myDog;

    //������� ������
    std::cout << std::endl << "������� ������:" << std::endl;
    myCat.play(catGame);
    myDog.play(dogGame);

    //������� ���������� � ��������
    std::cout << std::endl << "���������� � ��������:" << std::endl;
    std::cout << myCat << std::endl;
    std::cout << myDog;

    //������� ����
    std::cout << std::endl << "������� ��������:" << std::endl;
    myCat.sleep(petHouse);
    myDog.sleep(petHouse);

    //������� �������
    std::cout << std::endl << "������� ��������� ���������:" << std::endl;
    myCat.use(&medicine);
    myDog.use(&medicine);

    std::cout << std::endl << "������ ������ � ������������ �������� Cat:" << std::endl;
    Cat* catsArray = new Cat[2];
    catsArray[0].setName("��������");
    catsArray[1].setName("������");
    catsArray[0].makeSound();
    catsArray[1].makeSound();
    catsArray[0].walk(SUNNY);
    catsArray[1].getStatus();
    delete[] catsArray;

    std::cout << std::endl << "������ ������ � �������� ������������ �������� Pet:" << std::endl;
    Pet* petsArray[2];
    petsArray[0] = new Cat();
    petsArray[0]->setName("�����");
    petsArray[1] = new Dog();
    petsArray[1]->setName("�����");

    petsArray[0]->makeSound();
    petsArray[1]->makeSound();

    //������� ��� ��� ��������
    Food catFood2("���� ��� �����", 20, 5);
    Food dogFood2("���� ��� �����", 30, 8);
    petsArray[0]->use(&catFood2);
    petsArray[0]->use(&dogFood2);
    for (size_t i = 0; i < 2; i++) delete petsArray[i];

    
    Game* pointerGame;
    std::cout << std::endl;
    pointerGame = new Game();
    pointerGame->play();
    delete pointerGame;
    pointerGame = new Football();
    pointerGame->play();
    delete pointerGame;
    pointerGame = new LaserPointer();
    pointerGame->play();
    return 0;
}