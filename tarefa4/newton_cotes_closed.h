#ifndef NEWTON_COTES_H
#define NEWTON_COTES_H

#include "../method.h"
#include <vector>


class NewtonCotesClosed : public Method{
    public:
        NewtonCotesClosed();
        ~NewtonCotesClosed() = default;
        NewtonCotesClosed(double xi, double xf,int degree,double precision,double (*func)(double));
        double step(int stepCount, int partitionNum,std::ofstream & Log);
        
        
};

#endif