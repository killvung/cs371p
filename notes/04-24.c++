// -----------
// Mon, 24 Apr
// -----------

// static binding in 4 case:
// 1. an object
// 2. scope operator
// 3. constructor
// 4. destructor
// 5. final method
// 6. final class

// Java

class A {
    void f ()
        {}}

class B extends A {
    void f ()
        {}}

class T {
    public static void main (...) {
        A x;
        if (...)
            x = new A();
        else
            x = new B();
        x.f();

// static binding in Java
// 1. static method
// 2. final method
// 3. final class
// 4. private method

class A {
    void f1 () {
        f2();}

    private void f2 () {
        s.o.p("A.f2");}}

class B extends A {
    void f2 () {
        s.o.p("B.f2");}}

class T {
    public static void main (...) {
        A x;
        if (...)
            x = new A();
        else
            x = new B();
        x.f1(); // always A.f2
        x.f2(); // not ok

// C++

class A {
    virtual void f ();

    virtual ~A () = 0;

    ...};

A::~A() {}
void A::f () {}

class B
    {}

// consequences of a pure virtual method
// 1. children must implement or become abstract
// 2. definition is optional
// 3. class becomes abstract

int main () {
    A* p = new A;
    delete p;     // ~A()

    A *q = new B; // A() B()
    delete q;     // ~B() ~A()

// consequences of a pure virtual destructor
// 3. class becomes abstract

// Java

abstract class A {
             void f (int) {} // changing signature leads to a runtime logic error
    final    void g (int) {} // changing signature doesn't matter
    abstract void h (int) {} // changing signature leads to a compiler time error

class B extends A {
    void f (int) {}
    void h (int) {}}

// C++

struct A {
    virtual void f (int)       {} // changing signature leads to a runtime logic error
    virtual void g (int) final {} // changing signature doesn't matter
    virtual void h (int) = 0;     // changing signature leads to a compiler time error

struct B : A {
    void f (int) {}
    void h (int) {}}

// 1. consequence to the child about f(int)
// definition is optional

// 2. consequence to the child about g(int)
// definition is prohibited

// 3. consequence to the child about h(int)
// definition is required or child becomes abstract
