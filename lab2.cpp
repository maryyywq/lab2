#include "Pet.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Pet pet;
    Owner owner;
    initPet(&pet, "Чешулька", 3);
    initOwner(&owner, "Марина", 19, 1000);
    Food food = { "Корм", 30, 10 };
    Game game = { "Мяч", 40, 10 };
    Medicine medicine = { "Антибиотик", 20, 15 };
    GameDay day = { 1, SUNNY };
    PetHouse pethouse = { "Теплая постель хозяина", "Ленина, 102", 40 };

    displayPet(&pet);
    printf("\n");
    walkWithPet(&pet, &day);
    displayPet(&pet);
    printf("\n");
    playWithPet(&pet, &game);
    displayPet(&pet);
    printf("\n");
    feedPet(&pet, &food);
    displayPet(&pet);
    printf("\n");
    day.weather = RAINY;
    walkWithPet(&pet, &day);
    displayPet(&pet);
    printf("\n");
    healPet(&pet, &medicine);
    displayPet(&pet);
    printf("\n");
    sleepPet(&pet, pethouse);
    displayPet(&pet);

    return 0;
}