//
// Created by lsjlkz on 2021/9/29.
//

#ifndef AMD_FSR_COMMONPROPERTY_H
#define AMD_FSR_COMMONPROPERTY_H


class CommonProperty {
private:
public:
    static int allRow;
    static int allCol;
    static int GetAllRow() { return allRow; }

    static int GetAllCol() { return allCol; }

    static void SetSize(int row, int col) {
        allRow = row;
        allCol = col;
    }
};


#endif //AMD_FSR_COMMONPROPERTY_H
