#include <iostream>
#include "Core/FSR.h"
#include "Core/CommonProperty.h"

#define Vector2ToVector1(x, y, allCol) (x * allCol + y)
#define SetData(data, i, num) (data[i] = num)
#define Tab "\t"

void test() {
    int row = 4;
    int col = 4;
    CommonProperty::SetSize(row, col);
    int *matrix = new int[row * col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[Vector2ToVector1(i, j, col)] = rand() % 100;
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matrix[Vector2ToVector1(i, j, col)] << Tab;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
//    int *data = FSR::getAllMatrixData(matrix, NormalLapras::GetNormalLaprasMatrix);
    float *data = FSR::getAllMatrixData(matrix, FSR::GetPartWeightMatrix);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << data[Vector2ToVector1(i, j, col)] << Tab;
        }
        std::cout << std::endl;
    }
}

int main() {
    test();
}

