#include <iostream>
#include "Move.h"
#include "Pokemon.h"
#include "Trainer.h"
#include "Battle.h"

using namespace std;

int main()
{
    // =========================
    // Electric
    // =========================
    Move pikachuMoves[4] = {
        Move("Thunderbolt", PokemonType::Electric, 90, 15, 100),
        Move("Quick Attack", PokemonType::Normal, 40, 30, 100),
        Move("Iron Tail", PokemonType::Steel, 100, 15, 75),
        Move("Thunder", PokemonType::Electric, 110, 10, 70)
    };

    // =========================
    // Fire
    // =========================
    Move charizardMoves[4] = {
        Move("Flamethrower", PokemonType::Fire, 90, 15, 100),
        Move("Slash", PokemonType::Normal, 70, 20, 100),
        Move("Fire Blast", PokemonType::Fire, 110, 5, 85),
        Move("Air Slash", PokemonType::Flying, 75, 15, 95)
    };

    // =========================
    // Water
    // =========================
    Move blastoiseMoves[4] = {
        Move("Hydro Pump", PokemonType::Water, 110, 5, 80),
        Move("Water Pulse", PokemonType::Water, 60, 20, 100),
        Move("Bite", PokemonType::Dark, 60, 25, 100),
        Move("Ice Beam", PokemonType::Ice, 90, 10, 100)
    };

    // =========================
    // Grass
    // =========================
    Move venusaurMoves[4] = {
        Move("Solar Beam", PokemonType::Grass, 120, 10, 100),
        Move("Razor Leaf", PokemonType::Grass, 55, 25, 95),
        Move("Sludge Bomb", PokemonType::Poison, 90, 10, 100),
        Move("Earthquake", PokemonType::Ground, 100, 10, 100)
    };

    // =========================
    // Fighting
    // =========================
    Move lucarioMoves[4] = {
        Move("Aura Sphere", PokemonType::Fighting, 80, 20, 100),
        Move("Meteor Mash", PokemonType::Steel, 90, 10, 90),
        Move("Bone Rush", PokemonType::Ground, 65, 10, 90),
        Move("Extreme Speed", PokemonType::Normal, 80, 5, 100)
    };

    // =========================
    // Dragon
    // =========================
    Move dragoniteMoves[4] = {
        Move("Dragon Claw", PokemonType::Dragon, 80, 15, 100),
        Move("Hurricane", PokemonType::Flying, 110, 10, 70),
        Move("Fire Punch", PokemonType::Fire, 75, 15, 100),
        Move("Hyper Beam", PokemonType::Normal, 150, 5, 90)
    };

    // =========================
    // Ghost
    // =========================
    Move gengarMoves[4] = {
        Move("Shadow Ball", PokemonType::Ghost, 80, 15, 100),
        Move("Dark Pulse", PokemonType::Dark, 80, 15, 100),
        Move("Sludge Bomb", PokemonType::Poison, 90, 10, 100),
        Move("Dream Eater", PokemonType::Psychic, 100, 15, 100)
    };

    // =========================
    // Psychic
    // =========================
    Move alakazamMoves[4] = {
        Move("Psychic", PokemonType::Psychic, 90, 10, 100),
        Move("Shadow Ball", PokemonType::Ghost, 80, 15, 100),
        Move("Energy Ball", PokemonType::Grass, 90, 10, 100),
        Move("Recover", PokemonType::Normal, 0, 10, 100)
    };

    // =========================
    // Dark
    // =========================
    Move tyranitarMoves[4] = {
        Move("Crunch", PokemonType::Dark, 80, 15, 100),
        Move("Stone Edge", PokemonType::Rock, 100, 5, 80),
        Move("Earthquake", PokemonType::Ground, 100, 10, 100),
        Move("Ice Punch", PokemonType::Ice, 75, 15, 100)
    };

    // =========================
    // Water Ninja
    // =========================
    Move greninjaMoves[4] = {
        Move("Water Shuriken", PokemonType::Water, 75, 20, 100),
        Move("Night Slash", PokemonType::Dark, 70, 15, 100),
        Move("Surf", PokemonType::Water, 90, 15, 100),
        Move("Ice Beam", PokemonType::Ice, 90, 10, 100)
    };

    // =========================
    // Steel
    // =========================
    Move metagrossMoves[4] = {
        Move("Meteor Mash", PokemonType::Steel, 90, 10, 90),
        Move("Zen Headbutt", PokemonType::Psychic, 80, 15, 90),
        Move("Earthquake", PokemonType::Ground, 100, 10, 100),
        Move("Bullet Punch", PokemonType::Steel, 40, 30, 100)
    };

    // =========================
    // Fairy
    // =========================
    Move gardevoirMoves[4] = {
        Move("Moonblast", PokemonType::Fairy, 95, 15, 100),
        Move("Psychic", PokemonType::Psychic, 90, 10, 100),
        Move("Thunderbolt", PokemonType::Electric, 90, 15, 100),
        Move("Calm Mind", PokemonType::Psychic, 0, 20, 100)
    };

    // =====================================================
    // Pokemon
    // =====================================================

    Pokemon pikachu("Pikachu", PokemonType::Electric, PokemonType::None, 100, 70, 45, 60, 50, 90, pikachuMoves);

    Pokemon charizard("Charizard", PokemonType::Fire, PokemonType::Flying, 120, 84, 78, 109, 85, 100, charizardMoves);

    Pokemon blastoise("Blastoise", PokemonType::Water, PokemonType::None, 130, 83, 100, 85, 105, 78, blastoiseMoves);

    Pokemon venusaur("Venusaur", PokemonType::Grass, PokemonType::Poison, 125, 82, 83, 100, 100, 80, venusaurMoves);

    Pokemon lucario("Lucario", PokemonType::Fighting, PokemonType::Steel, 110, 90, 70, 115, 70, 95, lucarioMoves);

    Pokemon dragonite("Dragonite", PokemonType::Dragon, PokemonType::Flying, 150, 134, 95, 100, 100, 80, dragoniteMoves);

    Pokemon gengar("Gengar", PokemonType::Ghost, PokemonType::Poison, 100, 65, 60, 130, 75, 110, gengarMoves);

    Pokemon alakazam("Alakazam", PokemonType::Psychic, PokemonType::None, 95, 50, 45, 135, 95, 120, alakazamMoves);

    Pokemon tyranitar("Tyranitar", PokemonType::Rock, PokemonType::Dark, 160, 134, 110, 95, 100, 61, tyranitarMoves);

    Pokemon greninja("Greninja", PokemonType::Water, PokemonType::Dark, 115, 95, 67, 103, 71, 122, greninjaMoves);

    Pokemon metagross("Metagross", PokemonType::Steel, PokemonType::Psychic, 150, 135, 130, 95, 90, 70, metagrossMoves);

    Pokemon gardevoir("Gardevoir", PokemonType::Psychic, PokemonType::Fairy, 110, 65, 65, 125, 115, 80, gardevoirMoves);

    // =====================================================
    // Teams
    // =====================================================

    Pokemon ashTeam[6] = {
        pikachu,
        lucario,
        greninja,
        dragonite,
        gengar,
        gardevoir
    };

    Pokemon garyTeam[6] = {
        charizard,
        blastoise,
        venusaur,
        tyranitar,
        metagross,
        alakazam
    };

    Trainer ash("Ash", ashTeam);
    Trainer gary("Gary", garyTeam);

    Battle battle(ash, gary);

    battle.startBattle();

    return 0;
}