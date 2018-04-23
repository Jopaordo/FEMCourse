//
//  Geom1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.
//

#include "Shape1d.h"
#include "ShapeQuad.h"
#include "ShapeTriangle.h"
#include "DataTypes.h"

/// computes the shape functions in function of the coordinate in parameter space and orders of the shape functions (size of orders is number of sides of the element topology)
void ShapeTriangle::Shape(VecDouble &xi, VecInt &orders, VecDouble &phi, Matrix &dphi){
 
    ///Shape(TVec<double> &point, TVec<double> &phi, TMatrix &dphi)
    
    int fPorder = NShapeFunctions(orders)-1;
    phi.resize(fPorder+1);
    dphi.Resize(1,fPorder+1);
    for (int i=0; i<fPorder+1; i++){
        phi[i]=1.;
        dphi(0,i)=0;
    }

        if (fPorder==1){
            
            phi[0]=1-xi[0]-xi[1];
            phi[1]=xi[0];
            phi[2]=xi[1];
            
            
            dphi(0,0)=-1;
            dphi(0,1)=1;
            dphi(0,2)=0;
            dphi(1,0)=-1;
            dphi(1,1)=0;
            dphi(1,2)=1;
            
            
        }
        
        if (fPorder==2) {
            
            VecDouble eps(orders.size());
            
            eps[0]=1-xi[0]-xi[1];
            eps[1]=xi[0];
            eps[2]=xi[1];
            
            
            
            phi[0]=2*eps[0]*(eps[0]-0.5);
            phi[1]=2*eps[1]*(eps[1]-0.5);
            phi[2]=2*eps[2]*(eps[2]-0.5);
            phi[3]=4*eps[0]*eps[1];
            phi[4]=4*eps[1]*eps[2];
            phi[5]=4*eps[2]*eps[0];
            
            dphi(0,0)=-2*(0.5 - xi[1] - xi[0]) - 2*(1 - xi[1] - xi[0]);
            dphi(0,1)=2*(-0.5+xi[0])+2*xi[0];
            dphi(0,2)=0;
            dphi(0,3)=4*(1 - xi[1] - xi[0]) - 4*xi[0];
            dphi(0,4)=4*xi[1];
            dphi(0,5)=-4*xi[1];
            
            
            dphi(1,0)=-2*(0.5 - xi[1] - xi[0]) - 2*(1 - xi[1] - xi[0]);
            dphi(1,1)=0;
            dphi(1,2)=2*(-0.5 + xi[1]) + 2*xi[1];
            dphi(1,3)=-4*xi[0];
            dphi(1,4)=4*xi[0];
            dphi(1,5)=-4*xi[1] + 4*(1 - xi[1] - xi[0]);
            
            
        }
        
        if (fPorder==3){
            
            VecDouble eps(orders.size());
            
            eps[0]=1-xi[0]-xi[1];
            eps[1]=xi[0];
            eps[2]=xi[1];
            
            
            
            for (int i=0; i<=2; i++){
                phi[i]=(9/2)*eps[i]*(eps[i]-2/3)*(eps[i]-1/3);
            }
            
            phi[3]=(27/2)*eps[0]*eps[1]*(eps[0]-1/3);
            phi[4]=(27/2)*eps[0]*eps[1]*(eps[1]-1/3);
            phi[5]=(27/2)*eps[1]*eps[2]*(eps[1]-1/3);
            
            phi[6]=(27/2)*eps[1]*eps[2]*(eps[1]-2/3);
            phi[7]=(27/2)*eps[0]*eps[2]*(eps[2]-1/3);
            phi[8]=(27/2)*eps[0]*eps[2]*(eps[0]-1/3);
            
            phi[9]=27*eps[0]*eps[1]*eps[2];
            
            
            dphi(0,0)=-(9/2)*(1/3 - xi[0] - xi[1])*(2/3 - xi[0] - xi[1]) -
            (9/2)*(1/3 - xi[0] - xi[1])*(1 - xi[0] - xi[1]) -
            (9/2)*(2/3 - xi[0] - xi[1])*(1 - xi[0] - xi[1]);
            dphi(0, 1) = (9 / 2)*(-(2 / 3) + xi[0])*(-(1 / 3) + xi[0]) +
            (9 / 2)*(-(2 / 3) + xi[0])*xi[0] + (9 / 2)*(-(1 / 3) + xi[0])*xi[0];
            dphi(0, 2) = 0;
            dphi(0, 3) = -(27 / 2)*xi[0] * (2 / 3 - xi[0] - xi[1]) -
            (27 / 2)*xi[0] * (1 - xi[0] - xi[1]) +
            (27 / 2)*(2 / 3 - xi[0] - xi[1])*(1 - xi[0] - xi[1]);
            dphi(0, 4) = -(27 / 2)*(-(1 / 3) + xi[0])*xi[0] +
            (27 / 2)*(-(1 / 3) + xi[0])*(1 - xi[0] - xi[1]) +
            (27 / 2)*xi[0] * (1 - xi[0] - xi[1]);
            dphi(0, 5) = (27 / 2)*(-(1 / 3) + xi[0])*xi[1] + (27 / 2)*xi[0] * xi[1];
            dphi(0, 6) = (27 / 2)*(-(2 / 3) + xi[0])*xi[1] + (27 / 2)*xi[0] * xi[1];
            dphi(0, 7) = -(27 / 2)*(-(1 / 3) + xi[1])*xi[1];
            dphi(0, 8) = -(27 / 2)*(2 / 3 - xi[0] - xi[1])*xi[1] -
            (27 / 2)*(1 - xi[0] - xi[1])*xi[1];
            dphi(0, 9) = -27 * xi[0] * xi[1] + 27 * (1 - xi[0] - xi[1])*xi[1];
            
            dphi(1, 0) = -(9 / 2)*(1 / 3 - xi[0] - xi[1])*(2 / 3 - xi[0] - xi[1]) -
            (9 / 2)*(1 / 3 - xi[0] - xi[1])*(1 - xi[0] - xi[1]) -
            (9 / 2)*(2 / 3 - xi[0] - xi[1])*(1 - xi[0] - xi[1]);
            dphi(1, 1) = 0;
            dphi(1, 2) = (9 / 2)*(-(2 / 3) + xi[1])*(-(1 / 3) + xi[1]) +
            (9 / 2)*(-(2 / 3) + xi[1])*xi[1] + (9 / 2)*(-(1 / 3) + xi[1])*xi[1];
            dphi(1, 3) = -(27 / 2)*xi[0] * (2 / 3 - xi[0] - xi[1]) -
            (27 / 2)*xi[0] * (1 - xi[0] - xi[1]);
            dphi(1, 4) = -(27 / 2)*(-(1 / 3) + xi[0])*xi[0];
            dphi(1, 5) = (27 / 2)*(-(1 / 3) + xi[0])*xi[0];
            dphi(1, 6) = (27 / 2)*(-(2 / 3) + xi[0])*xi[0];
            dphi(1, 7) = (27 / 2)*(1 - xi[0] - xi[1])*(-(1 / 3) + xi[1]) +
            (27 / 2)*(1 - xi[0] - xi[1])*xi[1] -
            (27 / 2)*(-(1 / 3) + xi[1])*xi[1];
            dphi(1, 8) = (27 / 2)*(2 / 3 - xi[0] - xi[1])*(1 - xi[0] - xi[1]) -
            (27 / 2)*(2 / 3 - xi[0] - xi[1])*xi[1] -
            (27 / 2)*(1 - xi[0] - xi[1])*xi[1];
            dphi(1, 9) = 27 * xi[0] * (1 - xi[0] - xi[1]) - 27 * xi[0] * xi[1];
            
            
    }
}

/// returns the number of shape functions associated with a side
int ShapeTriangle::NShapeFunctions(int side, VecInt &orders){
        return orders[side];
}

/// returns the total number of shape functions

int ShapeTriangle::NShapeFunctions(VecInt &orders){
    int order = orders.size();
    int s=0;
    for (int i=0; i<order; i++) {
        s=s+orders[i];
    }
    return s;
}