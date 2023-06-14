#ifndef HH_H
#define HH_H

#include "../matrix.h"

class HouseHolder{
    public:
    HouseHolder(){}

    template<class T,int m,int n>
    void tridiagonalize(const Matrix<T,m,n> & a, Matrix<T,m,n> & a_bar, Matrix<T,m,n> & hn);

    //private:
    template<class T,int m,int n>
    Matrix<T,m,n> buildH(const Matrix<T,m,n> & a,int i);


};


template<class T,int m,int n>
void HouseHolder::tridiagonalize(const Matrix<T,m,n> & a, Matrix<T,m,n> & a_bar, Matrix<T,m,n> & hn){
    Matrix<double,m,n> hi;
    int rank = m >= n ? n : m;
    a_bar = a;
    for(int i = 0;i<rank;i++){
        hi = buildH(a_bar,i) * hi;
    }
    hn = std::move(hi);
}

template<class T,int m,int n>
    Matrix<T,m,n> HouseHolder::buildH(const Matrix<T,m,n> & a,int i){
        Matrix<T,m,n> hi;
        Matrix<T,m,1> xscaled,u;
        xscaled = a.getIthColumnZeroAbove(i).scale();
        u = xscaled(0)>0 ? xscaled + getCanonicalEi<T,m>(i) * xscaled.norm() : xscaled - getCanonicalEi<T,m>(i) * xscaled.norm() ;
        double uNorm = u.norm();
        double beta = 2.0/(uNorm*uNorm);
        return hi - u*u.transpose()*beta;
    }

#endif