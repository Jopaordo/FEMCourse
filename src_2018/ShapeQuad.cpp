//
//  Geom1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.
//

#include "Shape1d.h"
#include "ShapeQuad.h"
#include "DataTypes.h"

/// computes the shape functions in function of the coordinate in parameter space and orders of the shape functions (size of orders is number of sides of the element topology)

void ShapeQuad::Shape(VecDouble &xi, VecInt &orders, VecDouble &phi, Matrix &dphi){
    int fPorder = NShapeFunctions(orders)-1;
    phi.resize(fPorder+1);
    dphi.Resize(1,fPorder+1);
    for (int i=0; i<fPorder+1; i++){
        phi[i]=1.;
        dphi(0,i)=0;
    }
    if (fPorder==1) {
        
        int Indices[2][2]={{0,3},{1,2}};
        
        VecDouble coxi(1);
        coxi[0]=xi[0];
        
       VecDouble coeta(1);
        coeta[0]=xi[1];
        
        VecDouble phixi(orders.size()), phieta(orders.size());
        TMatrix dphixi(1,orders.size()),dphieta(1,orders.size());
        
        phi.resize(4);
        dphi.Resize(2, 4);
        
        
        for (int xi=0; xi<fPorder+1; xi++) {
            
            Shape1d::Shape(coxi, orders, phixi, dphixi);
            
            for (int eta=0; eta<fPorder+1; eta++) {
                
                Shape1d::Shape(coeta, orders, phieta, dphieta);
                
                phi[Indices[xi][eta]]=phixi[xi]*phieta[eta];
                
                dphi(0,Indices[xi][eta])=dphixi(0,xi)*phieta[eta];
                dphi(1,Indices[xi][eta])=dphieta(0,eta)*phixi[xi];
                
            }
            
        }
        
    }
    
    if (fPorder==2) {
        
        int Indices[3][3]={{0,7,3},{4,8,6},{1,5,2}};
        
        VecDouble coxi(1);
        coxi[0]=xi[0];
        
        VecDouble coeta(1);
        coeta[0]=xi[1];
        
        VecDouble phixi(orders.size()), phieta(orders.size());
        TMatrix dphixi(1,orders.size()),dphieta(1,orders.size());
        
        phi.resize(9);
        dphi.Resize(2, 9);
        
        
        for (int xi=0; xi<fPorder+1; xi++) {
            
            Shape1d::Shape(coxi, orders, phixi, dphixi);
            
            for (int eta=0; eta<fPorder+1; eta++) {
                
                Shape1d::Shape(coeta, orders, phieta, dphieta);
                
                phi[Indices[xi][eta]]=phixi[xi]*phieta[eta];
                
                dphi(0,Indices[xi][eta])=dphixi(0,xi)*phieta[eta];
                dphi(1,Indices[xi][eta])=dphieta(0,eta)*phixi[xi];
                
            }
        }
    }
}

/// returns the number of shape functions associated with a side

int ShapeQuad::NShapeFunctions(int side, VecInt &orders){
    return orders[side];
}

/// returns the total number of shape functions

int ShapeQuad::NShapeFunctions(VecInt &orders){
int order = orders.size();
int s=0;
for (int i=0; i<order; i++) {
    s=s+orders[i];
}
return s;
}
