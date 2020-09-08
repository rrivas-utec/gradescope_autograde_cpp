#include "common.h"
#include "catch.hpp"

TEST_CASE( "Test 02", "Example Project" )
{
    redirect_iostream_t ri("in/p1_test01.in");
    p1();
    p2();
}