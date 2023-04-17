#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.h"
#include <vector>
class Polynomial{
    private:
        std::vector<Term> terms;
    public:
        Polynomial();
        Polynomial(int degree);
        Polynomial(std::vector<Term>);
        double resolve(std::string invariant);
        
};

#endif