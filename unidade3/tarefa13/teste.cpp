#include <iostream>
#include "../matrix.h"
#include <vector>
#include "hh.h"
int main(){

    Matrix<double,3,2> m = std::vector<double>({1,2,3,4,5,6});
    Matrix<double,2,3> n = std::vector<double>({4,5,6,4,5,6});
    HouseHolder hh;
    //hh.tridiagonalize(m,n);
    //hh.tridiagonalize(a,b);
    //n = m.transpose();
    std::cout<<m.transpose();
    return 1;
}