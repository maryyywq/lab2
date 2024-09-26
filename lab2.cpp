#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
typedef enum Mood //настроение питомца
{
    HAPPY,
    ANGRY,
    SAD,
    AFRAID
};

typedef enum Weather //погода
{
    SUNNY,
    RAINY,
    WINDY,
    STORM
};

//структура для описания питомца
typedef struct {
    char name[MAX_LEN]; //имя питомца
    int age; //возраст питомца
    Status status;
} Pet;

//структура для описания медикаментозных препаратов для лечения питомца
typedef struct {
    char medicineName[MAX_LEN];
    int healingPower;  // насколько лечение улучшает здоровье питомца
} Medicine;


// Структура для описания пищи
typedef struct {
    char foodName[MAX_LEN]; //название еды
    int nutritionValue; // питательная ценность (увеличивает сытость)
} Food;

// Структура для описания игры
typedef struct {
    char gameName[MAX_LEN]; //название игры
    int funValue;    // сколько счастья добавляет игра
    int energyCost;  // сколько энергии отнимает игра
} Game;

// Структура для описания хозяина питомца
typedef struct {
    char ownerName[MAX_LEN]; //имя хозяина питомца
    int ownerAge; //его возраст
    int money; //количество денег хозяина
} Owner;

// Структура для описания дома питомца
typedef struct {
    char houseName[MAX_LEN]; // название дома
    char adress[MAX_LEN]; //адрес дома
    int comfortLevel; // уровень комфорта (0 - низкий, 10 - высокий)
} PetHouse;

// Структура для описания игрового дня
typedef struct {
    int dayNumber; // номер игрового дня
    Weather weather; //погода
} GameDay;

//структура, которая позволяет узнать текущее состояние питомца
typedef struct {
    int hunger;
    int energy;
    int health;
    Mood mood;
} Status;

// Инициализация питомца
void initPet(Pet* pet, const char* name, int age) {
    strncpy(pet->name, name, MAX_LEN);
    pet->age = age;
    pet->status.hunger = 0;
    pet->status.energy = 50;
    pet->status.health = 100;
    pet->status.mood = HAPPY;
}

// Отображение информации о питомце
void displayPet(const Pet* pet) {
    printf("Имя питомца: %s\n", pet->name);
    printf("Возраст питомца: %d\n", pet->age);
    printf("Голод: %d\n", pet->status.hunger);
    printf("Энергия: %d\n", pet->status.energy);
    printf("Здоровье: %d\n", pet->status.health);
    printf("Настроение: %d\n", pet->status.mood);
}

// Инициализация хозяина
void initOwner(Owner* owner, const char* name, int age, int money) {
    strncpy(owner->ownerName, name, MAX_LEN);
    owner->ownerAge = age;
    owner->money = money;
}

// Инициализация еды
void initFood(Food* food, const char* foodName, int nutritionValue) {
    strncpy(food->foodName, foodName, MAX_LEN);
    food->nutritionValue = nutritionValue;
}

// Кормление питомца
void feedPet(Pet* pet, Food* food) {
    pet->status.hunger -= food->nutritionValue;
    if (pet->status.hunger < 0) {
        pet->status.hunger = 0; // Питомец больше не голоден
    }
    printf("%s eats %s\n", pet->name, food->foodName);
}

// Инициализация игры
void initGame(Game* game, const char* gameName, int funValue, int energyCost) {
    strncpy(game->gameName, gameName, MAX_LEN);
    game->funValue = funValue;
    game->energyCost = energyCost;
}

// Играть с питомцем
void playWithPet(Pet* pet, Game* game) {
    if (pet->status.energy >= game->energyCost) {
        pet->status.mood = HAPPY;
        pet->status.energy -= game->energyCost;
        printf("%s играет и очень счастлив!\n", pet->name);
    }
    else {
        printf("%s очень устал для игры!", pet->name);
    }
}

// Инициализация медикамента
void initMedicine(Medicine* medicine, const char* name, int healingPower) {
    strncpy(medicine->medicineName, name, MAX_LEN);
    medicine->healingPower = healingPower;
}

// Лечение питомца
void healPet(Pet* pet, Medicine* medicine) {
    pet->status.health += medicine->healingPower;
    if (pet->status.health > 100) {
        pet->status.health = 100; // Здоровье не может превышать 100
    }
    printf("%s принял %s и чувствует себя лучше!\n", pet->name, medicine->medicineName);
}

// Инициализация дома
void initPetHouse(PetHouse* house, const char* name, const char* address, int comfortLevel) {
    strncpy(house->houseName, name, MAX_LEN);
    strncpy(house->adress, address, MAX_LEN);
    house->comfortLevel = comfortLevel;
}

// Увеличение комфорта питомца
void increaseComfort(Pet* pet, PetHouse* house) {
    if (house->comfortLevel >= 7) {
        pet->status.mood = HAPPY;
    }
    else {
        pet->status.mood = SAD;
    }
}

// Инициализация игрового дня
void initGameDay(GameDay* day, int dayNumber, Weather weather) {
    day->dayNumber = dayNumber;
    day->weather = weather;
}

// Обработка погоды в течение дня
void processWeather(Pet* pet, GameDay* day) {
    if (day->weather == STORM || day->weather == RAINY || day->weather == WINDY) {
        pet->status.mood = AFRAID;
		printf("%s очень испуган из-за плохой погоды!\n", pet->name);
    }
    else if (day->weather == SUNNY) {
        pet->status.mood = HAPPY;
        printf("%s наслаждается солнечным днем!\n", pet->name);
    }
}


int main()
{
    return 0;
}
