#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

//======================= STRESS ============================
// class StressTest : public ::testing::TestWithParam<int> {};

// TEST_P(StressTest, t) {
//   int size = GetParam();
//   S21Matrix matrix(size, size);
//   // Optionally, perform additional operations or checks on the matrix
// }

// INSTANTIATE_TEST_SUITE_P(stress_test, StressTest, ::testing::Range(1, 10));

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

TEST(test_constructors, test_7_move) {
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

TEST(test_constructors, test_8_move) {
  S21Matrix original(3, 3);

  S21Matrix moved(std::move(original));

  ASSERT_EQ(moved.getRows(), 3);
  ASSERT_EQ(moved.getCols(), 3);
  ASSERT_EQ(original.getRows(), 0);
  ASSERT_EQ(original.getCols(), 0);
}

TEST(test_constructors, test_9) { S21Matrix a; }
TEST(test_constructors, test_10) { S21Matrix a; }

//================ ACCESSORS and MUTATORS ===================

TEST(test_accessors_mutators, link_access) {
  S21Matrix a;
  double& link_a0_0 = a(0, 0);
  link_a0_0 = 1;
  S21Matrix b(a);
  ASSERT_EQ(a(0, 0), b(0, 0));
}

TEST(test_accessors_mutators, IncreaseRows) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setRows(4);

  EXPECT_EQ(matrix.getRows(), 4);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
}

TEST(test_accessors_mutators, DecreaseRows) {
  S21Matrix matrix(3, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix(2, 0) = 5.0;
  matrix(2, 1) = 6.0;

  matrix.setRows(2);

  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
}

TEST(test_accessors_mutators, SameRows) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setRows(2);

  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
}
TEST(test_accessors_mutators, SameCols) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setCols(2);

  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
  EXPECT_EQ(matrix(1, 1), 4.0);
}

TEST(test_accessors_mutators, ZeroRows) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  ASSERT_ANY_THROW(matrix.setRows(0));
}

TEST(test_accessors_mutators, OneRow) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setRows(1);

  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(0, 1), 2.0);
}
TEST(test_accessors_mutators, OneCol) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.setCols(1);

  EXPECT_EQ(matrix.getCols(), 1);
  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix(0, 0), 1.0);
  EXPECT_EQ(matrix(1, 0), 3.0);
}

TEST(test_accessors_mutators, test_2) { S21Matrix a; }
TEST(test_accessors_mutators, test_3) { S21Matrix a; }
TEST(test_accessors_mutators, test_4) { S21Matrix a; }

// =================== OPERATORS overloads ====================

TEST(test_operators, test_1_copy) {
  S21Matrix a(3);
  a(1, 1) = 1;
  S21Matrix b = a;
  ASSERT_EQ(a(1, 1), b(1, 1));
}

TEST(test_operators, test_2_copy) {
  S21Matrix a(3);
  a(1, 1) = 1;
  S21Matrix b;
  b = a;
  ASSERT_EQ(a(1, 1), b(1, 1));
}
TEST(test_operators, test_3_bad_access) {
  S21Matrix a(3);
  ASSERT_ANY_THROW(a(1, 4) = 5);
}
TEST(test_operators, test_4_bad_access) {
  S21Matrix a;
  a.printS21Matrix();
  ASSERT_ANY_THROW(a(1, 0) = 5);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}