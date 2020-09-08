#include "common.h"
#include "catch.hpp"


TEST_CASE( "Question #2", "PC" )
{
  try {
    redirect_iostream_t ri("in/p2_test01.in");
    auto result = p2();
    // cout << endl;

    // ri.restore();
    // string result;
    // ri >> result;
    REQUIRE(result == -3);
  }
  catch (const exception& e) {
    cout << "ERROR: " << e.what();
  }
}
