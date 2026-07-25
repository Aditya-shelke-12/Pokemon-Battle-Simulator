#include "PokemonType.h"
#include "TypeChart.h"

static void initializeTypeChart(double typeChart[19][19])
{
    for (int i = 0; i < 19; ++i)
    {
        for (int j = 0; j < 19; ++j)
        {
            typeChart[i][j] = 1.0;
        }
    }

    // Normal
    typeChart[(int)PokemonType::Normal][(int)PokemonType::Rock] = 0.5;
    typeChart[(int)PokemonType::Normal][(int)PokemonType::Steel] = 0.5;
    typeChart[(int)PokemonType::Normal][(int)PokemonType::Ghost] = 0.0;

    // Fire
    typeChart[(int)PokemonType::Fire][(int)PokemonType::Grass] = 2.0;
    typeChart[(int)PokemonType::Fire][(int)PokemonType::Ice] = 2.0;
    typeChart[(int)PokemonType::Fire][(int)PokemonType::Bug] = 2.0;
    typeChart[(int)PokemonType::Fire][(int)PokemonType::Steel] = 2.0;
    typeChart[(int)PokemonType::Fire][(int)PokemonType::Fire] = 0.5;
    typeChart[(int)PokemonType::Fire][(int)PokemonType::Water] = 0.5;
    typeChart[(int)PokemonType::Fire][(int)PokemonType::Rock] = 0.5;
    typeChart[(int)PokemonType::Fire][(int)PokemonType::Dragon] = 0.5;

    // Water
    typeChart[(int)PokemonType::Water][(int)PokemonType::Fire] = 2.0;
    typeChart[(int)PokemonType::Water][(int)PokemonType::Ground] = 2.0;
    typeChart[(int)PokemonType::Water][(int)PokemonType::Rock] = 2.0;
    typeChart[(int)PokemonType::Water][(int)PokemonType::Water] = 0.5;
    typeChart[(int)PokemonType::Water][(int)PokemonType::Grass] = 0.5;
    typeChart[(int)PokemonType::Water][(int)PokemonType::Dragon] = 0.5;

    // Grass
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Water] = 2.0;
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Ground] = 2.0;
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Rock] = 2.0;
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Fire] = 0.5;
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Grass] = 0.5;
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Poison] = 0.5;
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Flying] = 0.5;
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Bug] = 0.5;
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Dragon] = 0.5;
    typeChart[(int)PokemonType::Grass][(int)PokemonType::Steel] = 0.5;

    // Electric
    typeChart[(int)PokemonType::Electric][(int)PokemonType::Water] = 2.0;
    typeChart[(int)PokemonType::Electric][(int)PokemonType::Flying] = 2.0;
    typeChart[(int)PokemonType::Electric][(int)PokemonType::Electric] = 0.5;
    typeChart[(int)PokemonType::Electric][(int)PokemonType::Grass] = 0.5;
    typeChart[(int)PokemonType::Electric][(int)PokemonType::Dragon] = 0.5;
    typeChart[(int)PokemonType::Electric][(int)PokemonType::Ground] = 0.0;

    // Ice
    typeChart[(int)PokemonType::Ice][(int)PokemonType::Grass] = 2.0;
    typeChart[(int)PokemonType::Ice][(int)PokemonType::Ground] = 2.0;
    typeChart[(int)PokemonType::Ice][(int)PokemonType::Flying] = 2.0;
    typeChart[(int)PokemonType::Ice][(int)PokemonType::Dragon] = 2.0;
    typeChart[(int)PokemonType::Ice][(int)PokemonType::Fire] = 0.5;
    typeChart[(int)PokemonType::Ice][(int)PokemonType::Water] = 0.5;
    typeChart[(int)PokemonType::Ice][(int)PokemonType::Ice] = 0.5;
    typeChart[(int)PokemonType::Ice][(int)PokemonType::Steel] = 0.5;

    // Fighting
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Normal] = 2.0;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Ice] = 2.0;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Rock] = 2.0;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Dark] = 2.0;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Steel] = 2.0;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Poison] = 0.5;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Flying] = 0.5;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Psychic] = 0.5;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Bug] = 0.5;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Fairy] = 0.5;
    typeChart[(int)PokemonType::Fighting][(int)PokemonType::Ghost] = 0.0;

    // Poison
    typeChart[(int)PokemonType::Poison][(int)PokemonType::Grass] = 2.0;
    typeChart[(int)PokemonType::Poison][(int)PokemonType::Fairy] = 2.0;
    typeChart[(int)PokemonType::Poison][(int)PokemonType::Poison] = 0.5;
    typeChart[(int)PokemonType::Poison][(int)PokemonType::Ground] = 0.5;
    typeChart[(int)PokemonType::Poison][(int)PokemonType::Rock] = 0.5;
    typeChart[(int)PokemonType::Poison][(int)PokemonType::Ghost] = 0.5;
    typeChart[(int)PokemonType::Poison][(int)PokemonType::Steel] = 0.0;

    // Ground
    typeChart[(int)PokemonType::Ground][(int)PokemonType::Fire] = 2.0;
    typeChart[(int)PokemonType::Ground][(int)PokemonType::Electric] = 2.0;
    typeChart[(int)PokemonType::Ground][(int)PokemonType::Poison] = 2.0;
    typeChart[(int)PokemonType::Ground][(int)PokemonType::Rock] = 2.0;
    typeChart[(int)PokemonType::Ground][(int)PokemonType::Steel] = 2.0;
    typeChart[(int)PokemonType::Ground][(int)PokemonType::Grass] = 0.5;
    typeChart[(int)PokemonType::Ground][(int)PokemonType::Bug] = 0.5;
    typeChart[(int)PokemonType::Ground][(int)PokemonType::Flying] = 0.0;

    // Flying
    typeChart[(int)PokemonType::Flying][(int)PokemonType::Grass] = 2.0;
    typeChart[(int)PokemonType::Flying][(int)PokemonType::Fighting] = 2.0;
    typeChart[(int)PokemonType::Flying][(int)PokemonType::Bug] = 2.0;
    typeChart[(int)PokemonType::Flying][(int)PokemonType::Electric] = 0.5;
    typeChart[(int)PokemonType::Flying][(int)PokemonType::Rock] = 0.5;
    typeChart[(int)PokemonType::Flying][(int)PokemonType::Steel] = 0.5;

    // Psychic
    typeChart[(int)PokemonType::Psychic][(int)PokemonType::Fighting] = 2.0;
    typeChart[(int)PokemonType::Psychic][(int)PokemonType::Poison] = 2.0;
    typeChart[(int)PokemonType::Psychic][(int)PokemonType::Psychic] = 0.5;
    typeChart[(int)PokemonType::Psychic][(int)PokemonType::Steel] = 0.5;
    typeChart[(int)PokemonType::Psychic][(int)PokemonType::Dark] = 0.0;

    // Bug
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Grass] = 2.0;
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Psychic] = 2.0;
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Dark] = 2.0;
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Fire] = 0.5;
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Fighting] = 0.5;
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Poison] = 0.5;
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Flying] = 0.5;
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Ghost] = 0.5;
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Steel] = 0.5;
    typeChart[(int)PokemonType::Bug][(int)PokemonType::Fairy] = 0.5;

    // Rock
    typeChart[(int)PokemonType::Rock][(int)PokemonType::Fire] = 2.0;
    typeChart[(int)PokemonType::Rock][(int)PokemonType::Ice] = 2.0;
    typeChart[(int)PokemonType::Rock][(int)PokemonType::Flying] = 2.0;
    typeChart[(int)PokemonType::Rock][(int)PokemonType::Bug] = 2.0;
    typeChart[(int)PokemonType::Rock][(int)PokemonType::Fighting] = 0.5;
    typeChart[(int)PokemonType::Rock][(int)PokemonType::Ground] = 0.5;
    typeChart[(int)PokemonType::Rock][(int)PokemonType::Steel] = 0.5;

    // Ghost
    typeChart[(int)PokemonType::Ghost][(int)PokemonType::Psychic] = 2.0;
    typeChart[(int)PokemonType::Ghost][(int)PokemonType::Ghost] = 2.0;
    typeChart[(int)PokemonType::Ghost][(int)PokemonType::Dark] = 0.5;
    typeChart[(int)PokemonType::Ghost][(int)PokemonType::Normal] = 0.0;

    // Dragon
    typeChart[(int)PokemonType::Dragon][(int)PokemonType::Dragon] = 2.0;
    typeChart[(int)PokemonType::Dragon][(int)PokemonType::Steel] = 0.5;
    typeChart[(int)PokemonType::Dragon][(int)PokemonType::Fairy] = 0.0;

    // Dark
    typeChart[(int)PokemonType::Dark][(int)PokemonType::Psychic] = 2.0;
    typeChart[(int)PokemonType::Dark][(int)PokemonType::Ghost] = 2.0;
    typeChart[(int)PokemonType::Dark][(int)PokemonType::Fighting] = 0.5;
    typeChart[(int)PokemonType::Dark][(int)PokemonType::Dark] = 0.5;
    typeChart[(int)PokemonType::Dark][(int)PokemonType::Fairy] = 0.5;

    // Steel
    typeChart[(int)PokemonType::Steel][(int)PokemonType::Ice] = 2.0;
    typeChart[(int)PokemonType::Steel][(int)PokemonType::Rock] = 2.0;
    typeChart[(int)PokemonType::Steel][(int)PokemonType::Fairy] = 2.0;
    typeChart[(int)PokemonType::Steel][(int)PokemonType::Fire] = 0.5;
    typeChart[(int)PokemonType::Steel][(int)PokemonType::Water] = 0.5;
    typeChart[(int)PokemonType::Steel][(int)PokemonType::Electric] = 0.5;
    typeChart[(int)PokemonType::Steel][(int)PokemonType::Steel] = 0.5;

    // Fairy
    typeChart[(int)PokemonType::Fairy][(int)PokemonType::Fighting] = 2.0;
    typeChart[(int)PokemonType::Fairy][(int)PokemonType::Dragon] = 2.0;
    typeChart[(int)PokemonType::Fairy][(int)PokemonType::Dark] = 2.0;
    typeChart[(int)PokemonType::Fairy][(int)PokemonType::Fire] = 0.5;
    typeChart[(int)PokemonType::Fairy][(int)PokemonType::Poison] = 0.5;
    typeChart[(int)PokemonType::Fairy][(int)PokemonType::Steel] = 0.5;
}

double TypeChart::getMultiplier(PokemonType attackType, PokemonType defendType)
{
    static double typeChart[19][19];
    static bool initialized = false;

    if (!initialized)
    {
        initializeTypeChart(typeChart);
        initialized = true;
    }

    int attackIndex = static_cast<int>(attackType);
    int defendIndex = static_cast<int>(defendType);

    if (attackIndex < 0 || attackIndex >= 19 || defendIndex < 0 || defendIndex >= 19)
    {
        return 1.0;
    }

    return typeChart[attackIndex][defendIndex];
}
