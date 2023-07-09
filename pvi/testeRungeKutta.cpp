#include <iostream>
#include "pvi.h"

int main(){
    double dt = 0.1;
    double v0 = 3;
    double y0 = 150;
    // exit(-1);
    Matrix<double,2,1> s0 = std::vector<double>({v0, y0});
    PVI pvi = PVI(dt, s0);
    std::vector<Matrix<double,2,1>> solutions;
    pvi.solveRungeKuttaExplicit2ndOrder(16.3);
    pvi.getSolutions(solutions);
    std::cout<<"solução 1: " << solutions[1] << std::endl;
    std::cout<<"solução 2: " << solutions[2] << std::endl;
    std::cout<<"solução 163: " << solutions[163] << std::endl;
    return 1;
}