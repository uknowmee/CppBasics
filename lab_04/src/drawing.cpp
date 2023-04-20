//
// Created by Michał on 25.03.2021.
//
#include <iostream>
#include <cmath>
#include "drawing.h"
using namespace std;


int Drawing::number_of_existing_drawings=0;

Drawing::Drawing() {
    cout<<"############################################"<<endl;
    cout<<"[+]Object Drawing created[+]"<<endl;
    name="Drawing";
    high=0;
    width=0;
    figures.clear();
    cout<<"[+]Base name of the Drawing: "<<name<<"[+]"<<endl;
    cout<<"[+]Base high of the Drawing: "<<high<<"[+]"<<endl;
    cout<<"[+]Base width of the Drawing: "<<width<<"[+]"<<endl;
    cout<<"############################################"<<endl;
    number_of_existing_drawings++;
}

string Drawing::get_name() {
    return name;
}

int Drawing::get_high() const {
    return high;
}

int Drawing::get_width() const {
    return width;
}

void Drawing::set_drawing() {
    while (true) {
        cout << "now ure setting the drawing\n"
                "please type the name of the drawing\n-->";
        cin >> name;
        cout << "please type the high of the drawing\n-->";
        cin >> high;
        cout << "please type the width of the drawing\n-->";
        cin >> width;
        if (high>0 && width>0){
            break;
        }
        else{
            cout<<"you entered bad values"<<endl;
        }
    }
}

void Drawing::add_square() {
    figures.push_back(new Square);
    while (true) {
        dynamic_cast<Square *>(figures.back())->set_square();
        if (figures.back()->middle_high<get_high() &&
            figures.back()->middle_high>0 &&
            figures.back()->middle_width>0 &&
            figures.back()->middle_width<get_width()){
            break;
        }
        cout<<"you entered bad coordinates\n"
              "type once again"<<endl;
    }
}

void Drawing::add_circle() {
    figures.push_back(new Circle);
    while (true) {
        dynamic_cast<Circle *>(figures.back())->set_circle();
        if (figures.back()->middle_high<get_high() &&
            figures.back()->middle_high>0 &&
            figures.back()->middle_width>0 &&
            (figures.back())->middle_width<get_width()){
            break;
        }
        cout<<"you entered bad coordinates\n"
              "type once again"<<endl;
    }
}

void Drawing::erase_square() {
    cout<<"############################################"<<endl;
    cout<<"type name of the square u want to erase:\n"
          "-->";
    string declared_name;
    int deleted=0;
    _List_iterator<Figure *> index_delete;
    cin>>declared_name;

    for(auto it = figures.begin(); it != figures.end(); it++) {
        if ((*it)->name==declared_name){
            if (dynamic_cast<Square*>(*it)){
                index_delete=it;
                deleted++;
                break;
            }
        }
    }
    if (deleted!=0) {
        figures.erase(index_delete);
        delete *index_delete;
    }

    if (deleted==0) {
        cout << "name of the square u want to erase has not been found." << endl;
    }
    else{
        cout << "name of the square u want to erase has been found.\n"
                "square has been erased" << endl;
    }
    cout<<"############################################"<<endl;
}

void Drawing::erase_circle() {
    cout<<"############################################"<<endl;
    cout<<"type name of the circle u want to erase:\n"
          "-->";
    string declared_name;
    int deleted=0;
    _List_iterator<Figure *> index_delete;
    cin >> declared_name;

    for(auto it = figures.begin(); it != figures.end(); it++) {
        if ((*it)->name == declared_name){
            if (dynamic_cast<Circle*>(*it)){
                index_delete=it;
                deleted++;
                break;
            }
        }
    }
    if (deleted!=0) {
        figures.erase(index_delete);
        delete *index_delete;
    }

    if (deleted==0) {
        cout << "name of the circle u want to erase has not been found." << endl;
    }
    else{
        cout << "name of the circle u want to erase has been found.\n"
                "circle has been erased" << endl;
    }
    cout<<"############################################"<<endl;
}

void Drawing::copy_square() {
    cout<<"############################################"<<endl;
    cout<<"type name of the square u want to copy:\n"
          "-->";
    string declared_name;
    int copy=0;
    _List_iterator<Figure *> index_copy;
    cin >> declared_name;

    for(auto it = figures.begin(); it != figures.end(); it++) {
        if ((*it)->name == declared_name){
            if (dynamic_cast<Square*>(*it)){
                index_copy=it;
                copy++;
                break;
            }
        }
    }
    if (copy != 0) {
        figures.push_back(new Square(dynamic_cast<Square*>(*index_copy)));
    }

    if (copy == 0) {
        cout << "name of the square u want to copy has not been found." << endl;
    }
    else {
        cout << "name of the square u want to copy has been found.\n"
                "square has been copied" << endl;
    }
    cout<<"############################################"<<endl;
}

void Drawing::copy_circle() {
    cout<<"############################################"<<endl;
    cout<<"type name of the circle u want to copy:\n"
          "-->";
    string declared_name;
    int copy=0;
    _List_iterator<Figure *> index_copy;
    cin >> declared_name;

    for(auto it = figures.begin(); it != figures.end(); it++) {
        if ((*it)->name == declared_name){
            if (dynamic_cast<Circle*>(*it)){
                index_copy=it;
                copy++;
                break;
            }
        }
    }
    if (copy != 0) {
        figures.push_back(new Circle(dynamic_cast<Circle*>(*index_copy)));
    }

    if (copy == 0) {
        cout << "name of the circle u want to copy has not been found." << endl;
    }
    else {
        cout << "name of the circle u want to copy has been found.\n"
                "circle has been copied" << endl;
    }
    cout<<"############################################"<<endl;
}

void Drawing::reposition_square() {
    cout<<"############################################"<<endl;
    cout<<"type name of the square u want to reposition:\n"
          "-->";
    string declared_name;
    int repositioned=0;
    _List_iterator<Figure *> index_repositioned;
    cin >> declared_name;

    for(auto it = figures.begin(); it != figures.end(); it++) {
        if ((*it)->name == declared_name){
            if (dynamic_cast<Square*>(*it)){
                index_repositioned=it;
                repositioned++;
                break;
            }
        }
    }
    if (repositioned!=0) {
        while (true) {
            (*index_repositioned)->move_figure();
            if ((*index_repositioned)->middle_high < get_high() &&
                (*index_repositioned)->middle_high > 0 &&
                (*index_repositioned)->middle_width > 0 &&
                (*index_repositioned)->middle_width < get_width()) {
                break;
            }
            cout << "you entered bad coordinates\n"
                    "type once again" << endl;
        }
    }

    if (repositioned == 0) {
        cout << "name of the square u want to reposition has not been found." << endl;
    }
    else {
        cout << "name of the square u want to reposition has been found.\n"
                "square has been repositioned" << endl;
    }
    cout<<"############################################"<<endl;
}

void Drawing::reposition_circle() {
    cout<<"############################################"<<endl;
    cout<<"type name of the circle u want to reposition:\n"
          "-->";
    string declared_name;
    int repositioned=0;
    _List_iterator<Figure *> index_repositioned;
    cin >> declared_name;

    for(auto it = figures.begin(); it != figures.end(); it++) {
        if ((*it)->name == declared_name){
            if (dynamic_cast<Circle*>(*it)){
                index_repositioned=it;
                repositioned++;
                break;
            }
        }
    }
    if (repositioned!=0) {
        while (true) {
            (*index_repositioned)->move_figure();
            if ((*index_repositioned)->middle_high < get_high() &&
                (*index_repositioned)->middle_high > 0 &&
                (*index_repositioned)->middle_width > 0 &&
                (*index_repositioned)->middle_width < get_width()) {
                break;
            }
            cout << "you entered bad coordinates\n"
                    "type once again" << endl;
        }
    }

    if (repositioned == 0) {
        cout << "name of the circle u want to reposition has not been found." << endl;
    }
    else {
        cout << "name of the circle u want to reposition has been found.\n"
                "circle has been repositioned" << endl;
    }
    cout<<"############################################"<<endl;
}

void Drawing::list_all() {
    cout<<"############################################"<<endl;
    for(auto & figure : figures) {
        cout << figure->name << endl;
        cout << "the Y coordinate of: " << figure->name << " is: " << figure->middle_high << endl;
        cout << "the X coordinate of: " << figure->name << " is: " << figure->middle_width << endl;
        if (dynamic_cast<Square*>(figure)) {
            cout << "the edge of: " << figure->name << " is: " << figure->key_value << endl;
        }
        else if(dynamic_cast<Circle*>(figure)){
            cout << "the radius of: " << figure->name << " is: " << figure->key_value << endl;
        }
    }
    cout << "the number of existing squares is " << Square::number_of_existing_squares << endl;
    cout << "the number of existing circles is " << Circle::number_of_existing_circles << endl;
    cout<<"############################################"<<endl;
}

Drawing::~Drawing() {
    for(auto & figure : figures){
        delete figure;
    }
    cout<<"[+]Object Drawing: "<<name<<" deleted[+]"<<endl;
    number_of_existing_drawings--;
}

