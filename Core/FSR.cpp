//
// Created by lsjlkz on 2021/9/29.
//

#include <iostream>
#include "FSR.h"
#include "CommonProperty.h"

#define IsEdge(a, b, c, d) (a == 0 || b == 0 || a == c - 1 || b == d - 1)
#define Vector2ToVector1(x, y, allCol) ((x * allCol) + y)
#define SetData(data, i, num) (data[i] = num)
#define MaxAbs(a, b) (std::max(abs(a), abs(b)))


float* NormalLapras::weight = new float[9]{0, -1, 0, -1, 4, -1, 0, -1, 0};


float * FSR::GetPartWeightMatrix(int matrix[], Point *point) {
    float* data = new float[9];
    float feature = GetPointEdgeCharacter(matrix, point);
    for(int i = 0; i < 9; i++){
        int row = i / 3;
        int col = i % 3;
        float dist = sqrt((row - 1) * (row - 1) + (col - 1) * (col - 1));
        data[i] = GetLanczos2(feature, dist);
//        data[i] = GetPointWeight(matrix, point, dist);
    }
    return data;
}

float FSR::GetPartWeightMatrixData(int matrix[], float weight[], Point *point) {
    int curRow = point->GetRow();
    int curCol = point->GetCol();
    int sum = 0;
    int allCol = CommonProperty::GetAllCol();
    for(int i = 0; i < 9; i++){
        int row = i / 3;
        int col = i % 3;
        sum += matrix[Vector2ToVector1((curRow + row - 1), (curCol + col - 1), allCol)] * weight[Vector2ToVector1(row, col, 3)];
    }
    return sum;
}


float *FSR::getAllMatrixData(int matrix[], float *(*f)(int _matrix[], Point *_point)) {
    int row = CommonProperty::GetAllRow();
    int col = CommonProperty::GetAllCol();
    int allLength = row * col;
    float *data = new float[allLength];
    for(int i = 0; i < allLength; i++) {
        int _row = i / col;
        int _col = i % col;
        if (IsEdge(_row, _col, row, col)) {
            SetData(data, i, GetMatrixEdgeData());
            continue;
        }
        float *weight = f(matrix, new Point(_row, _col));
        for(int i=0; i < 3; i++){
            for(int j =0; j <3; j++){
                std::cout << weight[i * 3 + j] << "\t";
            }std::cout << std::endl;
        }
        SetData(data, i, GetPartWeightMatrixData(matrix, weight, new Point(_row, _col)));
    }
    return data;
}

int FSR::CalPointMinusPointEdgeCharacter(int matrix[], Point *point, Point *otherPoint) {
    float curPointData = GetPartNormalLaprasData(matrix, point);
    float otherPointData = GetPartNormalLaprasData(matrix, otherPoint);
    return otherPointData - curPointData;
}

float FSR::CalPointEdgeCharacterX(int matrix[], Point *point) {
    Point *rightPoint = point->GetRightPoint();
    Point *leftPoint = point->GetLeftPoint();
    int rightMinusCur = CalPointMinusPointEdgeCharacter(matrix, point, rightPoint);
    int leftMinusCur = CalPointMinusPointEdgeCharacter(matrix, point, leftPoint);
    int leftMinusRight = CalPointMinusPointEdgeCharacter(matrix, rightPoint, leftPoint);
    int denominator = MaxAbs(rightMinusCur, leftMinusCur);
    if(denominator == 0) return 0;
    return float(abs(leftMinusRight)) / denominator;
}

float FSR::CalPointEdgeCharacterY(int matrix[], Point *point) {
    Point *upPoint = point->GetUpPoint();
    Point *downPoint = point->GetDownPoint();
    int downMinusCur = CalPointMinusPointEdgeCharacter(matrix, point, downPoint);
    int upMinusCur = CalPointMinusPointEdgeCharacter(matrix, point, upPoint);
    int upMinusDown = CalPointMinusPointEdgeCharacter(matrix, downPoint, upPoint);
    int denominator = MaxAbs(downMinusCur, upMinusCur);
    if(denominator == 0) return 0;
    return float(abs(upMinusDown)) / denominator;
}

float FSR::GetPointEdgePointWeight(int matrix[], Point *point) {
    return 0;
}

int *FSR::GetPartMatrixWeightLapras(int matrix[], Point *point) {
    return nullptr;
}

float FSR::GetPartNormalLaprasData(int *matrix, Point *point) {
    return GetPartWeightMatrixData(matrix, NormalLapras::GetNormalLaprasMatrix(matrix, point), point);
}

float FSR::GetPointEdgeCharacter(int *matrix, Point *point) {
    float f = pow(((pow(CalPointEdgeCharacterX(matrix, point), 2) + pow(CalPointEdgeCharacterY(matrix, point), 2)) / 2), 2);
    return f;
}

float FSR::GetPointWeight(int *matrix, Point *point, float dist) {
    float feature = GetPointEdgeCharacter(matrix, point);
    return GetLanczos2(feature, dist);
}
float FSR::GetLanczos2W(float feature) {
    return 0.5 - feature / 4;
}

float FSR::GetLanczos2(float feature, float dist) {
    float w = GetLanczos2W(feature);
    dist = std::min(dist, float(1.0 / sqrt(w)));
    float l = ((25.0 / 16) * pow(((2.0 / 5) * dist * dist - 1), 2)) * pow((w * dist * dist - 1), 2);

    return l;
}



