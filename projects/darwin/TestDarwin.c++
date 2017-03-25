// ----------------------------------
// projects/c++/darwin/TestDarwin.c++
// Copyright (C) 2017
// Glenn P. Downing
// ----------------------------------

// https://github.com/google/googletest
// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md
// https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Darwin.h"

using namespace std;

// ----
// test
// ----

TEST(DarwinFixture, test) {
    Darwin x;
    ASSERT_TRUE(x.dummy());}
