#include <iostream>
#include "../matrix.h"

double mult100 (double elem){
    return elem*100;
}

// Matrix<double,3,3> map (Matrix<double,3,3>&m,double (*func) (double)) {
//     std::vector<double> v;
//     v.reserve(9);
//     v.resize(9);
//     for(int i=0;i<9;i++){
//         v[i] = func(m(i));
//     }
//     return Matrix<double,3,3>(std::move(v));
//  }

int main(){
    Matrix<double,3,3> m = std::vector<double>({9,9,9,
                                                1,4,1,
                                                3,5,2});

    // m(0) = 0;
    // std::cout<<m;
    std::cout << m.map(&mult100);
    return 1;
}