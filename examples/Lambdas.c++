// -----------
// Lambdas.c++
// -----------

#include <cassert>    // assert
#include <functional> // function, plus
#include <iostream>   // cout, endl

using namespace std;

int f (function<int (int, int)> bf, int x, int y, int z) {
    return bf(x, y) * bf(y, z);}

int g (function<int (int)> uf, int x, int y, int z) {
    return uf(x) * uf(y) * uf(z);}

function<int (int)> h (int x) {
    return [x] (int y) -> int {return x + y;};}

function<int (int)> h2 (int& x) {
    return [&x] (int y) -> int {++x; return x + y;};}

int my_plus (int x, int y) {
    return x + y;}

int main () {
    cout << "Arguments.c++" << endl;

    assert(f(&my_plus,                                 2, 3, 4) == 35); // (2+3) * (3+4)
    assert(f(plus<int>(),                              2, 3, 4) == 35); // (2+3) * (3+4)
    assert(f([] (int x, int y) -> int {return x + y;}, 2, 3, 4) == 35); // (2+3) * (3+4)

    {
    assert(g(h(2), 3, 4, 5) == 210); // (2+3) * (2+4) * (2+5)
    }

    {
    int x = 2;
    assert(g(h2(x), 3, 4, 5) == 480); // (3+3) * (4+4) * (5+5)
    assert(x == 5);
    }

    cout << "Done." << endl;
    return 0;}
