// -----------
// Wed, 26 Apr
// -----------

// return type of a virtual method is covariant

class AS {
    ...
    public:
        virtual AS* clone () const = 0;
    ...};

class CI : public AS {
    ...
    public:
        CI* clone () const {
            return new CI(*this);}};

Shape x = new Circle(...);
Shape y = new Triangle(...);
Shape z = x;
z = y;

class Shape {
    private:
        AS* _p
    public:
        Shape (AS* p) {
            _p = p;}
        Shape (const Shape& rhs) {
            _p = rhs._p->clone();}
        Shape& operator = (Shape rhs) {
            swap(_p, rhs._p);
            return *this;}
        ~Shape () {
            delete _p;}
