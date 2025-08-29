#pragma once
#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <vector>
#include <string>

class GameOfLife {
private:
    int rows, cols;
    std::vector<std::vector<int>> grid;
    int countNeighbors(int row, int col) const;

public:
    GameOfLife(int r = 10, int c = 10);

    void initialize();
    void randomInitialize(double aliveProbability = 0.5);
    void display() const;
    void nextGeneration();
    void simulate(int generations, int delayMs = 500);

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    int countLiveCells() const;
    int getRows() const;
    int getCols() const;
};

#endif
