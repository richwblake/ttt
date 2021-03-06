#include "board.h"
#include <iostream>

Board::Board () { 
    cells = std::vector<char> { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }; 
}

void Board::displayBoard () {
    for (int i = 0; i < 9; i += 3) {
        std::cout << "-----------" << "\n";
        std::cout << " " << cells[i] << " | " << cells[i + 1] << " | " << cells[i + 2] << "\n";
    }
    std::cout << "-----------" << std::endl;
}

bool Board::positionTaken (int index) {
    return cells[index] != ' ';
}

bool Board::fillPosition (int index, char token) {
    if (!positionTaken(index)) {
        cells[index] = token;
        return 1;
    }
    else
        return 0;
}

bool Board::isFull () {
    for (auto i : cells)
        if (i == ' ') return false;
    return true;
}

const std::vector<char>& Board::getCells () {
    return this->cells;
}


