#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "GameOfLife.h"
#include "GameStats.h"

class GameManager {
private:
    GameOfLife game;
    GameStats stats;
    GameOfLife bestBoard;
    int bestScore = 0;

public:
    GameManager();

    void displayBoard();
    void loadBoardFromCSV();
    void playGame();
    void showStatistics();
    void playRandomGames();
    void displayBestBoard();
};

#endif
