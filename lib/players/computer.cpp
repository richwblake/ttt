#include "computer.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int Computer::check_for_win (Board * board) {
    const int win_combos[9][3] = { 
        { 0, 1, 2 }, 
        { 3, 4, 5 }, 
        { 6, 7, 8 }, 
        { 0, 3, 6 }, 
        { 1, 4, 7 }, 
        { 2, 5, 8 }, 
        { 0, 4, 8 }, 
        { 2, 4, 6 } 
    };

    const int opponent_token_value = this->token == 'X' ? 79 : 88;
    const int winning_sum = int(this->token) * 2 + ' ';
    const int losing_sum = opponent_token_value * 2 + ' ';

    for (int i = 0; i < 9; i++) {
        int a = board->getCells()[win_combos[i][0]];
        int b = board->getCells()[win_combos[i][1]];
        int c = board->getCells()[win_combos[i][2]];
        int current_combo_sum = a + b + c;

        if (current_combo_sum == losing_sum || current_combo_sum == winning_sum) {
            if (a == b) {
                return win_combos[i][2];
            }
            if (b == c) {
                return win_combos[i][0];
            }

            return win_combos[i][1];
        }
    }

    return -1;
}

int Computer::hard_move (Board * board) {
    // TODO: Create hard mode algorithm
    return board == nullptr;
}

int Computer::medium_move (Board * board) {
    int guess = check_for_win(board);
    if (guess < 0) return easy_move(board);
    return guess + 1;
}

int Computer::easy_move(Board * board) {
    srand(time(NULL));
    int guess;

    do {
        guess = rand() % 9 + 1;
    } while (board->positionTaken(guess - 1));
    return guess;
}

int Computer::make_move(Board * board) {
    switch (*difficulty) {
        case easy:
            return easy_move(board);
        case medium:
            return medium_move(board);
        case hard:
            return 3;
            break;
        default:
            return board == nullptr;
            break;
    }
}
