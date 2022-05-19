#include "human.h"

int Human::make_move (Board * board) {
    int choice = -1;

    while (!(std::cin >> choice) || (choice < 1 || choice > 9) || board->positionTaken(choice - 1)) {
        std::cout << "Please try again, with a valid position (1 - 9)\n: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return choice;
}
