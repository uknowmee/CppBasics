#include <iostream>
#include "drawing.h"
using namespace std;


int main( int argc, char *argv[]){
///code is in drawing.cpp   &&  drawing.h

    Drawing first_drawing;
    first_drawing.infos();

    Drawing first_drawing_copy(first_drawing);
    first_drawing_copy.infos();

    return 0;
}