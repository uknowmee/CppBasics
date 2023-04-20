//
// Created by Michał on 12.03.2021.
//
#include <iostream>
#include "square.h"
using namespace std;

int Square::number_of_existing_squares=0;

Square::Square() {
    cout<<"[+]Object Square created[+]"<<endl;
    number_of_existing_squares++;
}

Square::Square(const Square &temp) {
    name=temp.name;
    edge=temp.edge;
    cout<<"[+]Object Square coppied[+]"<<endl;
    number_of_existing_squares++;
}

void Square::define_square() {
    cout<<"############################################"<<endl;
    cout<<"now ure defining the square\n"
          "please type the name of the square\n-->";
    cin>>name;
    cout<<"pleas type the edge of the square\n-->";
    cin>>edge;
    }

void Square::area() const{
    string decision;
    cout<<"do you want to know whats the area of "<<name<<"?"<<endl;
    cout<<"type yes/no\n-->";
    while (true) {
        cin >> decision;
        if (decision == "yes") {
            cout << "the area of " << name << " is: " << edge * edge<<endl;
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

void Square::circuit() const{
    string decision;
    cout<<"do you want to know whats the circuit of "<<name<<"?"<<endl;
    cout<<"type yes/no\n-->";
    while (true) {
        cin >> decision;
        if (decision == "yes") {
            cout << "the circuit of " << name << " is: " << 4*edge <<endl;
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

Square::~Square() {
    cout<<"[+]Object Square deleted[+]"<<endl;
}
