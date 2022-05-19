#include "player.h"

Player::Player (std::string name, char token) {
    this->score = 0;
    this->name = name;

    if (token == 'o' || token == 'x')
        this->token = token - 32;
    else
        this->token = token;
}

Player::~Player () { }

std::string Player::get_name () {
    return this->name;
}

char Player::get_token () {
    return this->token;
}

int Player::get_score () {
    return this->score;
}
