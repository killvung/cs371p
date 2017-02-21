// -----------
// Mon, 20 Feb
// -----------

/*
Java exhibits refinement overriding in constructors
nowhere else

C++ exhibits refinement overriding in constructors and destructors
nowhere else

In C++, given a base class, A, and a derived class, B:
the order of construction is: A B
the order of destruction  is: B A
*/

template <typename II1, typename II2, typename T>
T rmse (II1 b, II1 e, II2 c, T v) {
    int s = 0;
    while (b != e) {
        v += (*b - *c) * (*b - *c);
        ++b;
        ++c;
        ++s;}
    return sqrt(v / s);}

/*
distance() is O(1) with a random-access iterator
distance() is O(n) with a weaker iterator

transform() comes in two forms:

one form takes an input sequence, an output sequence, and a unary function
it calls the unary function on elements of the input sequence and
outputs the results to the output sequence

the other form taks two input sequences, an output sequence, and a binary function
it calls the binary function on the corresponding elements of the two input sequences and
outputs the results to the output sequence

accumulate() comes in two forms:

one form takes an input sequence and a seed
it invokes addition on the seed and elements of the sequence
(e.g. s + a0 + a1 + a2 ...)

the other form takes an input sequence, a seed, and a binary function
it invokes the binary function on the seed and elements of the sequence
*/
