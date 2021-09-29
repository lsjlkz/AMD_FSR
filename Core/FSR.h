//
// Created by lsjlkz on 2021/9/29.
//

#ifndef AMD_FSR_FSR_H
#define AMD_FSR_FSR_H

class Point {
private:
    int row;
    int col;
public:
    Point(int _row, int _col);

    int GetRow() { return this->row; }

    int GetCol() { return this->col; }
};


class FSR {
private:

    // 获取某点的带权拉普拉斯权重矩阵
    int *GetPartWeightMatrix(int matrix[], Point *point, int allCol);

    // 获取某点的边缘特征
    int GetPointEdgeCharacter(int matrix[], Point *point, int allCol);

    // 某点与右边的边缘特征
    int GetPointEdgeCharacterX(int matrix[], Point *point, int allCol);

    // 某点与下边的边缘特征
    int GetPointEdgeCharacterY(int matrix[], Point *point, int allCol);

    // 获取某点边上某点的权重
    int GetPointEdgePointWeight(int matrix[], Point *point);

public:
    static int *getAllMatrixData(int matrix[], int row, int col, int*(* f)(...));
    // 获取通用拉普拉斯算子
    static int* GetPartMatrixNormalLapras(...);

    // 获取权重拉普拉斯算子
    static int* GetPartMatrixWeightLapras(int matrix[], Point *point, int allCol);

    // 根据权重拉普拉斯算子计算值
    static int GetPartWeightMatrixData(int matrix[], int weight[], Point* point, int allCol);
};


#endif //AMD_FSR_FSR_H
