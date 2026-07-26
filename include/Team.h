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
    const Pokemon& getActivePokemon() const;
    Pokemon& getPokemon(int index);
    const Pokemon& getPokemon(int index) const;

    bool switchPokemon(int index);

    bool hasUsablePokemon() const;
};