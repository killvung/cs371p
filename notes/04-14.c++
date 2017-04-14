// -----------
// Fri, 14 Apr
// -----------

vector<int> x(10, 2);

B (const& B rhs) :
    A (rhs)
    {}

Shape* p = new Circle(...);
*p.move(...);   // not ok
(*p).move(...);
p->move(...);
