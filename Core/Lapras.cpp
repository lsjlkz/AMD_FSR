//
// Created by lsjlkz on 2021/9/29.
//

#include "Lapras.h"

int Lapras::getPartMatrixNormalData(int matrix[], int curRow, int curCol, int allCol)
{
    int* weight = new int[9]{ 0,-1,0,-1,4,-1,0,-1,0 };
    return this->getPartWeightMatrixData(matrix, weight, curRow, curCol, allCol);
}

int Lapras::getPartWeightMatrixData(int matrix[], int weight[], int curRow, int curCol, int allCol)
{

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[(curRow + i - 1) * allCol + curCol + j - 1] * weight[i * 3 + j];
        }
    }
    return sum;
}

int* Lapras::getPartWeightMatrix(int matrix[], int curRow, int curCol, int allCol)
{
    return nullptr;
}

Lapras::Lapras()
{
}

int* Lapras::getAllMatrixData(int matrix[], int row, int col)
{
    int* data = new int[row * col];
    for (int _row = 0; _row < row; _row++) {
        for (int _col = 0; _col < col; _col++) {
            if (_row == 0 || _col == 0 || _row == row - 1 || _col == col - 1) {
                data[_row * col + _col] = 0;
                continue;
            }
            data[_row * col + _col] = this->getPartMatrixNormalData(matrix, _row, _col, col);
        }
    }
    return data;
}
