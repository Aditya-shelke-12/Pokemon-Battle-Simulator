#pragma once

#include "PokemonType.h"

class TypeChart{

    public:

    static double getMultiplier(PokemonType attackType, PokemonType defendType);

};