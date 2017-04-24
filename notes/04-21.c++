// -----------
// Fri, 21 Apr
// -----------

struct A {
    A () {
        f();}          // statically bound
    virtual ~A () {
        f();}          // statically bound
    virtual void f ()
        {}};

struct B : A {
    void f ()
        {}};

int main () {
    A* p = new B;
    ...
    p->f();
    p->A::f();    // statically bound
    delete p;

    A x;
    x.f(); // statically bound

// static binding in 4 case:
// 1. an object
// 2. scope operator
// 3. constructor
// 4. destructor
// 5. final method
// 6. final class

struct Triangle : Shape {
    Triangle (...) : Shape(...) {...}};

// Java
abstract struct A {
    abstract void f (int);
    ...}

// C++
struct A {
    virtual void f (int) = 0; // pure virtual
    ...};

struct B {
    void f (int)
        {}};

int main () {
    A* p = new B;
    p->f();

    Triangle x;
    cout << x.area(); // 0

// Consequences of an abstract method.
// 1. the class becomes abstract
// 2. children must implement OR become abstract
// 3. can't be implemented in Java
//    MAY be implemented in C++
