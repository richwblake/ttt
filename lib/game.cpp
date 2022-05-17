#include "game.h"
#include "board.h"
#include "human.h"
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

Game::Game () {
    this->p1 = nullptr;
    this->p2 = nullptr;
    this->board = new Board();
}

Human * Game::current_player () {
    return this->turns % 2 == 0 ? this->p1 : this->p2;
}

void Game::take_turn() {
    std::cout << current_player()->getName() << ", it's your turn. Please enter a number between 1 and 9 to make a move (you are " << current_player()->getToken() << ")\n";  
    board->displayBoard();
    std::cout << "\n: ";
    int choice = -1;
    while (!(std::cin >> choice) && (choice < 1 || choice > 9) || board->positionTaken(choice - 1)) {
        std::cout << "Please try again, with a valid position (1 - 9)\n: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

bool Game::init () {
    char p1_token;
    std::string p1name;
    char p2_token;
    std::string p2name;

    std::cout << "Welcome to Tic-Tac-Toe.\n";

    std::cout << "Player 1, please enter your name: ";
    std::cin >> p1name;
    std::cout << "Player 2, please enter your name: ";
    std::cin >> p2name;

    std::cout << "Player 1, which token will you use? (X or O): ";


    while (!(std::cin >> p1_token) || !isValidInput(p1_token)) {
        std::cout << "Please check your input, it must be X or O\n: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }           

    p2_token = p1_token == 'x' || p1_token == 'X' ? 'O' : 'X';

    Human player1 (p1_token, p1name);
    Human player2 (p2_token, p2name);

    this->p1 = &player1;
    this->p2 = &player2;

    this->start_game();

    return 0;
}

bool Game::isValidInput (char c) {
    return (c == 'O' || c == 'o') || (c == 'X' || c == 'x') ? true : false;
}

bool Game::start_game () {
    std::cout << "Welcome " << this->p1->getName() << " and " << this->p2->getName() << "!" << std::endl;

    while (!board->isFull() && !has_a_win())
        take_turn();

    if (has_a_win())
        std::cout << "Congrats " << has_a_win()->getName() << "!" << std::endl;

    board->displayBoard();


    return 0;
}
