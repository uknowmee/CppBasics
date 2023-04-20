#include <vector>
#include <iostream>
using namespace std;


struct B {
    int m = 0;

    virtual void hello() const {
        cout << "Hello world, this is B!\n";
    }
};

struct D : B {
    void hello() const override {
        cout << "Hello world, this is D!\n";
    }
};

enum class E { ONE = 1, TWO, THREE };

struct Base {
    virtual ~Base() = default;
};

struct Derived: Base {
    virtual void name() {}
};


class type{
private:
    int att;
public:
    explicit type(int t):att(t) {}

    // A const function that changes atribute with the help of const_cast
    void fun() {
        att = 5;
    }

    int getAtt() const{ return att; }
};

int fun(int* ptr){
    *ptr = *ptr + 10;
    return (*ptr);
}

int main(){
    // 1.1: initializing conversion - convert float 3.14 to int n and print n
    int n = static_cast<int >(3.14);

    cout << "n = " << n << '\n';

    // 1.2 initializing conversion - init 10 element vector using implicit conversion sequence and pring vector v size
    vector<int> smallBby(10,1);
//    vector<int> v = smallBby;
    vector<int> v = smallBby;
    cout << "v.size() = " << v.size() << '\n';

    // 2.1: static downcast - upcast via implicit conversion and call hello()
    D d;
    B& br = d;
    // 2.2 downcast br to D and call hello()
    D& another_d = static_cast<D&>(br);
    another_d.hello();

    // 3: lvalue to xvalue - convert vector v from 1 to rvalue reference and print vector v size
    vector<int> v2 = static_cast<vector<int>&&>(v);
    vector<int> mama(2,1);
    static_cast<vector<int>&&>(v) = mama;
    cout << "after move, v2.size() = " << v2.size() << '\n';
    cout << "after move, v.size() = " << v.size() << '\n';

    // 4: discarded-value expression - use static_cast in this context
    // e.g. 2 * 2;
    static_cast<void>(v2.size());


    // 5. inverse of implicit conversion - perform inverse conversion of nv using static_cast
    void* nv = &n; // implicit inversion
    int* ni = static_cast<int*>(nv);
    cout << "*ni = " << *ni << '\n';

    // 6. array-to-pointer followed by upcast
    D a[10];
    B* dp = static_cast<B*>(a);

    // 7. scoped enum to int or float
    E e = E::ONE;
    int one = static_cast<int>(e);
    cout << one << '\n';

    // 8. void* to any type - voidp to p
    void* voidp = &e;
    vector<int>* p = static_cast<vector<int>*>(voidp);

    Base* b1 = new Base;
    // 9. Perform safe call of d->name() - convert b1 to d
    Derived* d_new = dynamic_cast<Derived*>(b1);
    // check pointer
    if (d_new){
        d_new->name(); // safe to call
    }

    // 10. Perform safe call of d->name() - convert b2 to d
    Base* b2 = new Derived;
    Derived* d_new_1 = dynamic_cast<Derived*>(b2);
    // check pointer
    d_new_1->name(); // safe to call

    delete b1;
    delete b2;

    // 11. Modify att in t
    type t(3);
    cout << endl << "Old att: " << t.getAtt() << endl;
    t.fun();
    cout << "New att: " << t.getAtt() << endl;

    // 12. Fix an error, uncomment fun(ptr)
    int val = 10;
    const int *ptr = &val;
    fun(const_cast<int*>(ptr));
    cout << "val" << val << endl;
    cout << "fun" << fun(const_cast<int*>(ptr));

}