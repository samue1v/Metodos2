#ifndef METHOD_H
#define METHOD_H

#include <vector>
#include <fstream>
#include <math.h>

class Method{

    public:
        std::vector<double> __points;
        std::vector<double> __coefs;
        double __xi;
        double __xf;
        double __precision;
        int __degree;

    public:
        virtual double func(double x) = 0;
        virtual double step(int stepCount, int partitionNum,std::ofstream & Log) = 0;

};


#endif