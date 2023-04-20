#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <typeinfo>
#include "Drawing.h"
using namespace std;


bool PComp(const Figure *const &a, const Figure *const &b) { return *a < *b;}

Drawing operator+(const Drawing &drawing1, const Drawing &drawing2){
    Drawing result (drawing1.getX(), drawing1.getY());
    for (Figure* itr1 : drawing1.figureList) {
        result.addFigure(itr1);
    }
    for (Figure* itr2 : drawing2.figureList) {
        int count = 0;
        for (Figure* re : result.figureList) {
            if (re == itr2){
                count++;
                break;
            }
        }
        if (count ==0){
            result.addFigure(itr2);
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    auto *drawing = new Drawing(100, 100);
    auto *drawing2 = new Drawing(200, 200);

    auto *s1 = new Square(15, 10, 15);
    auto *c1 = new Circle(5, 10, 15);
    drawing->addFigure(s1);
    drawing->addFigure(c1);

    drawing2->addFigure(s1);
    drawing2->addFigure(c1);

    auto *sq1 = new Square(*s1);
    auto *cir1 = new Circle(*c1);
    drawing->addFigure(sq1);
    drawing->addFigure(cir1);

    // 1 // print all available info
    cout << *drawing << endl;

    // 2 // change the drawing dimensions---podaj wysokosc i szerokosc nowego obrazka
    cin >> *drawing;
    cout << *drawing << endl;

    // 3 // comparison
    if (*drawing == *drawing2) {
        cout << "Drawing are equal" << endl;
    }
    else{
        cout << "Drawing are not equal" << endl;
    }

    // 4 // sort the figures based on area (compare pointer by the dereference)---
    // uncoment also PComp function
    drawing->getList().sort(PComp);
    cout << *drawing << endl;

    // 5 // return the n'th element in the figure list
    cout << (*drawing)[0]->getTyper() << endl;
    cout << (*drawing)[2]->getTyper() << endl;

    // 6 // return the n'th element in the figure list---operator subskrypcji
    cout << (*drawing)(0)->getTyper() << endl;
    cout << (*drawing)(2)->getTyper() << endl;

    // 7 // add figures from 2nd drawing to first drawing:
    *drawing += *drawing2;

    auto *sx = new Square(15, 10, 15);
    drawing2->addFigure(sx);
    *drawing = *drawing + *drawing2;

    // 8 //add copy assigment operator
    *drawing2 = *drawing;

    // 9 // fix the memory leak

    // 10 // clean the code

    delete drawing;
    delete drawing2;

    return 0;
}


