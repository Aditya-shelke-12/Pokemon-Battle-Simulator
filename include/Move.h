#pragma once

#include <string>
#include "PokemonType.h"

class Move
{
private:
    std::string name;
    PokemonType type;

    int power;
    short int pp;
    short int accuracy;

public:
    Move();
    Move(std::string name,
         PokemonType type,
         int power,
         short int pp,
         short int accuracy);

    std::string getName() const;

    PokemonType getType() const;

    int getPower() const;

    short int getPP() const;

    short int getAccuracy() const;

    bool use();

    void showInfo() const;
};