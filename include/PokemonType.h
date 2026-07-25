#pragma once

#include <string>

enum class PokemonType
{
    None,
    Normal,
    Fire,
    Water,
    Grass,
    Electric,
    Ice,
    Fighting,
    Poison,
    Ground,
    Flying,
    Psychic,
    Bug,
    Rock,
    Ghost,
    Dragon,
    Dark,
    Steel,
    Fairy
};

inline std::string PokemonTypeToString(PokemonType type)
{
    switch (type)
    {
    case PokemonType::None: return "None";
    case PokemonType::Normal: return "Normal";
    case PokemonType::Fire: return "Fire";
    case PokemonType::Water: return "Water";
    case PokemonType::Grass: return "Grass";
    case PokemonType::Electric: return "Electric";
    case PokemonType::Ice: return "Ice";
    case PokemonType::Fighting: return "Fighting";
    case PokemonType::Poison: return "Poison";
    case PokemonType::Ground: return "Ground";
    case PokemonType::Flying: return "Flying";
    case PokemonType::Psychic: return "Psychic";
    case PokemonType::Bug: return "Bug";
    case PokemonType::Rock: return "Rock";
    case PokemonType::Ghost: return "Ghost";
    case PokemonType::Dragon: return "Dragon";
    case PokemonType::Dark: return "Dark";
    case PokemonType::Steel: return "Steel";
    case PokemonType::Fairy: return "Fairy";
    }
    return "Unknown";
}
