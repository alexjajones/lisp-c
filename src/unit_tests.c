#include "helpers.h"
#include "minunit.h"

MU_TEST(test_check) {
  mu_check(test_func() == 7);
}
MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_check);
}

int main(int argc, char *argv[]) {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return minunit_status;
}
