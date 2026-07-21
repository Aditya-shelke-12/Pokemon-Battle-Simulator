#pragma once

#include "Pokemon.h"

class Team
{
private:
    Pokemon team[6];
    int activePokemonIndex;

public:
    Team(Pokemon team[6]);

    Pokemon& getActivePokemon();
    Pokemon& getPokemon(int index);

    bool switchPokemon(int index);

    bool hasUsablePokemon() const;
};