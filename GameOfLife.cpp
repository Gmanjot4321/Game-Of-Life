#include "GameOfLife.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

GameOfLife::GameOfLife(int r, int c) : rows(r), cols(c) {
    grid.assign(rows, vector<int>(cols, 0));
}

int GameOfLife::countNeighbors(int row, int col) const {
    int count = 0;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (!(dr == 0 && dc == 0)) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < rows && c >= 0 && c < cols)
                    count += grid[r][c];
            }
    return count;
}

void GameOfLife::initialize() {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            grid[r][c] = rand() % 2;
}

void GameOfLife::randomInitialize(double aliveProbability) {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            grid[r][c] = ((double)rand() / RAND_MAX < aliveProbability) ? 1 : 0;
}

void GameOfLife::display() const {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            cout << (grid[r][c] ? "O " : ". ");
        cout << endl;
    }
}

void GameOfLife::nextGeneration() {
    vector<vector<int>> newGrid = grid;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++) {
            int neighbors = countNeighbors(r, c);
            if (grid[r][c] == 1) {
                if (neighbors < 2 || neighbors > 3) newGrid[r][c] = 0;
            }
            else if (neighbors == 3) newGrid[r][c] = 1;
        }
    grid = newGrid;
}

void GameOfLife::simulate(int generations, int delayMs) {
    for (int gen = 0; gen < generations; gen++) {
        cout << "Generation " << gen + 1 << ":\n";
        display();
        cout << "----------------------------\n";
        Sleep(delayMs);
        nextGeneration();
    }
}

void GameOfLife::saveToFile(const string& filename) const {
    ofstream out(filename);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            out << grid[r][c];
            if (c < cols - 1) out << ",";
        }
        out << "\n";
    }
}

void GameOfLife::loadFromFile(const string& filename) {
    ifstream in(filename);
    string line;
    vector<vector<int>> newGrid;
    while (getline(in, line)) {
        vector<int> row;
        stringstream ss(line);
        string val;
        while (getline(ss, val, ',')) row.push_back(stoi(val));
        newGrid.push_back(row);
    }
    if (!newGrid.empty()) {
        rows = newGrid.size();
        cols = newGrid[0].size();
        grid = newGrid;
    }
}

int GameOfLife::countLiveCells() const {
    int alive = 0;
    for (const auto& row : grid)
        for (int cell : row)
            alive += cell;
    return alive;
}

int GameOfLife::getRows() const { return rows; }
int GameOfLife::getCols() const { return cols; }
