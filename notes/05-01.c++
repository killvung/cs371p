// -----------
// Mon,  1 May
// -----------

/*
local: non-static, static
global: non-static, static
class: non-static, static
*/

// foo.c++
int g = h();

// bar.c++
extern int g;

void f () {
    ...
    cout << g << endl;}

/*
1. How many are there?        (one)
2. When are they allocated?   (on program entry)
3. When are they initialized? (before main())
4. What is their lifetime?    (lifetime of program)
5. What is their scope?       (anywhere)
*/

// foo.c++
static int g = h();

// bar.c++
static int g;

void f () {
    ...
    cout << g << endl;}

/*
1. How many are there?        (one)
2. When are they allocated?   (on program entry)
3. When are they initialized? (before main())
4. What is their lifetime?    (lifetime of program)
5. What is their scope?       (the file)
*/











