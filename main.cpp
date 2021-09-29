#include <iostream>
#include "Core/Lapras.h"

int main() {
    std::cout << "Hello World!\n";
    Lapras* lapras = new Lapras();
    int* matrix = new int[4*4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i * 4 + j] = rand() % 10;
            std::cout << matrix[i * 4 + j] << "\t";
        }
        std::cout << std::endl;
    }
    int* data = lapras->getAllMatrixData(matrix, 4, 4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << data[i * 4 + j] << "\t";
        }
        std::cout << std::endl;
    }
}
