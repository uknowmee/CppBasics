#include <iostream>
#include "drawing.h"
using namespace std;
//////////////////////////////////////////////////////////////
///////every dimensions of the draw has to be positive////////
/////you can place figures wherever u want but take care://///
/////+the centre of the figure has to be inside the draw//////
/////name draw and figures only using names without spaces////
//////if u wanna copy a figure remember the first figure://///
///////+from the list with matching name will be copied///////
////////same logic works for erasing and repositioning////////
//////////////////////////////////////////////////////////////
int main( int argc, char *argv[]){
    Drawing first_drawing;
    while (true){
        string decision;
        cout<<"Hey, how you doing painter?\n"
              "Do you want to change the name of: "<<first_drawing.get_name()<<" and resize it?\n"
              "Type: yes/no\n"
              "-->";
        cin>>decision;
        if (decision=="yes"){
            first_drawing.set_drawing();
            break;
        }
        else if (decision=="exit"){
            return 0;
        }
        else{
            continue;
        }
    }
    while (true){
        cout<<"if u wanna draw square type: add_square\n"
              "if u wanna draw circle type: add_circle\n"
              "if u wanna erase square type: erase_square\n"
              "if u wanna erase circle type: erase_circle\n"
              "if u wanna copy circle type: copy_circle\n"
              "if u wanna copy square type: copy_square\n"
              "if u wanna change position of the square square type: re_position_square\n"
              "if u wanna change position of the circle square type: re_position_circle\n"
              "if u wanna list all elements type: list_all\n"
              "if u wanna exit type: exit\n";
        cout<<"-->";
        string decision;
        cin>>decision;

        if(decision=="add_square") {
            first_drawing.add_square();
        }
        if(decision=="add_circle"){
            first_drawing.add_circle();
        }
        if(decision=="erase_square"){
            first_drawing.erase_square();
        }
        if(decision=="erase_circle"){
            first_drawing.erase_circle();
        }
        if(decision=="copy_circle"){
            first_drawing.copy_circle();
        }
        if(decision=="copy_square"){
            first_drawing.copy_square();
        }
        if(decision=="re_position_square"){
            first_drawing.reposition_square();
        }
        if(decision=="re_position_circle"){
            first_drawing.reposition_circle();
        }
        if(decision=="list_all"){
            first_drawing.list_all();
        }
        if(decision=="exit"){
            return 0;
        }
        else{
            continue;
        }
    }
    return 0;
}