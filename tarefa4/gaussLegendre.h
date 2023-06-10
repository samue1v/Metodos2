#ifndef GAUSS_LEGENDRE_H
#define GAUSS_LEGENDRE_H

#include "../method.h"

class GaussLegendre : public Method{
    public:
        std::vector<double> __alphas;
        int __numPoints;
    public:
        GaussLegendre();
        ~GaussLegendre() = default;
        GaussLegendre(double xi, double xf,int degree,double precision,double (*func)(double));
        double step(int stepCount, int partitionNum,std::ofstream & Log);
        
        
};

#endif