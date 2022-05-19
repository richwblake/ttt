#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human: public Player {
    public:
        Human (std::string name, char token) : Player(name, token) { }
        int make_move (Board * board);
};

#endif
