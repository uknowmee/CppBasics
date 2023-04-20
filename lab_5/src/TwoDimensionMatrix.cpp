//
// Created by Michał on 08.04.2021.
//
#include <iostream>
#include "TwoDimensionMatrix.h"
using namespace std;


TwoDimensionMatrix::TwoDimensionMatrix() {
    for (auto & i : array){
        for (int & j : i){
            j = 0;
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const int matrix[size][size]) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            array[i][j]=matrix[i][j];
        }
    }
}

int TwoDimensionMatrix::getElement(int rowIndex, int colIndex) const{
    return array[rowIndex][colIndex];
}

void TwoDimensionMatrix::printTwoDimensionsMatrix() {
    cout<<"matrix:"<<endl;
    for (auto & i : array){
        for (int j : i){
            cout << j<< " ";
        }
        cout<<endl;
    }
}

ostream& operator<<(ostream &os ,const TwoDimensionMatrix &matrix){
    os<<"matrix:"<<endl;
    for (int i = 0; i < TwoDimensionMatrix::getSize(); ++i) {
        for (int j = 0; j < TwoDimensionMatrix::getSize(); ++j) {
            os<<matrix.getElement(i,j)<<" ";
        }
        os<<endl;
    }
    return os;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix &matrix){
    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j < size; ++j) {
            this->array[i][j] = matrix.array[i][j];
        }
    }
    return *this;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(int number){
    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j < size; ++j) {
            this->array[i][j] = number * TwoDimensionMatrix::getElement(i,j);
        }
    }
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &matrix) const {
    int arr[size][size];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (array[i][j]==matrix.array[i][j]){
                arr[i][j]=1;
            }
            else{
                arr[i][j]=0;
            }
        }
    }
    TwoDimensionMatrix result (arr);
    return result;
}

const int* TwoDimensionMatrix::operator[](size_t i){
    return array[i];
}

TwoDimensionMatrix::operator size_t() {
    return (size_t)TwoDimensionMatrix::getSize();
}

TwoDimensionMatrix::~TwoDimensionMatrix() = default;