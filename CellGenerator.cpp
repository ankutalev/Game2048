#include "CellGenerator.h"

int CellGenerator::generateValue() {
    return 2 * std::pow(2, distributionForValues(engine));
}

CellGenerator::CellGenerator(int fieldSize, int genError) : generationError(genError),
                                                            distributionForValues({TWO_PROPABILITY, FOUR_PROPABILITY}),
                                                            engine(rd()) {
    for (int i = 0; i < fieldSize; ++i) {
        emptyPositions.insert(i);
    }
}

int CellGenerator::generatePosition() {
    if (emptyPositions.empty())
        return generationError;
    std::uniform_int_distribution<> distributionForCells(0, emptyPositions.size() - 1);
    auto iterNumber = distributionForCells(engine);
    auto it = emptyPositions.begin();
    std::advance(it, iterNumber);
    auto cellNumber = *it;
    emptyPositions.erase(cellNumber);
    return cellNumber;
}

void CellGenerator::setEmptyCell(int cellNumber) {
    emptyPositions.insert(cellNumber);
}
