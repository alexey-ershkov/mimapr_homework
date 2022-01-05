//
// Created by a.ershkov on 05.01.2022.
//

#include "Model.h"

void Model::fill_matrix() {
    left = Matrix(MATRIX_SIZE, MATRIX_SIZE);
    right = Matrix(1, MATRIX_SIZE);
    fill_left();
    fill_right();
}

void Model::fill_left() {
    left.set_elem(0, 0, 1.);
    left.set_elem(0, 21, 1.);
    left.set_elem(0, 22, -1.);
    left.set_elem(0, 24, 1.);

    left.set_elem(1, 1, 1.);
    left.set_elem(1, 23, -1.);

    left.set_elem(2, 2, 1.);
    left.set_elem(2, 21, -1.);
    left.set_elem(2, 22, 1.);
    left.set_elem(2, 23, 1.);
    left.set_elem(2, 25, 1.);

    left.set_elem(3, 3, 1.);
    left.set_elem(3, 24, -1.);

    left.set_elem(4, 4, 1.);
    left.set_elem(4, 25, -1.);

    left.set_elem(5, 5, 1.);
    left.set_elem(5, 24, -1.);

    left.set_elem(6, 6, 1.);
    left.set_elem(6, 25, -1.);

    left.set_elem(7, 7, 1.);
    left.set_elem(7, 22, -1.);

    left.set_elem(8, 8, 1.);
    left.set_elem(8, 13, -1.);
    left.set_elem(8, 15, 1.);

    left.set_elem(9, 9, 1.);
    left.set_elem(9, 13, 1.);
    left.set_elem(9, 15, -1.);
    left.set_elem(9, 20, -1.);

    left.set_elem(10, 10, 1.);
    left.set_elem(10, 14, 1.);
    left.set_elem(10, 15, -1.);

    left.set_elem(11, 11, 1.);
    left.set_elem(11, 13, -1.);
    left.set_elem(11, 16, 1.);
    left.set_elem(11, 18, 1.);

    left.set_elem(12, 12, 1.);
    left.set_elem(12, 15, -1.);
    left.set_elem(12, 17, 1.);
    left.set_elem(12, 19, 1.);

    left.set_elem(13, 0, 1.);
    left.set_elem(13, 13, -Rb1);

    left.set_elem(14, 1, 1.);
    left.set_elem(14, 14, -R1);

    left.set_elem(15, 2, 1.);
    left.set_elem(15, 15, -Rb2);

    left.set_elem(16, 3, 1.);
    left.set_elem(16, 16, -Rd1);

    left.set_elem(17, 4, 1.);
    left.set_elem(17, 17, -Rd2);

    left.set_elem(18, 5, -Id1 / MFt * exp(solutions.back()[U_Id1] / MFt));
    left.set_elem(18, 18, 1.);

    left.set_elem(19, 6, -Id2 / MFt * exp(solutions.back()[U_Id2] / MFt));
    left.set_elem(19, 19, 1.);

    left.set_elem(20, 7, 1.);
    left.set_elem(20, 20, -L1 / delta_time);

    left.set_elem(21, 21, 1.);

    left.set_elem(22, 9, 1.);
    left.set_elem(22, 22, -C1 / delta_time);

    left.set_elem(23, 10, 1.);
    left.set_elem(23, 23, -C2 / delta_time);

    left.set_elem(24, 11, 1.);
    left.set_elem(24, 24, -Cd1 / delta_time);

    left.set_elem(25, 12, 1.);
    left.set_elem(25, 25, -Cd2 / delta_time);
}

void Model::fill_right() {
    auto prev_x = solutions[solutions.size() - 2];
    auto x = solutions.back();

    right.set_elem(U_Rb1, 0, x[U_Rb1] + x[U_E1] - x[U_C1] + x[U_Cd1]);
    right.set_elem(U_R1, 0, x[U_R1] - x[U_C2]);
    right.set_elem(U_Rb2, 0, x[U_Rb2] - x[U_E1] + x[U_C1] + x[U_C2] + x[U_Cd2]);
    right.set_elem(U_Rd1, 0, x[U_Rd1] - x[U_Cd1]);
    right.set_elem(U_Rd2, 0, x[U_Rd2] - x[U_Cd2]);
    right.set_elem(U_Id1, 0, x[U_Id1] - x[U_Cd1]);
    right.set_elem(U_Id2, 0, x[U_Id2] - x[U_Cd2]);
    right.set_elem(U_L1, 0, x[U_L1] - x[U_C1]);

    right.set_elem(I_E1, 0, x[I_E1] - x[I_Rb1] + x[I_Rb2]);
    right.set_elem(I_C1, 0, x[I_C1] + x[I_Rb1] - x[I_Rb2] + x[I_L1]);
    right.set_elem(I_C2, 0, x[I_C2] + x[I_R1] - x[I_Rb2]);
    right.set_elem(I_Cd1, 0, x[I_Cd1] - x[I_Rb1] + x[I_Rd1] + x[I_Id1]);
    right.set_elem(I_Cd2, 0, x[I_Cd2] - x[I_Rb2] + x[I_Rd2] + x[I_Id2]);

    right.set_elem(I_Rb1, 0, x[U_Rb1] - x[I_Rb1] * Rb1);
    right.set_elem(I_R1, 0, x[U_R1] - x[I_R1] * R1);
    right.set_elem(I_Rb2, 0, x[U_Rb2] - x[I_Rb2] * Rb2);
    right.set_elem(I_Rd1, 0, x[U_Rd1] - x[I_Rd1] * Rd1);
    right.set_elem(I_Rd2, 0, x[U_Rd2] - x[I_Rd2] * Rd2);
    right.set_elem(I_Id1, 0, x[I_Id1] - Id1 * (exp(x[U_Id1] / MFt) - 1.));
    right.set_elem(I_Id2, 0, x[I_Id2] - Id2 * (exp(x[U_Id2] / MFt) - 1.));
    right.set_elem(I_L1, 0, x[U_L1] - L1 * (x[I_L1] - prev_x[I_L1]) / delta_time);

    right.set_elem(U_E1, 0, x[U_E1] - EDS_amplitude * sin(current_time * (2 * M_PI) / EDS_period));
    right.set_elem(U_C1, 0, x[I_C1] - C1 * (x[U_C1] - prev_x[U_C1]) / delta_time);
    right.set_elem(U_C2, 0, x[I_C2] - C2 * (x[U_C2] - prev_x[U_C2]) / delta_time);
    right.set_elem(U_Cd1, 0, x[I_Cd1] - Cd1 * (x[U_Cd1] - prev_x[U_Cd1]) / delta_time);
    right.set_elem(U_Cd2, 0, x[I_Cd2] - Cd2 * (x[U_Cd2] - prev_x[U_Cd2]) / delta_time);
}

bool Model::is_converges() {
    return std::all_of(deltas.begin(), deltas.end(), [](const double &value) {
        return fabs(value) < INTEGRATION_ACCURACY;
    });
}

void Model::do_newton_step() {
    auto newton_count = 0;

    do {
        fill_matrix();
        deltas = left.solve_gauss(-right);
        for (int i = 0; i < solutions[0].size(); ++i) {
            solutions[solutions.size() - 1][i] += deltas[i];
        }

        ++newton_count;

        if (!is_converges() && newton_count > MAX_ITERATIONS) {
            newton_count = 0;
            delta_time /= 2;

            if (delta_time < MIN_DELTA_TIME) {
                std::cout << "Integration step is too small" << std::endl;
                exit(-1);
            }

            for (int i = 0; i < solutions[0].size(); ++i) {
                solutions[solutions.size() - 1][i] = solutions[solutions.size() - 2][i];
            }
        }

    } while (!is_converges());
}

void Model::solve() {
    while (current_time < TIME) {
        delta_time = corrected_delta_time;
        do_newton_step();

        auto sol = solutions.back();
        auto prev_sol = solutions[solutions.size() - 2];
        auto prev_prev_sol = solutions[solutions.size() - 3];
        auto curr_eps = 0.;

        for (int i = 0; i < solutions[0].size(); ++i) {
            auto eps = 0.5 * corrected_delta_time * fabs((sol[i] - prev_sol[i]) / corrected_delta_time -
                                                         (prev_sol[i] - prev_prev_sol[i]) / prev_delta_time);

            if (eps > curr_eps) {
                curr_eps = eps;
            }
        }

        if (curr_eps > MAX_EPS && corrected_delta_time > MIN_DELTA_TIME) {
            corrected_delta_time /= 2;
            for (int i = 0; i < solutions[0].size(); ++i) {
                solutions[solutions.size() - 1][i] = solutions[solutions.size() - 2][i];
            }
        } else {
            solutions.push_back(solutions.back());
            time.push_back(current_time);

            prev_delta_time = delta_time;
            current_time += delta_time;

            if (curr_eps < MIN_EPS || corrected_delta_time < MIN_DELTA_TIME) {
                corrected_delta_time *= 2;
            } else {
                corrected_delta_time = delta_time;
            }
        }

    }
}
