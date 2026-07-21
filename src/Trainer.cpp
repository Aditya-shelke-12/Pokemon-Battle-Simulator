#include "Trainer.h"

Trainer::Trainer(std::string name, Pokemon team[6])
    : team(team)
{
    this->name = std::move(name);
}

std::string Trainer::getName() const
{
    return name;
}

Team& Trainer::getTeam(){
    
    return team;
}

const Team& Trainer::getTeam() const{

    return team;
}