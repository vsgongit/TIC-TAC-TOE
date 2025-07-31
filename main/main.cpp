#include <iostream>
#include "../include/tic_tac_toe.h"

int main() {
    std::cout << "\n-------------------------------------------------------------------\n\n";
    std::cout << "\t\t\t Tic-Tac-Toe\n";
    std::cout << "\n-------------------------------------------------------------------\n\n";

    char cont = 'y';
    do {
        char choice;
        std::cout << "Do you want to start first? (y/n): ";
        std::cin >> choice;

        if (choice == 'n')
            playTicTacToe(COMPUTER);
        else if (choice == 'y')
            playTicTacToe(HUMAN);
        else
            std::cout << "Invalid choice\n";

        std::cout << "\nDo you want to quit (y/n): ";
        std::cin >> cont;
    } while (cont == 'n');

    return 0;
}
