//
// Created by Michał on 08.04.2021.
//
#ifndef SRC_TWODIMENSIONMATRIX_H
#define SRC_TWODIMENSIONMATRIX_H
#include <iostream>
using namespace std;


class TwoDimensionMatrix {
private:
    static constexpr int size=2;
    int array[size][size]{};

public:
    TwoDimensionMatrix();
    explicit TwoDimensionMatrix(const int matrix[size][size]);

    int getElement(int rowIndex, int colIndex) const;
    static constexpr int getSize(){return size;}

    void printTwoDimensionsMatrix();
    friend ostream& operator<< (ostream &os, const TwoDimensionMatrix &matrix);

    TwoDimensionMatrix& operator=(const TwoDimensionMatrix& matrix);
    TwoDimensionMatrix& operator*=(int number);
    TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;
    const int* operator[](size_t i) ;
    explicit operator size_t();

    ~TwoDimensionMatrix();
};
#endif //SRC_TWODIMENSIONMATRIX_H
