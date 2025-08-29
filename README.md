# Game-Of-Life
A C++ implementation of Conway’s Game of Life with customizable board size, probability for alive cells, file I/O support, and detailed game statistics. This project is designed for Windows and uses object-oriented programming principles.

---
This project demonstrates:

- **Object-Oriented Programming (OOP):** Use of classes, private/public members, constructors, and methods.
- **Dynamic Memory Management:** Use of `std::vector` for dynamically sized 2D grids.
- **File I/O:** Reading and writing board states to CSV files.
- **Randomization:** Initializing the board with a probability for alive cells.
- **Game Simulation:** Implementing the rules of Conway's Game of Life with multiple generations.
- **Statistics Tracking:** Recording and reporting individual and overall game statistics.
- **User Interaction:** Command-line menu with input validation.

## Features

- Set custom board size (rows × columns)
- Initialize board randomly with user-defined alive cell probability
- Display board in console (`O` for alive cells, `.` for dead cells)
- Simulate the game for a user-specified number of generations
- Play multiple random games and track the board with the most alive cells
- Save/load board state from/to CSV files
- Report statistics for individual games and overall games
- Display the best board achieved across all games
- Menu-driven interface for easy interaction

---

## Project Structure
     
    GameOfLife/
    ├── main.cpp         — Contains the main function and menu interface
    ├── GameOfLife.h     — Class definition for the game board
    ├── GameOfLife.cpp   — Implementation of GameOfLife methods
    ├── GameStats.h      — Structures and methods for storing game statistics
    ├── GameManager.h    — Class to manage menu and game logic
    └── GameManager.cpp  — Implementation of GameManager methods


---

## Usage

1. **Compile the code**:

   ```bash
   g++ main.cpp GameOfLife.cpp GameManager.cpp -o GameOfLife -std=c++11
2. **Run the executable**:
    ```bash
    GameOfLife.exe
3. **Follow the on-screen menu**:
     ```bash
    Hello! Welcome to the game of life in CMPT 1109.

    What would you like to do?
    1. Display the initial state for the game of life
    2. Load a new initial state from a CSV file into memory
    3. Play the game of life with the current initial state
    4. Report summary statistics on all games played
    5. Randomly play the game multiple times
    6. Display the best initial board
    7. Quit the program
    Enter choice:
## File I/O

- CSV Format: Board cells are stored as `0` (dead) or `1` (alive) separated by commas.
- Example CSV:
    ```bash
    0,1,0,0
    1,0,1,0
    0,1,0,1
## Built With

- **C++11** — Main programming language
- **Windows.h** — For `Sleep()` function to create delays between generations
- **Standard C++ libraries**:
  - `<vector>` — For dynamic 2D grid storage
  - `<fstream>` — For reading/writing CSV files
  - `<sstream>` — For parsing CSV lines
  - `<iostream>` — For console input/output
- Random number generation — To initialize the board with alive/dead cells probabilistically




