#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"

enum Difficulty { easy, medium, hard };

class Computer: public Player {
    int check_for_win (Board * board);
    int easy_move (Board * board);
    int medium_move (Board * board);
    int hard_move (Board * board);
    public:
        Computer (std::string name, char token, Difficulty& difficulty) : Player(name, token), difficulty(&difficulty) { }
        Difficulty * difficulty; 
        int make_move (Board * board);
};

#endif
