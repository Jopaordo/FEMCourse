//
//  Geom1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.
//

#include "Shape1d.h"
#include "DataTypes.h"


    /// computes the shape functions in function of the coordinate in parameter space and orders of the shape functions (size of orders is number of sides of the element topology)

void Shape1d::Shape(VecDouble &xi, VecInt &orders, VecDouble &phi, Matrix &dphi){
    
    int fPorder = NShapeFunctions(orders)-1;
    phi.resize(fPorder+1);
    dphi.Resize(1,fPorder+1);
    for (int i=0; i<fPorder+1; i++) {
        phi[i]=1.;
        dphi(0,i)=0;
    }
    
    for (int i=0; i<fPorder+1; i++) {
        double epsi=-1.+i*2./fPorder;
        
        for (int j=0; j<fPorder+1; j++) {
            
            TMatrix axdphi(1,fPorder+1);
            if (i!=j) {
                double epsj=-1.+j*2./fPorder;
                
                phi[i]*=(xi[0]-epsj)/(epsi-epsj);
                
                axdphi(0,i)=1/(epsi-epsj);
                
                for (int k=0; k<fPorder+1; k++) {
                    if (k!=i&&k!=j) {
                        epsj=-1.+k*2./fPorder;
                        axdphi(0,i)*=(xi[0]-epsj)/(epsi-epsj);
                    }
                }
                dphi(0,i)+=axdphi(0,i);
            }
        }
    }
}
    
    /// returns the number of shape functions associated with a side

 int Shape1d::NShapeFunctions(int side, VecInt &orders){
     return orders[side];
}
    
    /// returns the total number of shape functions

 int Shape1d::NShapeFunctions(VecInt &orders){
    int order = orders.size();
     int s=0;
     for (int i=0; i<order; i++) {
         s=s+orders[i];
     }
     return s;
 }

