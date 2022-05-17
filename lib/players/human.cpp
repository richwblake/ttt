#include "human.h"

Human::Human (char token, std::string name) {
    this->score = 0;
    this->name = name;
    if (token == 'o' || token == 'x')
        this->token = token - 32;
    else
        this->token = token;
}

int Human::getScore () {
    return this->score;
}

char Human::getToken() {
    return this->token;
}

std::string Human::getName () {
    return this->name;
}
