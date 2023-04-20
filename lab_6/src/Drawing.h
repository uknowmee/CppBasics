//
// Created by Michał on 22.04.2021.
//

#ifndef LAB_6_DRAWING_H
#define LAB_6_DRAWING_H
#include <iostream>
#include <list>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
using namespace std;


class Drawing {
private:
    int r_x, r_y;
    list<Figure *> figureList;

public:
    Drawing();
    Drawing(int _rx, int _ry);
    Drawing(const Drawing &f);
    ~Drawing();

    double getX() const { return this->r_x; }
    double getY() const { return this->r_y; }
    list<Figure *>& getList() {return this->figureList; };

    void setSize(int rx, int ry);

    friend ostream& operator<< (ostream &os, const Drawing &drawing);
    friend istream& operator>> (istream &is, Drawing &drawing);
    bool operator== ( const Drawing &drawing) const;
    Figure* operator[] ( const int &n) const;
    Figure* operator() ( const int &n) const;
    Drawing& operator+= ( const Drawing &drawing);
    friend Drawing operator+(const Drawing &drawing1, const Drawing &drawing2);
    Drawing& operator= ( const Drawing &drawing);

    void addFigure(Figure *ab);
};


#endif //LAB_6_DRAWING_H
