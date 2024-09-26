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

    printf("Работа со статическими переменными:\n");
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
    sleepPet(&pet, &pethouse);
    displayPet(&pet);

    Pet *pet_2 = (Pet*)(calloc(1, sizeof(Pet)));
    Owner *owner_2 = (Owner*)(calloc(1, sizeof(Owner)));
    initOwner(owner_2, "Александр", 15, 500);
    initPet(pet_2, "Шарик", 5);
    Food* food_2 = (Food*)(calloc(1, sizeof(Food)));
    initFood(food_2, "Педигри", 40, 100);
    Game* game_2 = (Game*)(calloc(1, sizeof(Game)));
    initGame(game_2, "Косточка", 20, 10);
    Medicine* medicine_2 = (Medicine*)(calloc(1, sizeof(Medicine)));
    initMedicine(medicine_2, "Укол", 30, 50);
    GameDay* gameday_2 = (GameDay*)(calloc(1, sizeof(GameDay)));
    initGameDay(gameday_2, 2, RAINY);
    PetHouse* pethouse_2 = (PetHouse*)(calloc(1, sizeof(PetHouse)));
    initPetHouse(pethouse_2, "Будка", "Обской бульвар, 144", 29);

    printf("Работа с динамическими переменными:\n");
    displayPet(pet_2);
    printf("\n");
    walkWithPet(pet_2, gameday_2);
    displayPet(pet_2);
    printf("\n");
    playWithPet(pet_2, game_2);
    displayPet(pet_2);
    printf("\n");
    feedPet(pet_2, food_2);
    displayPet(pet_2);
    printf("\n");
    healPet(pet_2, medicine_2);
    displayPet(pet_2);
    printf("\n");
    sleepPet(pet_2, pethouse_2);
    displayPet(pet_2);

    return 0;
}