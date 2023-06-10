#include "gaussLegendre.h"

GaussLegendre::GaussLegendre(){
    __degree = 0;
    __precision = 0;
    __numPoints = (__degree+1)/2;
    __func = nullptr;
    //coefs = w
    switch (__numPoints)
    {
    case 2:
        __coefs = std::vector<double>({1,1});
        __alphas = std::vector<double>({-sqrt(1.0/3.0),sqrt(1.0/3.0)});
        break;
    case 3:
        __coefs = std::vector<double>({5.0/9.0 , 8.0/9.0 , 5.0/9.0});
        __alphas = std::vector<double>({-sqrt(3.0/5.0) , 0 , sqrt(3.0/5.0)});
        break;
    case 4:
        __coefs = std::vector<double>({0.5 - (sqrt(5.0/6.0)/6.0) , 0.5 + (sqrt(5.0/6.0)/6.0), 0.5 + (sqrt(5.0/6.0)/6.0), 0.5 - (sqrt(5.0/6.0)/6.0)});
        __alphas = std::vector<double>({-sqrt( (3.0/7.0) + (2.0/7.0)*sqrt(6.0/5.0) ) , -sqrt( (3.0/7.0) - (2.0/7.0)*sqrt(6.0/5.0) ) , +sqrt( (3.0/7.0) - (2.0/7.0)*sqrt(6.0/5.0) ), +sqrt( (3.0/7.0) + (2.0/7.0)*sqrt(6.0/5.0) )});
        break;
    }
}

GaussLegendre::GaussLegendre(double xi, double xf,int degree,double precision,double (*func)(double)){
    __xi = xi;
    __xf = xf;
    __degree = degree;
    __precision = precision;
    __numPoints = (__degree+1) % 2==0 ? (__degree+1)/2 : (__degree+1)/2 + 1;
    __func = func;
    switch (__numPoints)
    {
    case 2:
        __coefs = std::vector<double>({1,1});
        __alphas = std::vector<double>({-sqrt(1.0/3.0),sqrt(1.0/3.0)});
        break;
    case 3:
        __coefs = std::vector<double>({5.0/9.0 , 8.0/9.0 , 5.0/9.0});
        __alphas = std::vector<double>({-sqrt(3.0/5.0) , 0 , sqrt(3.0/5.0)});
        break;
    case 4:
        __coefs = std::vector<double>({0.5 - (sqrt(5.0/6.0)/6.0) , 0.5 + (sqrt(5.0/6.0)/6.0), 0.5 + (sqrt(5.0/6.0)/6.0), 0.5 - (sqrt(5.0/6.0)/6.0)});
        __alphas = std::vector<double>({-sqrt( (3.0/7.0) + (2.0/7.0)*sqrt(6.0/5.0) ) , -sqrt( (3.0/7.0) - (2.0/7.0)*sqrt(6.0/5.0) ) , +sqrt( (3.0/7.0) - (2.0/7.0)*sqrt(6.0/5.0) ), +sqrt( (3.0/7.0) + (2.0/7.0)*sqrt(6.0/5.0) )});
        break;
    }
}

double GaussLegendre::step(int stepCount, int partitionNum,std::ofstream & Log){
    double sum = 0;
    double lxi = __xi + ((__xf-__xi)/(double)partitionNum)*(double)stepCount;
    double lxf = lxi + (__xf-__xi)/(double)partitionNum;
    Log<<"We are in partition number " << stepCount << std::endl;
    Log<<"Partition begin: " << lxi << std::endl << "Partition end: " << lxf << std::endl;
    double h = (lxf-lxi)/2;
    double middle = (lxf+lxi)/2;
    double xalpha = 0;
    // v itera pelo número de pontos, que é calculado a partir de __degree
    // v pode dar algum valor quebrado, entao no fim das contas era melhor ter __points em vez de __degree?
    for(int v = 0;v<__numPoints;v++){
        xalpha = (middle+h*__alphas[v]);
        Log<<"Computing point" << xalpha << std::endl;
        sum = sum + __func(xalpha)*__coefs[v];
    }
    //h não possui coef em Gauss Legendre
    sum = sum*h; // * __coefs[0];
    return sum;
}
