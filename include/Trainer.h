#pragma once

#include <string>
#include "Team.h"

class Trainer
{
private:
    std::string name;
    Team team;

public:
    Trainer(std::string name, Pokemon team[6]);

    std::string getName() const;
    Team& getTeam();
    const Team& getTeam() const;
};