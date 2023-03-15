#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#define EPS 1e-07

class S21Matrix {
 public:
  // конструкторы
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);

  // методы
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // сетеры & гетеры
  int GetRows();
  int GetCols();
  void SetRows(int rows);
  void SetCols(int cols);

  // перегрузка операторов
  double &operator()(int row, int col);
  double &operator()(int row, int col) const;
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double num);
  S21Matrix operator=(const S21Matrix &other);
  S21Matrix operator=(S21Matrix &&other);
  void operator+=(const S21Matrix &other);
  void operator-=(const S21Matrix &other);
  void operator*=(const double num);
  void operator*=(const S21Matrix &other);
  bool operator==(const S21Matrix &other);
  ~S21Matrix();

 private:
  int rows_, cols_;
  double **matrix_;
  void CreateMatrix();
  void MatrixZeroing();
  void MemoryAllocate(S21Matrix *matrix, int new_rows, int new_cols);
  S21Matrix CreateMinor(int row, int col);
  void CopyMatrix(S21Matrix matrix);
  void test(S21Matrix &&other);
};

#endif  // SRC_S21_MATRIX_OOP_H_
