#include <iostream>
#include <array>
#include <vector>
#include "VectoredList.h"

using namespace std;

int main(){
    cout << endl << "---------- 1 ----------" << endl;
    VectoredList v;
    string       t11("TEST 1.1");
    string       t12("TEST 1.2");
    v.push_back(t11);
    v.push_back(t12);

    VectoredList v1(move(v));

    for (int i = 0; i < v1.VectoredListSize(); ++i){
         cout << v1[i] << endl;
    }

    cout << endl << "---------- 2 ----------" << endl;
    VectoredList v2;
    string       t21("TEST 2.1");
    string       t22("TEST 2.2");
    v2.push_back(t21);
    v2.push_back(t22);

    v1 = move(v2);

    for (int i = 0; i < v1.VectoredListSize(); ++i){
        cout << v1[i] << endl;
    }

    cout << endl << "---------- 3 ----------" << endl;
    VectoredList v3, v4;
    string       t31("TEST 3.1");
    v3.push_back(t31);

    v4 = v1 + v3;

    for (int i = 0; i < v4.VectoredListSize(); ++i){
        cout << v4[i] << endl;
    }

    cout << endl << "---------- 4 ----------" << endl;
    vector<string> V{"TEST 4.1", "TEST 4.2"};

    v4.assign(V);

    for (int i = 0; i < v4.VectoredListSize(); ++i){
        cout << v4[i] << endl;
    }
    return 0;
}