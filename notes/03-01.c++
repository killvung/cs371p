// -----------
// Wed,  1 Mar
// -----------

# Java

class A {
    public int i;

    public class B {
        public int j;

        public void g () {
            S.O.P(this.j);
            S.O.P(A.this.i);}}

    public static class C {}}

class T {
    public static void main (...) {
        A x = new A();
        S.O.P(x.i);

        A.B y = x.new B();
        y.g();
        A.B t = x.new B();
        t.g();

        A.C z = new A.C();

class LinkedList {
    private static class Node {...}
    private        class Iter implements Iterator {...}

    public Iterator iterator () {
        return new Iter();}}

class T {
    public static void main (...) {
        LL x = new LL(...)
        Iterator p = x.iterator();
        while (p.hasNext()) {
            ...p.next()...}}}

Range r(2, 5);
Range::iterator p = begin(r); // r.begin()

template <typename T>
class Range {
    public:
        class iterator {...}

    private:
        T _b;
        T _e;

    public:
        Range (const T& b, const T& e) :
            _b (b),
            _e (e)
            {}

        iterator begin () const {
            return iterator(_b);}

        iterator end () const {
            return iterator(_e);}};

class A {
    void f ()       {}
    void f () const {}
    void g () const {}};

int main () {
    A x;
    x.f();     // non-const

    const A y;
    y.f();     // const

    return 0;}
