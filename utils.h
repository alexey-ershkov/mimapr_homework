//
// Created by a.ershkov on 12.12.2021.
//

#ifndef HW_UTILS_H
#define HW_UTILS_H

#include <vector>
#include <fstream>
#include "constants.h"
#include <string>

void print_to_file(const std::vector<std::vector<double>> &solutions, const std::vector<double> &time);

std::vector<std::string> get_names();

#endif //HW_UTILS_H
