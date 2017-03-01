// -----------
// Mon, 27 Feb
// -----------

template <typename T>
struct A {
    private:
        T _v;

    public:
        A () :
            _v () // T's default constructor
            {}

        A (const T& v) :
            _v (v)       // T's copy constructor
            {}

        A (const A& rhs) :
            _v (rhs._v)    // T's copy constructor
            {}

        A& operator = (const A& rhs) {
            _v = rhs._v;               // T's copy assignment operator
            return *this;}

        ~A ()
            {} // T's destructor

        bool operator == (const A& rhs) const {
            return (_v == rhs._v);}             // T's equality operator

void f (A y) {
    ...}

A x;  // default constructor
f(x); // copy    constructor

A y(); // function declaration

A z = x; // copy constructor
A z(x);  // copy constructor

z = x;          // copy assign operator
z.operator=(x);
++(z = x);

cout << (x == y);        // equality operator
cout << x.operator==(y);

*b            // dereference operator
b.operator*()

++b            // pre-increment operator
b.operator++()

b++             // post-increment operator
b.operator++(0)

template <typename T>
class Range_Iterator {
    private:
        T _v;

    public:
        Range_Iterator (const T& v) :
            _v (v)
            {}

        T operator * () {
            return _v;}

        Range_Iterator& operator ++ () {
            ++_v;
            return *this;}

        Range_Iterator operator ++ (int) {
            Range_Iterator x(*this);
            ++_v;
            return x;}
