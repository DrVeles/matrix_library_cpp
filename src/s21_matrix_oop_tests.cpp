#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

//======================= STRESS ============================
class StressTest : public ::testing::TestWithParam<int> {};

TEST_P(StressTest, t) {
  int size = GetParam();
  S21Matrix matrix(size, size);
  // Optionally, perform additional operations or checks on the matrix
}

INSTANTIATE_TEST_SUITE_P(stress_test, StressTest, ::testing::Range(1, 100));

//========================= BAZE ============================

TEST(test_constructors, test_1) { S21Matrix a(10); }
TEST(test_constructors, test_2) { S21Matrix a(1, 1); }
TEST(test_constructors, test_3) { ASSERT_ANY_THROW(S21Matrix a(1, 0)); }
TEST(test_constructors, test_4) { ASSERT_ANY_THROW(S21Matrix a(0, 1)); }
TEST(test_constructors, test_5) { ASSERT_ANY_THROW(S21Matrix a(0)); }
TEST(test_constructors, test_6_copy) {
  S21Matrix original(3, 3);
  original(0, 0) = 1.0;
  original(1, 1) = 2.0;
  original(2, 2) = 3.0;

  S21Matrix copy(original);

  ASSERT_EQ(copy(0, 0), original(0, 0));
  ASSERT_EQ(copy(1, 1), original(1, 1));
  ASSERT_EQ(copy(2, 2), original(2, 2));
  ASSERT_EQ(copy.getRows(), original.getRows());
  ASSERT_EQ(copy.getCols(), original.getCols());
}
TEST(test_constructors, test_7_) {
  S21Matrix original(3, 3);
  original(0, 0) = 1.0;
  original(1, 1) = 2.0;
  original(2, 2) = 3.0;

  S21Matrix moved(std::move(original));

  ASSERT_EQ(moved(0, 0), 1.0);
  ASSERT_EQ(moved(1, 1), 2.0);
  ASSERT_EQ(moved(2, 2), 3.0);
  ASSERT_EQ(moved.getRows(), 3);
  ASSERT_EQ(moved.getCols(), 3);
  ASSERT_EQ(original.getRows(), 0);
  ASSERT_EQ(original.getCols(), 0);
}
TEST(test_constructors, test_8) { S21Matrix a; }

//================ ACCESSORS and MUTATORS ===================

TEST(test_accessors_mutators, test_1) {
  S21Matrix a;
  double& link_a0_0 = a(0, 0);
  link_a0_0 = 1;
  S21Matrix b(a);
  ASSERT_EQ(a(0, 0), b(0, 0));
}

TEST(test_accessors_mutators, test_2) { S21Matrix a; }
TEST(test_accessors_mutators, test_3) { S21Matrix a; }
TEST(test_accessors_mutators, test_4) { S21Matrix a; }

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}