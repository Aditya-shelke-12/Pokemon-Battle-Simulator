#include "Team.h"

Team::Team(Pokemon team[TEAM_SIZE])
{
    for (int i = 0; i < TEAM_SIZE; i++)
    {
        this->team[i] = team[i];
    }

    activePokemonIndex = 0;
}

Pokemon& Team::getActivePokemon ()
{
    return team[activePokemonIndex];
}

const Pokemon& Team::getActivePokemon() const
{
    return team[activePokemonIndex];
}

Pokemon& Team::getPokemon(int index)
{
    return team[index];
}

const Pokemon& Team::getPokemon(int index) const
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
    for (int i = 0; i < TEAM_SIZE; i++)
    {
        if (!team[i].isFainted())
        {
            return true;
        }
    }

    return false;
}
