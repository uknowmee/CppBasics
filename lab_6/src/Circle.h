//
// Created by Michał on 22.04.2021.
//

#ifndef LAB_6_CIRCLE_H
#define LAB_6_CIRCLE_H
#include <iostream>
#include <cmath>
#include "Figure.h"
using namespace std;


class Circle : public Figure {
private:
    string type = "Circle";
    double radius = 10;

public:
    Circle();
    Circle(double _radius_, int x, int y);
    Circle(const Circle &cir);
    ~Circle() override;

    double getCircumference() override { return 2 * M_PI * radius; }
    double getArea() const override { return M_PI * radius * radius; }
    double getRadius() const { return radius; }
    string getTyper() override { return type; }
};


#endif //LAB_6_CIRCLE_H
