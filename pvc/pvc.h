#ifndef PVC_H
#define PVC_H
#include "../unidade3/matrix.h"
#include <functional>

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
// A*X = B
void solveLinearSystem(std::vector<std::vector<double>>& A, std::vector<double>& X,std::vector<double>& B){

}

class PVC{
    public:
        PVC();
        PVC(std::function<void(Matrix<double,2,1>&,Matrix<double,2,1>&, double)> func2, double xi, double xf, double yi, double yf, int N);
        void solveFiniteDifferences2ndOrder();
        // void solveFiniteElements();
    private:
        std::function<void(Matrix<double,2,1>&,Matrix<double,2,1>&, double)> func2;
        int N;
        std::vector<double> solutions;
        double xi;
        double xf;
        double yi;
        double yf;
};      

void PVC::solveFiniteDifferences2ndOrder(){
    //considera que o intervalo é sempre [0,1]
    double dx = (xf-xi)/N;
    double dy = (yf-yi)/N;
    double size = (N-1)*(N-1);
    //ordem top, down, mid, right, left
    std::vector<double> mask = std::vector<double>({1/(dy*dy), 1/(dy*dy), -2*(1/(dx*dx)+(1/(dy*dy))), 1/(dx*dx), 1/(dx*dx)});
    // lembrar de inicializar a matrix com tudo 0;
    // Matrix<double, int size, int size> matrix;
    // matrix.reserve(size*size);
    // matrix.resize(size*size);
    std::vector<double> B;
    for (int i=0;i<size;i++){
        isInInterval(i-size, size, size) ? matrix[i][i-size] = mask[TOP] : 1;
        isInInterval(i+size, size, size) ? matrix[i][i+size] = mask[DOWN] : 1;
        matrix[i][i] = mask[MID];
        isInInterval(i++,size, size) ? matrix[i][i++] = mask[RIGHT] : 1;
        isInInterval(i--,size, size) ? matrix[i][i--] = mask[LEFT] : 1;

        //considera que o intervalo é sempre [0,1]
        B.push_back(exampleFunction(xi+i*dx, yi+i*dy));
    }

    //resolve A*X = B para matrix e B o valor da derivada (dado por exampleFunction)
        solveLinearSystem(matrix, solutions, B);
}


#endif