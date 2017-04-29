// -------------
// SharedPtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/shared_ptr

#include <memory> // shared_ptr

#include "gtest/gtest.h"

#include "SharedPtr.h"

using namespace std;
using namespace testing;

struct A {
    static int c;

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

template <typename T>
struct SharedPtrFixture : Test {
    using shared_ptr_type = T;};

using
    shared_ptr_types =
    Types<
           shared_ptr<A>,
        my_shared_ptr<A>>;

TYPED_TEST_CASE(SharedPtrFixture, shared_ptr_types);

TYPED_TEST(SharedPtrFixture, test_1) {
    using shared_ptr_type = typename TestFixture::shared_ptr_type;
    ASSERT_EQ(0, A::c);
    {
//  shared_ptr_type x = new A; // error: no viable conversion from 'A *' to 'shared_ptr_type'
    shared_ptr_type x(new A);
    ASSERT_TRUE(x.unique());
    ASSERT_EQ(1, x.use_count());
    ASSERT_EQ(1, A::c);
    }
    ASSERT_EQ(0, A::c);}

TYPED_TEST(SharedPtrFixture, test_2) {
    using shared_ptr_type = typename TestFixture::shared_ptr_type;
    ASSERT_EQ(0, A::c);
    {
    shared_ptr_type x(new A);
    shared_ptr_type y = x;
    ASSERT_FALSE(x.unique());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_EQ(2, y.use_count());
    ASSERT_EQ(1, A::c);
    ASSERT_EQ(x.get(), y.get());
    }
    ASSERT_EQ(0, A::c);}

TYPED_TEST(SharedPtrFixture, test_3) {
    using shared_ptr_type = typename TestFixture::shared_ptr_type;
    ASSERT_EQ(0, A::c);
    {
    shared_ptr_type x(new A);
    shared_ptr_type y(new A);
    ASSERT_EQ(2, A::c);
    ASSERT_NE(x.get(), y.get());
    x = y;
    ASSERT_FALSE(x.unique());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_EQ(2, y.use_count());
    ASSERT_EQ(1, A::c);
    ASSERT_EQ(x.get(), y.get());
    }
    ASSERT_EQ(0, A::c);}
