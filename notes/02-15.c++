// -----------
// Wed, 15 Feb
// -----------

plus<int> x;
cout << x(2, 3); // 5

bool foo (int) {
    ...}

template <typename II, typename UP>
bool all_of (II b, II e, UP f) {
    while (b != e) {
        if !(f(*b))
            return false
        ++b;}
    return true;}

int a[] = {2, 3, 4};
cout << all_of(a, a + 3, [] (int) -> bool {....});

list<int> x(...);
cout << all_of(x.begin(), x.end(), &foo);
