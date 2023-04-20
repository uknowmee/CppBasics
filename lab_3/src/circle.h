//
// Created by Michał on 12.03.2021.
//
#ifndef SRC_CIRCLE_H
#define SRC_CIRCLE_H
#include <iostream>
using namespace std;


class Circle{
public:

    string name;
    double radius{};

    Circle();
    Circle(const Circle &temp);
    void define_circle();
    void area() const;
    void circuit() const;
    static double return_PI();
    ~Circle();
};

#endif //SRC_CIRCLE_H
