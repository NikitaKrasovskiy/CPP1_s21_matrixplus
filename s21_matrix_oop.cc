#include "s21_matrix_oop.h"

void S21Matrix::MatrixZeroing() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

void S21Matrix::CopyMatrix(S21Matrix matrix) {
  int rows = 0, cols = 0;
  if (matrix.cols_ > cols_ || matrix.rows_ > rows_) {
    cols = cols_;
    rows = rows_;
  } else {
    cols = matrix.cols_;
    rows = matrix.rows_;
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix_[i][j] = matrix.matrix_[i][j];
    }
  }
}

void S21Matrix::CreateMatrix() {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::MemoryAllocate(S21Matrix *matrix, int new_rows, int new_cols) {
    if (new_rows < 1 || new_cols < 1 || matrix_ == nullptr) {
    throw "ERROR";
  }
  for (int i = 0; i < matrix->GetRows(); i++) {
    delete (matrix->matrix_[i]);
  }
  delete (matrix_);
  matrix->rows_ = new_rows;
  matrix->cols_ = new_cols;
  double **new_matrix = new double *[matrix->GetRows()];
    for (int i = 0; i < matrix->GetRows(); i++) {
    new_matrix[i] = new double[matrix->GetCols()]();
  }
  matrix->matrix_ = new_matrix;
}

// конструкторы
S21Matrix::S21Matrix() : S21Matrix(1, 1) {}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw "ERROR";
  }
  rows_ = rows;
  cols_ = cols;
  CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}
S21Matrix::S21Matrix(S21Matrix &&other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr; // данных больше нет , у озер данных нет ими мы владеем мы
}

// методы
int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0) {
    throw "ERROR, rows should be > 0";
  }
  S21Matrix copy_matrix = *this;
  MemoryAllocate(this, rows, cols_);
  rows_ = rows;
  CopyMatrix(copy_matrix);
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) {
    throw "ERROR, cols should be > 0";
  }
  S21Matrix copy_matrix = *this;
  MemoryAllocate(this, rows_, cols);
  cols_ = cols;
  CopyMatrix(copy_matrix);
}

bool S21Matrix::EqMatrix(const S21Matrix &other) { return *this == other; }

void S21Matrix::SumMatrix(const S21Matrix &other) { *this += other; }

void S21Matrix::SubMatrix(const S21Matrix &other) { *this -= other; }

void S21Matrix::MulNumber(const double num) { *this *= num; }

void S21Matrix::MulMatrix(const S21Matrix &other) { *this *= other; }

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
        result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}
S21Matrix S21Matrix::CreateMinor(int row, int col) {
  int dst_row = 0, dst_col = 0;
  S21Matrix result(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i != row && j != col) {
        result(dst_row, dst_col++) = matrix_[i][j];
        if (dst_col == cols_ - 1) {
          dst_row++;
          dst_col = 0;
        }
      }
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw "ERROR, wrong matrix size";
  }
  double res = 0;
  if (rows_ == 1) {
    res = matrix_[0][0];
  } else if (rows_ == 2) {
    res = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
//    S21Matrix minor;
    for (int i = 0; i < cols_; i++) {
        S21Matrix minor = CreateMinor(0, i);
//      minor = CreateMinor(0, i);
      res += matrix_[0][i] * pow(-1, i) * minor.Determinant();
      minor.MatrixZeroing();
    }
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw "ERROR, wrong matrix size";
  }
  S21Matrix result{*this};
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      minor = CreateMinor(i, j);
      result.matrix_[i][j] = pow(-1, i + j) * minor.Determinant();
      minor.MatrixZeroing();
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (Determinant() == 0) {
    throw "ERROR";
  }
  S21Matrix result(CalcComplements());
  result = result.Transpose();
  result *= 1 / Determinant();
//  S21Matrix result = S21Matrix(rows_, cols_);
//  S21Matrix minor_matrix = CalcComplements();
//  minor_matrix = minor_matrix.Transpose();
//  result = minor_matrix * (1 / Determinant());
  return result;
}

// деструктор
S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}