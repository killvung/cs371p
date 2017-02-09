// -----------
// Wed,  8 Feb
// -----------

bool equal (int* b, int* e, int* c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

int a[] = {2, 3, 4};
int b[] = {2, 3, 4};
equal(a, a + 3, b);                   // ok

vector<int> x(...);
vector<int> y(...);
equal(x.begin(), x.end(), y.begin()); // ok

long a[] = {2, 3, 4};
long b[] = {2, 3, 4};
equal(a, a + 3, b);                   // not ok



template <typename T>
bool equal (T* b, T* e, T* c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

long a[] = {2, 3, 4};
long b[] = {2, 3, 4};
equal(a, a + 3, b);   // ok, T -> long

int  a[] = {2, 3, 4};
long b[] = {2, 3, 4};
equal(a, a + 3, b);   // not ok



template <typename T, typename U>
bool equal (T* b, T* e, U* c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

int  a[] = {2, 3, 4};
long b[] = {2, 3, 4};
equal(a, a + 3, b);                   // ok, T -> int, U -> long

list<int> x(...);
list<int> y(...);
equal(x.begin(), x.end(), y.begin()); // not ok
