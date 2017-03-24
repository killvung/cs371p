// -----------
// Fri, 24 Mar
// -----------

template <typename T>
class vector {
    private:
        T* _b;
        T* _e;

    public:
        vector () :
            _b (nullptr),
            _e (nullptr)
            {}

        vector (int s) :
            _b (new T[s]),
            _e (_b + s)
            {}
