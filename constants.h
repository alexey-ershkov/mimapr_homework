//
// Created by a.ershkov on 12.12.2021.
//

#ifndef HW_CONSTANTS_H
#define HW_CONSTANTS_H

#include <vector>
#include <string>

#define MATRIX_SIZE 26


#define R1 1e3
#define Rb1 20.0
#define Rb2 20.0
#define Rd1 1e6
#define Rd2 1e6
#define L1 2.53e-4
#define C1 1e-6
#define C2 1e-6
#define Cd1 2e-12
#define Cd2 2e-12
#define Id1 1e-12
#define Id2 1e-12
#define MFt 0.026
#define EDS_amplitude 10.0
#define EDS_period 1e-4

enum Names {
    U_Rb1,
    U_R1,
    U_Rb2,
    U_Rd1,
    U_Rd2,
    U_Id1,
    U_Id2,
    U_L1,
    I_E1,
    I_C1,
    I_C2,
    I_Cd1,
    I_Cd2,
    I_Rb1,
    I_R1,
    I_Rb2,
    I_Rd1,
    I_Rd2,
    I_Id1,
    I_Id2,
    I_L1,
    U_E1,
    U_C1,
    U_C2,
    U_Cd1,
    U_Cd2,
};

#define TIME 1e-3
#define MIN_DELTA_TIME 1e-15

#define MAX_ITERATIONS 10
#define INTEGRATION_ACCURACY 1e-4

#define MAX_EPS 1e-2
#define MIN_EPS 1e-3


#endif //HW_CONSTANTS_H
