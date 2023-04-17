#include "term.h"

Term::Term() : __coefficient(0) , __invariant("Undefined"){}





double Term::getCoefficient() const{
    return __coefficient;
}

void Term::setCoefficient(double coefficient){
    __coefficient = coefficient;
}

std::string Term::getInvariant() const{
    return __invariant;
}

void Term::setInvariant(std::string invariant){
    __invariant = invariant;
}