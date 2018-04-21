//
//  Geom1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.
//


#include "IntRule.h"
#include "IntRule1d.h"
#include "IntRuleQuad.h"
#include "tpanic.h"

IntRuleQuad::IntRuleQuad(){
    fOrder=0;
    SetOrder(fOrder);
}
IntRuleQuad::IntRuleQuad(int order){
    fOrder=order;
    SetOrder(fOrder);
}
void IntRuleQuad::SetOrder(int order){
    //Calculate required points number to integrate a fOrder order polynomial
    int npoints=0,resto=0;
    resto=fOrder%2;
    
    //Odd order
    if (resto!=0) {
        npoints=(fOrder+1)/2;
    }
    //Even order
    if (resto==0) {
        npoints=(fOrder+2)/2;
    }
    fPoints.Resize(npoints, 1);
    fWeights.resize(npoints);
    
    
    int p=order;
    if(p<0||p>=NPoints()){
        DebugStop();
    }
    
    IntRule1d Int1Dx(fOrder);
    IntRule1d Int1Dy(fOrder);
    
    fPoints.Resize(npoints, 1);
    fWeights.resize(npoints);
    
    VecDouble co(2);
    double weight;
    for (int i=0; i<Int1Dx.NPoints(); i++) {
        
        Int1Dx.Point(i, co, weight);
       VecDouble coX(1);
        double weightX;
        coX[0]=co[0];
        weightX=weight;
        
        for (int j=0; j<Int1Dy.NPoints(); j++) {
            
            Int1Dy.Point(j, co, weight);
            
            fPoints(j+i*Int1Dy.NPoints(),0)=co[0];
            fPoints(j+i*Int1Dy.NPoints(),1)=coX[0];
            
            fWeights[j+i*Int1Dy.NPoints()]=weightX*weight;
        }
        
    }


}
//Calculate integration points and weigths


void gaulegQuad(const double x1, const double x2, VecDouble&x, VecDouble &w){

}
    


