#pragma once

#include <unordered_map>
#include "CellGenerator.h"

class GameModel {

private:
    CellGenerator cellGenerator;
    const static int SIDE_SIZE = 4;
    const static int CANT_GENERATE_CELL = -1;
    int field[SIDE_SIZE * SIDE_SIZE];
    std::unordered_map<std::string, size_t> records;
};


