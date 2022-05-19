#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include <string>
#include <iostream>


class Player {
    protected:
        std::string name;
        char token;
        int score;
    public:
        Player (std::string name, char token);
        virtual ~Player ();
        std::string get_name ();
        char get_token ();
        int get_score ();
        virtual int make_move (Board * board) =0;
};

#endif
