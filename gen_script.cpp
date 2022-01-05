//
// Created by a.ershkov on 05.01.2022.
//

#include "constants.h"
#include <fstream>

int main() {
    system("rm -rf ../scripts");
    system("mkdir ../scripts");

    std::ofstream file;
    file.open("../scripts/plot_solutions.p");

    file << "set terminal png size 1100,750" << std::endl;

    for (const auto& name: string_names) {
        file << "set output '../graphs/" + name + ".png' " << std::endl;
        file << "set xlabel 't' " << std::endl;
        file << "plot '../cmake-build-debug/data/" + name + "' u 1:2 w l title '" + name + "'" << std::endl;
        file << std::endl;
    }

    file.close();

    return 0;
}