// -----------
// Classes.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T>
class A {
    friend bool operator == (const A& lhs, const A& rhs) {
        cout << "==(const A&, const A&) ";
        return lhs._v == rhs._v;}

    private:
        T _v;

    public:
        A (const T& v) :
                _v (v) {
            cout << "A(const T&) ";}

        A (const A& rhs) :
                _v (rhs._v) {
            cout << "A(const A&) ";}

        ~A () {
            cout << "~A()" << " ";}

        A& operator = (const A& rhs) {
            _v = rhs._v;
            cout << "=(const A&) ";
            return *this;}};

int main () {
    cout << "Classes.c++" << endl << endl;

    {
    cout << "T constructor" << endl;
    A<int> x = 2;
    assert(x == 2);
    }
    cout << endl << endl;

    {
    cout << "copy constructor" << endl;
    A<int> x = 2;
    A<int> y = x;
    assert(y == 2);
    }
    cout << endl << endl;

    {
    cout << "copy assignment operator" << endl;
    A<int> x = 2;
    A<int> y = 3;
    y = x;
    assert(y == 2);
    }
    cout << endl << endl;

    cout << "Done." << endl;
    return 0;}

/*
Classes.c++

T constructor
A(const T&) A(const T&) ==(const A&, const A&) ~A() ~A()

copy constructor
A(const T&) A(const A&) A(const T&) ==(const A&, const A&) ~A() ~A() ~A()

copy assignment operator
A(const T&) A(const T&) =(const A&) A(const T&) ==(const A&, const A&) ~A() ~A() ~A()

Done.
*/
