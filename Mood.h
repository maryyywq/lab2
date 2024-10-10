#pragma once
#include <string>

enum Mood {
    HAPPY,
    ANGRY,
    SAD,
    AFRAID
};

static std::string getMoodString(Mood mood) {
    switch (mood) {
    case HAPPY: return "счастлив(а)";
    case ANGRY: return "злится";
    case SAD: return "грустный(ая)";
    case AFRAID: return "боится";
    default: return "нейтральное настроение";
    }
}