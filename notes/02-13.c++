// -----------
// Mon, 13 Feb
// -----------

vector<int> x(10, 2);
assert(x[0] == 2);

/*
vector overloads the index operator: []
*/

plus<int> p;
assert(p(2, 3) == 5);

/*
plus overloads the function call operator: ()
*/

/*
the STL contains:
    algorithms
    containers
    iterators, the glue between them
*/

/*
copy()    needs an input and an output iterator
fill()    needs a forward              iterator
reverse() needs a bidirectional        iterator
sort()    needs a random access        iterator
*/

/*
vector (ArrayList)
adding   to   the end: amortized O(1)
removing from the end: O(1)
adding/removing to/from the middle: O(n)
adding/removing to/from the front:  O(n)
indexing: O(1)
iterator: random access

list (LinkedList)
doubly-linked list
adding/removing: O(1)
indexing: C++: not okay, Java: O(n)
iterator: bidirectional

forward_list
singly-linked list
iterator: forward
*/
