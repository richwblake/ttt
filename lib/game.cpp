#include "game.h"
#include <iostream>

std::vector<std::vector<int> > Game::WIN_COMBOS = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6},
};

Game::Game (Human& player1, Human& player2) {
    this->p1 = &player1;
    this->p2 = &player2;
    this->board = new Board();
}

Human * Game::current_player () {
    return this->turns % 2 == 0 ? this->p1 : this->p2;
}

void Game::take_turn() {
    std::cout << current_player()->getName() << ", it's your turn. Please enter a number between 1 and 9 to make a move (you are " << current_player()->getToken() << ")\n";  
    board->displayBoard();
    std::cout << "\n: ";
    bool retry = false;
    int choice = -1;
    while ((choice < 1 || choice > 9) || board->positionTaken(choice - 1)) {
        if (retry)
            std::cout << "Please try again, with a valid position (1 - 9)\n: ";
        std::cin >> choice;
        retry = true;
    }

    choice -= 1;

    board->fillPosition(choice, *current_player());

    turns += 1; 

}

Human * Game::has_a_win () {
    std::vector<char> cells = board->getCells();
    Human * xPlayer;
    Human * yPlayer;
    if (p1->getToken() == 'X') {
        xPlayer = p1;
        yPlayer = p2;
    } else {
        xPlayer = p2;
        yPlayer = p1;
    }

    for (auto combo : WIN_COMBOS) {
        char a = cells[combo[0]];
        char b = cells[combo[1]];
        char c = cells[combo[2]];

        if (a != ' ' && a == b && b == c && c == a)
            return a == 'X' ? xPlayer : yPlayer;
    }
    return nullptr;
}

bool Game::start_game() {
    std::cout << "Welcome " << this->p1->getName() << " and " << this->p2->getName() << "!" << std::endl;
    
    while (!board->isFull() && !has_a_win())
        take_turn();
   
    if (has_a_win())
        std::cout << "Congrats " << has_a_win()->getName() << "!" << std::endl;
    
    board->displayBoard();


    return 0;
}
