#include <iostream>
#include "../partitionCompute.h"
#include "newton_cotes_closed.h"
#include "gaussLegendre.h"

int main(){
    GaussLegendre * gl = new GaussLegendre(0,1,7,10e-6,[](double x){return x*x;});
    
    PartitionCompute * p = new PartitionCompute(gl,10e-6);
    std::cout<<"auw\n";
    std::cout<< p->pCompute() << std::endl;
    return 1;
}