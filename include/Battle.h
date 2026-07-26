#pragma once

#include "Trainer.h"
#include "Pokemon.h"
#include "Move.h"
#include"Action.h"

class Battle {
    
    private:
        Trainer player;
        Trainer opponent;

        struct DamageResult
        {
            int damage;
            double typeMultiplier;
            double stabMultiplier;
            bool critical;
            bool missed;
        };
        

        // Core battle logic
        DamageResult calculateDamage(const Pokemon& attacker,
                            const Pokemon& defender,
                            const Move& move);

        // Chooses a move for the attacker's active Pokemon and returns it
        Move& chooseMove(Trainer& trainer);

        Action chooseAction(const Trainer& trainer) const;

        // Executes a single attack from attacker to defender using the given move
        void executeAttack(
            Trainer& attacker,
            Trainer& defender,
            Move& move);

        // Handles switching after a Pokémon faints
        void handleFaintedPokemon(Trainer& trainer);

        Move& chooseRandomMove(Trainer& trainer) const;

        Action chooseAIAction(const Trainer& trainer) const;

        void switchRandomPokemon(Trainer& trainer);

        void switchPokemon(Trainer& trainer);

        void displayWinner() const;

        void displayBattleStatus() const;

        void displayTeam(const Trainer& trainer) const;

        // Returns true if the battle has ended
        bool checkWinner() const;

        bool attackHits(const Move& move) const;

        bool isCriticalHit() const;

        bool playerMovesFirst() const;

    public:
        Battle(const Trainer& player, const Trainer& opponent);

        // Starts and controls the battle loop
        void startBattle();
};