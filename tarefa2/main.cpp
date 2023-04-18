#include <iostream>
#include "newton_cotes.h"

int main(){

    Newton_Cotes nc = Newton_Cotes(0,1,4,10e-6,OPEN);
    std::cout<< nc.computeOpen()<<std::endl;
    return 1;
}