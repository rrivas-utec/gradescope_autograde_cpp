#include "../common.h"

int main()
{
  try {
    redirect_iostream_t ri("in/p1_test01.in");
    p1();
    p2();
  }
  catch (const exception& e) {
    cout << "ERROR: " << e.what();
  }
  return 0;
}
