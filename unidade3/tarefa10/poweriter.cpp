#include <iostream>
#include <math.h>
#include "../matrix.h"

Pair<double, Matrix> powerIter (const Matrix<double> A, const Matrix v, const double epsilon){
    double eigenvalue_new = 0.0;
    double eigenvalue_old;
    Matrix eigenvector_new = v;
    Matrix eigenvector_old;
    Matrix x1;
    do{
        eigenvalue_old = eigenvalue_new;
        eigenvector_old = eigenvector_new;
        x1 = eigenvector_old / sqrt(eigenvector_old.transpose() * eigenvalue_old);
        eigenvector_new = A * x1;
        eigenvalue_new = x1.transpose() * eigenvector_new;
    } while((eigenvalue_new - eigenvalue_old)/eigenvalue_new > epsilon);
    return {eigenvalue_new, eigenvector_new};
}

int main (){

    return 0;
}