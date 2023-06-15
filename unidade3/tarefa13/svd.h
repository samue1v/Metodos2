#ifndef SVD_H
#define SVD_H
#include "qr.h"

class SVD{
    public:
    SVD(){}
    ~SVD(){}
    //aqui deveria ser passado um método genérico(qr, poweriter, etc), mas por questão de tempo, será somente o método QR.
    SVD(const QR & qr){
        __qr = qr;
    }

    template <class T,int m, int n>
    void SingularValueDecomposition(const Matrix<T,m,n> & a, Matrix<T,m,n> & u, Matrix<T,m,n> & sigma,Matrix<T,m,n> & v);

    private:
    QR __qr;
};

template <class T,int m, int n>
void SingularValueDecomposition(const Matrix<T,m,n> & a, Matrix<T,m,n> & u, Matrix<T,m,n> & sigma,Matrix<T,m,n> & v){
    Matrix<T,m,n> a_bar;
    a_bar = a * a.transpose();
    __qr.QReigen(a_bar, u, sigma);
    sigma = sigma.map(sqrt); // conseguir fazer o compilador nao reclamar da implementação de map
    int rank = m >= n ? n : m; //checar se basta isso
    // achando v:
    temp_v.reserve(v.size()); // como pegar/calcular tamanho de v?
    temp_v.resize(v.size());
    std::vector<T> temp = 1/sqrt(sigma[i][i]) * a.transpose * u.getIthColumn(i);
    for (int i=0;i<rank;i++){
        temp_v.insert(temp_v.end(),temp.begin(), temp.end());
    }
    v = Matrix<T,m,n>(std::move(temp_v)).transpose(); // como pegar/calcular tamanho de v?
}

#endif