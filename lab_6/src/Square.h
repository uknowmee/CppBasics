//
// Created by Michał on 22.04.2021.
//

#ifndef LAB_6_SQUARE_H
#define LAB_6_SQUARE_H
#include <iostream>
#include "Figure.h"
using namespace std;


class Square : public Figure {
private:
    string type = "Square";
    double side = 5;

public:
    static double count;

    Square();
    Square(double _side_, int x, int y);
    Square(const Square &sq);
    ~Square() override;

    double getCircumference() override { return 4 * side; }
    double getArea() const override { return side * side; }
    double getSide() const { return side; }
    string getTyper() override { return type; }
};


#endif //LAB_6_SQUARE_H
