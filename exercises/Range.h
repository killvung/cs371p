// -------
// Range.h
// -------

#ifndef Range_h
#define Range_h

#include <iterator> // input_iterator_tag, iterator

template <typename T>
class Range {
    private:
        T _b;
        T _e;

    public:
        class iterator : public std::iterator<std::input_iterator_tag, T> {
            friend bool operator == (const iterator& lhs, const iterator& rhs) {
                return (lhs._v == rhs._v);}

            friend bool operator != (const iterator& lhs, const iterator& rhs) {
                return !(lhs == rhs);}

            private:
                T _v;

            public:
                iterator (const T& v) :
                        _v (v)
                    {}

                T operator * () const {
                    return _v;}

                iterator& operator ++ () {
                    ++_v;
                    return *this;}

                iterator operator ++ (int) {
                    iterator x = *this;
                    ++*this;
                    return x;}};

        Range (const T& b, const T& e) :
                _b (b),
                _e (e)
            {}

        iterator begin () const {
            return _b;}

        iterator end () const {
            return _e;}};

#endif // Range_h
