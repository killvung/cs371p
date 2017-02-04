// -----------
// Fri,  3 Feb
// -----------

/*
two tokens: * and &
two contexts: modifying a type and modifying an l-value
*/

int i = 2;
int v = i; // copy
++v;
cout << i; // 2

int  i = 2;
int* p = &i; // pointer, & needs an l-value
++*p;        // * needs an address
cout << i;   // 3

int j = 5;
p = &j;      // pointer is moveable

int  i = 2;
int& r = i;  // reference, r and i become indistinguishable
r = 3;
cout << i;   // 3

int    i = 2;
int*   p = &i;
int**  q = &p;
int*** r = &q;
