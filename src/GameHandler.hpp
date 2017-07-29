#ifndef GAMEHANDLER_HPP_INCLUDED
#define GAMEHANDLER_HPP_INCLUDED

#include <utility>
#include "Player.hpp"

class GHandler {
    private:
        std::pair<Player*, unsigned> player1;
        std::pair<Player*, unsigned> player2;

    public:
        GHandler();
        ~GHandler();
        void mainMenu();
        void showCredits();
        void loadPlayers(std::string name1, std::string name2);
        void prepareForGame();
        void runMainGame();
        void setShapeFor(Player* player);
        bool hasWon();
        void startRound();
        int getResult();
};

#endif // GAMEHANDLER_HPP_INCLUDED
