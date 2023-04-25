#ifndef NEWTON_COTES_OPEN_H
#define NEWTON_COTES_OPEN_H

#include "../method.h"
#include <vector>


class NewtonCotesOpen : public Method{
    public:
        NewtonCotesOpen();
        ~NewtonCotesOpen() = default;
        NewtonCotesOpen(double xi, double xf,int degree,double precision);
        double func(double x);
        double step(int stepCount, int partitionNum,std::ofstream & Log);
        
        
};

#endif