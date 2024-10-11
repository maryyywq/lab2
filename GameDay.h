#pragma once

//����������� ������
enum Weather {
    SUNNY,
    RAINY,
    WINDY,
    STORM
};

//����� �������� ���
class GameDay {
private:
    int dayNumber;
    Weather weather;

public:
    GameDay() : dayNumber(0), weather(SUNNY) {}
    GameDay(int dayNumber, Weather weather)
        : dayNumber(dayNumber), weather(weather) {}
    ~GameDay() = default; //���������� �� ���������

    //�������
    int getDayNumber() const { return dayNumber; }
    Weather getWeather() const { return weather; }

    //�������
    void setDayNumber(int dn) { dayNumber = dn; }
    void setWeather(Weather w) { weather = w; }
};
