#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <iostream>
#include <vector>

template <class T,int rows, int columns >class Matrix {
private:
  int nLines;
  int nColumns;
  T matrix[rows][columns];

public:

    Matrix(){
    this->nLines = rows;
    this->nColumns = columns;
    for(int i=0;i<rows;i++){
      for(int j=0;j<columns;j++){
        this->setVal(i,j,T());
      }
    }
  }

  T * operator[](int i) {
        return matrix[i];
  }


  T getVal(int x, int y) {
    return (this->matrix)[x][y];
  }

  Pair<int,int> getDimensions(){
    return {this->nLines,this->nColumns};
  }

  bool setVal(int x, int y, T val) {
    matrix[x][y] = val;
    return true;
  }

  static Matrix<T,rows,columns> identity(){
    Matrix<T,rows,columns> t = Matrix<T,rows,columns>();
    for(int i = 0;i<rows;i++){
      for(int j = 0;j<columns;j++){
         if(i==j){
           t.setVal(i,j,1);
         }
         else{
           t.setVal(i,j,0);
         }
      }
    }
    return t;
  }
  template <class C,int l,int k>
  Matrix<C,rows,k> operator*(Matrix<C,l,k> md){
    /*
    if(this->nColumns != md.getDimensions().left){
      return Matrix<C,rows,k>();
    }*/

    Matrix<C,rows,k> m = Matrix<C,rows,k>();
    for(int i =0;i<rows;i++){
      for(int j = 0;j<k;j++){
        T sum = 0;
        for(int s = 0;s<columns;s++){
          sum = sum + (this->getVal(i,s)*md.getVal(s,j));
        }
        m.setVal(i,j,sum);
      }
    }
    return m;
  }
  
  template <int l,int k>
  [[deprecated("not used anymore!!")]]
  T calcSum(Matrix<T,l,k> md,int line,int column){
  T sum = 0;
  for(int i =0;i<this->nColumns;i++){
    sum = sum + (this->getVal(line,i)*md.getVal(i,column));
  }
  return sum;
  }
  
  Matrix<T,rows,columns> operator-(Matrix<T,rows,columns> md){
    /*
    if((this->nLines != md.getDimensions().left)&&(this->nColumns != md.getDimensions().right)){
      return Matrix<T,rows,columns>();
    }*/
    Matrix<T,rows,columns> m = Matrix<T,rows,columns>();
    for(int i =0;i<rows;i++){
      for(int j = 0;j<columns;j++){
        m.setVal(i,j,this->getVal(i,j) - md.getVal(i,j));
      }
    }
    return m;
  }

  Matrix<T,rows,columns> operator*(float scalar){
    Matrix<T,rows,columns> m = Matrix<T,rows,columns>();
    for(int i =0;i<rows;i++){
      for(int j = 0;j<columns;j++){
        m.setVal(i,j,this->getVal(i,j)*scalar);
      }
    }
    return m;
  }

  Matrix<T,columns,rows> transpose(){
    Matrix<T,columns,rows> t = Matrix<T,columns,rows>();
    for(int i = 0;i<this->nLines;i++){
      for(int j = 0;j<this->nColumns;j++){
         t.setVal(j,i,this->getVal(i,j));
      }
    }
  return t;
}

  
};

template<class T,int n1 ,int n2 > inline std::ostream& operator<<(std::ostream& os, Matrix<T,n1,n2>& m){
    Pair<int,int> dim = m.getDimensions(); 
    T val;
    for(int i=0;i<dim.left;i++){
      for(int j=0;j<dim.right;j++){
        val = m.getVal(i,j);
        os<<val;
        os <<"  ";
      }
      os<<"\n";
    }
    return os;
}


#endif