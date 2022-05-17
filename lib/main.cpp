#include "human.h"
#include "game.h"
#include "board.h"
#include <iostream>

bool isValidInput (char c) {
    return (c == 'O' || c == 'o') || (c == 'X' || c == 'x') ? true : false;
}

bool init () {
    char p1_token;
    std::string p1name;
    char p2_token;
    std::string p2name;
    bool retry = false;
    
    std::cout << "Welcome to Tic-Tac-Toe.\n";

    std::cout << "Player 1, please enter your name: ";
    std::cin >> p1name;
    std::cout << "Player 2, please enter your name: ";
    std::cin >> p2name;



    while (!isValidInput(p1_token)) {
        if (retry) std::cout << "Please check your input, it must be X or O\n";
        std::cout << "Player 1, which token will you use? (X or O): ";
        std::cin >> p1_token;
        retry = true;
    }

    p2_token = p1_token == 'x' || p1_token == 'X' ? 'O' : 'X';

    Human player1 (p1_token, p1name);
    Human player2 (p2_token, p2name);

    Game game (player1, player2);

    game.start_game();

    return 0;
}

int main () {
    return init();
}
