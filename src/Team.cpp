#include "Team.h"

Team::Team(Pokemon team[6])
{
    for (int i = 0; i < 6; i++)
    {
        this->team[i] = team[i];
    }

    activePokemonIndex = 0;
}

Pokemon& Team::getActivePokemon()
{
    return team[activePokemonIndex];
}

Pokemon& Team::getPokemon(int index)
{
    return team[index];
}

bool Team::switchPokemon(int index)
{
    if (index < 0 || index >= 6)
    {
        return false;
    }

    if (team[index].isFainted())
    {
        return false;
    }

    if (index == activePokemonIndex)
    {
        return false;
    }

    activePokemonIndex = index;
    return true;
}

bool Team::hasUsablePokemon() const
{
    for (int i = 0; i < 6; i++)
    {
        if (!team[i].isFainted())
        {
            return true;
        }
    }

    return false;
}
