// -----------
// Wed, 19 Apr
// -----------

struct A {
            void f (int) {}
    virtual void g (int) {}};

struct B : A {
    void f (int) {}
    void g (int) {}};

int main () {
    A* p = new B;
    p->f(2);      // A::f
    p->g(2);      // B::g

// compile time casts
// static_cast
// const_cast
// reinterpret_cast

// runtime cast
// dynamic_cast

// Circle's equals()

bool equals (const Shape& rhs) const {
    if (Circle* p = dynamic_cast<Circle*>(&rhs)) {
        return Shape::equals(rhs) && (radius() == p->radius());
    return false;}

struct A {
    virtual void f (int) const {}};

struct B : A {
    void f (int) {}};

int main () {
    A* p;
    if (...)
        p = new A;
    else
        p = new B;
    p->f(2);       // incorrect f()
