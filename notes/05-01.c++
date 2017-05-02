// -----------
// Mon,  1 May
// -----------

/*
local: non-static, static
global: non-static, static
class: non-static, static
*/

// foo.c++
int g = h();

// bar.c++
extern int g;

void f () {
    ...
    cout << g << endl;}

/*
1. How many are there?        (one)
2. When are they allocated?   (on program entry)
3. When are they initialized? (before main())
4. What is their lifetime?    (lifetime of program)
5. What is their scope?       (anywhere)
*/

// foo.c++
static int g = h();

// bar.c++
static int g;

void f () {
    ...
    cout << g << endl;}

/*
1. How many are there?        (one)
2. When are they allocated?   (on program entry)
3. When are they initialized? (before main())
4. What is their lifetime?    (lifetime of program)
5. What is their scope?       (the file)
*/

class A {
    int i;};

/*
1. How many are there?        (one per instance)
2. When are they allocated?   (on instance creation)
3. When are they initialized? (on execution of the constructor)
4. What is their lifetime?    (lifetime of the instance)
5. What is their scope?       (in A and whatever access A declares)
*/

// A.h
template <typename T>
struct A {
    static T   sx; // not in Java, can't use T
    static int si;};

template <typename T>
T A<T>::sx = h(...); // this NOT a reference to sx, this is a DEFINITION of sx

template <typename T>
int A<T>::si = h(...); // this NOT a reference to si, this is a DEFINITION of si

// foo.c++
#include "A.h"
int f () {
    cout << A<int>::si;} // this is a reference to si

// bar.c++
#include "A.h"
int g () {
    cout << A<int>::si;} // this is a reference to si

/*
1. How many are there?        (one per T for C++, one for Java)
2. When are they allocated?   (on program entry)
3. When are they initialized? (before main())
4. What is their lifetime?    (lifetime of the program)
5. What is their scope?       (in A and whatever access A declares)
*/

// A.h
class A {
    private:
        int f ();
        int h () {...}};

// A.c++
int A::f () { // this is NOT a reference to f(), this is a DEFINITION of f()
    ...}

// foo.c++
#include "A.h"
int g () {
    A x;
    x.f(); // this is a reference to f()
