#include <iostream>
#include "../matrix.h"
#include <vector>
#include "hh.h"
int main(){

    Matrix<double,3,3> m = std::vector<double>({1,2,0,
                                                -1,4,1,
                                                -3,1,2});
    Matrix<double,3,2> mc;
    Matrix<double,5,5> n = std::vector<double>(
                                               {1,2,-1,3,5,
                                                2,-1,-2,1,0,
                                                -1,-2,1,-7,2,
                                                3,1,-7,2,-1,
                                                5,0,2,-1,1});
    HouseHolder hh;
    //hh.tridiagonalize(m,n);
    //hh.tridiagonalize(a,b);
    //n = m.transpose();
    
    //std::cout<<m*m.transpose();
    //mc = m;
    //m(3) = 111;
    //std::cout<<mc;
    //std::cout<<m;
    std::cout<<hh.buildH(m,0)*m;
    return 1;
}