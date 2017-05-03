// -----------
// Wed,  3 May
// -----------

template <typename T>
class shared_ptr {
    private:
        struct rc {
            int _c;
            T*  _p;
            rc (T* p) {
                _c = 1;
                _p = p;}

            ~rc () {
                delete _p;}};
        rc* _q;

    public:
        shared_ptr (T* p) {
            _q = new rc(p);}

        shared_ptr (const shared_ptr& rhs) {
            _q = rhs._q;
            ++_q->_c;}

        shared_ptr& operator = (shared_ptr rhs) {
            swap(...);

        ~shared_ptr () {
            if (_q->_c == 1)
                delete _q;
            else
                --_q->c;}
