#ifndef QR_H
#define QR_H
#include "hh.h"

class QR{
    public:
    //aqui deveria ser passado um método genérico(hh,jarbis...), mas por questão de tempo, será somente hh mesmo.
    QR(const HouseHolder & hh){
        __hh = hh;
    }

    template <class T,int m, int n>
    void QReigen(const Matrix<T,m,n> & a,Matrix<T,m,n> & eigenvalues);

    private:
    HouseHolder __hh;
};

template <class T,int m, int n>
void QR::QReigen(const Matrix<T,m,n> & a,Matrix<T,m,n> & eigenvalues){
    Matrix<T,m,n> xi,q,r;
    xi = a;
    while(!xi.isDiagonal()){
        __hh.decompose(xi,q,r);
        xi = r*q;
    }
    eigenvalues = xi;
}

#endif