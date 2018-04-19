//
//  Geom1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.
//


#include "IntRule.h"
#include "tpanic.h"


//Default Constructor of integration rule
IntRule::IntRule(){
    fOrder=0;
}


IntRule::IntRule(int order){
    fOrder=order;
}

IntRule::~IntRule(){
    
}

void IntRule::operator=(const IntRule &copy){
    fOrder=copy.fOrder;
    fPoints=copy.fPoints;
    fWeights=copy.fWeights;
}

IntRule::IntRule(const IntRule &copy){
    fOrder=copy.fOrder;
    fPoints=copy.fPoints;
    fWeights=copy.fWeights;
    
}



int IntRule::NPoints() const{
    return fWeights.size();
}

void IntRule::Point(int p, VecDouble &co, double &weight) const{
    
    co[0]=fPoints.GetVal(p, 0);
    weight=fWeights[p];

}

void IntRule::Print(std::ostream &out) const{
    std::cout<<"Polinomial Order: "<<fOrder<<"\n";
    std::cout<<"Integration Points Number: "<<NPoints()<<"\n";

    
}
