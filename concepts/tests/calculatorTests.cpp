#include "CppUTest/TestHarness.h"
#include "calculator.h"

TEST_GROUP(Calculator)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(Calculator, MultiplyToZero)
{
    CHECK_EQUAL(0, multiply(1, 0));
    CHECK_EQUAL(0, multiply(0, 2));
}

TEST(Calculator, MultiplyPositives)
{
    CHECK_EQUAL(5, multiply(5, 1));
    CHECK_EQUAL(8, multiply(2, 4));
}

TEST(Calculator, MultiplyNegatives)
{
    CHECK_EQUAL(-20, multiply(10, -2));
    CHECK_EQUAL(100, multiply(-10, -10));
}

TEST(Calculator, MultiplyOverflow)
{
    CHECK_EQUAL(INT_MAX, multiply(INT_MAX, 2));
}