#include "Player.hpp"

Player::Player(std::string name)
:   name(name) { }

Player::~Player() {
    delete this->shape;
}
