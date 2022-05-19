#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"

class Computer: public Player {
    public:
        Computer (std::string name, char token) : Player(name, token) { }
        int make_move (Board * board);
};

#endif
