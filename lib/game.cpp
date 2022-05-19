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

Game::Game () {
    this->p1 = nullptr;
    this->p2 = nullptr;
    this->board = new Board();
}

Game::~Game () {
    delete p1;
    delete p2;
    delete board;
}

Player * Game::current_player () {
    return this->turns % 2 == 0 ? this->p1 : this->p2;
}

void Game::take_turn() {
    std::cout << current_player()->get_name() << ", it's your turn. Please enter a number between 1 and 9 to make a move (you are " << current_player()->get_token() << ")\n";  
    board->displayBoard();
    std::cout << "\n: ";

    int choice = current_player()->make_move(board) - 1;

    board->fillPosition(choice, current_player()->get_token());
    turns += 1; 
}

Player * Game::has_a_win () {
    for (auto combo : WIN_COMBOS) {
        char a = board->getCells()[combo[0]];
        char b = board->getCells()[combo[1]];
        char c = board->getCells()[combo[2]];

        if (a != ' ' && a == b && b == c && c == a) return p1->get_token() == a ? p1 : p2;
    }
    return nullptr;
}

bool Game::init () {
    char p1_token;
    std::string p1_name;
    char p2_token;
    std::string p2_name;

    std::cout << "Welcome to Tic-Tac-Toe.\n";

    std::cout << "Player 1, please enter your name: ";
    std::cin >> p1_name;
    std::cout << "Player 2, please enter your name: ";
    std::cin >> p2_name;

    std::cout << "Player 1, which token will you use? (X or O): ";


    while (!(std::cin >> p1_token) || !isValidInput(p1_token)) {
        std::cout << "Please check your input, it must be X or O\n: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }           

    p2_token = p1_token == 'x' || p1_token == 'X' ? 'O' : 'X';

    this->p1 = new Human (p1_name, p1_token);
    this->p2 = new Human (p2_name, p2_token);

    this->start_game();

    return 0;
}

bool Game::isValidInput (char c) {
    return (c == 'O' || c == 'o') || (c == 'X' || c == 'x') ? true : false;
}

bool Game::start_game () {
    std::cout << "Welcome " << this->p1->get_name() << " and " << this->p2->get_name() << "!" << std::endl;

    while (!board->isFull() && !has_a_win())
        take_turn();

    if (has_a_win())
        std::cout << "=-=-=Congrats " << has_a_win()->get_name() << "!=-=-=" << std::endl;
    else
        std::cout << "-------Cat's game! No winner.-------" << std::endl;

    board->displayBoard();

    return 0;
}
