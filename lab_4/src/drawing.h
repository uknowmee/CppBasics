//
// Created by Michał on 25.03.2021.
//
#ifndef LAB_4_DRAWING_H
#define LAB_4_DRAWING_H
#include <iostream>
#include <list>
#include "figure.h"
#include "square.h"
#include "circle.h"
using namespace std;


class Drawing{
private:
    string name;
    int high;
    int width;
    static int number_of_existing_drawings;

public:
    list<Figure*> figures;
    Drawing();
    void set_drawing();
    void add_square();
    void add_circle();
    void erase_square();
    void erase_circle();
    void copy_square();
    void copy_circle();
    void reposition_square();
    void reposition_circle();
    void list_all();

    string get_name();
    int get_high() const;
    int get_width() const;
    ~Drawing();
};
#endif //LAB_4_DRAWING_H
