#include <iostream>
#include <vector>
#include <string>
#include "move.h"

int main() {
    int zeroCounter = 0;
    std::vector<Move> moves;
    std::string line;

    while(true){
        std::getline(std::cin, line);

        if(line.empty()){
            break;
        }

        char direction = line[0];

        if(!Move::isValidDirection(direction)){
            std::cout <<"Invalid direction. Use only L or R. \n";
            continue;
        }

        try{
            int value = std::stoi(line.substr(1));
            if(value > 100){
                value = value%100;
            }
            moves.emplace_back(direction, value);
        }
        catch (...) {
            std::cout<< "Invalid number format.\n";
        }
    }

    int position = 50;
    for(const auto&move: moves){
        switch (move.getDirection())
        {
        case 'L':
            if(position - move.getValue() < 0){
                position = 100 - abs(move.getValue()-position);
            } else {
                position = position - move.getValue();
            }
            break;
        case 'R':   
                if(position + move.getValue() >= 100){
                    position = abs(100 - (position + move.getValue()));
                } else {
                    position = position + move.getValue();
                }
            break;
        default:
            break;
        }
        if(position ==0){
            zeroCounter++;
        }
    }

    std::cout <<  zeroCounter;
}