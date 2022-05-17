#ifndef HUMAN_H
#define HUMAN_H
#include <string>

class Human {
    std::string name;
    int score;
    char token;
    public:
        Human (char token, std::string name);
        int getScore ();
        char getToken ();
        std::string getName ();
};

#endif
