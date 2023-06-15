#ifndef HH_H
#define HH_H

#include "../matrix.h"

class HouseHolder{
    public:
    HouseHolder(){}

    template<class T,int m,int n>
    void decompose(const Matrix<T,m,n> & a, Matrix<T,m,n> & q,Matrix<T,m,n> & r);

    private:
    template<class T,int m,int n>
    Matrix<T,m,n> buildH(const Matrix<T,m,n> & a,int i);


};


template<class T,int m,int n>
void HouseHolder::decompose(const Matrix<T,m,n> & a, Matrix<T,m,n> & q,Matrix<T,m,n> & r){
    
    Matrix<double,m,n> a_bar,hi,h_all,subident;
    int rank = m >= n ? n : m;
    a_bar = a;
    for(int i = 0;i<rank;i++){
        subident = getIdentitySubMatrix<double,m,n>(i);
        a_bar = subident * a_bar * subident;
        hi = buildH(a_bar,i);
        h_all = hi.completeDiagonal(i)*h_all;
        a_bar= hi*a_bar;
    }
    q = h_all.transpose();
    r = h_all*a;
    
}

template<class T,int m,int n>
    Matrix<T,m,n> HouseHolder::buildH(const Matrix<T,m,n> & a,int i){
        Matrix<T,m,1> xscaled,u;
        xscaled = a.getIthColumnZeroAbove(i);//.scale();
        
        u = xscaled(i)>0 ? xscaled + getCanonicalEi<T,m>(i) * xscaled.norm() : xscaled - getCanonicalEi<T,m>(i) * xscaled.norm() ;
        
        double uNorm = u.norm();
        double beta = 2.0/(uNorm*uNorm);
        return getIdentitySubMatrix<double,m,n>(i) - u*u.transpose()*beta;
    }

#endif