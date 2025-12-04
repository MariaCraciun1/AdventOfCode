#include "move.h"

Move::Move(char direction, int value){
    this->direction = direction;
    this->value = value;
}

char Move::getDirection() const{
    return direction;     
}

int Move::getValue() const{
    return value;
}

void Move::print() const {
    std::cout << direction << ": " << value << std::endl;
}

bool Move::isValidDirection(char direction){
    return direction == 'L' || direction == 'R';
}