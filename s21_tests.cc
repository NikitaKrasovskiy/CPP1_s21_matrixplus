#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// конструктор

TEST(Matrix_Test, test1) {
EXPECT_ANY_THROW({
S21Matrix test = S21Matrix(3, 3);
test(-1, -1) = 0;
});
}

TEST(Matrix_Test, test2) {
EXPECT_ANY_THROW({
S21Matrix test = S21Matrix(3, 3);
test(-1, 0) = 0;
});
}

TEST(Matrix_Test, test3) {
EXPECT_ANY_THROW({
S21Matrix test = S21Matrix(3, 3);
test(3, 4) = 0;
});
}

TEST(Matrix_Test, test4) {
EXPECT_NO_THROW({
const S21Matrix test = S21Matrix(5, 5);
test(1, 1) = 2;
test(2, 2) = 3;
EXPECT_EQ(test(1, 1), 2);
});
}

TEST(Matrix_Test, test5) {
EXPECT_ANY_THROW({
const S21Matrix test = S21Matrix(3, 3);
test(3, 4) = 0;
});
}

TEST(Matrix_Test, Seter_test1) {
EXPECT_ANY_THROW({
S21Matrix test = S21Matrix(3, 3);
test.SetRows(0);
});
}

TEST(Matrix_Test, Seter_test2) {
EXPECT_ANY_THROW({
S21Matrix test = S21Matrix(3, 3);
test.SetRows(-1);
});
}

TEST(Matrix_Test, Seter_test3) {
EXPECT_ANY_THROW({
S21Matrix test = S21Matrix(3, 3);
test.SetCols(-1);
});
}

TEST(Matrix_Test, Seter_test4) {
double result[2][3] = {{0, 1, 0}, {1, 2, 0}};
EXPECT_NO_THROW({
S21Matrix test = S21Matrix(2, 2);
for (int i = 0; i < test.GetRows(); i++) {
for (int j = 0; j < test.GetCols(); j++) {
test(i, j) = i + j;
}
}
test.SetCols(3);
EXPECT_EQ(test.GetCols(), 3);
for (int i = 0; i < test.GetRows(); i++) {
for (int j = 0; j < test.GetCols(); j++) {
EXPECT_EQ(test(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, Seter_test5) {
double result[2][1] = {{0}, {1}};
EXPECT_NO_THROW({
S21Matrix test = S21Matrix(2, 2);
for (int i = 0; i < test.GetRows(); i++) {
for (int j = 0; j < test.GetCols(); j++) {
test(i, j) = i + j;
}
}
test.SetCols(1);
EXPECT_EQ(test.GetCols(), 1);
for (int i = 0; i < test.GetRows(); i++) {
for (int j = 0; j < test.GetCols(); j++) {
EXPECT_EQ(test(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, Seter_test6) {
double result[3][3] = {{0, 1, 0}, {1, 2, 0}, {0, 0, 0}};
EXPECT_NO_THROW({
S21Matrix test = S21Matrix(2, 2);
for (int i = 0; i < test.GetRows(); i++) {
for (int j = 0; j < test.GetCols(); j++) {
test(i, j) = i + j;
}
}
test.SetRows(3);
test.SetCols(3);
EXPECT_EQ(test.GetRows(), 3);
EXPECT_EQ(test.GetCols(), 3);
for (int i = 0; i < test.GetRows(); i++) {
for (int j = 0; j < test.GetCols(); j++) {
EXPECT_EQ(test(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, Seter_test7) {
double result[2][2] = {{0, 1}, {1, 2}};
EXPECT_NO_THROW({
S21Matrix test = S21Matrix(3, 3);
for (int i = 0; i < test.GetRows(); i++) {
for (int j = 0; j < test.GetCols(); j++) {
test(i, j) = i + j;
}
}
test.SetRows(2);
test.SetCols(2);
EXPECT_EQ(test.GetRows(), 2);
EXPECT_EQ(test.GetCols(), 2);
for (int i = 0; i < test.GetRows(); i++) {
for (int j = 0; j < test.GetCols(); j++) {
EXPECT_EQ(test(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, construct_test1) {
EXPECT_NO_THROW({
S21Matrix test = S21Matrix();
EXPECT_EQ(test.GetRows(), 1);
EXPECT_EQ(test.GetCols(), 1);
});
}

TEST(Matrix_Test, construct_test2) {  // LEAK
EXPECT_ANY_THROW(S21Matrix(0, 1));
EXPECT_ANY_THROW(S21Matrix(-2, 3));
EXPECT_ANY_THROW(S21Matrix(4, -5));
EXPECT_ANY_THROW(S21Matrix(1, -1));
EXPECT_ANY_THROW(S21Matrix(-5, -6));
EXPECT_ANY_THROW(S21Matrix(0, 0));
}

TEST(Matrix_Test, construct_test3) {
S21Matrix check = S21Matrix(4, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = i + 1;
}
}
S21Matrix result = S21Matrix(check);
EXPECT_EQ(result.GetRows(), check.GetRows());
EXPECT_EQ(result.GetCols(), check.GetCols());
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
EXPECT_EQ(result(i, j), check(i, j));
}
}
}

TEST(Matrix_Test, construct_test4) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = 1;
}
}
S21Matrix result = S21Matrix(check);
EXPECT_EQ(result.GetRows(), check.GetRows());
EXPECT_EQ(result.GetCols(), check.GetCols());
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
EXPECT_EQ(result(i, j), check(i, j));
}
}
});
}

TEST(Matrix_Test, construct_test5) {
EXPECT_NO_THROW({
S21Matrix test1 = S21Matrix(2, 2);
test1(1, 1) = 2;
S21Matrix test2 = std::move(S21Matrix(test1));
EXPECT_EQ(test2(1, 1), test1(1, 1));
});
}

TEST(Matrix_Test, construct_test6) {
EXPECT_NO_THROW({
S21Matrix test1 = S21Matrix(2, 2);
for (int i = 0; i < test1.GetRows(); i++) {
for (int j = 0; j < test1.GetCols(); j++) {
test1(i, j) = i + j;
}
}
S21Matrix test2 = std::move(S21Matrix(test1));
EXPECT_EQ(test2.GetRows(), test1.GetRows());
EXPECT_EQ(test2.GetCols(), test1.GetCols());
for (int i = 0; i < test1.GetRows(); i++) {
for (int j = 0; j < test1.GetCols(); j++) {
EXPECT_EQ(test2(i, j), test1(i, j));
}
}
});
}

// перегрузка операций
TEST(Matrix_Test, operator_equal1) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = i + j;
}
}
S21Matrix result = S21Matrix();
result = check;
EXPECT_EQ(result.GetRows(), check.GetRows());
EXPECT_EQ(result.GetCols(), check.GetCols());
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
EXPECT_EQ(result(i, j), check(i, j));
}
}
});
}

TEST(Matrix_Test, operator_equal2) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix();
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = i + j;
}
}
S21Matrix result = S21Matrix(2, 2);
result = check;
EXPECT_EQ(result.GetRows(), check.GetRows());
EXPECT_EQ(result.GetCols(), check.GetCols());
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
EXPECT_EQ(result(i, j), check(i, j));
}
}
});
}

TEST(Matrix_Test, operator_plus) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = i + j;
}
}
S21Matrix result = S21Matrix(check);
S21Matrix result2 = result + check;
EXPECT_EQ(result2.GetRows(), check.GetRows());
EXPECT_EQ(result2.GetCols(), check.GetCols());
for (int i = 0; i < result2.GetRows(); i++) {
for (int j = 0; j < result2.GetCols(); j++) {
EXPECT_EQ(result2(i, j), check(i, j) * 2);
}
}
});
}

TEST(Matrix_Test, operator_plus_throw) {
EXPECT_ANY_THROW({
S21Matrix check = S21Matrix(3, 4);
S21Matrix result = S21Matrix(3, 3);
S21Matrix result2 = result + check;
});
}

TEST(Matrix_Test, operator_minus) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = 2 * (i + j);
}
}
S21Matrix result = S21Matrix(check);
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
result(i, j) = i + j;
}
}
S21Matrix result2 = result - check;
EXPECT_EQ(result2.GetRows(), check.GetRows());
EXPECT_EQ(result2.GetCols(), check.GetCols());
for (int i = 0; i < result2.GetRows(); i++) {
for (int j = 0; j < result2.GetCols(); j++) {
EXPECT_EQ(result2(i, j), -(i + j));
}
}
});
}

TEST(Matrix_Test, operator_minus_throw) {
EXPECT_ANY_THROW({
S21Matrix check = S21Matrix(3, 4);
S21Matrix result = S21Matrix(3, 3);
result = result - check;
});
}

TEST(Matrix_Test, operator_plus_equal) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = i + j;
}
}
S21Matrix result = S21Matrix(check);
result += check;
EXPECT_EQ(result.GetRows(), check.GetRows());
EXPECT_EQ(result.GetCols(), check.GetCols());
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
EXPECT_EQ(result(i, j), check(i, j) * 2);
}
}
});
}

TEST(Matrix_Test, operator_plus_equal_throw) {
EXPECT_ANY_THROW({
S21Matrix check = S21Matrix(3, 4);
S21Matrix result = S21Matrix(2, 2);
check += result;
});
}

TEST(Matrix_Test, operator_minus_equal) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = 1;
}
}
S21Matrix result = S21Matrix(3, 4);
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
result(i, j) = 2;
}
}
result -= check;
EXPECT_EQ(result.GetRows(), check.GetRows());
EXPECT_EQ(result.GetCols(), check.GetCols());
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
EXPECT_EQ(result(i, j), 1);
}
}
});
}

TEST(Matrix_Test, operator_minus_equal_throw) {
EXPECT_ANY_THROW({
S21Matrix check = S21Matrix(3, 2);
S21Matrix result = S21Matrix(3, 4);
result -= check;
});
}

TEST(Matrix_Test, operator_mult_num) {
double result[2][2] = {{2, 4}, {6, 8}};
double matrix1[2][2] = {{1, 2}, {3, 4}};
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(2, 2);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = matrix1[i][j];
}
}
check = check * 2;
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
EXPECT_EQ(check(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, operator_mult) {
double result[2][2] = {{2, 4}, {6, 8}};
double matrix1[2][2] = {{1, 2}, {3, 4}};
double matrix2[2][2] = {{2, 0}, {0, 2}};
EXPECT_NO_THROW({
S21Matrix check1 = S21Matrix(2, 2);
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
check1(i, j) = matrix1[i][j];
}
}
S21Matrix check2 = S21Matrix(2, 2);
for (int i = 0; i < check2.GetRows(); i++) {
for (int j = 0; j < check2.GetCols(); j++) {
check2(i, j) = matrix2[i][j];
}
}
check1 = check1 * check2;
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
EXPECT_EQ(check1(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, operator_mult_throw) {
double matrix1[2][2] = {{1, 2}, {3, 4}};
double matrix2[3][2] = {{2, 0}, {0, 2}, {0, 2}};
EXPECT_ANY_THROW({
S21Matrix check1 = S21Matrix(2, 2);
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
check1(i, j) = matrix1[i][j];
}
}
S21Matrix check2 = S21Matrix(3, 2);
for (int i = 0; i < check2.GetRows(); i++) {
for (int j = 0; j < check2.GetCols(); j++) {
check2(i, j) = matrix2[i][j];
}
}
check1 = check1 * check2;
});
}

TEST(Matrix_Test, operator_mult_equal1) {
double result[2][2] = {{2, 4}, {6, 8}};
double matrix1[2][2] = {{1, 2}, {3, 4}};
double matrix2[2][2] = {{2, 0}, {0, 2}};
EXPECT_NO_THROW({
S21Matrix check1 = S21Matrix(2, 2);
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
check1(i, j) = matrix1[i][j];
}
}
S21Matrix check2 = S21Matrix(2, 2);
for (int i = 0; i < check2.GetRows(); i++) {
for (int j = 0; j < check2.GetCols(); j++) {
check2(i, j) = matrix2[i][j];
}
}
check1 *= check2;
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
EXPECT_EQ(check1(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, operator_mult_equal2) {
double result[2][2] = {{18, 27}, {45, 66}};
double matrix1[2][3] = {{1, 2, 3}, {4, 5, 6}};
double matrix2[3][2] = {{4, 5}, {1, 2}, {4, 6}};
EXPECT_NO_THROW({
S21Matrix check1 = S21Matrix(2, 3);
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
check1(i, j) = matrix1[i][j];
}
}
S21Matrix check2 = S21Matrix(3, 2);
for (int i = 0; i < check2.GetRows(); i++) {
for (int j = 0; j < check2.GetCols(); j++) {
check2(i, j) = matrix2[i][j];
}
}
check1 *= check2;
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
EXPECT_EQ(check1(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, operator_mult_equal3) {
EXPECT_ANY_THROW({
S21Matrix check1 = S21Matrix(2, 2);
S21Matrix check2 = S21Matrix(3, 2);
check1 *= check2;
});
}

TEST(Matrix_Test, operator_isequal) {
double matrix1[2][2] = {{1, 2}, {3, 4}};
double matrix2[2][2] = {{1, 2}, {3, 4}};
EXPECT_NO_THROW({
S21Matrix check1 = S21Matrix(2, 2);
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
check1(i, j) = matrix1[i][j];
}
}
S21Matrix check2 = S21Matrix(2, 2);
for (int i = 0; i < check2.GetRows(); i++) {
for (int j = 0; j < check2.GetCols(); j++) {
check2(i, j) = matrix2[i][j];
}
}
EXPECT_TRUE(check1 == check2);
});
}

TEST(Matrix_Test, operator_isequal2) {
EXPECT_NO_THROW({
S21Matrix check1 = S21Matrix(2, 2);
check1(1, 1) = 21;
S21Matrix check2 = S21Matrix(2, 2);
EXPECT_FALSE(check1 == check2);
});
}

// методы

TEST(Matrix_Test, EqMatrix) {
double matrix1[2][2] = {{1, 2}, {3, 4}};
double matrix2[2][2] = {{1, 2}, {3, 4}};
EXPECT_NO_THROW({
S21Matrix check1 = S21Matrix(2, 2);
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
check1(i, j) = matrix1[i][j];
}
}
S21Matrix check2 = S21Matrix(2, 2);
for (int i = 0; i < check2.GetRows(); i++) {
for (int j = 0; j < check2.GetCols(); j++) {
check2(i, j) = matrix2[i][j];
}
}
EXPECT_TRUE(check1.EqMatrix(check2));
});
}

TEST(Matrix_Test, SumMatrix) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = i + j;
}
}
S21Matrix result = S21Matrix(check);
result.SumMatrix(check);
EXPECT_EQ(result.GetRows(), check.GetRows());
EXPECT_EQ(result.GetCols(), check.GetCols());
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
EXPECT_EQ(result(i, j), check(i, j) * 2);
}
}
});
}

TEST(Matrix_Test, SubMatrix) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = i + j;
}
}
S21Matrix result = S21Matrix(check);
result.SubMatrix(check);
EXPECT_EQ(result.GetRows(), check.GetRows());
EXPECT_EQ(result.GetCols(), check.GetCols());
for (int i = 0; i < result.GetRows(); i++) {
for (int j = 0; j < result.GetCols(); j++) {
EXPECT_EQ(result(i, j), 0);
}
}
});
}

TEST(Matrix_Test, MulNumber1) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = i + j;
}
}
check.MulNumber(2);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
EXPECT_EQ(check(i, j), (i + j) * 2);
}
}
});
}

TEST(Matrix_Test, MulNumber2) {
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = 1;
}
}
check.MulNumber(2.5);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
EXPECT_EQ(check(i, j), 2.5);
}
}
});
}

TEST(Matrix_Test, MulMatrix) {
double result[4][4] = {{18, 27, -48, 65},
                       {45, 66, -123, 152},
                       {256, 381, -294, 813},
                       {115, 184, 47, 420}};
double matrix1[4][3] = {{1, 2, 3}, {4, 5, 6}, {9, 12, 52}, {-12, -1, 41}};
double matrix2[3][4] = {{4, 5, -2, 5}, {1, 2, -23, 12}, {4, 6, 0, 12}};
EXPECT_NO_THROW({
S21Matrix check1 = S21Matrix(4, 3);
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
check1(i, j) = matrix1[i][j];
}
}
S21Matrix check2 = S21Matrix(3, 4);
for (int i = 0; i < check2.GetRows(); i++) {
for (int j = 0; j < check2.GetCols(); j++) {
check2(i, j) = matrix2[i][j];
}
}
check1.MulMatrix(check2);
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
EXPECT_EQ(check1(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, Transpose) {
double result[3][2] = {{1, 4}, {2, 5}, {3, 6}};
double matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
EXPECT_NO_THROW({
S21Matrix check1 = S21Matrix(2, 3);
for (int i = 0; i < check1.GetRows(); i++) {
for (int j = 0; j < check1.GetCols(); j++) {
check1(i, j) = matrix[i][j];
}
}
S21Matrix check2 = check1.Transpose();
for (int i = 0; i < check2.GetRows(); i++) {
for (int j = 0; j < check2.GetCols(); j++) {
EXPECT_EQ(check2(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, Determinant) {
double matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
double matrix2[4][4] = {
        {1, 2, 3, 2}, {4, -5, 6, 2}, {7, -8, 9, 2}, {1, 2, 2, 2}};
double matrix3[4][4] = {{0.5, 1, 1.5, 3},
                        {4.4, 5.2, 1.7, 2},
                        {6.1, 2.7, -9.1, 1},
                        {2, 5, 21.621, 4}};
EXPECT_ANY_THROW({
S21Matrix check = S21Matrix(2, 3);
check.Determinant();
});
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 3);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = matrix[i][j];
}
}
EXPECT_EQ(check.Determinant(), 0);
check = S21Matrix(4, 4);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = matrix2[i][j];
}
}
EXPECT_EQ(check.Determinant(), 24);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = matrix3[i][j];
}
}
EXPECT_TRUE(722.34022 - check.Determinant() < EPS);
S21Matrix check2 = S21Matrix();
check2(0, 0) = 21;
EXPECT_EQ(check2.Determinant(), 21);
});
}

TEST(Matrix_Test, CalcComplements) {
double matrix[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
double result[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 3);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = matrix[i][j];
}
}
S21Matrix res = check.CalcComplements();
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
EXPECT_EQ(res(i, j), result[i][j]);
}
}
});
}

TEST(Matrix_Test, CalcComplementsThrow) {
EXPECT_ANY_THROW({
S21Matrix check = S21Matrix(4, 3);
check.CalcComplements();
});
}

TEST(Matrix_Test, InverseMatrix) {
double matrix[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
double matrix_throw[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
double result[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
EXPECT_ANY_THROW({
S21Matrix check = S21Matrix(2, 3);
check.InverseMatrix();
});
EXPECT_ANY_THROW({
S21Matrix check = S21Matrix(3, 3);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = matrix_throw[i][j];
}
}
check.InverseMatrix();
});
EXPECT_NO_THROW({
S21Matrix check = S21Matrix(3, 3);
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
check(i, j) = matrix[i][j];
}
}
S21Matrix res = check.InverseMatrix();
for (int i = 0; i < check.GetRows(); i++) {
for (int j = 0; j < check.GetCols(); j++) {
EXPECT_EQ(res(i, j), result[i][j]);
}
}
});
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
