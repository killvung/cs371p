// -----------
// Fri, 31 Mar
// -----------

template <typename T>
class vector {
    private:
        T* _b;
        T* _e;

    public:
       vector (size_t s = 0, const T& v = T()) :
                _b ((s == 0) ? nullptr : new T[s]),
                _e (_b + s) {
            fill(_b, _e, v);}

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
            _b = new T[rhs.size()];
            _e = _b + rhs.size();
            copy(rhs._b, rhs._e, _b);}

        vector& operator = (const vector& rhs) {
            delete [] _b;
            _b = new T[rhs.size()];
            _e = _b + rhs.size();
            copy(rhs._b, rhs._e, _b);
            return *this;}

        ...}

int main () {
    vector<int> x(10, 2);
    cout << x[3];         // 2
    x[3] = 4;

    const vector<int> y(10, 2);
    cout << y[3];               // 2
//  y[3] = 4;                   // doesn't compile

    const vector<int> z(20, 3);
    const vector<int> t = z;    // copy consttructor

    x = z; // copy assignment operator
