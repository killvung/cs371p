// -----------
// SharedPtr.h
// -----------

#ifndef SharedPtr_h
#define SharedPtr_h

#include <cassert>   // assert
#include <algorithm> // swap
#include <utility>   // move

template <typename T>
class my_shared_ptr {
    public:
        using value_type = T;
        using pointer    = value_type*;

    private:
        struct count {
            int     _c;
            pointer _q;

            count (pointer q) :
                    _c (1),
                    _q (q) {
                assert(_q != nullptr);}

            ~count () {
                assert(_c == 1);
                delete _q;}};

        count* _p;

    public:
        explicit my_shared_ptr (pointer q) :
                _p ((q == nullptr) ? nullptr : new count(q))
            {}

        my_shared_ptr (const my_shared_ptr& rhs) :
                _p (rhs._p) {
            if (_p != nullptr)
                ++_p->_c;}

        my_shared_ptr& operator = (my_shared_ptr rhs) {
            swap(rhs);
            return *this;}

        ~my_shared_ptr () {
            if (unique())
                delete _p;
            else
                --_p->_c;}

        pointer get () const {
            if (_p != nullptr)
                return _p->_q;
            return nullptr;}

        void swap (my_shared_ptr& that) {
            std::swap(_p, that._p);}

        bool unique () const {
            return use_count() <= 1;}

        int use_count () const {
            if (_p != nullptr)
                return _p->_c;
            return 0;}};

#endif // SharedPtr_h
