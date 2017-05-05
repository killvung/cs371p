// ---------
// Vector2.h
// ---------

#ifndef Vector_h
#define Vector_h

#include <algorithm>        // copy, equal, fill, swap
#include <cstddef>          // ptrdiff_t, size_t
#include <initializer_list> // initializer_list
#include <stdexcept>        // out_of_range
#include <utility>          // !=

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

} // rel_ops
} // std;
*/

using std::rel_ops::operator!=;

template <typename T>
class my_vector {
    friend bool operator == (const my_vector& lhs, const my_vector& rhs) {
        return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());}

    public:
        using value_type      = T;

        using size_type       = std::size_t;
        using difference_type = std::ptrdiff_t;

        using       pointer   =       value_type*;
        using const_pointer   = const value_type*;

        using       reference =       value_type&;
        using const_reference = const value_type&;

        using       iterator  =       pointer;
        using const_iterator  = const_pointer;

    private:
        pointer _b = nullptr;
        pointer _e = nullptr;

    public:
        explicit my_vector (size_type s = 0, const_reference v = T()) :
                _b ((s == 0) ? nullptr : new T[s]),
                _e ((s == 0) ? nullptr : _b + s) {
            std::fill(_b, _e, v);}

        my_vector (std::initializer_list<T> rhs) :
                _b ((rhs.size() == 0) ? nullptr : new T[rhs.size()]),
                _e ((rhs.size() == 0) ? nullptr : _b + rhs.size()) {
            std::copy(rhs.begin(), rhs.end(), _b);}

        my_vector (const my_vector& rhs) :
                _b ((rhs.size() == 0) ? nullptr : new T[rhs.size()]),
                _e ((rhs.size() == 0) ? nullptr : _b + rhs.size()) {
            std::copy(rhs._b, rhs._e, _b);}

        my_vector& operator = (const my_vector& rhs) {
            my_vector that(rhs);
            swap(that);
            return *this;}

        ~my_vector () {
            delete [] _b;}

        reference operator [] (size_type i) {
            return _b[i];}

        const_reference operator [] (size_type i) const {
            return (*const_cast<my_vector*>(this))[i];}

        reference at (size_type i) {
            if (i >= size())
                throw std::out_of_range("my_vector::at index out of range");
            return (*this)[i];}

        const_reference at (size_type i) const {
            return const_cast<my_vector*>(this)->at(i);}

        iterator begin () {
            return _b;}

        const_iterator begin () const {
            return const_cast<my_vector*>(this)->begin();}

        iterator end () {
            return _e;}

        const_iterator end () const {
            return const_cast<my_vector*>(this)->end();}

        size_type size () const {
            return _e - _b;}

        void swap (my_vector& rhs) {
            std::swap(_b, rhs._b);
            std::swap(_e, rhs._e);}};

#endif // Vector_h
