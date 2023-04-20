//
// Created by Michał on 18.03.2021.
//
#ifndef LAB_3_DRAWING_H
#define LAB_3_DRAWING_H
#include <iostream>
using namespace std;


class Drawing{

private:
    string name;
    int high;
    int width;
    static int number_of_existing_drawings;

    class Square{
        friend class Drawing;
    private:
        string name;
        int edge;
        int middle_high;
        int middle_width;
        static int number_of_existing_squares;

        void infos_();
        Square();
        explicit Square(Square *pSquare);
        void define_square();
        ~Square();
    };

    class Circle{
        friend class Drawing;
    private:
        string name;
        int radius;
        int middle_high;
        int middle_width;
        static int number_of_existing_circles;

        void infos_();
        Circle();
        explicit Circle(Circle *temp);
        void define_circle();
        ~Circle();
    };

    Square *point_square=nullptr;
    Circle *point_circle=nullptr;

public:
    void infos();
    Drawing();
    Drawing(const Drawing &temp);
    void define_drawing();
    ~Drawing();
};

#endif //LAB_3_DRAWING_H
