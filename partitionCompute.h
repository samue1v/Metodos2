#ifndef PARTITION_COMPUTE_H
#define PARTITION_COMPUTE_H
#include "method.h"

class PartitionCompute{
    public:
        Method * __method;
        double __precision;
    public:
        PartitionCompute();
        PartitionCompute(Method * method,double precision);
        ~PartitionCompute() = default;
        double pCompute();
};

inline PartitionCompute::PartitionCompute(){
    __method = nullptr;
}

inline PartitionCompute::PartitionCompute(Method * method,double precision){
    __precision = precision;
    __method = method;
}

double inline PartitionCompute::pCompute(){
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

#endif