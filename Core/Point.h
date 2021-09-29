//
// Created by lsjlkz on 2021/9/29.
//

#ifndef AMD_FSR_POINT_H
#define AMD_FSR_POINT_H


#include <iostream>
#include "CommonProperty.h"

class Point {
private:
    int row;
    int col;
public:
    Point(int _row, int _col);

    int GetRow() { return this->row; }

    int GetCol() { return this->col; }


    Point *GetRightPoint() {
        if (this->col >= CommonProperty::GetAllCol() - 1) return this;
        else
            return new Point(this->row, this->col + 1);
    }

    Point *GetDownPoint() {
        if (this->row >= CommonProperty::GetAllRow() - 1) return this;
        else
            return new Point(this->row + 1, this->col);
    }
    Point *GetUpPoint(){
        if (this->row <= 0) return this;
        else
            return new Point(this->row - 1, this->col);
    }
    Point *GetLeftPoint(){
        if (this->col <= 0) return this;
        else
            return new Point(this->row, this->col - 1);
    }

    void Print(){
        std::cout << "(" << this->row << "," << this->col << "):";
    }

    static float GetPointEdgeCharacter(int matrix[], Point *p1, Point *p2);
};

#endif //AMD_FSR_POINT_H
