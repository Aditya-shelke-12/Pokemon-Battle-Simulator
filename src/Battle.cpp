#include <iostream>
#include <limits>
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


void Battle::startBattle(){

    while (!checkWinner()){

        executeTurn(player, opponent);

        if (checkWinner()){

            break;
        }

        executeTurn(opponent, player);
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

void Battle::executeTurn(Trainer& attacker, Trainer& defender)
{
    Pokemon& attackerPokemon = attacker.getTeam().getActivePokemon();
    Pokemon& defenderPokemon = defender.getTeam().getActivePokemon();

    std::cout << "\n----------------------------------------";
    std::cout << "\n" << attackerPokemon.getName()
              << " (HP : " << attackerPokemon.getCurrentHP()
              << "/" << attackerPokemon.getMaxHP() << ")";
    std::cout << "\nVS";
    std::cout << "\n" << defenderPokemon.getName()
              << " (HP : " << defenderPokemon.getCurrentHP()
              << "/" << defenderPokemon.getMaxHP() << ")";
    std::cout << "\n----------------------------------------";

    std::cout << "\nChoose a move:\n\n";

    for (int i = 0; i < 4; i++)
    {
        std::cout << i + 1 << ". "
                  << attackerPokemon.getMove(i).getName()
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

    Move& selectedMove = attackerPokemon.getMove(choice - 1);

    Battle::DamageResult result = calculateDamage(
        attackerPokemon,
        defenderPokemon,
        selectedMove
    );
    
    defenderPokemon.takeDamage(result.damage);

    std::cout << "\n"
              << attackerPokemon.getName()
              << " used "
              << selectedMove.getName()
              << "!\n";
    
    if (result.typeMultiplier > 1){
        std::cout<<"It's Super Effective !";
    } else if (result.typeMultiplier == 0){
        std::cout<<"It has no effect! on " <<defenderPokemon.getName();
    } else if (result.typeMultiplier < 1){
        std::cout<<"It's not very Effective !";
    }

    std::cout << "It dealt "
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

    double stabMultiplier = 1;

    double multiplier =
        TypeChart::getMultiplier(move.getType(), defender.getType1()) *
        TypeChart::getMultiplier(move.getType(), defender.getType2());

    if (move.getType() == attacker.getType1() ||
        move.getType() == attacker.getType2())
    {
        stabMultiplier = 1.5;
    }

    damage *= multiplier;
    damage *= stabMultiplier;

    if (multiplier == 0){
        result.damage = 0;
    } else {
        result.damage = std::max(1, damage);
    }

    result.stabMultiplier = stabMultiplier;
    result.typeMultiplier = multiplier;
    return result;
}

void Battle::handleFaintedPokemon(Trainer& trainer)
{
    Team& team = trainer.getTeam();

    for (int i = 0; i < 6; i++)
    {
        if (!team.getPokemon(i).isFainted())
        {
            team.switchPokemon(i);

            std::cout << trainer.getName()
                      << " sent out "
                      << team.getActivePokemon().getName()
                      << "!\n\n";

            return;
        }
    }

    std::cout << trainer.getName()
              << " has no usable Pokemon left!\n\n";
}

bool Battle::checkWinner() const{

    if (player.getTeam().hasUsablePokemon() && opponent.getTeam().hasUsablePokemon()){

        return false;
    }

    return true;
}