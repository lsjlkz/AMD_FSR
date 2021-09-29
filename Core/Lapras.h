//
// Created by lsjlkz on 2021/9/29.
//

#ifndef AMD_FSR_LAPRAS_H
#define AMD_FSR_LAPRAS_H



class Lapras
{
private:
    // 通用拉普拉斯算子
    int getPartMatrixNormalData(int matrix[], int curRow, int curCol, int allCol);
    //带权拉普拉斯算子
    int getPartWeightMatrixData(int matrix[], int weight[], int curRow, int curCol, int allCol);
    int* getPartWeightMatrix(int matrix[], int curRow, int curCol, int allCol);

public:
    Lapras();
    int* getAllMatrixData(int matrix[], int row, int col);
};


#endif //AMD_FSR_LAPRAS_H
