#ifndef PARTITION_COMPUTE_H
#define PARTITION_COMPUTE_H
#include "method.h"
#include <cmath>

class PartitionCompute{
    public:
        Method * __method;
        double __precision;
    public:
        PartitionCompute();
        PartitionCompute(Method * method,double precision);
        ~PartitionCompute() = default;
        bool validateInterval();
        double computeSingularity();
        double pCompute();
};

inline PartitionCompute::PartitionCompute(){
    __method = nullptr;
}

inline PartitionCompute::PartitionCompute(Method * method,double precision){
    __precision = precision;
    __method = method;
}

bool inline PartitionCompute::validateInterval(){
    return (std::isnormal(__method->__func(__method->__xi)) && !(std::isinf(__method->__func(__method->__xi))) && !(std::isnan(__method->__func(__method->__xi))) && std::isnormal(__method->__func(__method->__func(__method->__xf))) && !(std::isinf(__method->__func(__method->__xf))) && !(std::isnan(__method->__func(__method->__xf))));
}

double inline PartitionCompute::pCompute(){
    if(!validateInterval()){

    }
    std::ofstream Log("log.txt");
    int partitions = 0;
    int counter = 0;
    double current_res = INFINITY;
    double prev_res = 0;
    while(abs(current_res - prev_res) > __precision){
        partitions = partitions+=1;
        prev_res = current_res;
        current_res = 0;
        Log<<"We are currently working on " << partitions << " partitions." <<std::endl;
        for(int t = 0; t < partitions; t++){
            current_res += __method->step(t,partitions,Log);
        }
        Log<<"Result: " << current_res <<std::endl;
        Log<<std::endl;
    }
    Log.close();
    return current_res;
}

double inline PartitionCompute::computeSingularity()
{(__method->__xi + __method->__xf + (__method->__xf-__method->__xi)* tanh(M_PI/2.0 * sinh(s)))/2.0
    double fxs = __method->__func([](double s){});
    (__method->__func) = [](double s){ return __tempfunc(s); };
}
#endif