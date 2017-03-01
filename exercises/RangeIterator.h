// ---------------
// RangeIterator.h
// ---------------

#ifndef RangeIterator_h
#define RangeIterator_h

#include <iterator> // input_iterator_tag, iterator

template <typename T>
class Range_Iterator : public std::iterator<std::input_iterator_tag, T> {
    friend bool operator == (const Range_Iterator& lhs, const Range_Iterator& rhs) {
            return (lhs._v == rhs._v);}

    friend bool operator != (const Range_Iterator& lhs, const Range_Iterator& rhs) {
            return !(lhs == rhs);}

    private:
        T _v;

    public:
        Range_Iterator (const T& v) :
                _v (v)
            {}

        T operator * () const {
            return _v;}

        Range_Iterator& operator ++ () {
            ++_v;
            return *this;}

        Range_Iterator operator ++ (int) {
            Range_Iterator x = *this;
            ++*this;
            return x;}};

#endif // RangeIterator_h
