//
// Created by Michał on 25.03.2021.
//
#include <iostream>
#include <cmath>
#include "square.h"


int Square::number_of_existing_squares=0;

Square::Square() {
    cout<<"############################################"<<endl;
    cout<<"[+]Object Square created[+]"<<endl;
    name="Square";
    middle_high=0;
    middle_high=0;
    key_value=0;
    cout<<"[+]Base name of the Square: "<<name<<"[+]"<<endl;
    cout<<"[+]Base Y coordinate of the middle of the Square: "<<middle_high<<"[+]"<<endl;
    cout<<"[+]Base X coordinate of the middle of the Square: "<<middle_width<<"[+]"<<endl;
    cout<<"[+]Base edge of the Square: "<<key_value<<"[+]"<<endl;
    cout<<"############################################"<<endl;
    number_of_existing_squares++;
}

void Square::set_square(){
    cout<<"now ure setting the square\n"
          "please type the name of the square\n-->";
    cin>>name;
    cout<<"please type the Y coordinate of the middle of the Square\n-->";
    cin>>middle_high;
    cout<<"please type the X coordinate of the middle of the Square\n-->";
    cin>>middle_width;
    cout<<"please type the edge of the square\n-->";
    cin>>key_value;
}

Square::Square(Square *const temp){
    name=temp->name;
    key_value=temp->key_value;
    middle_width=temp->middle_width;
    middle_high=temp->middle_high;
    cout<<"[+]Object Square "<<name<<" copied[+]"<<endl;
    number_of_existing_squares++;
}

Square::~Square() {
    number_of_existing_squares--;
    cout<<"[+]Object Square "<<name<<" deleted[+]"<<endl;
}
