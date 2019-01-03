#include "CellGenerator.h"

int CellGenerator::generateValue() {
    return 2 * std::pow(2, distributionForValues(engine));
}

CellGenerator::CellGenerator(int fieldSize, int genError) : generationError(genError),
                                                            distributionForValues({TWO_PROPABILITY, FOUR_PROPABILITY}),
                                                            distributionForCells(0, fieldSize - 1), engine(rd()) {
    for (int i = 0; i < fieldSize; ++i) {
        emptyPositions.insert(i);
    }
}

int CellGenerator::generatePosition() {
    if (emptyPositions.empty())
        return generationError;
    //в продакшен я бы такое не пустил
    while (1) {
        auto cellNumber = distributionForCells(engine);
        if (emptyPositions.count(cellNumber)) {
            emptyPositions.erase(cellNumber);
            return cellNumber;
        }
    }
    return generationError;
}

void CellGenerator::setEmptyCell(int cellNumber) {
    emptyPositions.insert(cellNumber);
}
