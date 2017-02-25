// -----------
// Fri, 24 Feb
// -----------

A<int> x;   // default constructor
A<int> x(); // function declaration

A<int> x = 2; // T constructor
A<int> x(2);  // T constructor

A<int> y = x; // copy constructor
A<int> y(x);  // copy constructor

y = x;          // copy assignment operator
y.operator=(x); // copy assignment operator

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

        ~A () {}}; // T's destructor
