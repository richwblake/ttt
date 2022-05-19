#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board {
    private:
        std::vector<char> cells;
    public:
        Board ();
        void displayBoard ();
        bool positionTaken (int index);
        bool fillPosition (int index, char token);
        bool isFull ();
        const std::vector<char>& getCells ();
};

#endif
