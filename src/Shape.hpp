#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED

#define WINS 1
#define LOSES 0
#define DRAW -1

#include <iostream>

class Shape {
    protected:
        std::string name;
        std::string beats;

    public:
        Shape()  = default;
        ~Shape() = default;
        int doesBeat(Shape* enemy);
        std::string getName() const;
};

class Rock : public Shape {
    public:
        Rock();
};

class Paper : public Shape {
    public:
        Paper();
};

class Scissors : public Shape {
    public:
        Scissors();
};

#endif // SHAPE_HPP_INCLUDED
