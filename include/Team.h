#pragma once

#include "Pokemon.h"

constexpr int TEAM_SIZE = 6;

class Team
{
private:
    Pokemon team[TEAM_SIZE];
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