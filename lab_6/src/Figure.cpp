//
// Created by Michał on 22.04.2021.
//
//#include <iostream>
#include <cmath>
//#include "Figure.h"
#include "Square.h"

Figure::Point2D::Point2D() {
    x_ob = 0;
    y_ob = 0;
}

Figure::Point2D::Point2D(int _x, int _y) {
    x_ob = _x;
    y_ob = _y;
}

void Figure::Point2D::setPtXY(int x, int y) {
    x_ob = x;
    y_ob = y;
}

Figure::Figure() {
    coord.x_ob = 0;
    coord.y_ob = 0;
}

Figure::Figure(const Figure &f) {
    this->setXY(f.getX(), f.getY());
    this->type = f.type;
}

void Figure::setXY(int _x, int _y) {
    coord.setPtXY(_x, _y);
}

void Figure::setType(const char *n) {
    type = n;
}

bool Figure::operator< ( const Figure &fig1) const{
    if (this->getArea() < fig1.getArea()){
        return true;
    }
    return false;
}


