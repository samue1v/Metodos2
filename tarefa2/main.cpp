#include <iostream>
#include "../partitionCompute.h"
#include "newton_cotes_closed.h"
#include "gaussLegendre.h"

int main(){
    NewtonCotesClosed * nc = new NewtonCotesClosed(0,1,2,10e-6);
    PartitionCompute * p = new PartitionCompute(nc,10e-6);
    std::cout<< p->pCompute() << std::endl;
    return 1;
}