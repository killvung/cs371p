// -----------
// Complex.c++
// -----------

// http://www.cplusplus.com/reference/complex/

#include <complex>  // complex
#include <iostream> // cout, endl
#include <utility>  // !=

#include "gtest/gtest.h"

#include "Complex.h"

using namespace std;
using namespace testing;

using rel_ops::operator!=;

template <typename T>
struct Complex_Fixture : Test {
    using complex_type = T;};

using complex_types =
    Types<
           complex<int>,
        my_complex<int>>;

TYPED_TEST_CASE(Complex_Fixture, complex_types);

TYPED_TEST(Complex_Fixture, test_1) {
    using complex_type = typename TestFixture::complex_type;

    const complex_type x;
    ASSERT_EQ(0, real(x));
    ASSERT_EQ(0, imag(x));}

TYPED_TEST(Complex_Fixture, test_2) {
    using complex_type = typename TestFixture::complex_type;

    const complex_type x(2);
    ASSERT_EQ(2, real(x));
    ASSERT_EQ(0, imag(x));}

TYPED_TEST(Complex_Fixture, test_3) {
    using complex_type = typename TestFixture::complex_type;

    const complex_type x(2, 3);
    ASSERT_EQ(2, real(x));
    ASSERT_EQ(3, imag(x));}

TYPED_TEST(Complex_Fixture, test_4) {
    using complex_type = typename TestFixture::complex_type;

    const complex_type x(2, 3);
    complex_type y = x;
    ASSERT_EQ(x, y);}

TYPED_TEST(Complex_Fixture, test_5) {
    using complex_type = typename TestFixture::complex_type;

          complex_type  x(2, 3);
    const complex_type  y(4, 5);
          complex_type& r = (x = y);
    ASSERT_EQ(x,  y);
    ASSERT_EQ(&r, &x);}

TYPED_TEST(Complex_Fixture, test_6) {
    using complex_type = typename TestFixture::complex_type;

          complex_type  x(2, 3);
    const complex_type  y(2, 3);
    const complex_type  z(4, 6);
          complex_type& r = (x += y);
    ASSERT_NE(x,  y);
    ASSERT_EQ(x,  z);
    ASSERT_EQ(&r, &x);}

TYPED_TEST(Complex_Fixture, test_7) {
    using complex_type = typename TestFixture::complex_type;

    const complex_type x(2, 3);
    const complex_type y(2, 3);
    const complex_type z(4, 6);
    const complex_type t = (x + y);
    ASSERT_EQ(x, y);
    ASSERT_EQ(t, z);}

TYPED_TEST(Complex_Fixture, test_8) {
    using complex_type = typename TestFixture::complex_type;

    const complex_type x(2,  3);
    const complex_type y(2, -3);
    const complex_type z = conj(x);
    ASSERT_NE(x, y);
    ASSERT_EQ(y, z);}

/*
% g++ -pedantic -std=c++11 -Wall Complex.c++ -o Complex -lgtest -lgtest_main -pthread



% Complex
Running main() from gtest_main.cc
[==========] Running 16 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 8 tests from Complex_Fixture/0, where TypeParam = std::__1::complex<int>
[ RUN      ] Complex_Fixture/0.test_1
[       OK ] Complex_Fixture/0.test_1 (0 ms)
[ RUN      ] Complex_Fixture/0.test_2
[       OK ] Complex_Fixture/0.test_2 (0 ms)
[ RUN      ] Complex_Fixture/0.test_3
[       OK ] Complex_Fixture/0.test_3 (0 ms)
[ RUN      ] Complex_Fixture/0.test_4
[       OK ] Complex_Fixture/0.test_4 (0 ms)
[ RUN      ] Complex_Fixture/0.test_5
[       OK ] Complex_Fixture/0.test_5 (0 ms)
[ RUN      ] Complex_Fixture/0.test_6
[       OK ] Complex_Fixture/0.test_6 (0 ms)
[ RUN      ] Complex_Fixture/0.test_7
[       OK ] Complex_Fixture/0.test_7 (0 ms)
[ RUN      ] Complex_Fixture/0.test_8
[       OK ] Complex_Fixture/0.test_8 (0 ms)
[----------] 8 tests from Complex_Fixture/0 (0 ms total)

[----------] 8 tests from Complex_Fixture/1, where TypeParam = my_complex<int>
[ RUN      ] Complex_Fixture/1.test_1
[       OK ] Complex_Fixture/1.test_1 (0 ms)
[ RUN      ] Complex_Fixture/1.test_2
[       OK ] Complex_Fixture/1.test_2 (0 ms)
[ RUN      ] Complex_Fixture/1.test_3
[       OK ] Complex_Fixture/1.test_3 (0 ms)
[ RUN      ] Complex_Fixture/1.test_4
[       OK ] Complex_Fixture/1.test_4 (0 ms)
[ RUN      ] Complex_Fixture/1.test_5
[       OK ] Complex_Fixture/1.test_5 (0 ms)
[ RUN      ] Complex_Fixture/1.test_6
[       OK ] Complex_Fixture/1.test_6 (0 ms)
[ RUN      ] Complex_Fixture/1.test_7
[       OK ] Complex_Fixture/1.test_7 (0 ms)
[ RUN      ] Complex_Fixture/1.test_8
[       OK ] Complex_Fixture/1.test_8 (0 ms)
[----------] 8 tests from Complex_Fixture/1 (1 ms total)

[----------] Global test environment tear-down
[==========] 16 tests from 2 test cases ran. (1 ms total)
[  PASSED  ] 16 tests.
*/
