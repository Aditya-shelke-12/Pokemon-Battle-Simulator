#pragma once

#include <string>

class Move
{
private:
    std::string name;
    std::string type;

    int power;
    short int pp;
    short int accuracy;

public:
    Move();
    Move(std::string name,
         std::string type,
         int power,
         short int pp,
         short int accuracy);

    std::string getName() const;

    std::string getType() const;

    int getPower() const;

    short int getPP() const;

    short int getAccuracy() const;

    bool use();

    void showInfo();
};