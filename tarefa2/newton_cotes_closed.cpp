#include <iostream>
#include <math.h>
#include "newton_cotes_closed.h"
#include <fstream>


NewtonCotesClosed::NewtonCotesClosed(){
    __degree = 0;
    __precision = 0;
    switch (__degree)
    {
    case 1:
        __coefs = std::vector<double>({0.5,1,1});
        break;
    case 2:
        __coefs = std::vector<double>({1.0/3.0,1,4,1});
        break;
    case 3:
        __coefs = std::vector<double>({3.0/8.0,1,3,3,1});
        break;
    case 4:
        __coefs = std::vector<double>({2.0/45.0,7,32,12,32,7});
        break;
    }
}

NewtonCotesClosed::NewtonCotesClosed(double xi, double xf,int degree,double precision){
    __xi = xi;
    __xf = xf;
    __degree = degree;
    __precision = precision;
    switch (__degree)
    {
    case 1:
        __coefs = std::vector<double>({0.5,1,1});
        break;
    case 2:
        __coefs = std::vector<double>({1.0/3.0,1,4,1});
        break;
    case 3:
        __coefs = std::vector<double>({3.0/8.0,1,3,3,1});
        break;
    case 4:
        __coefs = std::vector<double>({2.0/45.0,7,32,12,32,7});
        break;
    }
    
    
}

double NewtonCotesClosed::func(double x){
    return x*x;
}



double NewtonCotesClosed::step(int stepCount, int partitionNum,std::ofstream & Log){
    double sum = 0;
    double lxi = __xi + ((__xf-__xi)/(double)partitionNum)*(double)stepCount;
    double lxf = lxi + (__xf-__xi)/(double)partitionNum;
    Log<<"We are in partition number " << stepCount << std::endl;
    Log<<"Partition begin: " << lxi << std::endl << "Partition end: " << lxf << std::endl;
    double h = (lxf-lxi)/double(__degree);
    for(int v = 0;v<__degree+1;v++){
        Log<<"Computing point" << lxi + (double)v*(h) << std::endl;
        sum = sum + func((lxi + (double)v*(h)))*__coefs[v+1];
    }
    sum = sum*__coefs[0]*h;
    return sum;
}

