#ifndef TST_CALCLUALTOR_H
#define TST_CALCLUALTOR_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(SampleTest, Calclualtor)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_CALCLUALTOR_H
