// -----------
// Mon, 20 Mar
// -----------

class string {
    friend bool operator == (const string& lhs, const string& rhs) {
        ...}

    friend ostream& operator << (ostream& lhs, const string& rhs) {
        ...}

    private:
        ...
    public:
        string (const char*) {
            ...}};

int main () {
    string s("abc");                 // always works
    string t = "def";                // only works if NOT explicit

    cout << (s == t)        << endl; // false
    cout << s.operator==(t) << endl;

    cout << (s == "abc")         << endl; // true
    cout << s.operator==("abc")  << endl;

    cout << ("abc" == s)         << endl; // not ok
    cout << "abc".operator==(s); << endl; // not ok, can NOT be a method

    cout << operator==(s, t)     << endl; // make == a friend function
    cout << operator==(s, "abc") << endl;
    cout << operator==("abc", s) << endl;

    cout << s           << endl;
    cout.operator<<(s)  << endl; // not ok, can NOT be a method
    operator<<(cout, x) << endl; // make << a friend function, too

/*
rules of C++ friend
    If I declare YOU to be friend,
    I have to be a class
    YOU can be a class, a method, or a function
    friendship is not symmetric
    friendship is not transitive
*/

struct A {
       A          (const A&) = default;
       ~A         ()         = default;
    A& operator = (const A&) = default;};
