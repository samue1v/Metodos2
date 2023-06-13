#include <iostream>
#include "../matrix.h"
#include <vector>
#include "hh.h"
int main(){

    Matrix<double,3,3> m = std::vector<double>({1,2,3,1,2,3,1,2,3});
    Matrix<double,3,3> n;
    Matrix<double,2,2> a = std::vector<double>({1,2,1,2});
    Matrix<double,2,2> b;
    HouseHolder hh;
    hh.tridiagonalize(m,n);
    hh.tridiagonalize(a,b);
    //n = m.transpose();
    std::cout<<b;
    return 1;
}