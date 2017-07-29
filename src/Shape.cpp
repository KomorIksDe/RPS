#include "Shape.hpp"

int Shape::doesBeat(Shape* enemy) {
    if(this->name == enemy->getName())
        return DRAW;
    else {
        if(this->beats == enemy->getName())
            return WINS;
        else
            return LOSES;
    }
}

std::string Shape::getName() const {
    return this->name;
}

Rock::Rock() {
    this->name  = "rock";
    this->beats = "scissors";
}

Paper::Paper() {
    this->name  = "paper";
    this->beats = "rock";
}

Scissors::Scissors() {
    this->name  = "scissors";
    this->beats = "paper";
}
