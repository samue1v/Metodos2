#ifndef PVI_H
#define PVI_H
#include "../unidade3/matrix.h"
#include <functional>

void exampleFunction(Matrix<double,2,1>& res,Matrix<double,2,1>& Si, double t){
    double g = 10.;
    double k = 0.5;
    double m = 0.5;
    res = std::vector<double>({-g - (k/m)*Si(0), Si(0)});
}

class PVI{
    public:
        PVI();
        //PVI(std::function<double(double)> func1, double dt, double s0);
        PVI(std::function<void(Matrix<double,2,1>&,Matrix<double,2,1>&, double)> func2, double dt, Matrix<double,2,1>& s0);
        PVI(double dt, Matrix<double,2,1>& s0);
        //void solve(double res, double t);
        void solveEulerExplicit(double t);
        void solveEulerImplicit(double t);
        void solveRungeKuttaExplicit2ndOrder(double t);
        void getSolutions(std::vector<Matrix<double,2,1>> & solutions);
        double getDeltaT();

    private:
        //std::function<double(double)> func1;
        std::function<void(Matrix<double,2,1>&,Matrix<double,2,1>&, double)> func2; // res, si ou si+1, t
        double dt;
        std::vector<Matrix<double,2,1>> solutions;
};

PVI::PVI(std::function<void(Matrix<double,2,1>&,Matrix<double,2,1>&, double)> func2, double dt, Matrix<double,2,1>& s0){
    // this->func2 = func2;
    this->dt = dt;
    solutions.push_back(s0);
}
PVI::PVI(double dt, Matrix<double,2,1>& s0){
    // this->func2 = func2;
    this->dt = dt;
    solutions.push_back(s0);
}

double PVI::getDeltaT(){
    return this->dt;
}

void PVI::solveEulerExplicit(double t){
    int intervals = t/dt + 1;
    Matrix<double,2,1> res;
    for(int i=1;i<=intervals;i++){
        Matrix<double,2,1> Si;
        exampleFunction(Si,solutions[i-1],i*dt); 
        res = solutions[i-1] + Si*dt;
        solutions.push_back(res);
    }
}

void PVI::solveEulerImplicit(double t){
    int intervals = t/dt + 1;
    for(int j=1;j<=intervals;j++){
        Matrix<double,2,1> Si = solutions[j-1];
        Matrix<double,2,1> Si_plus_1 = Si;
        // newton raphson method
        int maxIterations = 100;
        int iter = 0;
        double tolerance = 1e-6;
        Matrix<double,2,1> error = std::vector<double>({1., 1.});
        Matrix<double,2,1>Si_plus_1_new;
        Matrix<double,2,1>funcRes;
        Matrix<double,2,1>funcRes_dx;
        double dx = 1e-3;
        while (error.max() > tolerance && iter < maxIterations) {
            // Si_plus_1 = Si + F(Si,i*dt)*dt;
            exampleFunction(funcRes,Si_plus_1,j*dt);
            Si_plus_1 = Si + funcRes*dt;
            auto _g = Si_plus_1 - Si - funcRes*dt;

            auto Si_plus_1_dx = Si_plus_1+dx;
            exampleFunction(funcRes_dx, Si_plus_1_dx, j*dt);
            auto _g_plus_dx = Si_plus_1+dx - Si - funcRes_dx*dt;
            // trapezoid rule
            auto _g_deriv = ((_g_plus_dx) - (_g))/dx;
            Si_plus_1_new = Si_plus_1 - _g/_g_deriv;
            auto deltaS = Si_plus_1_new - Si_plus_1;
            error = deltaS.abs();
            Si_plus_1 = Si_plus_1_new;
            iter++;
        }
        solutions.push_back(Si_plus_1);
    }
}

void PVI::solveRungeKuttaExplicit2ndOrder(double t){
    Matrix<double,2,1> Si_plus_1_bar;
    PVI eulerPVI = PVI(getDeltaT(), solutions[0]);
    int intervals = t/dt + 1;
    Matrix<double,2,1> res;
    Matrix<double,2,1>funcRes;
    Matrix<double,2,1>funcRes_bar;
    for(int i=1;i<=intervals;i++){
    Matrix<double,2,1> Si = solutions[i-1];
        eulerPVI.solveEulerExplicit(i*dt);
        // Si_plus_1_bar = Si + dt * F(Si,i*dt)
        exampleFunction(funcRes,Si,i*dt);
        Si_plus_1_bar = Si + funcRes*dt;
        // Si_plus_1 = Si + dt * 1/2 *(F(Si_plus_1_bar,i*dt) + F(Si,i*dt))
        exampleFunction(funcRes_bar,Si_plus_1_bar,i*dt);
        auto Si_plus_1 = Si + (funcRes+funcRes_bar)*dt*1/2;
        solutions.push_back(Si_plus_1);
    }
}

void PVI::getSolutions(std::vector<Matrix<double,2,1>> & solutions){
    solutions = this->solutions;
}

#endif