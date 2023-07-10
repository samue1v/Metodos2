#include <iostream>
#include "pvi.h"

int main(){
    double dt = 0.1;
    double v0 = 3;
    double y0 = 150;
    // exit(-1);
    std::cout<<"====runge kutta======\n";
    Matrix<double,2,1> s0 = std::vector<double>({v0, y0});
    PVI pviRK = PVI(dt, s0);
    std::vector<Matrix<double,2,1>> solutionsRK;
    pviRK.solveRungeKuttaExplicit2ndOrder(16.3);
    pviRK.getSolutions(solutionsRK);
    for (int i=0;i<10;i++){
        std::cout<<"===solução "<<i<<": " << solutionsRK[i]<<std::endl;
    }
    std::cout<<"solução 163: " << solutionsRK[163];
    std::cout<<"tamanho do solutionsRK: "<<solutionsRK.size()<<std::endl;
    
    std::cout<<"====preditor corretor======\n";
    PVI pviPC = PVI(dt, s0);
    std::vector<Matrix<double,2,1>> solutionsPC;
    pviPC.solvePredictorCorrector2ndOrder(16.3);
    pviPC.getSolutions(solutionsPC);
    for (int i=0;i<10;i++){
        std::cout<<"===solução "<<i<<": " << solutionsPC[i]<<std::endl;
    }
    std::cout<<"solução 161: " << solutionsPC[160];
    std::cout<<"solução 162: " << solutionsPC[161];
    std::cout<<"solução 163: " << solutionsPC[162];
    std::cout<<"solução 164: " << solutionsPC[163]; //correta

    // std::cout<<"solução 326: " << solutionsPC[326];
    // std::cout<<"solução 327: " << solutionsPC[327];
    // std::cout<<"solução 328: " << solutionsPC[328];    
    std::cout<<"tamanho do solutionsPC: "<<solutionsPC.size()<<std::endl;

    return 1;
}