#include <iostream>
#include "square.h"
#include "circle.h"
using namespace std;

void informations(){
    cout<<"############################################"<<endl;
    cout<<"returned value of PI is: "<<Circle::return_PI()<<endl;
    cout<<"number of existing square is: "<<Square::number_of_existing_squares<<endl;
    cout<<"############################################"<<endl;
}

int main( int argc, char *argv[]){

    Square sq1;
    sq1.define_square();
    sq1.area();
    sq1.circuit();

    Square sq1_copy(sq1);

    Circle cir1;
    cir1.define_circle();
    cir1.area();
    cir1.circuit();

    Circle cir1_copy(cir1);

    informations();

    return 0;
}