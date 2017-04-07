// -----------
// Fri,  7 Apr
// -----------

template <typename T, typename A = allocator<T>>
class vector {
    private:
        A  _a;
        T* _b;
        T* _e;

    public:
       vector (size_t s = 0, const T& v = T(), const A& a = A()) :
                _a (a),
                _b ((s == 0) ? nullptr : _a.allocate(s))
                _e (_b + s) {
            for (T* b = _b; b != _e; ++b)
                _a.construct(b, v);}

        size_t size () const {
            return _e - _b;}

        T* begin () {
            return _b;}

        const T* begin () const {
            return _b;}

        T* end () {
            return _e;}

        const T* end () const {
            return _e;}

        T& operator [] (size_t i) {
            return *(_b + i);}

        const T& operator [] (size_t i) const {
            return *(_b + i);}

        vector (const vector& rhs) {
            _b = (rhs.size() == 0) ? nullptr : _a.allocate(rhs.size());
            _e = _b + rhs.size();
            rb = rhs._b;
            for (T* b = _b; b != _e; ++b)
                _a.construct(*b, *rb);
                ++rb;}}

        vector (vector&& rhs) {
            _a = move(rhs._a);
            _b = rhs._b;
            _e = rhs._e;
            rhs._b = nullptr;
            rhs._e = nullptr;}

        vector& operator = (const vector& rhs) {
            vector tmp(rhs);
            swap(_a, tmp._a);
            swap(_b, tmp._b);
            swap(_e, tmp._e);
            return *this;

        vector& operator = (vector&& rhs) {
            vector tmp(move(rhs));
            swap(tmp._a, _a);
            swap(tmp._b, _b);
            swap(tmp._e, _e);
            return *this;

        ~vector () {
            for (T* b = _b; b != _e; ++b) // O(n)
                _a.destroy(b);
            _a.deallocate(_b, size());}   // O(1)
        ...}

struct A {};

int main () {
    vector<int>                    x; // std::allocator
    vector<int, my_allocator<int>> y; // my_allocator
    allocator<int> a(...);
    vector<int>                    z(10, 2, a);

    x = f(...); // move assignment

/*
local: non-static, static
global: non-static, static
class: non-static, static
*/

void f () {
    ...
    int i = g(...);}

/*
1. How many are there?        (one per function call)
2. When are they allocated?   (on function entry)
3. When are they initialized? (at the declaration)
4. What is their lifetime?    (lifetime of function)
5. What is their scope?       (in the function, after the declaration)
*/

void f () {
    ...
    static int i = g(...);}

/*
1. How many are there?        (one)
2. When are they allocated?   (on program entry)
3. When are they initialized? (at the declaration, only the first time)
4. What is their lifetime?    (lifetime of program)
5. What is their scope?       (in the function, after the declaration)
*/
