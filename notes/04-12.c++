// -----------
// Wed, 12 Apr
// -----------

vector<ConwayCell> x(s, ConwayCell());
// ConwayCell(),           once
// ConwayCell(ConwayCell), s times

vector<FredkinCell> x(s, FredkinCell());
// FredkinCell(),            once
// FredkinCell(FredkinCell), s times

vector<AbstractCell> x(s, FredkinCell()); // doesn't compile or slice

vector<AbstractCell*> x(s, FredkinCell()); // doesn't compile
// FredkinCell(), once

{
vector<AbstractCell*> x(s, new FredkinCell()); // not useful
// FredkinCell(), once

vector<AbstractCell*> y(x); // not useful
}

{
vector<AbstractCell*> x(s);
fill(begin(x), end(x), new FredkinCell()); // not useful
// FredkinCell(), one

vector<AbstractCell*> y(x); // not useful
}

{
vector<AbstractCell*> x(s);
for (int i = 0; i != s; ++i)
    x[i] = new FredkinCell();
// FredkinCell(), s times

// vector<AbstractCell*> y(x); // not useful

for (int i = 0; i != s; ++i)
    delete x[i];
}

{
Cell x = new FredkinCell();
Cell y = new ConwayCell();

Cell z(x); // FredkinCell's copy constructor
Cell t(y); // ConwayCell's  copy constructor

y = x; // ConwayCell's destructor, FredkinCell copy constructor
}

vector<AbstractCell*> x(s, new FredkinCell()); // not useful

vector<Cell>          y(s, Cell(new FredkinCell()));
// FredkinCell(), once
// Cell(AbstractCell*), once
// Cell(Cell), s times
// FredkinCell(FredkinCell), s times
// ~Cell(), once
// ~FredkinCell(), once

vector<Cell>          y(s, new FredkinCell()); // same
