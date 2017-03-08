// -----------
// Wed,  8 Mar
// -----------

/*
In the Java library, class Stack EXTENDS class Vector.

That was a mistake, since clients of Stack can invoke any Vector method on a Stack.

The correct design would have been for Stack to CONTAIN Vector.

That design pattern is called the Adapter Pattern.

C++'s class stack CONTAINS a generic backing container.

That backing container can be C++'s vector, deque, or list.

But, it can also be a user-defined backing container, if the correct API is provided.
*/

struct A {
    A (int) {}};

void f (A y) {}

int main () {
    A x(2);  // always ok
    A x = 2; // only ok without explicit
    f(x);    // A's copy constructor
    f(A(2)); // A's copy constructor
    f(2);    // A's copy constructor
    return 0;}



struct string {
    string (const char*) {...}
    ...};

void g (string t) {}

int main () {
    string s("abc")
    string s = "abc";
    g(s);             // string's copy constructor
    g(string("abc")); // string's copy constructor
    g("abc");         // string's copy constructor
    return 0;}



template <typename T>
struct vector {
    explicit vector (int) {...}
    ...};

void h (vector<int> y) {}

int main () {
    vector<int> x(10000);
    vector<int> x = 10000; // not ok
    h(x);                  // vector's copy constructor
    h(vector<int>(10000)); // vector's copy constructor
    h(10000);              // not ok
    return 0;}
