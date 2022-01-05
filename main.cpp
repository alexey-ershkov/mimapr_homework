#include "Model/Model.h"
#include "utils.h"

int main() {
    system("rm -rf data/");
    system("mkdir data");
    system("rm -rf ../graphs/");
    system("mkdir ../graphs");

    auto model = Model();
    model.solve();
    auto sols = model.get_solutions();
    auto time = model.get_time();

    print_to_file(sols, time);

    system("gnuplot ../scripts/plot_solutions.p");

    return 0;
}
