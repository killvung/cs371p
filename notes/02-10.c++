// -----------
// Fri, 10 Feb
// -----------

template <typename II1, typename II2>
bool equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

int  a[] = {2, 3, 4};
long b[] = {2, 3, 4};
equal(a, a + 3, b);   // ok, T -> int*, U -> long*

list<int> x(...);
set<int> y(...);
equal(x.begin(), x.end(), y.begin()); // ok, T -> list::iterator, U -> set::iterator

/*
STL has many algorithms
has many containers
iterators are the glue between them
*/

/*
input iteraor
    ==, !=, ++, * (read only)

output iterator
    ++, * (write only)

forward iterator
    ==, !=, ++, * (read write)

bidirectional iterator
    <forward iterator>, --

random access iterator
    <bidirectional iterator>, [], + (int), - (int), -, <, >, >=, <=
*/

int a = [2, 3, 4]
int b[10];
copy(a, a + 3, b);

template <typename II, typename OI>
OI copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++x;
        ++b;}
    return x;}

int a[10];
fill(a, a + 3, 2);

template <typename FI, typename T>
void fill (FI b, FI e, T v) {
    while (b != e) {
        *b = v;
        ++b;}}
