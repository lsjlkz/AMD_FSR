//
// Created by lsjlkz on 2021/9/29.
//

#include "FSR.h"


int* FSR::GetPartMatrixNormalLapras(...) {
    int *weight = new int[9]{0, -1, 0, -1, 4, -1, 0, -1, 0};
    return weight;
}

int FSR::GetPartWeightMatrixData(int matrix[], int weight[], Point* point, int allCol) {
    int curRow = point->GetRow();
    int curCol = point->GetCol();
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[(curRow + i - 1) * allCol + curCol + j - 1] * weight[i * 3 + j];
        }
    }
    return sum;
}

int *FSR::GetPartWeightMatrix(int matrix[], Point *point, int allCol) {
    return nullptr;
}

#define IsEdge(a, b, c, d) (a == 0 || b == 0 || a == c - 1 || b == d - 1)
#define SetData(data, a, b, d, num) (data[a * d + b] = num)

int *FSR::getAllMatrixData(int matrix[], int row, int col, int*(* f)(...)) {
    int *data = new int[row * col];
    for (int _row = 0; _row < row; _row++) {
        for (int _col = 0; _col < col; _col++) {
            if(IsEdge(_row, _col, row, col)){
                SetData(data, _row, _col, col, 0);
                continue;
            }
            int* weight = f(matrix, new Point(_row, _col), col);
            SetData(data, _row, _col, col, GetPartWeightMatrixData(matrix, weight, new Point(_row, _col), col));
        }
    }
    return data;
}

int FSR::GetPointEdgeCharacter(int *matrix, Point *point, int allCol) {
    return 0;
}

int FSR::GetPointEdgeCharacterX(int *matrix, Point *point, int allCol) {
    return 0;
}

int FSR::GetPointEdgeCharacterY(int *matrix, Point *point, int allCol) {
    return 0;
}

int FSR::GetPointEdgePointWeight(int *matrix, Point *point) {
    return 0;
}

int *FSR::GetPartMatrixWeightLapras(int *matrix, Point *point, int allCol) {
    return nullptr;
}

Point::Point(int _row, int _col) {
    this->row = _row;
    this->col = _col;
}
