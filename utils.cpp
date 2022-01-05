#include "utils.h"

void print_to_file(const std::vector<std::vector<double>> &solutions, const std::vector<double> &time) {
    std::vector<std::ofstream> files;
    files.resize(get_names().size());
    for (int i = 0; i < get_names().size(); ++i) {
        files[i].open("data/" + get_names()[i]);
    }

    for (int i = 0; i < time.size(); ++i) {
        for (int j = 0; j < get_names().size(); ++j) {
            files[j] << time[i] << " " << solutions[i][j] << std::endl;
        }
    }

    for (auto &file: files) {
        file.close();
    }
}

std::vector<std::string> get_names() {
    return {
            "U_Rb1",
            "U_R1",
            "U_Rb2",
            "U_Rd1",
            "U_Rd2",
            "U_Id1",
            "U_Id2",
            "U_L1",
            "I_E1",
            "I_C1",
            "I_C2",
            "I_Cd1",
            "I_Cd2",
            "I_Rb1",
            "I_R1",
            "I_Rb2",
            "I_Rd1",
            "I_Rd2",
            "I_Id1",
            "I_Id2",
            "I_L1",
            "U_E1",
            "U_C1",
            "U_C2",
            "U_Cd1",
            "U_Cd2",
    };
}