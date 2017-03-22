// -----------
// Wed, 20 Mar
// -----------

B<int> x = 2; // not ok, with explicit

T i = 2;
T j = i; // ok with most types, but not arrays on the stack

int* p;

if (...)
    p = new int;
else
    p = new int[10];

delete ? p;

/*
possible errors related to delete

1. not delete
2. getting the [] wrong
3. deleting too early
4. deleting the wrong address
5. deleting more than once
*/

int* f () {
    int a[] = {...};
    ...
    return a; // not ok

int* g () {
    int* a = new int[...];
    ...
    return a;}

int s;
cin >> s;
int a[s]; // not ok

int s;
cin >> s;
int* a = new int[s];

int s;
cin >> s;
vector<int> x(s, v);
