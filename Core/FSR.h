//
// Created by lsjlkz on 2021/9/29.
//

#ifndef AMD_FSR_FSR_H
#define AMD_FSR_FSR_H

#include "Point.h"


class NormalLapras{
private:
    static float *weight;
public:
    // 获取通用拉普拉斯算子
    static float *GetNormalLaprasMatrix(int matrix[], Point *point){
        return weight;
    }
};

class FSR {
private:

    // 获取某点的边缘特征，就是Feature，越小越平缓，越大越边缘
    static float GetPointEdgeCharacter(int matrix[], Point *point);

    // 获取某点的权重
    static float GetPointWeight(int matrix[], Point *point, float dist);

    // 计算某两点之间的边缘特征
    static int CalPointMinusPointEdgeCharacter(int matrix[], Point *point, Point *otherPoint);

    // 某点x轴的边缘特征，就是FeatureX轴，越小越平缓，越大越边缘
    static float CalPointEdgeCharacterX(int matrix[], Point *point);

    // 某点y轴的边缘特征，就是FeatureY轴，越小越平缓，越大越边缘
    static float CalPointEdgeCharacterY(int matrix[], Point *point);

    // 获取某点边上某点的权重
    static float GetPointEdgePointWeight(int matrix[], Point *point);

    // 获取某点权重的w
    static float GetLanczos2W(float feature);

    static float GetLanczos2(float w, float dist);

    static int GetMatrixEdgeData(){
        return 0;
    }

public:
    static float *getAllMatrixData(int matrix[], float *(*f)(int _matrix[], Point *_point));

    // 获取通用拉普拉斯算子计算值
    static float GetPartNormalLaprasData(int matrix[], Point *point);

    // 获取权重拉普拉斯算子
    static int *GetPartMatrixWeightLapras(int matrix[], Point *point);

    // 根据权重拉普拉斯算子计算值
    static float GetPartWeightMatrixData(int matrix[], float weight[], Point *point);

    // 获取某点的带权拉普拉斯权重矩阵
    static float *GetPartWeightMatrix(int matrix[], Point *point);
};


#endif //AMD_FSR_FSR_H
