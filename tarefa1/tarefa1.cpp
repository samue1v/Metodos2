#include <iostream>
#include <math.h>
#include <vector>


void printVec(std::vector<double> & vec );

double poly(double x){
    return sqrt(pow(exp(1),3*x)+4*x*x);
}

void calcPoints(int numPoints, double x0, double delta, const std::vector<double> & vecCoef, std::vector<double> & vecRes){
    double padleft = -(numPoints/2)*delta;
    double currentCoef;
    double polyRes;
    
    for( int i = 0;i<numPoints;++i){
        currentCoef =  padleft + x0 + i*delta;
        polyRes = poly(currentCoef);
        
        vecRes.insert(vecRes.begin() + i,polyRes);
    }
    
    std::cout<<std::endl;
    
}

double calcSum(const std::vector<double> & vecCoef,const std::vector<double> & vecRes){
    double sum = 0;
    for(int i = 0;i<vecRes.size();i++){
        sum+= vecRes.at(i) * vecCoef.at(i);
    }
    return sum;
}

void printVec(std::vector<double> & vec ){
    for(int i = 0;i<vec.size();i++){
        std::cout<< std::fixed << *(vec.begin() + i) << " " <<std::endl;
    }
    std::cout<<std::endl;
}

int main(){
    double delta = 0.5;
    double x0 = 2.0;
    int numPoints = 5;
    double denom = 12*delta*delta;
    std::cout.precision(5);
    std::vector<double> vecRes;
    vecRes.reserve(5);
    std::vector<double> vecCoef = {-1.0/denom,16.0/denom,-30.0/denom,16.0/denom,-1.0/denom};


    
    double sum = 0;
    double error = INFINITY;
    double lastSum = -INFINITY;
    int counter = 0;
    while(error>1e-4){
        std::cout<<"Iteração: " << counter++ << std::endl;
        calcPoints(numPoints,x0,delta,vecCoef,vecRes);
        sum = calcSum(vecCoef,vecRes);
        printVec(vecRes);
        std::cout<< "Sum = " << sum << std::endl;
        error = (sum - lastSum)/sum;
        error = error < 0  ? -error : error;
        std::cout<< "Error "<<error <<std::endl;

        vecRes.clear();
        delta =  delta / 2;
        denom = 12*delta*delta;
        vecCoef = {-1.0/denom,16.0/denom,-30.0/denom,16.0/denom,-1.0/denom};
        lastSum = sum;

    }


    
}