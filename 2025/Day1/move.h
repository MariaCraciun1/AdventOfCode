#pragma once
#include <iostream>
#include <string>

class Move {
private:
    char direction;
    int value;

public:
    Move(char direction, int value);
    char getDirection() const;
    int getValue() const;

    void print() const;

    static bool isValidDirection(char direction);
};
