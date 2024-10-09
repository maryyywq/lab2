#include "Pet.h"
#include <Windows.h>

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
    Medicine catMedicine("Витамины для кошек", 15, 10);
    Medicine dogMedicine("Витамины для собак", 20, 12);

    // Питомцы гуляют
    std::cout << "Питомцы идут на прогулку:" << std::endl;
    myCat.walk(SUNNY);
    myDog.walk(RAINY);

    // Питомцы едят
    std::cout << "Кормим питомцев:" << std::endl;
    if (owner.getMoney() >= catFood.getCost()) {
        myCat.feed(catFood.getNutritionValue());
        owner.setMoney(owner.getMoney() - catFood.getCost()); // Уменьшаем деньги владельца
        std::cout << owner.getOwnerName() << " потратил(а) " << catFood.getCost() << " на " << catFood.getFoodName() << "." << std::endl;
    }
    else {
        std::cout << owner.getOwnerName() << " недостаточно денег для покупки " << catFood.getFoodName() << "." << std::endl;
    }

    if (owner.getMoney() >= dogFood.getCost()) {
        myDog.feed(dogFood.getNutritionValue());
        owner.setMoney(owner.getMoney() - dogFood.getCost()); // Уменьшаем деньги владельца
        std::cout << owner.getOwnerName() << " потратил(а) " << dogFood.getCost() << " на " << dogFood.getFoodName() << "." << std::endl;
    }
    else {
        std::cout << owner.getOwnerName() << " недостаточно денег для покупки " << dogFood.getFoodName() << "." << std::endl;
    }

    // Питомцы играют
    std::cout << "Питомцы играют:" << std::endl;
    myCat.play(catGame.getEnergyCost());
    myDog.play(dogGame.getEnergyCost());

    // Питомцы спят
    std::cout << "Питомцы отдыхают:" << std::endl;
    myCat.sleep(30);
    myDog.sleep(40);

    // Питомцы лечатся
    std::cout << "Питомцы принимают лекарства:" << std::endl;
    if (owner.getMoney() >= catMedicine.getCost()) {
        myCat.heal(catMedicine.getHealingPower());
        owner.setMoney(owner.getMoney() - catMedicine.getCost()); // Уменьшаем деньги владельца
        std::cout << owner.getOwnerName() << " потратил(а) " << catMedicine.getCost() << " на " << catMedicine.getMedicineName() << "." << std::endl;
    }
    else {
        std::cout << owner.getOwnerName() << " недостаточно денег для покупки " << catMedicine.getMedicineName() << "." << std::endl;
    }

    if (owner.getMoney() >= dogMedicine.getCost()) {
        myDog.heal(dogMedicine.getHealingPower());
        owner.setMoney(owner.getMoney() - dogMedicine.getCost()); // Уменьшаем деньги владельца
        std::cout << owner.getOwnerName() << " потратил(а) " << dogMedicine.getCost() << " на " << dogMedicine.getMedicineName() << "." << std::endl;
    }
    else {
        std::cout << owner.getOwnerName() << " недостаточно денег для покупки " << dogMedicine.getMedicineName() << "." << std::endl;
    }

    // Выводим информацию о питомцах и о деньгах владельца
    std::cout << std::endl << "Информация о питомцах:" << std::endl;
    myCat.display();
    std::cout << std::endl;
    myDog.display();

    // Выводим информацию о деньгах хозяина
    std::cout << std::endl << owner.getOwnerName() << ", у вас осталось " << owner.getMoney() << " денег." << std::endl;

    return 0;
}
