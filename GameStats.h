#pragma once
#ifndef GAME_STATS_H
#define GAME_STATS_H

#include <vector>
#include <iostream>

struct IndividualGameStats {
    int generations = 0;
    int aliveCells = 0;
    int deadCells = 0;
};

struct GameStats {
    std::vector<IndividualGameStats> allGames;

    void addGame(int generations, int aliveCells, int boardSize) {
        IndividualGameStats g;
        g.generations = generations;
        g.aliveCells = aliveCells;
        g.deadCells = boardSize - aliveCells;
        allGames.push_back(g);
    }

    void report() {
        std::cout << "\n--- Game Statistics ---\n";
        int totalGenerations = 0, totalAlive = 0, totalDead = 0;
        for (size_t i = 0; i < allGames.size(); i++) {
            const auto& g = allGames[i];
            std::cout << "Game " << i + 1 << ":\n";
            std::cout << " - Generations: " << g.generations << "\n";
            std::cout << " - Alive cells: " << g.aliveCells << "\n";
            std::cout << " - Dead cells: " << g.deadCells << "\n";
            std::cout << "----------------------\n";
            totalGenerations += g.generations;
            totalAlive += g.aliveCells;
            totalDead += g.deadCells;
        }

        if (!allGames.empty()) {
            std::cout << "Overall Totals:\n";
            std::cout << " - Games played: " << allGames.size() << "\n";
            std::cout << " - Total generations: " << totalGenerations << "\n";
            std::cout << " - Total alive cells: " << totalAlive << "\n";
            std::cout << " - Total dead cells: " << totalDead << "\n";
            std::cout << " - Average alive cells per game: " << totalAlive / allGames.size() << "\n";
            std::cout << " - Average dead cells per game: " << totalDead / allGames.size() << "\n";
        }
        std::cout << "------------------------\n";
    }
};

#endif
