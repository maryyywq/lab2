#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define MAX_LEN 100
#define MAX_ENERGY 100
#define MAX_HEALTH 100
#define MAX_SATIETY 100
#define MAX_COMFORT 10
#define ENERGY_COST 5
#define HEALTH_COST 5
#define SATIETY_COST 10

// Определение настроения питомца
typedef enum Mood {
    HAPPY,
    ANGRY,
    SAD,
    AFRAID
} Mood;

// Определение погоды
typedef enum Weather {
    SUNNY,
    RAINY,
    WINDY,
    STORM
} Weather;

// Состояние питомца
typedef struct {
    int satiety;
    int energy;
    int health;
    Mood mood;
} Status;

// Описание питомца
typedef struct {
    char name[MAX_LEN];
    int age;
    Status status;
} Pet;

// Описание медикаментов
typedef struct {
    char medicineName[MAX_LEN];
    int healingPower;
    int cost;
} Medicine;

// Описание пищи
typedef struct {
    char foodName[MAX_LEN];
    int nutritionValue;
    int cost;
} Food;

// Описание игры
typedef struct {
    char gameName[MAX_LEN];
    int funValue;
    int energyCost;
} Game;

// Описание хозяина
typedef struct {
    char ownerName[MAX_LEN];
    int ownerAge;
    int money;
} Owner;

// Описание дома питомца
typedef struct {
    char houseName[MAX_LEN];
    char address[MAX_LEN];
    int comfortLevel;
} PetHouse;

// Описание игрового дня
typedef struct {
    int dayNumber;
    Weather weather;
} GameDay;

// Инициализация питомца
void initPet(Pet* pet, char* name, int age) {
    strncpy(pet->name, name, MAX_LEN);
    pet->age = age;
    pet->status.satiety = MAX_SATIETY;
    pet->status.energy = MAX_ENERGY / 2;
    pet->status.health = MAX_HEALTH;
    pet->status.mood = HAPPY;
}

// Вывод строки настроения
char* getMoodString(Mood mood) {
    switch (mood) {
    case HAPPY: return "счастлив(а)";
    case ANGRY: return "злится";
    case SAD: return "грустный(ая)";
    case AFRAID: return "боится";
    default: return "нейтральное настроение";
    }
}

// Вывод строки погоды
char* getWeatherString(Weather weather) {
    switch (weather) {
    case SUNNY: return "солнечно";
    case RAINY: return "дождливо";
    case WINDY: return "ветренно";
    case STORM: return "буря";
    default: return "неизвестная погода";
    }
}

// Отображение информации о питомце
void displayPet(Pet* pet) {
    printf("Имя питомца: %s\n", pet->name);
    printf("Возраст питомца: %d\n", pet->age);
    printf("Голод: %d\n", pet->status.satiety);
    printf("Энергия: %d\n", pet->status.energy);
    printf("Здоровье: %d\n", pet->status.health);
    printf("Настроение: %s\n", getMoodString(pet->status.mood));
}

// Инициализация хозяина
void initOwner(Owner* owner, char* name, int age, int money) {
    strncpy(owner->ownerName, name, MAX_LEN);
    owner->ownerAge = age;
    owner->money = money;
}

// Кормление питомца
void feedPet(Pet* pet, Food* food) {
    pet->status.satiety += food->nutritionValue;
    if (pet->status.satiety > MAX_SATIETY) pet->status.satiety = MAX_SATIETY;
    printf("%s съел(а) %s и его(ее) голод уменьшился.\n", pet->name, food->foodName);
}

// Игра с питомцем
void playWithPet(Pet* pet, Game* game) {
    if (pet->status.energy >= game->energyCost) {
        pet->status.mood = HAPPY;
        pet->status.energy -= game->energyCost;
        pet->status.satiety -= SATIETY_COST;
        printf("%s поиграл(а) в %s и очень счастлив(а)!\n", pet->name, game->gameName);
    }
    else {
        printf("%s слишком устал(а) для игры.\n", pet->name);
    }
}

// Лечение питомца
void healPet(Pet* pet, Medicine* medicine) {
    pet->status.health += medicine->healingPower;
    if (pet->status.health > MAX_HEALTH) pet->status.health = MAX_HEALTH;
    printf("%s принял(а) %s и его(ее) здоровье улучшилось.\n", pet->name, medicine->medicineName);
}

// Прогулка с питомцем
void walkWithPet(Pet* pet, GameDay* day) {
    if (day->weather == STORM || day->weather == RAINY || day->weather == WINDY) {
        pet->status.mood = AFRAID;
        pet->status.health -= HEALTH_COST;
        if (pet->status.health < 0) pet->status.health = 0;
        printf("%s испугался(ась), потому что на улице плохая погода.\n", pet->name);
    }
    else {
        pet->status.mood = HAPPY;
        printf("%s гуляет и наслаждается хорошей погодой.\n", pet->name);
    }
    pet->status.energy -= ENERGY_COST;
    pet->status.satiety -= SATIETY_COST;
    if (pet->status.energy < 0) pet->status.energy = 0;
}

// Восстановление энергии питомца
void sleepPet (Pet* pet) {
    pet->status.energy = MAX_ENERGY;
    printf("Ваш питомец %s отлично поспал!\n", pet->name);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Pet pet;
    Owner owner;
    initPet(&pet, "Чешулька", 3);
    initOwner(&owner, "Марина",19, 1000);
    Food food = { "Корм", 30, 10 };
    Game game = { "Мяч", 40, 10 };
    Medicine medicine = { "Антибиотик", 20, 15 };
    GameDay day = { 1, SUNNY };

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
    sleepPet(&pet);
    displayPet(&pet);

    return 0;
}