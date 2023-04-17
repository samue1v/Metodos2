#ifndef NEWTON_COTES_H
#define NEWTON_COTES_H

#include <vector>

#define CLOSED 0
#define OPEN 1

class Newton_Cotes{
    public:
        std::vector<double> __points;
        std::vector<double> __coefs;
        double __xi;
        double __xf;
        double __precision;
        int __degree;
        int __approach;
    public:
        Newton_Cotes();
        ~Newton_Cotes() = default;
        Newton_Cotes(double xi, double xf,int degree,double precision,int approach);
        void setPrecision(double precision);
        void setDegree(int degree);
        double computeClosed();
        double computeOpen();
        double func(double x);
        
};

#endif