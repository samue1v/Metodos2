#include <iostream>
#include <math.h>
#include "newton_cotes.h"
#include <fstream>


Newton_Cotes::Newton_Cotes() : __degree(0) , __precision(0) {}

Newton_Cotes::Newton_Cotes(double xi, double xf,int degree,double precision,int approach){
    __xi = xi;
    __xf = xf;
    __degree = degree;
    __precision = precision;
    __approach = approach;
    

    if(!approach){
        switch (__degree)
        {
        case 1:
            __coefs = std::vector<double>({0.5,1,1});
        case 2:
            __coefs = std::vector<double>({1.0/3.0,1,4,1});
        case 3:
            __coefs = std::vector<double>({3.0/8.0,1,3,3,1});
        case 4:
            __coefs = std::vector<double>({2.0/45.0,7,32,12,32,7});
        }
        //computeClosed();
    }
    else{
        //computeOpen();
    }
    /*
    if(approach){
        double h = (xf-xi)/degree;
        for(int t = 0 ; t<degree+1;t++){
            __points.push_back(xi + t*h);
        }
    }
    else{
        double h = (xf-xi)/(degree+2);
        for(int t = 0 ; t<degree+3;t++){
            __points.push_back(xi + h + t*h);
        }
    }
    */
    
}

double Newton_Cotes::func(double x){
    return x*x;
}

void Newton_Cotes::setDegree(int degree){
    __degree = degree;
}

void Newton_Cotes::setPrecision(double precision){
    __precision = precision;
}

double Newton_Cotes::computeClosed(){
    std::ofstream Log("log.txt");
    int partitions = 1;
    int counter = 0;
    double current_res = INFINITY;
    double prev_res = 0;
    double lxi,lxf;
    while(abs(current_res - prev_res) > __precision){
        partitions = partitions << 1;
        prev_res = current_res;
        current_res = 0;
        Log<<"We are currently working on " << partitions << " partitions." <<std::endl;
        for(int t = 0; t < partitions; t++){
            double sum = 0;
            lxi = __xi + ((__xf-__xi)/(double)partitions)*(double)t;
            lxf = lxi + (__xf-__xi)/(double)partitions;
            Log<<"We are in partition number " << t << std::endl;
            Log<<"Partition begin: " << lxi << std::endl << "Partition end: " << lxf << std::endl;
            double h = (lxf-lxi)/(double)__degree;
            for(int v = 0;v<__degree+1;v++){
                Log<<"Computing point" << lxi + (double)v*(h) << std::endl;
                sum = sum + func((lxi + (double)v*(h)))*__coefs[v+1];
            }
            sum = sum*__coefs[0]*h;
            current_res += sum;
        }
        //std::cout<<"Partitions: "<<partitions<<std::endl;
        //std::cout<< "Res: " <<current_res<<std::endl;

    }
    Log.close();
    return current_res;
}










double Newton_Cotes::computeOpen(){
    /*
    int partitions = 1;
    int counter = 0;
    double current_res = INFINITY;
    double prev_res = 0;
    double lxi,lxf;
    while(current_res - prev_res > __precision){
        partitions << counter;
        for(int t = 0; t < partitions; t++){
            lxi = __xi + ((__xf-__xi)/partitions)*t;
            lxf = lxi + (__xf-__xi)/partitions;
            double 
        }

    }
    */
}