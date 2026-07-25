#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon()
    : name(), type1(PokemonType::None), type2(PokemonType::None), maxHP(0), currentHP(0),
      attack(0), defense(0), spAttack(0), spDefense(0), speed(0)
{
}

Pokemon::Pokemon(
    std::string name,
    PokemonType type1,
    PokemonType type2,
    int maxHP,
    int attack,
    int defense,
    int spAttack,
    int spDefense,
    int speed,
    Move moves[4]
)
    : name(std::move(name)), type1(type1), type2(type2), maxHP(maxHP), currentHP(maxHP),
      attack(attack), defense(defense), spAttack(spAttack), spDefense(spDefense), speed(speed)
{
    for (int i = 0; i < 4; i++) {
        this->moves[i] = moves[i];
    }
}

bool Pokemon::useMove(int index)
{
    return moves[index].use();
}

void Pokemon::takeDamage(int damage)
{
    if (damage >= currentHP)
    {
        currentHP = 0;
        return;
    }

    currentHP -= damage;
}

void Pokemon::heal()
{
    currentHP = maxHP;
}

bool Pokemon::isFainted() const
{
    return currentHP == 0;
}

void Pokemon::displayStats() const
{
    std::cout << "\n==============================";
    std::cout << "\nPokemon : " << name;
    std::cout << "\nType : " << PokemonTypeToString(type1);
    if (type2 != PokemonType::None)
    {
        std::cout << "/" << PokemonTypeToString(type2);
    }
    std::cout << "\nHP : " << currentHP << "/" << maxHP;
    std::cout << "\nAttack : " << attack;
    std::cout << "\nDefense : " << defense;
    std::cout << "\nSp. Attack : " << spAttack;
    std::cout << "\nSp. Defense : " << spDefense;
    std::cout << "\nSpeed : " << speed;
    std::cout << "\n==============================\n";
}

std::string Pokemon::getName() const
{
    return name;
}

int Pokemon::getCurrentHP() const
{
    return currentHP;
}

int Pokemon::getMaxHP() const
{
    return maxHP;
}

int Pokemon::getAttack() const
{
    return attack;
}

int Pokemon::getDefense() const
{
    return defense;
}

int Pokemon::getSpAttack() const
{
    return spAttack;
}

int Pokemon::getSpDefense() const
{
    return spDefense;
}

int Pokemon::getSpeed() const
{
    return speed;
}

PokemonType Pokemon::getType1() const
{
    return type1;
}

PokemonType Pokemon::getType2() const
{
    return type2;
}

Move& Pokemon::getMove(int index)
{
    return moves[index];
}
