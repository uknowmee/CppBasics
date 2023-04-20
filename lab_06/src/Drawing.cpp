//
// Created by Michał on 22.04.2021.
//

#include <iostream>
#include <cmath>
#include "Drawing.h"
using namespace std;

Drawing::Drawing() {
    r_x = 20;
    r_y = 20;
};

Drawing::Drawing(int _rx, int _ry) {
    r_x = _rx;
    r_y = _ry;
    cout << "Drawing has been created." << endl;
}

Drawing::Drawing(const Drawing &f){
    r_x = f.getX();
    r_y = f.getY();
    cout << "Drawing has been created." << endl;
};

void Drawing::setSize(int rx, int ry) {
    r_x = rx;
    r_y = ry;
}

ostream& operator<<(ostream &os ,const Drawing &drawing){
    os << endl << "parameters of the drawing: " << endl;
    os << "r_x: " << drawing.r_x << endl;
    os << "r_y: " << drawing.r_y << endl;
    os << "List of elements: " << endl;
    for (auto const &v : drawing.figureList) {
        os << endl <<"Figure type: ";
        v->getType();
        os << " ";
        os << endl << "Co-ordinates: ";
        v->getCo();
        os << endl;
        if (v->getTyper() == "Square"){
            os << "side: " <<dynamic_cast<Square*>(v)->getSide()<< endl;
        }
        else{
            os << "radius: " << dynamic_cast<Circle*>(v)->getRadius()<< endl;
        }
        os << "Area: " << v->getArea()
             << " Circumference: " << v->getCircumference() << endl;
    }
    os << "###########################################################";
    return os;
}

istream& operator>>(istream &is , Drawing &drawing){
    int x, y;
    is >> x;
    is >> y;
    drawing.setSize(x, y);

    return is;
}


bool Drawing::operator== ( const Drawing &drawing) const{
    int tsquare, tcircle, dsquare, dcircle;
    tsquare=0;
    tcircle=0;
    dsquare=0;
    dcircle=0;
    if (this->getX() == drawing.getX() && this->getY() == drawing.getY()){
        if (this->figureList.size() == drawing.figureList.size()){
            for (auto &itr : this->figureList) {
                if (itr->getTyper() == "Square"){
                    tsquare++;
                }
                if (itr->getTyper() == "Circle"){
                    tcircle++;
                }
            }
            for (auto &itr1 : drawing.figureList) {
                if (itr1->getTyper() == "Square"){
                    dsquare++;
                }
                if (itr1->getTyper() == "Circle"){
                    dcircle++;
                }
            }
            if (tsquare!=dsquare || tcircle!=dcircle){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

Figure* Drawing::operator[] ( const int &n) const{
    int counter=0;
    for (auto &itr : this->figureList) {
        if(counter == n){
            return itr;
        }
        counter++;
    }
    return nullptr;
}

Figure* Drawing::operator() ( const int &n) const{
    int counter=0;
    for (auto &itr : this->figureList) {
        if(counter == n){
            return itr;
        }
        counter++;
    }
    return nullptr;
}

Drawing& Drawing::operator+= ( const Drawing &drawing){
    for (Figure* itr : drawing.figureList) {
        if (dynamic_cast<Square*>(itr)){
            this->addFigure( new Square(*dynamic_cast<Square*>(itr)));
        }
        if (dynamic_cast<Circle*>(itr)){
            this->addFigure(new Circle(*dynamic_cast<Circle*>(itr)));
        }
    }
    return *this;
}

Drawing& Drawing::operator= ( const Drawing &drawing){
    this->figureList.clear();
    this->r_x = drawing.r_x;
    this->r_y = drawing.r_y;
    for (Figure* itr : drawing.figureList) {
        //cout << itr->getTyper()<< endl;
        if (dynamic_cast<Square*>(itr)){
            this->addFigure( new Square(*dynamic_cast<Square*>(itr)));
        }
        if (dynamic_cast<Circle*>(itr)){
            this->addFigure(new Circle(*dynamic_cast<Circle*>(itr)));
        }
    }
    return *this;
}

void Drawing::addFigure(Figure *ab) {
    figureList.push_back(ab);
}

Drawing::~Drawing() {
    if (!figureList.empty()){
        for(auto & figure : figureList){
            delete figure;
        }
    }
    figureList.clear();
    cout << endl << "Drawing deleted" << endl;
}