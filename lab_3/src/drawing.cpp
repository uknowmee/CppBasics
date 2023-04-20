//
// Created by Michał on 18.03.2021.
//
#include <iostream>
#include <cmath>
#include "drawing.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////
int Drawing::number_of_existing_drawings=0;

Drawing::Drawing() {
    cout<<"############################################"<<endl;
    cout<<"[+]Object Drawing created[+]"<<endl;
    define_drawing();
    point_square=new Square;
    point_circle=new Circle;
    //point_square->define_square();
    //point_circle->define_circle();
    number_of_existing_drawings++;
}

Drawing::Drawing(const Drawing &temp) {
    name=temp.name;
    high=temp.high;
    width=temp.width;

    point_square=new Square(temp.point_square);
    point_circle=new Circle(temp.point_circle);

    /*point_square->edge=temp.point_square->edge;
    point_square->middle_high=temp.point_square->middle_high;
    point_square->middle_width=temp.point_square->middle_width;

    point_circle->radius=temp.point_circle->radius;
    point_circle->middle_high=temp.point_circle->middle_high;
    point_circle->middle_width=temp.point_circle->middle_width;
    */
    cout<<"[+]Object Drawing "<<name<<" copied[+]"<<endl;
    number_of_existing_drawings++;
}

void Drawing::infos() {
    cout<<"############################################"<<endl;
    cout<<"number of drawings drawings is: "<<Drawing::number_of_existing_drawings<<endl;
    cout<<"the name of your drawing is: "<<name<<endl;
    cout<<"the high of the draw is: "<<high<<endl;
    cout<<"the width of the draw is: "<<width<<endl;
    point_square->infos_();
    point_circle->infos_();
}

void Drawing::define_drawing() {
    cout<<"now ure defining the drawing\n"
          "please type the name of the drawing\n-->";
    cin>>name;
    high=20;
    width=20;
}

Drawing::~Drawing() {
    delete point_square;
    delete point_circle;
    cout<<"[+]Object Drawing "<<name<<" deleted[+]"<<endl;
    number_of_existing_drawings--;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int Drawing::Square::number_of_existing_squares=0;

Drawing::Square::Square() {
    cout<<"############################################"<<endl;
    cout<<"[+]Object Square created[+]"<<endl;
    define_square();
    number_of_existing_squares++;
}

Drawing::Square::Square(Square *const temp){
    name=temp->name;
    edge=temp->edge;
    middle_width=temp->middle_width;
    middle_high=temp->middle_high;
    cout<<"[+]Object Square "<<name<<" copied[+]"<<endl;
    number_of_existing_squares++;
}

void Drawing::Square::infos_() {
    cout<<"number of existing square is: "<<number_of_existing_squares<<endl;
    cout<<"the name of your square is: "<<name<<endl;
    cout<<"the x of the square is: "<<middle_width<<endl;
    cout<<"the y of the square is: "<<middle_high<<endl;
    cout<<"the area of the square is: "<<edge*edge<<endl;
    cout<<"the perimeter of the square is: "<<4*edge<<endl;
}

void Drawing::Square::define_square(){
    cout<<"now ure defining the square\n"
          "please type the name of the square\n-->";
    cin>>name;
    edge=5;
    middle_high=5;
    middle_width=5;
}

Drawing::Square::~Square() {
    cout<<"[+]Object Square "<<name<<" deleted[+]"<<endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int Drawing::Circle::number_of_existing_circles=0;

Drawing::Circle::Circle() {
    cout<<"############################################"<<endl;
    cout<<"[+]Object Circle created[+]"<<endl;
    define_circle();
    number_of_existing_circles++;
}

Drawing::Circle::Circle(Circle *const temp){
    name=temp->name;
    radius=temp->radius;
    middle_width=temp->middle_width;
    middle_high=temp->middle_high;
    cout<<"[+]Object Circle "<<name<<" copied[+]"<<endl;
    number_of_existing_circles++;
}

void Drawing::Circle::infos_() {
    cout<<"number of existing circle is: "<<number_of_existing_circles<<endl;
    cout<<"the name of your circle is: "<<name<<endl;
    cout<<"the radius of the circle is: "<<radius<<endl;
    cout<<"the x of the circle is: "<<middle_width<<endl;
    cout<<"the y of the circle is: "<<middle_high<<endl;
    cout<<"the area of the circle is: "<<M_PI*radius*radius<<endl;
    cout<<"the circumference  of the circle is: "<<2*M_PI*radius<<endl;
    cout<<"############################################"<<endl;
}

void Drawing::Circle::define_circle(){
    cout<<"now ure defining the circle\n"
          "please type the name of the circle\n-->";
    cin>>name;
    radius=5;
    middle_high=10;
    middle_width=10;
}

Drawing::Circle::~Circle() {
    cout<<"[+]Object Circle "<<name<<" deleted[+]"<<endl;
    number_of_existing_circles--;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////