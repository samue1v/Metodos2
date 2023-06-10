#include <iostream>
#include "matrix.h"
#include "vector"

int main(){

    Matrix<double,5,5> m = std::vector<double>(
                        {1,2,3,4,5,
                         2,3,4,5,1,
                         3,4,5,1,2,
                         4,5,1,2,3,
                         5,1,2,3,4});
    
    Matrix<double,5,5> diag = std::vector<double>(
                        {1,0,0,0,0,
                         0,2,0,0,0,
                         0,0,3,0,0,
                         0,0,0,4,0,
                         0,0,0,0,5});


    double d = m.det();   
    Matrix<double,5,5>i = m.inverse();
    std::cout<<d;
    std::cout<<std::endl;
    std::cout<<i;
    return 1;
}