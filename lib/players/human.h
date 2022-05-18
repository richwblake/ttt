#ifndef HUMAN_H
#define HUMAN_H
#include <string>

class Human {
    private:
        std::string name;
        int score;
        char token;
    public:
        Human (char token, std::string name);
        std::string getName ();
        int getScore ();
        char getToken ();
};

#endif
