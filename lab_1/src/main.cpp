#include <iostream>
#include <time.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////INSTRUCTIONS
/*W pliku main.cpp:
1.Proszę napisać cztery funkcje dodające do siebie dwie liczby całkowite A i B.
 Wynik dodawania zapisujemy w zmiennej C. Zmienne A i B nie są modyfikowane w funkcjach.
 Zmienna C przekazana do funkcji przez wskaźnik.
a)Pierwsza funkcja przyjmuje argumenty A, B przez wartość
b)Druga funkcja przyjmuje argumenty A, B przez wskaźnik
c)Trzecia funkcja przyjmuje argumenty A, B przez referencję
d)Czwarta funkcja przyjmuje argumenty A, B przez wskaźnik do referencji
Przetestuj działanie wszystkich funkcji
Słowa kluczowe: *, &, *&, const, restrict

2.To samo co w punkcie 1) tylko z jednowymiarowymi tablicami typu całkowitego o rozmiarze 10.
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////TASK 1
void func_1(const int a, const int b, int *__restrict__ c){
    *c=a+b;
}

void func_2(const int *a, const int *b, int *__restrict__ c){
    *c=*a+*b;
}

void func_3(int &ref_a, int &ref_b, int *__restrict__ c){
    *c=ref_a+ref_b;
}

void func_4(const int *&a, const int *&b, int *__restrict__ c){
    *c=*a+*b;
}

void task_1(){
    int A, B, C;
    int &ref_A = A;
    int &ref_B = B;
    int *c=&C;
    const int *p_ref_A=&ref_A, *p_ref_B=&ref_B;

    A=1;
    B=2;
    func_1(A, B, c);
    cout << "C=A+B  <=>  "<< "C=" << A <<"+"<< B << "=" << C << endl;

    A=2;
    B=3;
    func_2(&A, &B, c);
    cout << "C=A+B  <=>  "<< "C=" << A <<"+"<< B << "=" << C << endl;

    A=3;
    B=4;
    func_3(A, B, c);
    cout << "C=A+B  <=>  "<< "C=" << A <<"+"<< B << "=" << C << endl;

    A=4;
    B=5;
    func_4(p_ref_A, p_ref_B, c);
    cout << "C=A+B  <=>  "<< "C=" << A <<"+"<< B << "=" << C << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////TASK 2
int *generate(int *temp){
    temp=(int *)malloc(sizeof(int)*10);
    for (int i = 0; i < 10; ++i) {
        temp[i]=rand() % 10;
    }
    return temp;
}

void printOut(int *temp){
    for (int i = 0; i < 10; ++i) {
        if (i < 9) {
            cout << temp[i] << ",";
        }
        else{
            cout << temp[i];
        }
    }
    cout << endl;
}

void printOut_1(int *a, int *b, int *c){
    printOut(a);
    printOut(b);
    cout << "++++++++++++++++++++++\n";
    printOut(c);
    cout << "\n";
}

void func__1(int a, int b, int *c){
    *c=a+b;
}

void func__2(int *a, int *b, int *c){
    *c=*a+*b;
}

void func__3(int &ref_a, int &ref_b, int * c){
    *c=ref_a+ref_b;
}

void func__4(){

}

void func__0(int *a, int *b, int *c, int counter){
    if (counter==1) {
        for (int i = 0; i < 10; ++i) {
            func__1(a[i], b[i], &c[i]);
        }
    }
    if (counter==2) {
        for (int i = 0; i < 10; ++i) {
            func__2(&a[i], &b[i], &c[i]);
        }
    }
    if (counter==3) {
        for (int i = 0; i < 10; ++i) {
            func__3(a[i], b[i], &c[i]);
        }
    }
    if (counter==4) {
        for (int i = 0; i < 10; ++i) {

        }
    }
}

void task_2(){
    int i;
    int *array_A;
    int *array_B;
    int *array_C;

    array_C=(int *)malloc(sizeof(int)*10);
    for (i=1; i<5 ; i++) {
        array_A=generate(array_A);
        array_B=generate(array_B);
        func__0(array_A, array_B, array_C, i);
        if (i==1) {
            cout << "first way:\n";
        }
        if (i==2) {
            cout << "second way:\n";
        }
        if (i==3) {
            cout << "third way:\n";
        }
        if (i==4) {
            break;
        }
        printOut_1(array_A, array_B, array_C);
    }

    free(array_A);
    free(array_B);
    free(array_C);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////MAIN
int main(int argc, char *argv[]){
    srand(time(NULL));
    cout << "Hello world.\n"
            "TASK 1):" << endl;
    task_1();
    cout << "\n"
            "TASK 2):" << endl;
    task_2();
    cout << "Bye world." << endl << endl;
    return 0;
}