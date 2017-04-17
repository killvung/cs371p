// -----------
// Mon, 17 Apr
// -----------

B (const B& x) :
    A (x)
    {}

B& operator = (const B& x) {
    A::operator=(x);
    return *this;}

int i;
i = 2; // assignment

vs.

int i = 2; // initialization

struct A {
    void f (int) {}
    void g (int) {}
    void h (int) {}
    void m (int) {}

struct B : A {
    using A::m;
    void f (int)    {}
    void g (string) {}
    void h (string) {}
    void h (int i)  {
        A::h(i);}
    void m (string) {}};

int main () {
    B x;
    x.f(2);    // B::f()
    x.g(2);    // Java: A::g(); C++: doesn't compile
    x.A::g(2); // A::g()
    x.h(2);    // B::h() -> A::h()
    x.m(2);    // A::m()
