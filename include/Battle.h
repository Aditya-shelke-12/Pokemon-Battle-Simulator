#pragma once

#include "Trainer.h"
#include "Pokemon.h"
#include "Move.h"

class Battle {
    
    private:
        Trainer player;
        Trainer opponent;

        // Core battle logic
        int calculateDamage(const Pokemon& attacker,
                            const Pokemon& defender,
                            const Move& move);

        // Executes one complete turn
        void executeTurn(Trainer& attacker,
                        Trainer& defender);

        // Handles switching after a Pokémon faints
        void handleFaintedPokemon(Trainer& trainer);

        // Returns true if the battle has ended
        bool checkWinner() const;

    public:
        Battle(const Trainer& player, const Trainer& opponent);

        // Starts and controls the battle loop
        void startBattle();
};