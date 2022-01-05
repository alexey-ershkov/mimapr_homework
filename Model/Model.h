//
// Created by a.ershkov on 05.01.2022.
//

#ifndef HW_MODEL_H
#define HW_MODEL_H


#include "../Matrix/Matrix.h"
#include "../constants.h"

#include <cmath>

class Model {
public:
    void fill_matrix();

    void do_newton_step();

    void solve();

    std::vector<std::vector<double>> get_solutions() {
        return solutions;
    }

    std::vector<double> get_time() {
        return time;
    }

private:
    void fill_left();

    void fill_right();

    bool is_converges();

    Matrix left = Matrix(MATRIX_SIZE, MATRIX_SIZE);
    Matrix right = Matrix(1, MATRIX_SIZE);
    std::vector<std::vector<double>> solutions = std::vector(3, std::vector(MATRIX_SIZE, 0.0));

    double delta_time = MIN_DELTA_TIME;
    double prev_delta_time = MIN_DELTA_TIME;
    double corrected_delta_time = MIN_DELTA_TIME;
    double current_time = 0.;
    std::vector<double> deltas = std::vector(MATRIX_SIZE, 0.);
    std::vector<double> time = {0.};
};


#endif //HW_MODEL_H
