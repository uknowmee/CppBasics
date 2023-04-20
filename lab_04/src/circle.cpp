//
// Created by Michał on 25.03.2021.
//
#include <iostream>
#include "circle.h"


int Circle::number_of_existing_circles=0;

Circle::Circle() {
    cout<<"############################################"<<endl;
    cout<<"[+]Object Circle created[+]"<<endl;
    name="Circle";
    middle_high=0;
    middle_high=0;
    key_value=0;
    cout<<"[+]Base name of the Circle: "<<name<<"[+]"<<endl;
    cout<<"[+]Base Y coordinate of the middle of the Circle: "<<middle_high<<"[+]"<<endl;
    cout<<"[+]Base X coordinate of the middle of the Circle: "<<middle_width<<"[+]"<<endl;
    cout<<"[+]Base radius of the Circle: "<<key_value<<"[+]"<<endl;
    cout<<"############################################"<<endl;
    number_of_existing_circles++;
}

void Circle::set_circle(){
    cout<<"now ure setting the circle\n"
          "please type the name of the circle\n-->";
    cin>>name;
    cout<<"please type the Y coordinate of the middle of the Circle\n-->";
    cin>>middle_high;
    cout<<"please type the X coordinate of the middle of the Circle\n-->";
    cin>>middle_width;
    cout<<"please type the radius of the Circle\n-->";
    cin>>key_value;
}

Circle::Circle(Circle *const temp){
    name=temp->name;
    key_value=temp->key_value;
    middle_width=temp->middle_width;
    middle_high=temp->middle_high;
    cout<<"[+]Object Circle "<<name<<" copied[+]"<<endl;
    number_of_existing_circles++;
}

Circle::~Circle() {
    number_of_existing_circles--;
    cout<<"[+]Object Circle "<<name<<" deleted[+]"<<endl;
}
