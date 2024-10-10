#include <Windows.h>
#include "Pet.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Создаем владельца
    Owner owner("Мария", 19, 500);

    // Создаем дом для питомцев
    PetHouse petHouse("Теплая постель хозяйки", "Ленина, 59", 75);

    // Создаем питомцев
    Cat myCat("Чешулька", 3);
    Dog myDog("Белка", 5);

    // Создаем игры для питомцев
    Game catGame("Мышеловка", 20, 15);
    Game dogGame("Мячик", 25, 10);

    // Создаем еду для питомцев
    Food catFood("Корм для кошек", 20, 5);
    Food dogFood("Корм для собак", 30, 8);

    // Создаем медикаменты для питомцев
    Medicine medicine("Витаминки", 15, 10);

    //Питомцы гуляют
    std::cout << "Питомцы идут на прогулку:" << std::endl;
    myCat.walk(SUNNY);
    myDog.walk(RAINY);

    //Питомцы едят
    std::cout << std::endl << "Питомцы едят:" << std::endl;
    myCat.use(&catFood);
    myDog.use(&dogFood);

    //Питомцы играют
    std::cout << std::endl << "Питомцы играют:" << std::endl;
    myCat.play(catGame);
    myDog.play(dogGame);

    //Питомцы спят
    std::cout << std::endl << "Питомцы отдыхают:" << std::endl;
    myCat.sleep(petHouse);
    myDog.sleep(petHouse);

    //Питомцы лечатся
    std::cout << std::endl << "Питомцы принимают лекарства:" << std::endl;
    myCat.use(&medicine);
    myDog.use(&medicine);

    // Выводим информацию о питомцах
    std::cout << std::endl << "Информация о питомцах:" << std::endl;
    std::cout << myCat;
    std::cout << myDog;

    return 0;
}
