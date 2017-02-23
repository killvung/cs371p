// -----------
// Wed, 22 Feb
// -----------

/*
Java has FOUR access privileges:

public
package (default)
protected
private
*/

/*
C++ has THREE access privileges:

public (default with "struct")
protected
private (default with "class")
*/

/*
this definition of A requires T to have:

default constructor
copy constructor
copy assignment operator
*/

template <typename T>
struct A {
    private:
        T _v;

    public:
        A () {
            _v = T();}

        A (T v) {
            _v = v;}};

/*
this definition of A requires T to have:

default constructor
copy constructor

and uses of a member initialization list
member initialization lists can only be used in constructors

a member initialization list is REQUIRED under FOUR conditions:

a const member
a reference member
a user-defined type member with no default constructor
a parent type with no default constructor
*/

template <typename T>
struct A {
    private:
        T _v;

    public:
        A () :
                _v ()
            {}

        A (const T& v) :
                _v (v)
            {}};

int main () {
//  A<int> x();     // not ok
    A<int> x;
    A<int> y(2);
//  A<int> z(3, 4); // not ok

    A<int>* p = new A<int>;
    A<int>* q = new A<int>();
    A<int>* r = new A<int>(2);
//  A<int>* s = new A<int>(2, 3); // not ok
    return 0;}
