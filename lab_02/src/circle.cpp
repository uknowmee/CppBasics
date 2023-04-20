//
// Created by Michał on 12.03.2021.
//
#include <iostream>
#include <cmath>
#include "circle.h"
using namespace std;


Circle::Circle() {
    cout<<"[+]Object Circle created[+]"<<endl;
}

Circle::Circle(const Circle &temp) {
    name=temp.name;
    radius=temp.radius;
    cout<<"[+]Object Circle coppied[+]"<<endl;
}

void Circle::define_circle(){
    cout<<"############################################"<<endl;
    cout<<"now ure defining the circle\n"
          "please type the name of the circle\n-->";
    cin>>name;
    cout<<"pleas type the radius of the circle\n-->";
    cin>>radius;
}

void Circle::area() const{
    string decision;
    cout<<"do you want to know whats the area of "<<name<<"?"<<endl;
    cout<<"type yes/no\n-->";
    while (true) {
        cin >> decision;
        if (decision == "yes") {
            cout << "the area of " << name << " is: " << M_PI*radius*radius<<endl;
            break;
        }
        else if (decision == "no") {
            cout << "okkay, fine"<<endl;
            break;

        }
        else {
            cout << "sorry i didnt understand, type again\n-->";
        }
    }
}

void Circle::circuit() const{
    string decision;
    cout<<"do you want to know whats the circuit of "<<name<<"?"<<endl;
    cout<<"type yes/no\n-->";
    while (true) {
        cin >> decision;
        if (decision == "yes") {
            cout << "the circuit of " << name << " is: " << 2*M_PI*radius <<endl;
            break;
        }
        else if (decision == "no") {
            cout << "okkay, fine"<<endl;
            break;

        }
        else {
            cout << "sorry i didnt understand, type again\n-->";
        }
    }
    cout<<"############################################"<<endl;
}

double Circle::return_PI() {
    return M_PI;
}

Circle::~Circle() {
    cout<<"[+]Object Circle deleted[+]"<<endl;
}