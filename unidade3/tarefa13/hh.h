#ifndef HH_H
#define HH_H

#include "../matrix.h"

class HouseHolder{
    public:
    HouseHolder(){}

    template<class T,int n,int m>
    void tridiagonalize(const Matrix<T,n,m> & a, Matrix<T,n,m> & a_bar){
        a_bar = a.transpose();
    }
};

#endif