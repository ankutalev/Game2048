#pragma once

#include <set>
#include <random>

class CellGenerator {
public:
    CellGenerator(int fieldSize, int genError);

    CellGenerator() = delete;

    ~CellGenerator() = default;

    int generateValue();

    int generatePosition();

    void setEmptyCell(int cellNumber);

private:
    int generationError;
    constexpr static double TWO_PROPABILITY = 90.9090909;
    constexpr static double FOUR_PROPABILITY = 9.09090909;
    std::random_device rd;
    std::discrete_distribution<> distributionForValues;
    std::uniform_int_distribution<> distributionForCells;
    std::mt19937 engine;
    std::set<int> emptyPositions;
};


