// -----------
// Wed, 15 Feb
// -----------

template <typename II, typename UP>
bool all_of (II b, II e, UP f) {
    while (b != e) {
        if !(f(*b))
            return false
        ++b;}
    return true;}

int plus_function (int x, int y) {
    return x + y;}

struct plus_type {
    int operator () (int x, int y) {
        return x + y;}};

int main () {
    assert(plus_function(2, 3) == 5);
    plus_type p;
    assert(p(2, 3) == 5);

    function<int (int, int)> f = &plus_function;
    assert(f(2, 3) == 5);

    function<int (int, int)> g = [] (int x, int y) -> int {return x + y;};
    assert(g(2, 3) == 5);

    function<int (int, int)> h = plus_type();
    assert(h(2, 3) == 5);

    return 0;}
