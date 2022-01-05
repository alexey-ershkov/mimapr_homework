//
// Created by a.ershkov on 12.12.2021.
//

#include <iomanip>
#include "Matrix.h"

Matrix Matrix::operator*=(int value) {
    for (auto &line: matrix) {
        for (auto &elem: line) {
            elem *= value;
        }
    }

    return matrix;
}

Matrix Matrix::operator*(int value) {
    for (auto &line: matrix) {
        for (auto &elem: line) {
            elem *= value;
        }
    }

    return matrix;
}

Matrix Matrix::operator+(const Matrix &rhs) {
    if (matrix.size() != rhs.matrix.size() || matrix[0].size() != rhs.matrix[0].size()) {
        throw std::range_error("Invalid matrix sizes to sum");
    }

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] += rhs.matrix[i][j];
        }
    }

    return matrix;
}

Matrix Matrix::operator-(const Matrix &rhs) {
    if (matrix.size() != rhs.matrix.size() || matrix[0].size() != rhs.matrix[0].size()) {
        throw std::range_error("Invalid matrix sizes to sub");
    }

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] -= rhs.matrix[i][j];
        }
    }

    return matrix;
}

Matrix Matrix::operator+=(const Matrix &rhs) {
    if (matrix.size() != rhs.matrix.size() || matrix[0].size() != rhs.matrix[0].size()) {
        throw std::range_error("Invalid matrix sizes to sum");
    }

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] += rhs.matrix[i][j];
        }
    }

    return matrix;
}

Matrix Matrix::operator-=(const Matrix &rhs) {
    if (matrix.size() != rhs.matrix.size() || matrix[0].size() != rhs.matrix[0].size()) {
        throw std::range_error("Invalid matrix sizes to sum");
    }

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] -= rhs.matrix[i][j];
        }
    }

    return matrix;
}

std::vector<double> Matrix::solve_gauss(Matrix equal_to) {
    if (equal_to.getMatrix()[0].size() != 1 || equal_to.getMatrix().size() != matrix.size() ||
        equal_to.getMatrix().size() != matrix[0].size()) {
        throw std::range_error("Can't solve gauss due to sizes");
    }

    auto extended_matrix = matrix;
    for (int i = 0; i < extended_matrix.size(); ++i) {
        extended_matrix[i].push_back(equal_to.getMatrix()[i][0]);
    }

    const double eps = 1e-17;
    for (int k = 0; k < extended_matrix.size(); ++k) {
        for (int i = k; i < extended_matrix.size(); ++i) {
            auto buf = extended_matrix[i][k];
            if (abs(buf) < eps) continue;
            for (int j = 0; j < extended_matrix.size() + 1; ++j) {
                extended_matrix[i][j] /= buf;
                if (i != k) {
                    extended_matrix[i][j] -= extended_matrix[k][j];
                }
            }
        }
    }

    std::vector<double> out;
    for (int k = int(extended_matrix.size() - 1); k >= 0; --k) {
        out.resize(extended_matrix.size());
        out[k] = extended_matrix[k][extended_matrix[0].size() - 1];
        for (int i = 0; i < k; i++) {
            extended_matrix[i][extended_matrix[0].size() - 1] -= extended_matrix[i][k] * out[k];
        }
    }

    return out;
}

Matrix Matrix::operator-() {
    for (auto &line: matrix) {
        for (auto &elem: line) {
            elem *= -1;
        }
    }

    return matrix;
}

Matrix::Matrix(int width, int height) {
    matrix = std::vector(height, std::vector(width, 0.0));
}

void Matrix::print_matrix() {
    for (const auto& line: matrix) {
        for (auto elem: line) {
            std::cout << std::setw(8) << std::setprecision (2) << elem;
        }
        std::cout << std::endl;
    }
}

