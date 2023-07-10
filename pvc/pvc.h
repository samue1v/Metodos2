#ifndef PVC_H
#define PVC_H
#include "../unidade3/matrix.h"
#include "../unidade3/tarefa13/qr.h"
#include <functional>

#define M_SIZE 9
#define R_SIZE 3
enum Pos{
    TOP,
    DOWN,
    MID,
    RIGHT,
    LEFT
};

double exampleFunction(double x, double y){
    return 4; //exemplo do creto
}

bool isInInterval(int val, int xi, int xf){
    return (xi <= val && xf >= val);
}

int map(int i,int j){
    int coord=(i-1)*R_SIZE+(j-1);
    return coord;
}

void applyMask(std::vector<double>&temp, const std::vector<double>&mask){
    for (int i=0;i<temp.size();i++){
        temp[i]*=mask[i];
    }
}
// A*X = B
void solveLinearSystem(Matrix<double,M_SIZE,M_SIZE>& A, std::vector<double>& X,std::vector<double>& B){
    std::cout<<"dentro do Solve\n";
    QR qr = QR(HouseHolder());
    Matrix<double,M_SIZE,M_SIZE>res(std::vector<double>(M_SIZE*M_SIZE,0.));
    qr.QReigen(A,res);
    for(int i=0;i<M_SIZE;i++){
        X.push_back(B[i]/res(i,i));
    }
}

class PVC{
    public:
        PVC();
        // PVC(std::function<void(Matrix<double,2,1>&,Matrix<double,2,1>&, double)> func2, double xi, double xf, double yi, double yf, int N);
        PVC(double xi, double xf, double yi, double yf, int N);
        void solveFiniteDifferences2ndOrder();
        // void solveFiniteElements();
        std::vector<double> solutions;
    private:
        std::function<void(Matrix<double,2,1>&,Matrix<double,2,1>&, double)> func2;
        int N;
        double xi;
        double xf;
        double yi;
        double yf;
};      


PVC::PVC(double xi, double xf, double yi, double yf, int N){
        this->N=N;
        this->xi=xi;
        this->xf=xf;
        this->yi=yi;
        this->yf=yf;

}

void PVC::solveFiniteDifferences2ndOrder(){
    //considera que o intervalo é sempre [0,1]
    double dx = (xf-xi)/N;
    double dy = (yf-yi)/N;
    int rsize = sqrt(M_SIZE);
    //int size = (N-1)*(N-1);
    //ordem top, down, mid, right, left
    std::vector<double> mask({1./(dy*dy), 1./(dy*dy), -2.*(1./(dx*dx)+(1./(dy*dy))), 1./(dx*dx), 1./(dx*dx)});
    Matrix<double,M_SIZE,M_SIZE>matrix(std::vector<double>(M_SIZE*M_SIZE,0));
    Matrix<double,R_SIZE+2,R_SIZE+2>u(std::vector<double>((R_SIZE+2)*(R_SIZE+2),0));
    std::vector<double> B;
    std::cout<<"inicio do preenchimento com mascara\n";    
    for (int i=1;i<R_SIZE+1;i++){
        for (int j=1;j<R_SIZE+1;j++){
            u(i,j)= 1; // exampleFunction(xi+j*dx, yf-(yi+i*dy));
            //considera que o intervalo é sempre [0,1]
            B.push_back(exampleFunction(xi+i*dx, yf-(yi+i*dy)));
        }
    }
    std::vector<double> temp(mask.size(),0);
    int t,d,m,r,l;
    int currLine = 0;
    for (int i=1;i<R_SIZE+1;i++){
        for(int j=1;j<R_SIZE+1;j++){
            t=map(i-1,j);
            d=map(i+1,j);
            m=map(i,j);
            r=map(i,j+1);
            l=map(i,j-1);
            temp[TOP] = u(i-1,j);
            temp[DOWN] = u(i+1,j);
            temp[MID] = u(i,j);
            temp[RIGHT] = u(i,j+1);
            temp[LEFT] = u(i,j-1);
            currLine=m;
            applyMask(temp,mask);
            matrix(currLine,t)=temp[TOP];
            matrix(currLine,d)=temp[DOWN];
            matrix(currLine,m)=temp[MID];
            matrix(currLine,r)=temp[RIGHT];
            matrix(currLine,l)=temp[LEFT];
        }
    }
    std::cout<<"passou do preenchimento com mascara\n";

    //resolve A*X = B para matrix e B o valor da derivada (dado por exampleFunction)
    std::cout<<matrix;
    std::cout<<matrix.solveLinearSystem(Matrix<double,9,1>(B));
    //solveLinearSystem(matrix, solutions, B);
    std::cout<<"negocin dentro\n";
}


#endif