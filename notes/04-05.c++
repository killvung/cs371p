// -----------
// Wed,  5 Apr
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

        vector& operator = (vector rhs) {
            swap(_b, rhs._b);
            swap(_e, rhs._e);
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
