#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "Shape.hpp"

class Player {
    public:
        std::string name;
        Shape* shape;

        Player(std::string name);
        ~Player();
};

#endif // PLAYER_HPP_INCLUDED
