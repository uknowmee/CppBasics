//
// Created by Michał on 25.03.2021.
//
#ifndef SRC_CIRCLE_H
#define SRC_CIRCLE_H
#include <iostream>
#include "figure.h"
using namespace std;


class Circle: public Figure{
public:
    static int number_of_existing_circles;

    Circle();
    explicit Circle(Circle *temp);
    void set_circle();
    ~Circle() override;
};
#endif //SRC_CIRCLE_H
