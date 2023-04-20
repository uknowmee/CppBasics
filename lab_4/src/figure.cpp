//
// Created by Michał on 25.03.2021.
//
#include <iostream>
#include <cmath>
#include "figure.h"


Figure::Figure() {
    name="Figure";
    key_value=0;
    middle_width=0;
    middle_high=0;
}

void Figure::move_figure() {
    cout << "the Y coordinate of: " << name << " is: " << middle_high << endl;
    cout << "the X coordinate of: " << name << " is: " << middle_width << endl;
    cout << "define the new Y coordinate:\n"
            "-->";
    cin>>middle_high;
    cout << "define the new X coordinate:\n"
            "-->";
    cin>>middle_width;
}

Figure::~Figure() {
    cout<<"[+]Object Figure "<<name<<" deleted[+]"<<endl;
}
