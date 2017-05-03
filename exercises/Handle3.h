// ---------
// Handle3.h
// ---------

#ifndef Handle3_h
#define Handle3_h

#include <algorithm> // swap
#include <cassert>   // assert

template <typename T>
class Handle {
    friend bool operator == (const Handle& lhs, const Handle& rhs) {
        if ((lhs.get() == nullptr) && (rhs.get() == nullptr))
            return true;
        if ((lhs.get() == nullptr) || (rhs.get() == nullptr))
            return false;
        return (*lhs.get() == *rhs.get());}

    public:
        typedef T                 value_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

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

    protected:
        pointer get () {
            assert(_p != nullptr);
            if (!unique()) {
                --_p->_c;
                _p = new count(_p->_q->clone());}
            return _p->_q;}

        const_pointer get () const {
            assert(_p != nullptr);
            return _p->_q;}

    public:
        Handle (pointer q) :
                _p ((q == nullptr) ? nullptr : new count(q))
            {}

        Handle (const Handle& rhs) :
                _p (rhs._p) {
            if (_p != nullptr)
                ++_p->_c;}

        Handle& operator = (Handle that) {
            swap(that);
            return *this;}

        ~Handle () {
            if (unique())
                delete _p;
            else
                --_p->_c;}

        void swap (Handle& that) {
            std::swap(_p, that._p);}

        bool unique () const {
            return use_count() <= 1;}

        int use_count () const {
            if (_p != nullptr)
                return _p->_c;
            return 0;}};

#endif // Handle3_h
