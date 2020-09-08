#include "common.h"
#include "catch.hpp"


TEST_CASE( "Question #1", "PC" )
{
  try {
    redirect_iostream_t ri("in/p1_test01.in");
    p1();
    cout << endl;

    ri.restore();
    string result;
    ri >> result;
    REQUIRE(result == "5");
  }
  catch (const exception& e) {
    cout << "ERROR: " << e.what();
  }
}
