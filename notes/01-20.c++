// -----------
// Fri, 20 Jan
// -----------

/*
cycle of 3 is:
3 10 5 16 8 4 2 1

assertions are not good for user errors
and they're not good for testing
*/

for (int i = 0; i != s; ++i) {
    ...}

int i = 0;
while (i != s) {
    ...
    i++;}

/*
i++ is slower than ++i for any type
for builtin types the compiler will convert i++ to ++i
for user types the compiler is not allowed to do that
it's best to get in the habit of always using pre-increment
when the expression stands alone
*/

int i = 2;
int j = ++i;
cout << i;   // 3
cout << j;   // 3

int i = 2;
int j = i++;
cout << i;   // 3
cout << j;   // 2

// operator overloading

int i = 2;
int j = 3;
int k = (i << j); // builtin      <<

cout << i;        // user-defined <<

/*
you can't invent a token (e.g. ,,,)
you can't redefine an operator (e.g. << on int)
you can't define an operator on a built in type (e.g. << on double)
you can define an old token on a new type (e.g. << on ostream)
*/

int i = 2;
int j = 3;
int k = (i + j);
i + j;           // not ok

i += j;
int k = (i += j); // ok in C, Java, C++, not in Python

(i + j) = k; // not ok
// + takes two r-values and returns an r-value

++(i += j); // not ok in C, Java, Python; ok in C++
// += takes an l-value and an r-value and returns an l-value

++++i; // not ok in C, Java, Python; ok in C++
// pre-increment ++ takes an l-value and returns a l-value

i++++; // not ok for anybody
// post-increment ++ takes an l-value and returns a r-value
