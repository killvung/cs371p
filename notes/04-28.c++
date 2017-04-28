// -----------
// Fri, 28 Apr
// -----------

// Design Patterns
// https://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612/
// https://www.amazon.com/Head-First-Design-Patterns-Brain-Friendly/dp/0596007124/

// Handles are examples of the proxy pattern

// Handle1
// pro: substitute for the classes that it handles
// pro: well encapsulated
// con: replicate the entire interface of the wrapped abstract class

// Handle2
// pro: don't have to replicate the entire interface of the wrapped abstract class
// con: can't substitute for the classes that it handles
// con: not encapsulated

template <typename T>
class Handle {
    private:
        T* _p;

    public:
        T& operator * () {
            return *_p;}

        const T& operator * () const {
            return *_p;}

        T* operator -> () {
            return _p;}

        const T* operator -> () const {
            return _p;}


class unique_ptr {
    ...
    unique_ptr (const unique_ptr&) = delete;


class Shape : public Handle<AbstractShape> {
    ...

Shape x = new Circle(...);
cout << (*x).area();          cout << x.operator*().area();
cout << x->area();            cout << x.operator->()->area();

x == y
x.operator==(y)
operator==(x, y)
