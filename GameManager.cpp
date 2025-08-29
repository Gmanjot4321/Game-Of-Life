#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

GameManager::GameManager() {
    srand((unsigned)time(nullptr));
    int rows, cols;
    double probability;

    cout << "Enter number of rows for the board: ";
    cin >> rows;
    cout << "Enter number of columns for the board: ";
    cin >> cols;
    cout << "Enter probability for a cell being alive (0.0 - 1.0): ";
    cin >> probability;

    if (probability < 0.0 || probability > 1.0) {
        cout << "Invalid probability! Defaulting to 0.5\n";
        probability = 0.5;
    }

    game = GameOfLife(rows, cols);
    game.randomInitialize(probability);
}

void GameManager::displayBoard() { game.display(); }

void GameManager::loadBoardFromCSV() {
    string filename;
    cout << "Enter CSV filename: ";
    cin >> filename;
    game.loadFromFile(filename);
    cout << "Board loaded from " << filename << endl;
}

void GameManager::playGame() {
    int generations;
    cout << "Enter number of generations to simulate: ";
    cin >> generations;
    game.simulate(generations);
    int aliveCells = game.countLiveCells();
    int boardSize = game.getRows() * game.getCols();
    stats.addGame(generations, aliveCells, boardSize);
    if (aliveCells > bestScore) {
        bestScore = aliveCells;
        bestBoard = game;
    }
}

void GameManager::showStatistics() { stats.report(); }

void GameManager::playRandomGames() {
    int runs, generations;
    double probability;

    cout << "Enter number of random games: ";
    cin >> runs;
    cout << "Enter generations per game: ";
    cin >> generations;
    cout << "Enter probability for a cell being alive (0.0 - 1.0): ";
    cin >> probability;

    if (probability < 0.0 || probability > 1.0) {
        cout << "Invalid probability! Defaulting to 0.5\n";
        probability = 0.5;
    }

    for (int i = 0; i < runs; i++) {
        GameOfLife randomGame(game.getRows(), game.getCols());
        randomGame.randomInitialize(probability);
        randomGame.simulate(generations, 0);
        int aliveCells = randomGame.countLiveCells();
        int boardSize = randomGame.getRows() * randomGame.getCols();
        stats.addGame(generations, aliveCells, boardSize);
        if (aliveCells > bestScore) {
            bestScore = aliveCells;
            bestBoard = randomGame;
        }
    }
    cout << runs << " random games completed.\n";
}

void GameManager::displayBestBoard() {
    if (bestScore == 0) {
        cout << "No games played yet, no best board available.\n";
        return;
    }
    cout << "\n--- Best Board ---\n";
    bestBoard.display();
    cout << "Alive cells: " << bestBoard.countLiveCells() << "\n";
    cout << "------------------\n";
}
