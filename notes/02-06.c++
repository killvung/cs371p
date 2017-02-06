// -----------
// Mon,  6 Feb
// -----------

/*
one goal of OOP languages is to
convert runtime errors into
compile-time errors
*/

void f (int v) {
    ++v;}

void g (int* p) {
    ++*p;}

void h (int& r) {
    ++r;}

int main () {
    int i = 2;
    f(i);
    cout << i; // 2

//  g(i);      // not ok
    g(&i);
//  g(185);    // not ok
//  g(0);      // runtime error
    cout << i; // 3

//  h(&i);     // not ok
    h(i);
//  h(185);    // not ok
//  h(0);      // not ok
    cout << i; // 4
