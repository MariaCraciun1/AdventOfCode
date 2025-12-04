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
            moves.emplace_back(direction, value);
        }
        catch (...) {
            std::cout<< "Invalid number format.\n";
        }
    }

    int position = 50;
    for(const auto&move: moves){
        auto steps = move.getValue();    
        switch (move.getDirection())
        {
        case 'L':
            if(position > 0){
                if(steps >= position){
                    zeroCounter += 1 + (steps-position) / 100;
                }
            } else {
                zeroCounter += steps / 100;
            }
            position = (position - steps) % 100;
            if(position < 0){
                position += 100;
            }
            break;
        case 'R':   
            zeroCounter += (position + steps) / 100;
            position = (position + steps) % 100;
            break;
        default:
            break;
        }
    } 

    std::cout << "\nzero counter: " << zeroCounter;
}