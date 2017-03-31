// -----------
// Fri, 31 Mar
// -----------

template <typename T>
class vector {
    private:
        allocator<T> _a;
        T* _b;
        T* _e;

    public:
       vector (size_t s = 0, const T& v = T()) :
                _a (),
                _b ((s == 0) ? nullptr : _a.allocate(s))
                _e (_b + s) {
            for (T* i = _b; i != _e; ++i)
                _a.construct(i, v);}

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
/*
            _b = nullptr;
            *this = rhs;
*/
            _b = new T[rhs.size()];
            _e = _b + rhs.size();
            copy(rhs._b, rhs._e, _b);}

        vector& operator = (vector rhs) {
            swap(_b, rhs._b);
            swap(_e, rhs._e);
            return *this;
/*
            if (*this == rhs)           if (this != &rhs)
                return *this;
            delete [] _b;
            _b = new T[rhs.size()];
            _e = _b + rhs.size();
            copy(rhs._b, rhs._e, _b);
            return *this;}
*/
        ~vector () {
            for (T* i = _b; i != _e; ++i) O(n)
                _a.destroy(i);
            _a.deallocate(_b, size());} O(1)
        ...}

int main () {
    const vector<int> x(20, 3);
    const vector<int> y(10, 4);

    y = y; // copy assignment operator
