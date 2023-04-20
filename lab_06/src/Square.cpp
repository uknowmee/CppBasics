//
// Created by Michał on 22.04.2021.
//

#include <iostream>
#include "Square.h"


double Square::count = 0;

Square::Square() {
    count++;
    this->setType("Square");
};

Square::Square(const Square &sq) : Figure(sq) {
    this->side = sq.side;
    count++;
}

Square::Square(double _side_, int x, int y) {
    count++;
    side = _side_;
    std::cout << "Object Square created" << std::endl;
    this->setType("Square");
    this->setXY(x, y);
}

Square::~Square() {
    count--;
    std::cout << "Object Square destroyed" << std::endl;
}