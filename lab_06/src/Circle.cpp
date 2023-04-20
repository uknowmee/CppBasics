//
// Created by Michał on 22.04.2021.
//

#include <iostream>
#include "Circle.h"


Circle::Circle() {
    this->setType("Circle");
    this->setXY(0, 0);
};

Circle::Circle(const Circle &cir) : Figure(cir) {
    this->radius = cir.radius;
}

Circle::Circle(double _radius_, int x, int y) {
    radius = _radius_;
    std::cout << "Object Circle created" << std::endl;
    this->setXY(x, y);
    this->setType("Circle");
}

Circle::~Circle() {
    std::cout << "Object Circle destroyed" << std::endl;
}
