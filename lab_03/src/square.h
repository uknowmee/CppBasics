//
// Created by Michał on 12.03.2021.
//
#ifndef SRC_SQUARE_H
#define SRC_SQUARE_H
#include <iostream>
using namespace std;


class Square{
public:

    string name;
    double edge{};
    static int number_of_existing_squares;

    Square();
    Square(const Square &temp);
    void define_square();
    void area() const;
    void circuit() const;
    ~Square();
};

#endif //SRC_SQUARE_H
