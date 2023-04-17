#ifndef TERM_H
#define TERM_H
#include <string>

class Term
{
    private:
        double __coefficient;
        std::string __invariant;
        //double invariantResult;
    public:
        Term();
        Term(std::string,double);
        Term operator +(const Term & rhs) const {
            if(__invariant != rhs.getInvariant()){
                return Term();
            }
            Term newT;
            newT.setInvariant(__invariant);
            newT.setCoefficient(__coefficient+rhs.getCoefficient());
            return newT;

        }

        Term operator -(const Term & rhs) const {
            if(__invariant != rhs.getInvariant()){
                return Term();
            }
            Term newT;
            newT.setInvariant(__invariant);
            newT.setCoefficient(__coefficient-rhs.getCoefficient());
            return newT;

        }

        Term operator *(const Term & rhs) const {
            if(__invariant != rhs.getInvariant()){
                return Term();
            }
            Term newT;
            newT.setInvariant(__invariant);
            newT.setCoefficient(__coefficient*rhs.getCoefficient());
            return newT;

        }

        Term operator /(const Term & rhs) const {
            if(__invariant != rhs.getInvariant()){
                return Term();
            }
            Term newT;
            newT.setInvariant(__invariant);
            newT.setCoefficient(__coefficient/rhs.getCoefficient());
            return newT;

        }
        
        double getCoefficient() const;
        std::string getInvariant() const;
        //double getInvariant
        void setCoefficient(double coefficient);
        void setInvariant(std::string invariant);
};


#endif