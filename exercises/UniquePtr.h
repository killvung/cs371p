// -----------
// UniquePtr.h
// -----------

#ifndef UniquePtr_h
#define UniquePtr_h

#include <algorithm> // swap
#include <utility>   // move

template <typename T>
class my_unique_ptr {
    public:
        using value_type = T;
        using pointer    = value_type*;

    private:
        pointer _p;

    public:
        explicit my_unique_ptr (pointer p) :
                _p (p)
            {}

        my_unique_ptr (const my_unique_ptr&) = delete;

        my_unique_ptr (my_unique_ptr&& rhs) :
                _p (std::move(rhs._p)) {
            rhs._p = nullptr;}

        my_unique_ptr& operator = (const my_unique_ptr&) = delete;

        my_unique_ptr& operator = (my_unique_ptr&& rhs) {
            my_unique_ptr that(std::move(rhs));
            swap(that);
            return *this;}

        ~my_unique_ptr () {
            delete _p;}

        pointer get () const {
            return _p;}

        void swap (my_unique_ptr& that) {
            std::swap(_p, that._p);}};

#endif // UniquePtr_h
