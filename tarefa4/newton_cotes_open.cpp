#include <iostream>
#include <math.h>
#include "newton_cotes_open.h"
#include <fstream>


NewtonCotesOpen::NewtonCotesOpen(){
    __degree = 0;
    __precision = 0;
    switch (__degree)
    {
    case 1:
        __coefs = std::vector<double>({3.0/2.0,1,1});
        break;
    case 2:
        __coefs = std::vector<double>({4.0/3.0,2,-1,2});
        break;
    case 3:
        __coefs = std::vector<double>({5.0/24.0,11,1,1,11});
        break;
    case 4:
        __coefs = std::vector<double>({3.0/10.0,11,-14,26,-14,11});
        break;
    }
}

NewtonCotesOpen::NewtonCotesOpen(double xi, double xf,int degree,double precision,double (*func)(double)){
    __xi = xi;
    __xf = xf;
    __degree = degree;
    __precision = precision;
    __func = func;
    switch (__degree)
    {
    case 1:
        __coefs = std::vector<double>({3.0/2.0,1,1});
        break;
    case 2:
        __coefs = std::vector<double>({4.0/3.0,2,-1,2});
        break;
    case 3:
        __coefs = std::vector<double>({5.0/24.0,11,1,1,11});
        break;
    case 4:
        __coefs = std::vector<double>({3.0/10.0,11,-14,26,-14,11});
        break;
    }
    
    
}

double NewtonCotesOpen::step(int stepCount, int partitionNum,std::ofstream & Log){
    double sum = 0;
    double lxi = __xi + ((__xf-__xi)/(double)partitionNum)*(double)stepCount;
    double lxf = lxi + (__xf-__xi)/(double)partitionNum;
    Log<<"We are in partition number " << stepCount << std::endl;
    Log<<"Partition begin: " << lxi << std::endl << "Partition end: " << lxf << std::endl;
    double h = (lxf-lxi)/double(__degree + 2);
    for(int v = 0;v<__degree+1;v++){
        Log<<"Computing point" << lxi + h + (double)v*(h) << std::endl;
        sum = sum + __func((lxi + h + (double)v*(h)))*__coefs[v+1];
    }
    sum = sum*__coefs[0]*h;
    return sum;
}
