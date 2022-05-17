#ifndef GAME_H
#define GAME_H
#include <vector>
#include "human.h"
#include "board.h"
#include <string>

class Game {
    Human * p1;
    Human * p2;
    Board * board;
    int turns = 0;
    public:
        Game ();
        static std::vector<std::vector<int> > WIN_COMBOS;
        bool start_game ();
        bool init ();
        bool isValidInput (char c);
        Human * has_a_win ();
        int getTurnCount ();
        void take_turn ();
        Human * current_player ();
};

#endif
