#ifndef GAME_H
#define GAME_H
#include "human.h"
#include "board.h"

class Game {
    private:
        Human * p1;
        Human * p2;
        Board * board;
        int turns = 0;
    public:
        Game ();
        ~Game ();
        static std::vector<std::vector<int> > WIN_COMBOS;
        bool start_game ();
        bool init ();
        bool isValidInput (char c);
        void take_turn ();
        int getTurnCount ();
        Human * has_a_win ();
        Human * current_player ();
};

#endif
