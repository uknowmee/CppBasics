//
// Created by Michał on 25.03.2021.
//
#ifndef SRC_SQUARE_H
#define SRC_SQUARE_H
#include <iostream>
#include "figure.h"
using namespace std;


class Square: public Figure{
public:
    static int number_of_existing_squares;

    Square();
    explicit Square(Square *pSquare);
    void set_square();
    ~Square() override;
};
#endif //SRC_SQUARE_H
