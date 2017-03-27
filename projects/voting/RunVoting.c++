// ------------------------------------
// projects/c++/voting/RunVoting.c++
// Copyright (C) 2017
// Glenn P. Downing
// ------------------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <fstream>  // ifstream
#include <iostream> // cout, endl, getline

#include "Voting.h"

// ----
// main
// ----

int main () {
    using namespace std;
    // read  RunVoting.in
    // write RunVoting.out

    // replace!
    ifstream fin("RunVoting.out");
    char a[80];
    while (fin.getline(a, 80))
        cout << a << endl;
    return 0;}
