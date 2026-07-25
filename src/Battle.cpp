#include <iostream>
#include <limits>
#include <cstdlib>
#include "Battle.h"
#include "Trainer.h"
#include "Pokemon.h"
#include "Move.h"
#include "PokemonType.h"
#include "TypeChart.h"

Battle::Battle(const Trainer& player, const Trainer& opponent)
    : player(player), opponent(opponent)
{
}


void Battle::startBattle()
{
    while (!checkWinner())
    {
        Pokemon& playerPokemon = player.getTeam().getActivePokemon();
        Pokemon& opponentPokemon = opponent.getTeam().getActivePokemon();

        std::cout << "\n----------------------------------------";
        std::cout << "\n" << playerPokemon.getName()
                << " (HP : " << playerPokemon.getCurrentHP()
                << "/" << playerPokemon.getMaxHP() << ")";
        std::cout << "\nVS";
        std::cout << "\n" << opponentPokemon.getName()
                << " (HP : " << opponentPokemon.getCurrentHP()
                << "/" << opponentPokemon.getMaxHP() << ")";
        std::cout << "\n----------------------------------------";

        // Player chooses move
        Move& playerMove = chooseMove(player);

        // Opponent chooses move
        Move& opponentMove = chooseMove(opponent);


        if (playerMovesFirst())
        {
            executeAttack(player, opponent, playerMove);

            if (!checkWinner())
            {
                executeAttack(opponent, player, opponentMove);
            }
        }
        else
        {
            executeAttack(opponent, player, opponentMove);

            if (!checkWinner())
            {
                executeAttack(player, opponent, playerMove);
            }
        }
    }

    std::cout << "\n==============================\n";
    std::cout << "Battle Finished!\n";

    bool playerHasPokemon = player.getTeam().hasUsablePokemon();
    bool opponentHasPokemon = opponent.getTeam().hasUsablePokemon();

    if (playerHasPokemon && !opponentHasPokemon)
    {
        std::cout << "Winner : " << player.getName() << "\n";
    }
    else if (!playerHasPokemon && opponentHasPokemon)
    {
        std::cout << "Winner : " << opponent.getName() << "\n";
    }
    else
    {
        std::cout << "Winner : None (tie or both teams are out of usable Pokemon)\n";
    }

    std::cout << "==============================\n";
}

Move& Battle::chooseMove(Trainer& trainer)
{
    Pokemon& active = trainer.getTeam().getActivePokemon();

    std::cout << "\nChoose a move:\n\n";

    for (int i = 0; i < 4; i++)
    {
        std::cout << i + 1 << ". "
                  << active.getMove(i).getName()
                  << "\n";
    }

    int choice;

    while (true)
    {
        std::cout << "\nEnter your choice : ";

        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter a number.\n";
            continue;
        }

        if (choice >= 1 && choice <= 4)
            break;

        std::cout << "Invalid choice. Enter 1-4.\n";
    }

    return active.getMove(choice - 1);
}

void Battle::executeAttack(Trainer& attacker, Trainer& defender, Move& selectedMove)
{
    Pokemon& attackerPokemon = attacker.getTeam().getActivePokemon();
    Pokemon& defenderPokemon = defender.getTeam().getActivePokemon();

    std::cout << "\n"
              << attackerPokemon.getName()
              << " used "
              << selectedMove.getName()
              << "!\n\n";

    if (!attackHits(selectedMove)) 
    { 
        std::cout << "The attack missed!\n"; 
        return; 
    }

    DamageResult result = calculateDamage(
        attackerPokemon,
        defenderPokemon,
        selectedMove
    );

    if (result.typeMultiplier > 1)
    { 
        std::cout<<"It's Super Effective ! \n"; 
    } else if (result.typeMultiplier == 0)
    { 
        std::cout<<"It doesnt affect " <<defenderPokemon.getName() <<"\n"; 
    } else if (result.typeMultiplier < 1)
    { 
        std::cout<<"It's not very Effective !\n"; 
    }

    if (result.critical){
        std::cout<<"It's Critical Hit!\n";
    }

    defenderPokemon.takeDamage(result.damage);

    std::cout << "\nIt dealt "
              << result.damage
              << " damage!\n";

    std::cout << defenderPokemon.getName()
              << "'s HP: "
              << defenderPokemon.getCurrentHP()
              << "/"
              << defenderPokemon.getMaxHP()
              << "\n";

    if (defenderPokemon.isFainted())
    {
        std::cout << defenderPokemon.getName()
                  << " fainted!\n";

        handleFaintedPokemon(defender);
    }
}

Battle::DamageResult Battle::calculateDamage(const Pokemon& attacker,
                            const Pokemon& defender,
                            const Move& move){

    Battle::DamageResult result;

    int damage = move.getPower() + attacker.getAttack() / 2 - defender.getDefense()/ 3;

    double multiplier =
        TypeChart::getMultiplier(move.getType(), defender.getType1()) *
        TypeChart::getMultiplier(move.getType(), defender.getType2());

    double stabMultiplier = 1;

    if (move.getType() == attacker.getType1() ||
        move.getType() == attacker.getType2())
    {
        stabMultiplier = 1.5;
    }

    damage *= multiplier;
    damage *= stabMultiplier;

    if (isCriticalHit())
    {
        damage *= 1.5;
        result.critical = true;
    }
    else
    {
        result.critical = false;
    }

    if (multiplier == 0){
        result.damage = 0;
    } else {
        result.damage = std::max(1, damage);
    }

    result.typeMultiplier = multiplier;
    result.stabMultiplier = stabMultiplier;

    return result;
}

bool Battle::isCriticalHit(){

    int roll = rand()%100 + 1;

    return roll <= 10;
}

bool Battle::attackHits(const Move& move)
{
    int roll = rand() %100 + 1;

    return roll <= move.getAccuracy();
}

bool Battle::playerMovesFirst()
{
    int playerSpeed = player.getTeam().getActivePokemon().getSpeed();
    int opponentSpeed = opponent.getTeam().getActivePokemon().getSpeed();

    if(playerSpeed == opponentSpeed) 
        return rand() % 2;

    return playerSpeed > opponentSpeed;
}

void Battle::handleFaintedPokemon(Trainer& trainer)
{
    Team& team = trainer.getTeam();

    for (int i = 0; i < 6; i++)
    {
        if (!team.getPokemon(i).isFainted())
        {
            team.switchPokemon(i);

            std::cout << "\n" <<trainer.getName()
                      << " sent out "
                      << team.getActivePokemon().getName()
                      << "!\n";

            return;
        }
    }

    std::cout << trainer.getName()
              << " has no usable Pokemon left!\n\n";
}

bool Battle::checkWinner() const
{
    if (player.getTeam().hasUsablePokemon() && opponent.getTeam().hasUsablePokemon()){

        return false;
    }

    return true;
}

