#include "GameManager.h"
#include <iostream>
using namespace std;

int main() {
    GameManager manager;
    int choice;

    cout << "Hello! Welcome to the game of life.\n";

    do {
        cout << "\nWhat would you like to do?\n";
        cout << "1. Display the initial state for the game of life\n";
        cout << "2. Load a new initial state from a CSV file into memory\n";
        cout << "3. Play the game of life with the current initial state\n";
        cout << "4. Report summary statistics on all games played\n";
        cout << "5. Randomly play the game multiple times\n";
        cout << "6. Display the best initial board\n";
        cout << "7. Quit the program\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: manager.displayBoard(); break;
        case 2: manager.loadBoardFromCSV(); break;
        case 3: manager.playGame(); break;
        case 4: manager.showStatistics(); break;
        case 5: manager.playRandomGames(); break;
        case 6: manager.displayBestBoard(); break;
        case 7: cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
