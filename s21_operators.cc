#include "s21_matrix_oop.h"

double &S21Matrix::operator()(int row, int col) {
    if (row > this->rows_ || col > this->cols_ || row < 0 || col < 0) {
        throw "ERROR";
    }
    return this->matrix_[row][col];
}

double &S21Matrix::operator()(int row, int col) const {
    if (row > this->rows_ || col > this->cols_ || row < 0 || col < 0) {
        throw "ERROR";
    }
    return this->matrix_[row][col];
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
    if ((other.cols_ != cols_) || (other.rows_ != rows_)) {
        throw "ERROR";
    }
    S21Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
        }
    }
    return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
    if ((other.cols_ != cols_) || (other.rows_ != rows_)) {
        throw "ERROR";
    }
    S21Matrix result(rows_, cols_);
    for (int i = 0; i < other.rows_; i++) {
        for (int j = 0; j < other.cols_; j++) {
            result.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
        }
    }
    return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
    if (cols_ != other.rows_) {
        throw "ERROR";
    }
    S21Matrix result(rows_, other.cols_);
    for (int i = 0; i < result.rows_; i++) {
        for (int j = 0; j < result.cols_; j++) {
            for (int k = 0; k < other.rows_; k++) {
                result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    return result;
}

S21Matrix S21Matrix::operator*(const double num) {
    S21Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result.matrix_[i][j] = matrix_[i][j] * num;
        }
    }
    return result;
}

void S21Matrix::operator*=(const double num) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] *= num;
        }
    }
}

void S21Matrix::operator*=(const S21Matrix &other) {
    if ((other.rows_ != cols_) && matrix_ != nullptr &&
        other.matrix_ != nullptr) {
        throw "ERROR";
    }
    S21Matrix result(rows_, other.cols_);
    for (int i = 0; i < result.rows_; i++) {
        for (int j = 0; j < result.cols_; j++) {
            for (int k = 0; k < other.rows_; k++) {
                result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    MemoryAllocate(this, result.rows_, result.cols_);
    *this = S21Matrix(result);
}

S21Matrix S21Matrix::operator=(const S21Matrix &other) {
    if (this == &other) return *this;
    MemoryAllocate(this, other.rows_, other.cols_);
    this->CopyMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator=(S21Matrix &&other) {
    if (this == &other) return *this;
    for (int i = 0; i < rows_; i++) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
    return *this;
}

void S21Matrix::operator+=(const S21Matrix &other) {
    if ((other.cols_ != this->cols_) || (other.rows_ != this->rows_)) {
        throw "ERROR";
    }
    for (int i = 0; i < other.rows_; i++) {
        for (int j = 0; j < other.cols_; j++) {
            this->matrix_[i][j] += other.matrix_[i][j];
        }
    }
}

void S21Matrix::operator-=(const S21Matrix &other) {
    if ((other.cols_ != this->cols_) || (other.rows_ != this->rows_)) {
        throw "ERROR";
    }
    for (int i = 0; i < other.rows_; i++) {
        for (int j = 0; j < other.cols_; j++) {
            this->matrix_[i][j] -= other.matrix_[i][j];
        }
    }
}

bool S21Matrix::operator==(const S21Matrix &other) {
    bool isResult = false;
    if ((other.cols_ == cols_) && (other.rows_ == rows_)) {
        isResult = true;
        for (int i = 0; i < other.rows_; i++) {
            for (int j = 0; j < other.cols_; j++) {
                if (fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) {
                    isResult = false;
                }
            }
        }
    }
    return isResult;
}
