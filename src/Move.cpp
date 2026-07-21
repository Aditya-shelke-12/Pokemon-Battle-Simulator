#include "Move.h"
#include <iostream>

Move::Move()
    : name(""), type(""), power(0), pp(0), accuracy(0)
{
}

Move::Move(std::string name,
    std::string type,
    int power,
    short int pp,
    short int accuracy)
    : name(std::move(name)), type(std::move(type)), power(power), pp(pp), accuracy(accuracy)
{
}

std::string Move::getName() const
{
    return name;
}

std::string Move::getType() const
{
    return type;
}

int Move::getPower() const
{
    return power;
}

short int Move::getPP() const
{
    return pp;
}

short int Move::getAccuracy() const
{
    return accuracy;
}

bool Move::use()
{
    if (pp == 0)
    {
        return false;
    }

    --pp;
    return true;
}

void Move::showInfo()
{
    std::cout << "=====================";
    std::cout << "\nmove : " << name;
    std::cout << "\nType : " << type;
    std::cout << "\nPower : " << power;
    std::cout << "\nAccuracy : " << accuracy;
    std::cout << "\nPP : " << pp;
    std::cout << "\n=====================";
}
