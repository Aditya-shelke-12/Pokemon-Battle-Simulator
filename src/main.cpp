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
        Move("Thunderbolt", "Electric", 90, 15, 100),
        Move("Quick Attack", "Normal", 40, 30, 100),
        Move("Iron Tail", "Steel", 100, 15, 75),
        Move("Thunder", "Electric", 110, 10, 70)
    };

    // =========================
    // Fire
    // =========================
    Move charizardMoves[4] = {
        Move("Flamethrower", "Fire", 90, 15, 100),
        Move("Slash", "Normal", 70, 20, 100),
        Move("Fire Blast", "Fire", 110, 5, 85),
        Move("Air Slash", "Flying", 75, 15, 95)
    };

    // =========================
    // Water
    // =========================
    Move blastoiseMoves[4] = {
        Move("Hydro Pump", "Water", 110, 5, 80),
        Move("Water Pulse", "Water", 60, 20, 100),
        Move("Bite", "Dark", 60, 25, 100),
        Move("Ice Beam", "Ice", 90, 10, 100)
    };

    // =========================
    // Grass
    // =========================
    Move venusaurMoves[4] = {
        Move("Solar Beam", "Grass", 120, 10, 100),
        Move("Razor Leaf", "Grass", 55, 25, 95),
        Move("Sludge Bomb", "Poison", 90, 10, 100),
        Move("Earthquake", "Ground", 100, 10, 100)
    };

    // =========================
    // Fighting
    // =========================
    Move lucarioMoves[4] = {
        Move("Aura Sphere", "Fighting", 80, 20, 100),
        Move("Meteor Mash", "Steel", 90, 10, 90),
        Move("Bone Rush", "Ground", 65, 10, 90),
        Move("Extreme Speed", "Normal", 80, 5, 100)
    };

    // =========================
    // Dragon
    // =========================
    Move dragoniteMoves[4] = {
        Move("Dragon Claw", "Dragon", 80, 15, 100),
        Move("Hurricane", "Flying", 110, 10, 70),
        Move("Fire Punch", "Fire", 75, 15, 100),
        Move("Hyper Beam", "Normal", 150, 5, 90)
    };

    // =========================
    // Ghost
    // =========================
    Move gengarMoves[4] = {
        Move("Shadow Ball", "Ghost", 80, 15, 100),
        Move("Dark Pulse", "Dark", 80, 15, 100),
        Move("Sludge Bomb", "Poison", 90, 10, 100),
        Move("Dream Eater", "Psychic", 100, 15, 100)
    };

    // =========================
    // Psychic
    // =========================
    Move alakazamMoves[4] = {
        Move("Psychic", "Psychic", 90, 10, 100),
        Move("Shadow Ball", "Ghost", 80, 15, 100),
        Move("Energy Ball", "Grass", 90, 10, 100),
        Move("Recover", "Normal", 0, 10, 100)
    };

    // =========================
    // Dark
    // =========================
    Move tyranitarMoves[4] = {
        Move("Crunch", "Dark", 80, 15, 100),
        Move("Stone Edge", "Rock", 100, 5, 80),
        Move("Earthquake", "Ground", 100, 10, 100),
        Move("Ice Punch", "Ice", 75, 15, 100)
    };

    // =========================
    // Water Ninja
    // =========================
    Move greninjaMoves[4] = {
        Move("Water Shuriken", "Water", 75, 20, 100),
        Move("Night Slash", "Dark", 70, 15, 100),
        Move("Surf", "Water", 90, 15, 100),
        Move("Ice Beam", "Ice", 90, 10, 100)
    };

    // =========================
    // Steel
    // =========================
    Move metagrossMoves[4] = {
        Move("Meteor Mash", "Steel", 90, 10, 90),
        Move("Zen Headbutt", "Psychic", 80, 15, 90),
        Move("Earthquake", "Ground", 100, 10, 100),
        Move("Bullet Punch", "Steel", 40, 30, 100)
    };

    // =========================
    // Fairy
    // =========================
    Move gardevoirMoves[4] = {
        Move("Moonblast", "Fairy", 95, 15, 100),
        Move("Psychic", "Psychic", 90, 10, 100),
        Move("Thunderbolt", "Electric", 90, 15, 100),
        Move("Calm Mind", "Psychic", 0, 20, 100)
    };

    // =====================================================
    // Pokemon
    // =====================================================

    Pokemon pikachu("Pikachu","Electric",100,70,45,60,50,90,pikachuMoves);

    Pokemon charizard("Charizard","Fire",120,84,78,109,85,100,charizardMoves);

    Pokemon blastoise("Blastoise","Water",130,83,100,85,105,78,blastoiseMoves);

    Pokemon venusaur("Venusaur","Grass",125,82,83,100,100,80,venusaurMoves);

    Pokemon lucario("Lucario","Fighting",110,90,70,115,70,95,lucarioMoves);

    Pokemon dragonite("Dragonite","Dragon",150,134,95,100,100,80,dragoniteMoves);

    Pokemon gengar("Gengar","Ghost",100,65,60,130,75,110,gengarMoves);

    Pokemon alakazam("Alakazam","Psychic",95,50,45,135,95,120,alakazamMoves);

    Pokemon tyranitar("Tyranitar","Rock",160,134,110,95,100,61,tyranitarMoves);

    Pokemon greninja("Greninja","Water",115,95,67,103,71,122,greninjaMoves);

    Pokemon metagross("Metagross","Steel",150,135,130,95,90,70,metagrossMoves);

    Pokemon gardevoir("Gardevoir","Fairy",110,65,65,125,115,80,gardevoirMoves);

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