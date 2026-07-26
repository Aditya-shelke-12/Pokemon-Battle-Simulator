#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include "Battle.h"
#include "Trainer.h"
#include "Pokemon.h"
#include "Move.h"
#include "PokemonType.h"
#include "TypeChart.h"
#include "Action.h"

Battle::Battle(const Trainer& player, const Trainer& opponent)
    : player(player), opponent(opponent)
{
}


void Battle::startBattle()
{
    while (!checkWinner())
    {
        displayBattleStatus();

        Pokemon* playerAttacker = &player.getTeam().getActivePokemon();
        Pokemon* opponentAttacker = &opponent.getTeam().getActivePokemon();

        Move* playerMove = nullptr;
        Move* opponentMove = nullptr;

        // ---------- Player ----------
        Action playerAction = chooseAction(player);

        if (playerAction == Action::Fight)
        {
            playerMove = &chooseMove(player);
        }
        else
        {
            switchPokemon(player);
        }

        // ---------- Opponent ----------
        Action opponentAction = chooseAction(opponent);

        if (opponentAction == Action::Fight)
        {
            opponentMove = &chooseMove(opponent);
        }
        else
        {
            switchPokemon(opponent);
        }

        // ---------- Battle ----------
        if (playerMovesFirst())
        {
            if (playerMove &&
                &player.getTeam().getActivePokemon() == playerAttacker &&
                !checkWinner())
            {
                executeAttack(player, opponent, *playerMove);
            }

            if (opponentMove &&
                &opponent.getTeam().getActivePokemon() == opponentAttacker &&
                !checkWinner())
            {
                executeAttack(opponent, player, *opponentMove);
            }
        }
        else
        {
            if (opponentMove &&
                &opponent.getTeam().getActivePokemon() == opponentAttacker &&
                !checkWinner())
            {
                executeAttack(opponent, player, *opponentMove);
            }

            if (playerMove &&
                &player.getTeam().getActivePokemon() == playerAttacker &&
                !checkWinner())
            {
                executeAttack(player, opponent, *playerMove);
            }
        }
    }

    displayWinner();
}

void Battle::displayBattleStatus() {

    std::cout << "\n----------------------------------------\n";

    std::cout<<player.getName() <<" vs " <<opponent.getName();

    std::cout << "\n----------------------------------------\n";

    Pokemon& playerPokemon = player.getTeam().getActivePokemon();
    Pokemon& opponentPokemon = opponent.getTeam().getActivePokemon();

    std::cout << "\n" << playerPokemon.getName()
              << "\n(HP : " << playerPokemon.getCurrentHP()
              << "/" << playerPokemon.getMaxHP() << ")";
    std::cout << "\nVS";
    std::cout << "\n" << opponentPokemon.getName()
              << "\n(HP : " << opponentPokemon.getCurrentHP()
              << "/" << opponentPokemon.getMaxHP() << ")";
    std::cout << "\n----------------------------------------";
}

Move& Battle::chooseMove(Trainer& trainer)
{
    Pokemon& active = trainer.getTeam().getActivePokemon();

    std::cout << "\nChoose a move:\n\n";

    for (int i = 0; i < 4; i++)
    {
        std::cout <<std::left
                  << i + 1 << ". "
                  <<std::setw(15) << active.getMove(i).getName()
                  <<"(PP: " <<active.getMove(i).getPP() <<")"
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

Action Battle::chooseAction(const Trainer& player) const{


    std::cout <<"\n=========================\n";
    std::cout <<"what will " 
              <<player.getName()
              <<" do:\n\n";

    std::cout <<"1. Fight\n"
              <<"2. Pokemon";
    std::cout<<"\n=========================\n";

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

        switch (choice)
        {
        case 1:
            return Action::Fight;

        case 2:
            return Action::Pokemon;
        
        default:
            std::cout << "Invalid choice. Choose 1 or 2.\n";
            break;   
        }
    }
}

void Battle::executeAttack(Trainer& attacker, Trainer& defender, Move& selectedMove)
{
    Pokemon& attackerPokemon = attacker.getTeam().getActivePokemon();
    Pokemon& defenderPokemon = defender.getTeam().getActivePokemon();

    if(!selectedMove.use()){

        std::cout<<selectedMove.getName() <<" has no PP Left!";
        return;
    }

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

void Battle::displayTeam(const Trainer& player) const{

    std::cout << "\n=========================================\n";
    std::cout<<"              " <<player.getName() <<"'s Team\n";
    std::cout << "=========================================\n\n";

    for (int i = 0; i < 6; i++){

        const Pokemon& pokemon = player.getTeam().getPokemon(i);

        std::cout<<std::left
                 <<std::setw(3) <<i+1
                 <<std::setw(15) <<pokemon.getName();

        std::cout<<std::left
                 <<"HP: "
                 <<std::setw(3) <<pokemon.getCurrentHP()
                 <<"/"
                 <<std::setw(3) <<pokemon.getMaxHP();

        if (&pokemon == &player.getTeam().getActivePokemon()){

            std::cout <<"[Active]";
        }

        if (pokemon.isFainted()){
            std::cout <<"[Fainted]";
        }

        std::cout <<"\n";
    }

    std::cout << "\n=========================================\n";

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

void Battle::displayWinner() const{

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

void Battle::handleFaintedPokemon(Trainer& trainer)
{

    if(!checkWinner()){
        switchPokemon(trainer);
        return;
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

void Battle::switchPokemon(Trainer& player){

    displayTeam(player);

    int choice;

    while (true)
    {
        std::cout << "\nChoose Pokemon : ";

        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter a number.\n";
            continue;
        }

        if (choice < 1 || choice > 6){

            std::cout << "Invalid choice. Enter 1-6.\n";
            continue;
        }

        if (player.getTeam().getPokemon(choice-1).isFainted()){

            std::cout <<player.getTeam().getPokemon(choice-1).getName()
                     <<" is Fainted!"
                     <<"\nChoose another: ";
                     continue;
        }

        if (&player.getTeam().getActivePokemon() == &player.getTeam().getPokemon(choice-1)){

            std::cout<<player.getTeam().getActivePokemon().getName()
                     <<" is Already in Battle";
                     continue;
        }

        player.getTeam().switchPokemon(choice - 1);

        std::cout << "\n"
                << player.getName()
                << " switched to "
                << player.getTeam().getActivePokemon().getName()
                << "!\n";

        return;
    }

}
