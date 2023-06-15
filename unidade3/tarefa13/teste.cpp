#include <iostream>
#include "../matrix.h"
#include <vector>
#include "hh.h"
#include "qr.h"
int main(){

    Matrix<double,3,3> m = std::vector<double>({1,2,0,
                                                -1,4,1,
                                                -3,1,2});
    
    Matrix<double,5,5> n = std::vector<double>(
                                               {1,2,-1,3,5,
                                                2,-1,-2,1,0,
                                                -1,-2,1,-7,2,
                                                3,1,-7,2,-1,
                                                5,0,2,-1,1});

    Matrix<double,5,5> d = std::vector<double>(
                                               {1,1e-11,1e-11,1e-11,1e-11,
                                                1e-11,-1,1e-11,1e-11,1e-11,
                                                -1e-11,1e-11,1,1e-11,1e-11,
                                                1e-11,1e-11,1e-11,2,-1e-11,
                                                1e-11,1e-11,0,0,1});

    Matrix<double,3,3> mc = std::vector<double>({2,-2,18,
                                                2,1,0,
                                                1,2,0});


    Matrix<double,4,4> a = std::vector<double>({
                                                52,30,49,28,
                                                30,50,8,44,
                                                49,8,46,16,
                                                28,44,16,22
                                              });
    Matrix<double,4,4> q,r,eigenvalues;
    HouseHolder hh;
    QR qr(hh);
    qr.QReigen(a,eigenvalues);

    std::cout<<eigenvalues;
    return 1;
}