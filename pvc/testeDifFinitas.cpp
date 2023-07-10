#include "pvc.h"

int main(){
    int N=4;
    double xi=0.;
    double xf=1.;
    double yi=0.;
    double yf=1.;
    PVC pvc = PVC(xi, xf, yi, yf, N);
    std::cout<<"negocin\n";
    pvc.solveFiniteDifferences2ndOrder();
    // for (int i=0;i<M_SIZE;i++){
    //     std::cout<<"===solução "<<i<<": " << pvc.solutions[i]<<std::endl;
    // }
    std::cout<<"negocin\n";
    return 1;
}