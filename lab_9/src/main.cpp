#include <iostream>
#include <bitset>
#include <functional>

struct Base{
    virtual ~Base()= default;
};

struct Derived : Base{
    virtual void name(){
        std::cout << "name()" << std::endl;
    }
};

class MyExeption{
public:
    int line;
    std::string funname;

    MyExeption(int l, std::string fn);
    ~MyExeption() = default;

    void what() const{
        std::cout << "error QQ: " << std::endl;
        std::cout << "at line: " << line << std::endl;
        std::cout << "function name: " << funname << std::endl;
    }
};

MyExeption::MyExeption(int l, std::string fn) {
    line = l;
    funname = fn;
}

float division(const int *num, int den){
    if (den == 0 ){
        throw MyExeption(__LINE__, __FUNCTION__ );
    }
    if (num == nullptr){
        throw MyExeption(__LINE__, __FUNCTION__ );
    }
    auto newden = static_cast<float>(den);
    auto result = *num/newden;
    return result;
}

int main(){
    // 0. Solve the quiz
    // https://www.geeksforgeeks.org/c-plus-plus-gq/exception-handling-gq/

    // 1. Handle standard exceptions
    try {
        int *myarray = new int[10000000000000L];
    }
    catch (const std::bad_alloc& bad_alloc) {
        std::cout << "Error: " << bad_alloc.what() << std::endl;
    }

    // 2. Handle standard exceptions
    Base b;
    try {
        Derived &f = dynamic_cast<Derived &>(b);
    }
    catch (const std::bad_cast& bad_cast) {
        std::cout << "Error: " << bad_cast.what() << std::endl;
    }

    // 3. Handle standard exceptions
    std::function<int(int, int)> add = std::plus<int>();
    std::function<int(int, int)> add2;

    try {
        std::cout << add(10, 20) << '\n';
        std::cout << add2(10, 20) << '\n';
    }
    catch (const std::bad_function_call& bad_function_call) {
        std::cout << "Error: " << bad_function_call.what() << std::endl;
    }

    // 4. Handle standard exceptions
    Base *base = nullptr;
    try {
        typeid(*base);
    }
    catch (const std::bad_typeid& bad_typeid) {
        std::cout << "Error: " << bad_typeid.what() << std::endl;
    }

    // 5. Handle standard exceptions
    std::bitset<128> x(1);
    std::cout << x.to_ulong() << std::endl;
    x.flip();
    try {
        std::cout << x.to_ulong() << std::endl;
    }
    catch (const std::exception& exception) {
        std::cout << "Error: " << exception.what() << std::endl;
    }

    std::cout << "[+]First part is done[+]" << std::endl;
    // 6. Write a function: float division(int *num, int den)
    // write your own expection class(es) to handle two kinds of exceptions
    // throw when num is null or x == 0
    // provide and extra info about the exception (message, line, function name,
    // info) e.g throw myexception("msg", __FILE__, 
    // catch exceptions

    int num1=2;
    int num2=0;
    int* ptr1 = &num1;

    int num3=0;
    int* ptr2 = nullptr;
    try {
        std::cout << division(ptr1, num2) << std::endl;
        std::cout << division(ptr1, num3) << std::endl;
        std::cout << division(ptr2, num2) << std::endl;
        std::cout << division(ptr2, num3) << std::endl;
    }
    catch (const MyExeption& myExeption) {
        myExeption.what();
    }
    return 0;
}