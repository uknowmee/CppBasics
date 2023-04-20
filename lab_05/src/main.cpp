#include <iostream>
#include "TwoDimensionMatrix.h"
using namespace std;


TwoDimensionMatrix operator+ (const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2){
    int arr[TwoDimensionMatrix::getSize()][TwoDimensionMatrix::getSize()];
    for (int i = 0; i <TwoDimensionMatrix::getSize() ; ++i) {
        for (int j = 0; j <TwoDimensionMatrix::getSize() ; ++j) {
            arr[i][j]=matrix1.getElement(i, j)+matrix2.getElement(i, j);
        }
    }
    TwoDimensionMatrix result (arr);
    return result;
}

int main(int argc, char *argv[]){
    TwoDimensionMatrix matrix1;
    matrix1.printTwoDimensionsMatrix();
    cout<<"size: "<<TwoDimensionMatrix::getSize()<<endl;
    cout<<endl;

    int arr[2][2]={{1,2},{3,4}};
    TwoDimensionMatrix matrix2 (arr);
    matrix2.printTwoDimensionsMatrix();
    cout<<endl;

    matrix1=matrix2;
    matrix1.printTwoDimensionsMatrix();
    cout<<endl;

    TwoDimensionMatrix matrix3;
    matrix3=matrix2 + matrix1;
    cout << matrix3 << endl;

    matrix3*=2;
    cout << matrix3 << endl;

    TwoDimensionMatrix matrix4;
    matrix4=matrix1 && matrix2;
    cout << matrix4 << endl;
    matrix4=matrix3 && matrix2;
    cout << matrix4 << endl;

    const int* firstRowOfMatrix3;
    firstRowOfMatrix3=matrix3[0];
    for (int i = 0; i < 2; ++i) {
        cout<<firstRowOfMatrix3[i]<<" ";
    }
    cout << endl;
    ///firstRowOfMatrix3[1]=2; blad- tak mialo byc
    matrix3*=2;
    for (int i = 0; i < 2; ++i) {
        cout<<firstRowOfMatrix3[i]<<" ";
    }
    cout<<endl;
    ///wartosci firstRowOfMatrix3 ulegly zmianie- tak mialo byc

    size_t test;
    test=(size_t)matrix3;
    cout<<test;

    return 0;
}