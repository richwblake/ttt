#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "human.h"
#include "computer.h"
#include "board.h"

class Game {
    private:
        Player * p1;
        Player * p2;
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
        Player * has_a_win ();
        Player * current_player ();
};

#endif
