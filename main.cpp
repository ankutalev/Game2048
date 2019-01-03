#include <iostream>
#include "GameModel.h"

int main() {
    CellGenerator cg(16);
    int f = 0, t = 0;
    for (int i = 0; i < 1000000; ++i) {
        ++(cg.generateValue() == 2 ? t : f);
    }
    return 0;
}