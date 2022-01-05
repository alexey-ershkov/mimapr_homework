//
// Created by a.ershkov on 12.12.2021.
//

#ifndef HW_MATRIX_H
#define HW_MATRIX_H

#include <utility>
#include <vector>
#include <utility>
#include <exception>
#include <vector>
#include <iostream>

class Matrix {
public:
    Matrix(std::vector<std::vector<double>> init_matrix) : matrix(std::move(init_matrix)) {};

    Matrix(int width, int height);

    Matrix operator*=(int value);

    Matrix operator*(int value);

    Matrix operator+(const Matrix &rhs_matrix);

    Matrix operator-(const Matrix &rhs_matrix);

    Matrix operator+=(const Matrix &rhs_matrix);

    Matrix operator-=(const Matrix &rhs_matrix);

    Matrix operator-();

    std::vector<std::vector<double>> getMatrix() const {
        return matrix;
    }

    double get_elem(int i, int j) {
        return matrix[i][j];
    }

    void set_elem(int i, int j, double value) {
        matrix[i][j] = value;
    }

    std::vector<double> solve_gauss(Matrix equal_to);

    void print_matrix();

private:
    std::vector<std::vector<double>> matrix;
};


#endif //HW_MATRIX_H
