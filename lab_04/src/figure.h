//
// Created by Michał on 25.03.2021.
//
#ifndef SRC_FIGURE_H
#define SRC_FIGURE_H
#include <iostream>
using namespace std;


class Figure{
    friend class Drawing;
public:
    string name;
    int key_value;
    int middle_high;
    int middle_width;

    Figure();
    void move_figure();
    virtual ~Figure();
};


#endif //SRC_FIGURE_H
