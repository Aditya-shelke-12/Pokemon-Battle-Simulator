#pragma once
#include "Move.h"
#include <string>


class Pokemon
{
private:
    std::string name;
    std::string type;

    int maxHP;
    int currentHP;

    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;

    Move moves[4];
public:

    Pokemon();
    Pokemon(
        std::string name,
        std::string type,
        int maxHP,
        int attack,
        int defense,
        int spAttack,
        int spDefense,
        int speed,
        Move moves[4]
    );

    bool useMove(int index);

    void takeDamage(int damage);

    void heal();

    bool isFainted() const;

    void displayStats() const;

    std::string getName() const;

    int getCurrentHP() const;

    int getMaxHP() const;

    int getAttack() const;

    int getDefense() const;

    int getSpAttack() const;

    int getSpDefense() const;

    int getSpeed() const;

    Move& getMove(int index);
};

